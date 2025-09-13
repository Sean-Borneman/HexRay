#!/usr/bin/env python3
"""
Vulnerability and payload extractor with LLM integration + offline heuristics.

Inputs:
 - combined context file (e.g., storage/working_combined.txt or the LLM
   combined input file)
 - optional typed C and summary files from the LLM typing phase

Outputs (written to storage/results):
 - vulnerabilities.json: structured findings (LLM + heuristics)
 - possible_exploits.txt: concise human-readable exploit avenues (ASCII only)
 - payloads.json: candidate payloads to try (consumed by auto_exploit.py)
 - autohack_llm_report.txt: raw LLM report (when LLM is available)
"""
from __future__ import annotations

import json
import os
import re
import sys
from pathlib import Path
from typing import Dict, List, Optional


# Ensure we can import llm_analyzer when running from automatedhacking/
def _ensure_import_path():
    here = Path(__file__).resolve().parent
    parent = here.parent
    if str(parent) not in sys.path:
        sys.path.insert(0, str(parent))


_ensure_import_path()
try:
    from llm_analyzer import LLMAnalyzer  # type: ignore
except Exception:
    LLMAnalyzer = None  # type: ignore


DANGEROUS_FUNCS = [
    'gets', 'strcpy', 'strcat', 'sprintf', 'vsprintf', 'scanf', 'fscanf', 'sscanf',
    'memcpy', 'memmove', 'bcopy', 'strncpy', 'strncat', 'snprintf', 'vsnprintf',
    'system', 'popen', 'execl', 'execlp', 'execle', 'execv', 'execvp', 'execve',
]

VULN_KEYWORDS = [
    'buffer overflow', 'format string', 'use-after-free', 'double free',
    'command injection', 'directory traversal', 'integer overflow', 'race condition',
    'info leak', 'out-of-bounds', 'stack overflow', 'heap overflow',
]


def _read_text(path: Optional[Path]) -> str:
    if not path:
        return ''
    try:
        return Path(path).read_text(errors='ignore')
    except Exception:
        return ''


def _sanitize_ascii(text: str) -> str:
    """Normalize common Unicode punctuation to ASCII and strip control chars."""
    if not text:
        return ''
    repl = {
        '\u2013': '-',  # en dash
        '\u2014': '-',  # em dash
        '\u2015': '-',
        '\u2212': '-',  # minus
        '\u2018': "'",  # left single quote
        '\u2019': "'",  # right single quote
        '\u201C': '"',  # left double quote
        '\u201D': '"',  # right double quote
        '\u2026': '...', # ellipsis
        '\u00A0': ' ',   # nbsp
        '\u200B': '',    # zero width space
    }
    for k, v in repl.items():
        text = text.replace(k, v)
    # Remove other control characters except tab/newline/carriage return
    cleaned = ''.join(ch for ch in text if (ch == '\t' or ch == '\n' or ch == '\r' or ord(ch) >= 32))
    return cleaned


def _detect_dangerous_calls(c_code: str) -> List[Dict[str, str]]:
    findings: List[Dict[str, str]] = []
    for func in DANGEROUS_FUNCS:
        # Detect calls like func( ... )
        pat = re.compile(rf"\b{re.escape(func)}\s*\(")
        hits = pat.findall(c_code)
        if hits:
            findings.append({
                'type': 'dangerous_function',
                'function': func,
                'count': len(hits),
                'hint': _danger_hint(func),
            })
    return findings


def _danger_hint(func: str) -> str:
    mapping = {
        'gets': 'Unbounded input; classic stack overflow risk. Prefer fgets().',
        'strcpy': 'Potential overflow into fixed-size buffers; use strncpy/strlcpy.',
        'strcat': 'Potential overflow concatenating into fixed-size buffers; use strncat/strlcat.',
        'sprintf': 'Formats into buffer without bounds; prefer snprintf.',
        'vsprintf': 'Formats into buffer without bounds; prefer vsnprintf.',
        'scanf': 'Unbounded %s read can overflow; add width or use fgets.',
        'fscanf': 'Unbounded %s read can overflow; add width or use fgets.',
        'sscanf': 'Unbounded %s read can overflow; add width or use fgets.',
        'memcpy': 'Validate lengths and buffer sizes to avoid out-of-bounds writes.',
        'memmove': 'Validate lengths and buffer sizes to avoid out-of-bounds writes.',
        'bcopy': 'Legacy copy; ensure proper length checks.',
        'strncpy': 'May not NUL-terminate; verify bounds and termination.',
        'snprintf': 'Safer but still check buffer sizes and return codes.',
        'vsnprintf': 'Safer but still check buffer sizes and return codes.',
        'system': 'Command injection risk if inputs reach the shell; validate inputs.',
        'popen': 'Command injection risk if inputs reach the shell; validate inputs.',
        'execl': 'Exec family; review arguments sources for injection.',
        'execlp': 'Exec family; review arguments sources for injection.',
        'execle': 'Exec family; review arguments sources for injection.',
        'execv': 'Exec family; review arguments sources for injection.',
        'execvp': 'Exec family; review arguments sources for injection.',
        'execve': 'Exec family; review arguments sources for injection.',
    }
    return mapping.get(func, 'Review usage and input validation for safety.')


def _scan_keywords(text: str) -> List[str]:
    found = []
    lo = text.lower()
    for kw in VULN_KEYWORDS:
        if kw in lo:
            found.append(kw)
    return sorted(set(found))


def _build_heuristic_payloads(findings: List[Dict[str, str]]) -> List[Dict[str, str]]:
    payloads: List[Dict[str, str]] = []
    funcs = {f.get('function') for f in findings if f.get('type') == 'dangerous_function'}
    if {'gets', 'strcpy', 'strcat', 'scanf'} & funcs:
        payloads.append({
            'type': 'overflow_candidate_stdin',
            'channel': 'stdin',
            'data': 'A' * 512,
            'note': 'Try to trigger overflow via unbounded input.'
        })
    if {'sprintf', 'vsprintf'} & funcs:
        payloads.append({
            'type': 'format_string_candidate',
            'channel': 'stdin',
            'data': '%x.' * 20,
            'note': 'Probe for format string vulnerability.'
        })
    if {'system', 'popen'} & funcs:
        payloads.append({
            'type': 'cmd_injection_probe',
            'channel': 'stdin',
            'data': '"; echo injected; #',
            'note': 'Probe for command injection if user input reaches shell.'
        })
    payloads.append({
        'type': 'baseline_run',
        'channel': 'none',
        'data': '',
        'note': 'Baseline execution without special input.'
    })
    return payloads


def _llm_payload_prompt(summary_text: str) -> str:
    """Compose an LLM prompt that elicits actionable techniques, not just payloads.

    We guide the model to propose concrete approaches an exploit script could use
    later (e.g., recognizing reversible patterns, decoding steps), without asking
    it to write the exploit itself.
    """
    header = (
        "You are a security assistant helping prepare for an automated exploit step.\n"
        "Read the program analysis summary and return ONLY JSON (no markdown, no prose).\n"
        "Include not only input payload hints, but also concrete reversible\n"
        "techniques the exploit can apply based on code logic.\n\n"
        "Schema strictly as follows (no extra keys):\n"
        "{\n"
        "  \"findings\": [ {\"type\": string, \"description\": string, \"function\": string|null, \"severity\": \"low|medium|high\" } ],\n"
        "  \"payloads\": [ {\"type\": string, \"channel\": \"stdin|argv\", \"data\": string, \"note\": string } ],\n"
        "  \"techniques\": [ string ],\n"
        "  \"notes\": string\n"
        "}\n\n"
        "Guidance for techniques (examples, include only those that match the summary):\n"
        "- If a pattern-based check exists (e.g., sequence of '<', '>', '=' from a binary-search loop),\n"
        "  describe reversing it to recover bytes by simulating decisions until '='.\n"
        "- If an array like the above appears in data/objdump (hex 3c/3d/3e), note extracting and decoding it.\n"
        "- If custom encodings, XOR/ROT, base-N, or CRC/rolling hashes appear, outline precise reversal steps.\n"
        "- If PRNG/LCG-derived checks appear, outline state recovery and reconstruction.\n"
        "- If argument-driven modes exist, specify argv layout and constraints.\n"
        "- Keep techniques high signal: step-by-step, but compact.\n\n"
        "Rules: JSON only. No code fences. Do not include Python code.\n"
    )
    body = f"Summary concisely trimmed (<=15k chars):\n{summary_text[:15000]}\n"
    return header + body


def _dedupe_payloads(payloads: List[Dict[str, str]]) -> List[Dict[str, str]]:
    seen = set()
    out: List[Dict[str, str]] = []
    for p in payloads:
        key = (p.get('channel'), p.get('data'))
        if key in seen:
            continue
        seen.add(key)
        out.append(p)
    return out


def find_vulnerabilities(
    combined_path: str,
    typed_c_path: Optional[str] = None,
    summary_path: Optional[str] = None,
    out_dir: Optional[str] = None,
) -> Dict[str, str]:
    combined = Path(combined_path)
    typed_c = Path(typed_c_path) if typed_c_path else None
    summary = Path(summary_path) if summary_path else None
    results_dir = Path(out_dir) if out_dir else Path('./storage/results')
    working_dir = Path('./storage/working')
    results_dir.mkdir(parents=True, exist_ok=True)
    working_dir.mkdir(parents=True, exist_ok=True)

    combined_text = _read_text(combined)
    typed_text = _read_text(typed_c)
    summary_text = _read_text(summary)

    # 1) Offline heuristics
    findings: List[Dict[str, str]] = []
    if typed_text:
        findings.extend(_detect_dangerous_calls(typed_text))
    kw = set(_scan_keywords(combined_text) + _scan_keywords(summary_text))
    if kw:
        findings.append({
            'type': 'keywords_present',
            'keywords': sorted(kw),
            'hint': 'These vulnerability terms appear in analysis or notes.'
        })
    heuristic_payloads = _build_heuristic_payloads(findings)

    # 2) Optional LLM pass using summary (smaller) to propose findings+payloads
    llm_findings: List[Dict[str, str]] = []
    llm_payloads: List[Dict[str, str]] = []
    llm_report_text = None
    if LLMAnalyzer is not None:
        try:
            analyzer = LLMAnalyzer()
            if getattr(analyzer, 'client', None) is not None and summary_text:
                prompt = _llm_payload_prompt(summary_text)
                try:
                    response = analyzer.client.messages.create(
                        model=analyzer.model,
                        max_tokens=2000,
                        temperature=0,
                        messages=[{"role": "user", "content": prompt}],
                    )
                    llm_report_text = response.content[0].text if response and getattr(response, 'content', None) else None
                    tokens_used = getattr(response.usage, 'total_tokens', 0) if hasattr(response, 'usage') else 0
                    if tokens_used:
                        print(f"[AutoHack][LLM] tokens_used={tokens_used}")
                except Exception as e:
                    llm_report_text = f"LLM error: {e}"
                # Attempt to parse JSON strictly; else fallback to extracting largest JSON block
                parsed = None
                if llm_report_text:
                    try:
                        parsed = json.loads(llm_report_text)
                    except Exception:
                        m = re.search(r"\{[\s\S]*\}", llm_report_text)
                        if m:
                            try:
                                parsed = json.loads(m.group(0))
                            except Exception:
                                parsed = None
                if isinstance(parsed, dict):
                    llm_findings = parsed.get('findings') or []
                    llm_payloads = parsed.get('payloads') or []
                    llm_techniques = parsed.get('techniques') or []
                    llm_notes = parsed.get('notes') or ''
        except Exception as e:
            # Non-fatal; keep heuristic results
            llm_report_text = f"LLM call failed: {e}"

    # Merge findings and payloads
    all_findings = findings.copy()
    if llm_findings:
        all_findings.extend(llm_findings)
    all_payloads = _dedupe_payloads((llm_payloads or []) + heuristic_payloads)
    techniques_list = []
    try:
        techniques_list = llm_techniques  # type: ignore[name-defined]
    except Exception:
        techniques_list = []

    # Human-readable exploits (ASCII-only hygiene)
    exploit_lines: List[str] = []
    for f in all_findings:
        if f.get('type') == 'dangerous_function':
            line = f"- Potential issue: {f.get('function','?')}() - {_danger_hint(f.get('function',''))}"
            exploit_lines.append(_sanitize_ascii(line))
    # Append LLM descriptions succinctly
    for f in (llm_findings or []):
        desc = f.get('description') or ''
        if desc:
            exploit_lines.append(_sanitize_ascii(f"- LLM: {desc}"))
    # Include LLM techniques explicitly
    for t in (techniques_list or []):
        if t:
            exploit_lines.append(_sanitize_ascii(f"- Technique: {t}"))
    if not exploit_lines:
        exploit_lines.append("- No obvious exploit avenue detected; try baseline and heuristic probes.")

    # Write outputs
    # Write only whitelisted artifacts to results; others to working
    vulns_json = results_dir / 'vulnerabilities.json'            # allowed in results
    exploits_txt = working_dir / 'possible_exploit.txt'          # move to working
    payloads_json = working_dir / 'payloads.json'                # move to working
    llm_report = working_dir / 'autohack_llm_report.txt'         # move to working

    out_obj = {
        'source': 'llm+heuristics' if llm_findings else 'heuristics',
        'findings': all_findings,
        'heuristic_only_findings': findings,
        'llm_findings': llm_findings,
        'payloads_suggested': all_payloads,
        'techniques': techniques_list,
        'llm_notes': (llm_notes if 'llm_notes' in locals() else ''),
        'llm_report_file': str(llm_report) if llm_report_text else None,
    }
    with open(vulns_json, 'w', encoding='utf-8') as f:
        json.dump(out_obj, f, indent=2)
    # Final write with sanitized content
    safe_body = "\n".join(_sanitize_ascii(l) for l in exploit_lines) + "\n"
    with open(exploits_txt, 'w', encoding='utf-8') as f:
        f.write(safe_body)
    with open(payloads_json, 'w', encoding='utf-8') as f:
        json.dump({'payloads': all_payloads}, f, indent=2)
    if llm_report_text:
        try:
            llm_report.write_text(llm_report_text, encoding='utf-8', errors='ignore')
        except Exception:
            pass

    print(f"[AutoHack] Wrote: {vulns_json}")
    print(f"[AutoHack] Wrote (working): {exploits_txt}")
    print(f"[AutoHack] Wrote: {payloads_json}")
    if llm_report_text:
        print(f"[AutoHack] Wrote: {llm_report}")

    return {
        'vulnerabilities': str(vulns_json),
        'possible_exploit': str(exploits_txt),
        'possible_exploits': str(exploits_txt),
        'payloads': str(payloads_json),
    }


def run_cli():
    import argparse
    p = argparse.ArgumentParser(description='Extract vulnerabilities and possible exploits (LLM + heuristics)')
    p.add_argument('--combined', required=True, help='Path to combined context file')
    p.add_argument('--typed', help='Path to typed C file')
    p.add_argument('--summary', help='Path to summary text file')
    p.add_argument('--out', help='Output directory (default: alongside combined or storage/results)')
    args = p.parse_args()
    find_vulnerabilities(args.combined, args.typed, args.summary, args.out)


if __name__ == '__main__':
    run_cli()

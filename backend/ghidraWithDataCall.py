import pyghidra
from pathlib import Path
import subprocess
import sys

def export_code_and_data(binary_path: str | None = None,
                         project_name: str | None = None,
                         project_dir: str | None = None):
    """Export both decompiled C code AND data from the binary"""
    
    # Setup paths
    script_dir = Path(__file__).parent
    ghidra_install_dir = script_dir.parent / "Ghidra_full_open_source_install" / "ghidra_11.4.2_PUBLIC"
    ghidra_install_dir_str = str(ghidra_install_dir.resolve())
    
    project_dir_path = Path(project_dir).resolve() if project_dir else Path("./ghidra_projects").resolve()
    output_dir = Path("./decompiled_output")
    output_dir.mkdir(exist_ok=True)
    
    # Create separate folders for different types of output
    code_dir = output_dir / "functions"
    data_dir = output_dir / "data"
    strings_dir = output_dir / "strings"
    symbols_dir = output_dir / "symbols"
    
    for dir_path in [code_dir, data_dir, strings_dir, symbols_dir]:
        dir_path.mkdir(exist_ok=True)
    
    # Optionally create/import a project from a provided binary first
    if binary_path:
        project_dir_path.mkdir(parents=True, exist_ok=True)
        base = Path(binary_path).resolve()
        pname = project_name or f"{base.stem}_analysis"
        ghidra_cli = (script_dir.parent / "ghidra-cli").resolve()
        if not ghidra_cli.exists():
            print(f"❌ ghidra-cli helper not found at {ghidra_cli}")
            print("Please ensure the helper script exists and Ghidra is installed at Ghidra_full_open_source_install.")
            return
        try:
            print(f"🔧 Creating Ghidra project '{pname}' and importing: {base}")
            cmd = ["bash", str(ghidra_cli), "-n", "-i", str(base), "-d", str(project_dir_path), "--name", pname]
            subprocess.run(cmd, check=True)
        except Exception as e:
            print(f"❌ Failed to create/import project via ghidra-cli: {e}")
            return

    # Find project
    rep_files = list(project_dir_path.glob("*.rep"))
    if not rep_files:
        print(f"❌ No projects found")
        return
    
    project_name = rep_files[0].stem
    print(f"🎯 Found project: {project_name}")
    
    print("🔧 Starting Ghidra...")
    pyghidra.start(ghidra_install_dir_str)
    
    from ghidra.base.project import GhidraProject
    from ghidra.app.decompiler import DecompInterface
    from ghidra.program.model.listing import Data
    from ghidra.program.model.symbol import SymbolType
    from ghidra.program.model.mem import MemoryBlock
    from java.lang import Object
    
    print("📂 Opening Ghidra project...")
    
    try:
        project = GhidraProject.openProject(str(project_dir_path), project_name, False)
        project_data = project.getProjectData()
        root_folder = project_data.getRootFolder()
        
        domain_files = []
        for df in root_folder.getFiles():
            if df.getContentType() == "Program":
                domain_files.append(df)
        
        if not domain_files:
            print("❌ No programs found")
            return
        
        consumer = Object()
        program = domain_files[0].getDomainObject(consumer, False, False, None)
        
        print(f"📄 Opened program: {program.getName()}")
        
        # ========== EXPORT FUNCTIONS (C CODE) ==========
        print("🔄 Exporting functions...")
        
        decompiler = DecompInterface()
        decompiler.openProgram(program)
        
        function_manager = program.getFunctionManager()
        functions = function_manager.getFunctions(True)
        
        function_count = 0
        for function in functions:
            func_name = function.getName()
            
            if func_name.startswith("__") or "@plt" in func_name:
                continue
            
            print(f"📝 Function: {func_name}")
            
            try:
                results = decompiler.decompileFunction(function, 30, None)
                if results.decompileCompleted():
                    decompiled_code = results.getDecompiledFunction().getC()
                    
                    clean_name = "".join(c for c in func_name if c.isalnum() or c in "._-")
                    output_file = code_dir / f"{clean_name}.c"
                    
                    with open(output_file, 'w', encoding='utf-8') as f:#with open(output_file, 'w') as f:
                        f.write(f"// Function: {func_name}\n")
                        f.write(f"// Address: {function.getEntryPoint()}\n")
                        f.write(f"// Size: {function.getBody().getNumAddresses()} bytes\n")
                        f.write("=" * 60 + "\n\n")
                        f.write(decompiled_code)
                    
                    function_count += 1
            except Exception as e:
                print(f"❌ Error with function {func_name}: {e}")
        
        # ========== EXPORT DATA SECTIONS ==========
        print("🔄 Exporting data sections...")
        
        listing = program.getListing()
        memory = program.getMemory()
        
        data_count = 0
        data_summary = []
        
        # Get all memory blocks
        for block in memory.getBlocks():
            block_name = block.getName()
            block_start = block.getStart()
            block_end = block.getEnd()
            
            print(f"📊 Processing block: {block_name}")
            
            # Get data in this block
            data_iterator = listing.getDefinedData(block_start, True)
            
            block_data = []
            for data_item in data_iterator:
                if data_item.getAddress().compareTo(block_end) > 0:
                    break
                
                data_type = data_item.getDataType()
                data_address = data_item.getAddress()
                
                try:
                    data_value = data_item.getValue()
                    data_str = str(data_value) if data_value else "undefined"
                except:
                    data_str = "undefined"
                
                block_data.append({
                    'address': str(data_address),
                    'type': str(data_type),
                    'value': data_str,
                    'size': data_item.getLength()
                })
                
                data_count += 1
            
            # Save block data to file
            if block_data:
                block_file = data_dir / f"{block_name}_data.txt"
                with open(block_file, 'w', encoding='utf-8') as f:#with open(block_file, 'w') as f:
                    f.write(f"Data Section: {block_name}\n")
                    f.write(f"Address Range: {block_start} - {block_end}\n")
                    f.write(f"Size: {block.getSize()} bytes\n")
                    f.write("=" * 60 + "\n\n")
                    
                    for item in block_data:
                        f.write(f"Address: {item['address']}\n")
                        f.write(f"Type: {item['type']}\n")
                        f.write(f"Size: {item['size']} bytes\n")
                        f.write(f"Value: {item['value']}\n")
                        f.write("-" * 40 + "\n")
                
                data_summary.append({
                    'block': block_name,
                    'count': len(block_data),
                    'file': f"{block_name}_data.txt"
                })
        
        # ========== EXPORT STRINGS ==========
        print("🔄 Exporting strings...")
        
        string_count = 0
        strings_data = []
        
        # Find all string data
        data_iterator = listing.getDefinedData(True)
        for data_item in data_iterator:
            data_type = data_item.getDataType()
            
            # Check if it's a string type
            if "string" in str(data_type).lower() or "char" in str(data_type).lower():
                try:
                    value = data_item.getValue()
                    if value and len(str(value)) > 1:
                        strings_data.append({
                            'address': str(data_item.getAddress()),
                            'type': str(data_type),
                            'value': str(value),
                            'length': data_item.getLength()
                        })
                        string_count += 1
                except:
                    pass
        
        # Save strings to file
        strings_file = strings_dir / "all_strings.txt"
        with open(strings_file, 'w', encoding='utf-8') as f:#with open(strings_file, 'w') as f:
            f.write("STRING DATA EXPORT\n")
            f.write(f"Total strings found: {string_count}\n")
            f.write("=" * 60 + "\n\n")
            
            for string_item in strings_data:
                f.write(f"Address: {string_item['address']}\n")
                f.write(f"Type: {string_item['type']}\n")
                f.write(f"Length: {string_item['length']}\n")
                f.write(f"Value: {repr(string_item['value'])}\n")
                f.write("-" * 40 + "\n")
        
        # ========== EXPORT SYMBOLS ==========
        print("🔄 Exporting symbols...")
        
        symbol_table = program.getSymbolTable()
        symbols = symbol_table.getAllSymbols(True)
        
        symbol_count = 0
        symbols_data = []
        
        for symbol in symbols:
            symbol_name = symbol.getName()
            symbol_address = symbol.getAddress()
            symbol_type = symbol.getSymbolType()
            
            symbols_data.append({
                'name': symbol_name,
                'address': str(symbol_address),
                'type': str(symbol_type),
                'namespace': str(symbol.getParentNamespace())
            })
            symbol_count += 1
        
        # Save symbols to file
        symbols_file = symbols_dir / "all_symbols.txt"
        with open(symbols_file, 'w', encoding='utf-8') as f:#with open(symbols_file, 'w') as f:
            f.write("SYMBOL TABLE EXPORT\n")
            f.write(f"Total symbols: {symbol_count}\n")
            f.write("=" * 60 + "\n\n")
            
            for symbol in symbols_data:
                f.write(f"Name: {symbol['name']}\n")
                f.write(f"Address: {symbol['address']}\n")
                f.write(f"Type: {symbol['type']}\n")
                f.write(f"Namespace: {symbol['namespace']}\n")
                f.write("-" * 40 + "\n")
        
        # ========== CREATE MASTER SUMMARY ==========
        summary_file = output_dir / "EXPORT_SUMMARY.txt"
        with open(summary_file, 'w', encoding='utf-8') as f:#with open(summary_file, 'w') as f:
            f.write("COMPLETE BINARY EXPORT SUMMARY\n")
            f.write(f"Program: {program.getName()}\n")
            f.write(f"Export Date: {program.getCreationDate()}\n")
            f.write("=" * 60 + "\n\n")
            
            f.write(f"📝 Functions Exported: {function_count}\n")
            f.write(f"   Location: {code_dir.name}/\n\n")
            
            f.write(f"📊 Data Items Exported: {data_count}\n")
            f.write(f"   Location: {data_dir.name}/\n")
            for summary in data_summary:
                f.write(f"   - {summary['block']}: {summary['count']} items ({summary['file']})\n")
            f.write("\n")
            
            f.write(f"🔤 Strings Exported: {string_count}\n")
            f.write(f"   Location: {strings_dir.name}/all_strings.txt\n\n")
            
            f.write(f"🔗 Symbols Exported: {symbol_count}\n")
            f.write(f"   Location: {symbols_dir.name}/all_symbols.txt\n\n")
            
            f.write("📁 Directory Structure:\n")
            f.write(f"   {output_dir.name}/\n")
            f.write(f"   ├── functions/     (C code)\n")
            f.write(f"   ├── data/          (data sections)\n")
            f.write(f"   ├── strings/       (string data)\n")
            f.write(f"   ├── symbols/       (symbol table)\n")
            f.write(f"   └── EXPORT_SUMMARY.txt\n")
        
        # Cleanup
        decompiler.dispose()
        
        print("✅ Complete export finished!")
        print(f"📝 Functions: {function_count}")
        print(f"📊 Data items: {data_count}")  
        print(f"🔤 Strings: {string_count}")
        print(f"🔗 Symbols: {symbol_count}")
        print(f"📁 Output: {output_dir.resolve()}")
        
    finally:
        if 'program' in locals():
            program.release(consumer)
        if 'project' in locals():
            project.close()

if __name__ == "__main__":
    import argparse
    p = argparse.ArgumentParser(description="Export C, data, strings, and symbols with Ghidra")
    p.add_argument("--binary", help="Path to input executable to import into a new project")
    p.add_argument("--project-name", help="Optional project name")
    p.add_argument("--project-dir", help="Optional project directory (default: ./ghidra_projects)")
    args = p.parse_args()
    export_code_and_data(binary_path=args.binary, project_name=args.project_name, project_dir=args.project_dir)

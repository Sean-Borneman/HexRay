// Function: FUN_140008254
// Address: 140008254
// Size: 156 bytes
============================================================


LPWCH FUN_140008254(void)

{
  WCHAR WVar1;
  ulonglong uVar2;
  LPWCH pWVar3;
  longlong lVar4;
  LPWCH pWVar6;
  LPWCH pWVar7;
  WCHAR *pWVar8;
  longlong lVar5;
  
  pWVar3 = GetEnvironmentStringsW();
  pWVar7 = pWVar3;
  if (pWVar3 != (LPWCH)0x0) {
    WVar1 = *pWVar3;
    pWVar8 = pWVar3;
    while (WVar1 != L'\0') {
      lVar4 = -1;
      do {
        lVar5 = lVar4;
        lVar4 = lVar5 + 1;
      } while (pWVar8[lVar4] != L'\0');
      pWVar8 = pWVar8 + lVar5 + 2;
      WVar1 = *pWVar8;
    }
    uVar2 = ((longlong)pWVar8 + (2 - (longlong)pWVar3) >> 1) * 2;
    pWVar6 = (LPWCH)_malloc_base(uVar2);
    pWVar7 = (LPWCH)0x0;
    if (pWVar6 != (LPWCH)0x0) {
      FUN_140002d40((undefined8 *)pWVar6,(undefined8 *)pWVar3,uVar2);
      pWVar7 = pWVar6;
    }
    FUN_140006f7c((LPVOID)0x0);
    FreeEnvironmentStringsW(pWVar3);
  }
  return pWVar7;
}


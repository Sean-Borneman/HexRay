// Function: FUN_1400065a4
// Address: 1400065a4
// Size: 210 bytes
============================================================


__acrt_ptd * FUN_1400065a4(void)

{
  DWORD dwErrCode;
  BOOL BVar1;
  __acrt_ptd *lpFlsData;
  __acrt_ptd *p_Var2;
  
  dwErrCode = GetLastError();
  p_Var2 = (__acrt_ptd *)0x0;
  if ((DAT_140018060 == 0xffffffff) ||
     (lpFlsData = (__acrt_ptd *)FlsGetValue(DAT_140018060), lpFlsData == (__acrt_ptd *)0x0)) {
    BVar1 = FlsSetValue(DAT_140018060,(PVOID)0xffffffffffffffff);
    lpFlsData = p_Var2;
    if (BVar1 != 0) {
      lpFlsData = (__acrt_ptd *)_calloc_base(1,0x3c8);
      if (lpFlsData == (__acrt_ptd *)0x0) {
        FlsSetValue(DAT_140018060,(PVOID)0x0);
        lpFlsData = (__acrt_ptd *)0x0;
      }
      else {
        BVar1 = FlsSetValue(DAT_140018060,lpFlsData);
        if (BVar1 != 0) {
          construct_ptd_array(lpFlsData);
          FUN_140006f7c((LPVOID)0x0);
          goto LAB_140006651;
        }
        FlsSetValue(DAT_140018060,(PVOID)0x0);
      }
      FUN_140006f7c(lpFlsData);
      lpFlsData = p_Var2;
    }
  }
  else if (lpFlsData == (__acrt_ptd *)0xffffffffffffffff) {
    lpFlsData = p_Var2;
  }
LAB_140006651:
  SetLastError(dwErrCode);
  if (lpFlsData == (__acrt_ptd *)0x0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  return lpFlsData;
}


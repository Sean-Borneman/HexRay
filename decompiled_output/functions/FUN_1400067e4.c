// Function: FUN_1400067e4
// Address: 1400067e4
// Size: 190 bytes
============================================================


__acrt_ptd * FUN_1400067e4(undefined8 param_1,longlong param_2)

{
  BOOL BVar1;
  __acrt_ptd *lpFlsData;
  __acrt_ptd *p_Var2;
  
  p_Var2 = (__acrt_ptd *)0x0;
  if ((DAT_140018060 == 0xffffffff) ||
     (lpFlsData = (__acrt_ptd *)FlsGetValue(DAT_140018060), lpFlsData == (__acrt_ptd *)0x0)) {
    BVar1 = FlsSetValue(DAT_140018060,(PVOID)0xffffffffffffffff);
    if (BVar1 == 0) {
      return (__acrt_ptd *)0x0;
    }
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
        goto LAB_140006885;
      }
      FlsSetValue(DAT_140018060,(PVOID)0x0);
    }
    FUN_140006f7c(lpFlsData);
  }
  else {
    if (lpFlsData == (__acrt_ptd *)0xffffffffffffffff) {
      return (__acrt_ptd *)0x0;
    }
LAB_140006885:
    p_Var2 = lpFlsData + param_2 * 0x3c8;
  }
  return p_Var2;
}


// Function: FUN_140006bbc
// Address: 140006bbc
// Size: 206 bytes
============================================================


void FUN_140006bbc(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uintptr_t param_5
                  ,longlong *param_6)

{
  byte bVar1;
  __acrt_ptd *p_Var2;
  ulonglong *puVar3;
  
  p_Var2 = FUN_140006904(param_6);
  if (((p_Var2 == (__acrt_ptd *)0x0) || (*(longlong *)(p_Var2 + 0x3b8) == 0)) &&
     (puVar3 = (ulonglong *)FUN_140006970(0x140018ef0,(longlong)param_6),
     bVar1 = (byte)DAT_140018038 & 0x3f,
     (DAT_140018038 ^ *puVar3) >> bVar1 == 0 && (DAT_140018038 ^ *puVar3) << 0x40 - bVar1 == 0)) {
                    /* WARNING: Subroutine does not return */
    _invoke_watson(param_1,param_2,param_3,param_4,param_5);
  }
  (*(code *)PTR__guard_dispatch_icall_14000e268)(param_1,param_2,param_3,param_4,param_5);
  return;
}


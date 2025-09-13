// Function: FUN_140006f7c
// Address: 140006f7c
// Size: 60 bytes
============================================================


void FUN_140006f7c(LPVOID param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined4 uVar3;
  __acrt_ptd *p_Var4;
  
  if ((param_1 != (LPVOID)0x0) && (BVar1 = HeapFree(DAT_140019738,0,param_1), BVar1 == 0)) {
    DVar2 = GetLastError();
    uVar3 = __acrt_errno_from_os_error(DVar2);
    p_Var4 = FUN_140006ee4();
    *(undefined4 *)p_Var4 = uVar3;
  }
  return;
}


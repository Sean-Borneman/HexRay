// Function: FUN_14000a348
// Address: 14000a348
// Size: 38 bytes
============================================================


undefined4 FUN_14000a348(longlong param_1)

{
  undefined4 uVar1;
  __acrt_ptd *p_Var2;
  
  if (param_1 == 0) {
    p_Var2 = FUN_140006ee4();
    *(undefined4 *)p_Var2 = 0x16;
    FUN_140006c8c();
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x18);
  }
  return uVar1;
}


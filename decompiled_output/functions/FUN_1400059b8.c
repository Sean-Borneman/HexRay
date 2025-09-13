// Function: FUN_1400059b8
// Address: 1400059b8
// Size: 43 bytes
============================================================


uint FUN_1400059b8(uint param_1)

{
  uint uVar1;
  __acrt_ptd *p_Var2;
  
  if (param_1 < 2) {
    LOCK();
    UNLOCK();
    uVar1 = DAT_140018eb8;
    DAT_140018eb8 = param_1;
  }
  else {
    p_Var2 = FUN_140006ee4();
    *(undefined4 *)p_Var2 = 0x16;
    FUN_140006c8c();
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


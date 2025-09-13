// Function: FUN_140006ee4
// Address: 140006ee4
// Size: 32 bytes
============================================================


__acrt_ptd * FUN_140006ee4(void)

{
  __acrt_ptd *p_Var1;
  
  p_Var1 = FUN_14000671c();
  if (p_Var1 == (__acrt_ptd *)0x0) {
    p_Var1 = (__acrt_ptd *)&DAT_140018064;
  }
  else {
    p_Var1 = p_Var1 + 0x20;
  }
  return p_Var1;
}


// Function: FUN_140006ec4
// Address: 140006ec4
// Size: 32 bytes
============================================================


__acrt_ptd * FUN_140006ec4(void)

{
  __acrt_ptd *p_Var1;
  
  p_Var1 = FUN_14000671c();
  if (p_Var1 == (__acrt_ptd *)0x0) {
    p_Var1 = (__acrt_ptd *)&DAT_140018068;
  }
  else {
    p_Var1 = p_Var1 + 0x24;
  }
  return p_Var1;
}


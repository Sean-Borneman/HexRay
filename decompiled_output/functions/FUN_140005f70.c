// Function: FUN_140005f70
// Address: 140005f70
// Size: 41 bytes
============================================================


void FUN_140005f70(void)

{
  __acrt_ptd *p_Var1;
  
  p_Var1 = FUN_1400065a4();
  if (*(longlong *)(p_Var1 + 0x18) != 0) {
    (*(code *)PTR__guard_dispatch_icall_14000e268)();
  }
                    /* WARNING: Subroutine does not return */
  abort();
}


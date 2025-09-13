// Function: _set_errno_from_matherr
// Address: 14000d288
// Size: 46 bytes
============================================================


/* Library Function - Single Match
    _set_errno_from_matherr
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

void _set_errno_from_matherr(int param_1)

{
  __acrt_ptd *p_Var1;
  
  if (param_1 == 1) {
    p_Var1 = FUN_140006ee4();
    *(undefined4 *)p_Var1 = 0x21;
  }
  else if (param_1 - 2U < 2) {
    p_Var1 = FUN_140006ee4();
    *(undefined4 *)p_Var1 = 0x22;
  }
  return;
}


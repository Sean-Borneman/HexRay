// Function: _set_statfp
// Address: 14000d354
// Size: 31 bytes
============================================================


/* Library Function - Single Match
    _set_statfp
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void _set_statfp(uint param_1)

{
  uint uVar1;
  
  uVar1 = _get_fpsr();
  FUN_14000cf10(uVar1 | param_1 & 0x3f);
  return;
}


// Function: _statfp
// Address: 14000d374
// Size: 17 bytes
============================================================


/* Library Function - Single Match
    _statfp
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

uint _statfp(void)

{
  uint uVar1;
  
  uVar1 = _get_fpsr();
  return uVar1 & 0x3f;
}


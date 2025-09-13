// Function: _configthreadlocale
// Address: 140005944
// Size: 105 bytes
============================================================


/* Library Function - Single Match
    _configthreadlocale
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl _configthreadlocale(int _Flag)

{
  uint uVar1;
  __acrt_ptd *p_Var2;
  uint uVar3;
  
  p_Var2 = FUN_1400065a4();
  uVar1 = *(uint *)(p_Var2 + 0x3a8);
  if (_Flag == -1) {
    DAT_1400187c0 = 0xffffffff;
  }
  else if (_Flag != 0) {
    if (_Flag == 1) {
      uVar3 = uVar1 | 2;
    }
    else {
      if (_Flag != 2) {
        p_Var2 = FUN_140006ee4();
        *(undefined4 *)p_Var2 = 0x16;
        FUN_140006c8c();
        return -1;
      }
      uVar3 = uVar1 & 0xfffffffd;
    }
    *(uint *)(p_Var2 + 0x3a8) = uVar3;
  }
  return 2 - (uint)((uVar1 & 2) != 0);
}


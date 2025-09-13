// Function: _ctrlfp
// Address: 14000d2d8
// Size: 99 bytes
============================================================


/* Library Function - Single Match
    _ctrlfp
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

uint _ctrlfp(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = _get_fpsr();
  uVar2 = (~param_2 | 0xffff807f) & uVar1 | param_1 & param_2;
  if ((DAT_1400189f0 == '\0') || ((uVar2 & 0x40) == 0)) {
    FUN_14000cf10(uVar2 & 0xffffffbf);
  }
  else {
    FUN_14000cf10(uVar2);
  }
  return uVar1;
}


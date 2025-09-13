// Function: _CallSettingFrameEncoded
// Address: 140004ac0
// Size: 71 bytes
============================================================


/* Library Function - Single Match
    _CallSettingFrameEncoded
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void _CallSettingFrameEncoded(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)_NLG_Notify();
  (*pcVar1)(param_3);
  FUN_140002240();
  _NLG_Notify();
  return;
}


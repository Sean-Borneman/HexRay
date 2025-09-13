// Function: _CallSettingFrame
// Address: 140004a10
// Size: 64 bytes
============================================================


/* Library Function - Single Match
    _CallSettingFrame
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void _CallSettingFrame(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)_NLG_Notify();
  (*pcVar1)();
  FUN_140002240();
  _NLG_Notify();
  return;
}


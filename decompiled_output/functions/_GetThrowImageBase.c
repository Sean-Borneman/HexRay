// Function: _GetThrowImageBase
// Address: 140002c40
// Size: 18 bytes
============================================================


/* Library Function - Single Match
    _GetThrowImageBase
   
   Library: Visual Studio 2019 Release */

undefined8 _GetThrowImageBase(void)

{
  longlong lVar1;
  
  lVar1 = __vcrt_getptd();
  return *(undefined8 *)(lVar1 + 0x68);
}


// Function: _GetImageBase
// Address: 140002c2c
// Size: 18 bytes
============================================================


/* Library Function - Single Match
    _GetImageBase
   
   Library: Visual Studio 2019 Release */

undefined8 _GetImageBase(void)

{
  longlong lVar1;
  
  lVar1 = __vcrt_getptd();
  return *(undefined8 *)(lVar1 + 0x60);
}


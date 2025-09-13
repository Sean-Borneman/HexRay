// Function: FUN_140002c54
// Address: 140002c54
// Size: 24 bytes
============================================================


void FUN_140002c54(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = __vcrt_getptd();
  *(undefined8 *)(lVar1 + 0x60) = param_1;
  return;
}


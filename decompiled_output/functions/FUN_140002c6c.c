// Function: FUN_140002c6c
// Address: 140002c6c
// Size: 24 bytes
============================================================


void FUN_140002c6c(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = __vcrt_getptd();
  *(undefined8 *)(lVar1 + 0x68) = param_1;
  return;
}


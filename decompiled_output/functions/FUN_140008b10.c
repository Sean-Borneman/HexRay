// Function: FUN_140008b10
// Address: 140008b10
// Size: 50 bytes
============================================================


void FUN_140008b10(undefined8 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = param_1 + param_2;
  if (param_1 != puVar1) {
    do {
      FUN_140006f7c((LPVOID)*param_1);
      param_1 = param_1 + 1;
    } while (param_1 != puVar1);
  }
  return;
}


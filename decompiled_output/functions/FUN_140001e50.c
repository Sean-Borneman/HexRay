// Function: FUN_140001e50
// Address: 140001e50
// Size: 16 bytes
============================================================


undefined8 FUN_140001e50(undefined1 *param_1,undefined1 param_2,longlong param_3,undefined8 param_4)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_1 = param_2;
    param_1 = param_1 + 1;
  }
  return param_4;
}


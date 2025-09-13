// Function: FUN_140009848
// Address: 140009848
// Size: 70 bytes
============================================================


undefined8 FUN_140009848(longlong param_1,longlong param_2)

{
  longlong in_RAX;
  
  if (param_1 != param_2) {
    do {
      in_RAX = *(longlong *)(param_2 + -8);
      if (in_RAX != 0) {
        in_RAX = (*(code *)PTR__guard_dispatch_icall_14000e268)(0);
      }
      param_2 = param_2 + -0x10;
    } while (param_2 != param_1);
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}


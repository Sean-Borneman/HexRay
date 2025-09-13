// Function: FUN_1400097b4
// Address: 1400097b4
// Size: 148 bytes
============================================================


undefined8 FUN_1400097b4(undefined8 *param_1,undefined8 *param_2)

{
  longlong *in_RAX;
  longlong *plVar1;
  
  plVar1 = param_1;
  if (param_1 != param_2) {
    do {
      in_RAX = (longlong *)*plVar1;
      if ((in_RAX != (longlong *)0x0) &&
         (in_RAX = (longlong *)(*(code *)PTR__guard_dispatch_icall_14000e268)(),
         (char)in_RAX == '\0')) break;
      plVar1 = plVar1 + 2;
    } while (plVar1 != param_2);
    if (plVar1 != param_2) {
      if (plVar1 != param_1) {
        plVar1 = plVar1 + -1;
        do {
          if ((plVar1[-1] != 0) && (*plVar1 != 0)) {
            (*(code *)PTR__guard_dispatch_icall_14000e268)(0);
          }
          in_RAX = plVar1 + -1;
          plVar1 = plVar1 + -2;
        } while (in_RAX != param_1);
      }
      return (ulonglong)in_RAX & 0xffffffffffffff00;
    }
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}


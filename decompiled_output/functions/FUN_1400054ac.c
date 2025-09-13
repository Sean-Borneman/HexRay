// Function: FUN_1400054ac
// Address: 1400054ac
// Size: 65 bytes
============================================================


void FUN_1400054ac(undefined8 *param_1,undefined8 *param_2)

{
  if (param_1 != param_2) {
    do {
      if (*param_1 != 0) {
        (*(code *)PTR__guard_dispatch_icall_14000e268)();
      }
      param_1 = param_1 + 1;
    } while (param_1 != param_2);
  }
  return;
}


// Function: FUN_140005570
// Address: 140005570
// Size: 197 bytes
============================================================


void FUN_140005570(undefined8 *param_1)

{
  undefined *puVar1;
  
  if (DAT_140018eb0 != '\0') {
    return;
  }
  LOCK();
  DAT_140018ea4 = 1;
  UNLOCK();
  if (*(int *)*param_1 == 0) {
    if (DAT_140018ea8 != DAT_140018038) {
      (*(code *)PTR__guard_dispatch_icall_14000e268)(0,0,0);
    }
    puVar1 = &DAT_140018ec0;
  }
  else {
    if (*(int *)*param_1 != 1) goto LAB_1400055ea;
    puVar1 = &DAT_140018ed8;
  }
  FUN_140005d44(puVar1);
LAB_1400055ea:
  if (*(int *)*param_1 == 0) {
    FUN_1400054ac((undefined8 *)&DAT_14000e2e0,(undefined8 *)&DAT_14000e300);
  }
  FUN_1400054ac((undefined8 *)&DAT_14000e308,(undefined8 *)&DAT_14000e310);
  if (*(int *)param_1[1] == 0) {
    DAT_140018eb0 = '\x01';
    *(undefined1 *)param_1[2] = 1;
  }
  return;
}


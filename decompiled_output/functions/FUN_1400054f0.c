// Function: FUN_1400054f0
// Address: 1400054f0
// Size: 71 bytes
============================================================


undefined8 FUN_1400054f0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  bool bVar2;
  
  bVar2 = param_1 == param_2;
  while( true ) {
    if (bVar2) {
      return 0;
    }
    if ((*param_1 != 0) &&
       (uVar1 = (*(code *)PTR__guard_dispatch_icall_14000e268)(), (int)uVar1 != 0)) break;
    param_1 = param_1 + 1;
    bVar2 = param_1 == param_2;
  }
  return uVar1;
}


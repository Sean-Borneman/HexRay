// Function: FUN_14000dac4
// Address: 14000dac4
// Size: 133 bytes
============================================================


void FUN_14000dac4(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  
  _FindAndUnlinkFrame(*(longlong *)(param_2 + 0x38));
  if ((((*(int *)(param_2 + 0x20) == 0) &&
       (piVar1 = *(int **)(param_2 + 0xb8), *piVar1 == -0x1f928c9d)) && (piVar1[6] == 4)) &&
     (((piVar1[8] == 0x19930520 || (piVar1[8] == 0x19930521)) || (piVar1[8] == 0x19930522)))) {
    iVar3 = _IsExceptionObjectToBeDestroyed(*(longlong *)(piVar1 + 10));
    if (iVar3 != 0) {
      __DestructExceptionObject(piVar1);
    }
  }
  lVar2 = __vcrt_getptd();
  *(undefined8 *)(lVar2 + 0x20) = *(undefined8 *)(param_2 + 0xc0);
  lVar2 = __vcrt_getptd();
  *(undefined8 *)(lVar2 + 0x28) = *(undefined8 *)(param_2 + 0x40);
  return;
}


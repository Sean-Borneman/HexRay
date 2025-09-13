// Function: FUN_140006ea0
// Address: 140006ea0
// Size: 34 bytes
============================================================


void FUN_140006ea0(int param_1,longlong param_2)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_2 + 0x38) = 1;
  *(int *)(param_2 + 0x34) = param_1;
  uVar1 = __acrt_errno_from_os_error(param_1);
  *(undefined4 *)(param_2 + 0x2c) = uVar1;
  *(undefined1 *)(param_2 + 0x30) = 1;
  return;
}


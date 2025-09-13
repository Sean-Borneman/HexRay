// Function: FUN_14000beb4
// Address: 14000beb4
// Size: 121 bytes
============================================================


ulonglong FUN_14000beb4(int *param_1,longlong *param_2)

{
  ulonglong uVar1;
  
  if (param_1 == (int *)0x0) {
    *(undefined1 *)(param_2 + 6) = 1;
    *(undefined4 *)((longlong)param_2 + 0x2c) = 0x16;
    FUN_140006bbc((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0,param_2);
  }
  else {
    if (((uint)param_1[5] >> 0xc & 1) == 0) {
      FUN_14000a0e0((longlong)param_1);
      uVar1 = FUN_14000bf30(param_1,param_2);
      FUN_14000a0ec((longlong)param_1);
      return uVar1 & 0xffffffff;
    }
    FUN_14000cb50((undefined8 *)param_1);
  }
  return 0xffffffff;
}


// Function: FUN_140002798
// Address: 140002798
// Size: 98 bytes
============================================================


longlong FUN_140002798(longlong param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0xc);
  do {
    if (uVar2 == 0) {
      return 0;
    }
    uVar2 = uVar2 - 1;
    lVar1 = __vcrt_getptd();
    lVar1 = (longlong)*(int *)(param_1 + 0x10) +
            *(longlong *)(lVar1 + 0x60) + (ulonglong)uVar2 * 0x14;
  } while ((param_2 <= *(int *)(lVar1 + 4)) || (*(int *)(lVar1 + 8) < param_2));
  return lVar1;
}


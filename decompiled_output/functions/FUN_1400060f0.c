// Function: FUN_1400060f0
// Address: 1400060f0
// Size: 118 bytes
============================================================


void FUN_1400060f0(longlong *param_1)

{
  longlong lVar1;
  
  lVar1 = FUN_140006080(param_1);
  param_1[3] = *(longlong *)(lVar1 + 0x90);
  param_1[4] = *(longlong *)(lVar1 + 0x88);
  FUN_14000a12c(lVar1,param_1 + 3,param_1[1]);
  FUN_14000a198(lVar1,param_1 + 4,param_1[1]);
  if ((*(uint *)(lVar1 + 0x3a8) & 2) == 0) {
    *(uint *)(lVar1 + 0x3a8) = *(uint *)(lVar1 + 0x3a8) | 2;
    *(undefined1 *)(param_1 + 5) = 2;
  }
  return;
}


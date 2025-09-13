// Function: FUN_140009dfc
// Address: 140009dfc
// Size: 138 bytes
============================================================


undefined8 FUN_140009dfc(int *param_1,longlong *param_2)

{
  wchar_t *pwVar1;
  uint uVar2;
  uint uVar3;
  
  if ((((byte)param_1[5] & 3) == 2) && ((param_1[5] & 0xc0U) != 0)) {
    uVar3 = *param_1 - param_1[2];
    param_1[4] = 0;
    pwVar1 = *(wchar_t **)(param_1 + 2);
    *(wchar_t **)param_1 = pwVar1;
    if (0 < (int)uVar3) {
      uVar2 = FUN_14000a348((longlong)param_1);
      uVar2 = FUN_14000b638(uVar2,pwVar1,uVar3,param_2);
      if (uVar3 != uVar2) {
        LOCK();
        param_1[5] = param_1[5] | 0x10;
        UNLOCK();
        return 0xffffffff;
      }
      if (((uint)param_1[5] >> 2 & 1) != 0) {
        LOCK();
        param_1[5] = param_1[5] & 0xfffffffd;
        UNLOCK();
      }
    }
  }
  return 0;
}


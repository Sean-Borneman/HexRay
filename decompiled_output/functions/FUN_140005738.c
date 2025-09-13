// Function: FUN_140005738
// Address: 140005738
// Size: 48 bytes
============================================================


int FUN_140005738(void)

{
  int iVar1;
  uint3 uVar2;
  
  iVar1 = __acrt_get_process_end_policy();
  uVar2 = (uint3)((uint)iVar1 >> 8);
  if ((iVar1 == 1) || ((*(uint *)((longlong)ProcessEnvironmentBlock + 0xbc) >> 8 & 1) != 0)) {
    iVar1 = (uint)uVar2 << 8;
  }
  else {
    iVar1 = CONCAT31(uVar2,1);
  }
  return iVar1;
}


// Function: FUN_14000ba70
// Address: 14000ba70
// Size: 177 bytes
============================================================


int FUN_14000ba70(void)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  longlong lVar4;
  int local_18;
  
  local_18 = 0;
  __acrt_lock(8);
  for (iVar3 = 3; iVar3 != DAT_140019768; iVar3 = iVar3 + 1) {
    lVar4 = (longlong)iVar3;
    lVar1 = *(longlong *)(DAT_140019770 + lVar4 * 8);
    if (lVar1 != 0) {
      if (((*(uint *)(lVar1 + 0x14) >> 0xd & 1) != 0) &&
         (uVar2 = FUN_14000bfd4(*(int **)(DAT_140019770 + lVar4 * 8)), (int)uVar2 != -1)) {
        local_18 = local_18 + 1;
      }
      DeleteCriticalSection((LPCRITICAL_SECTION)(*(longlong *)(DAT_140019770 + lVar4 * 8) + 0x30));
      FUN_140006f7c(*(LPVOID *)(DAT_140019770 + lVar4 * 8));
      *(undefined8 *)(DAT_140019770 + lVar4 * 8) = 0;
    }
  }
  __acrt_unlock(8);
  return local_18;
}


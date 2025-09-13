// Function: FUN_14000ab9c
// Address: 14000ab9c
// Size: 168 bytes
============================================================


undefined4 FUN_14000ab9c(ushort *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 != (ushort *)0x0) {
    iVar4 = 0;
    iVar5 = 0xe3;
    do {
      iVar2 = (iVar5 + iVar4) / 2;
      iVar3 = __ascii_wcsnicmp(param_1,(ushort *)(&PTR_DAT_140012440)[(longlong)iVar2 * 2],0x55);
      if (iVar3 == 0) {
        uVar1 = *(uint *)(&DAT_140012448 + (longlong)iVar2 * 0x10);
        if ((int)uVar1 < 0) {
          return 0;
        }
        if (0xe3 < uVar1) {
          return 0;
        }
        return *(undefined4 *)(&DAT_1400109e0 + (longlong)(int)uVar1 * 0x10);
      }
      if (iVar3 < 0) {
        iVar5 = iVar2 + -1;
      }
      else {
        iVar4 = iVar2 + 1;
      }
    } while (iVar4 <= iVar5);
  }
  return 0;
}


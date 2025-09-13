// Function: FUN_14000acfc
// Address: 14000acfc
// Size: 139 bytes
============================================================


undefined8 FUN_14000acfc(undefined8 param_1,uint *param_2,undefined8 *param_3,uint *param_4)

{
  uint uVar1;
  BOOL BVar2;
  DWORD DVar3;
  HANDLE hFile;
  __acrt_ptd *p_Var4;
  undefined8 uVar5;
  
  FUN_140008584(*param_2);
  uVar1 = *(uint *)*param_3;
  if ((*(byte *)((&DAT_140019190)[(longlong)(int)uVar1 >> 6] + 0x38 +
                (ulonglong)(uVar1 & 0x3f) * 0x48) & 1) != 0) {
    hFile = (HANDLE)FUN_140008690(uVar1);
    BVar2 = FlushFileBuffers(hFile);
    uVar5 = 0;
    if (BVar2 != 0) goto LAB_14000ad73;
    DVar3 = GetLastError();
    p_Var4 = FUN_140006ec4();
    *(DWORD *)p_Var4 = DVar3;
  }
  p_Var4 = FUN_140006ee4();
  *(undefined4 *)p_Var4 = 9;
  uVar5 = 0xffffffff;
LAB_14000ad73:
  FUN_1400085ac(*param_4);
  return uVar5;
}


// Function: FUN_14000ca80
// Address: 14000ca80
// Size: 205 bytes
============================================================


undefined8 FUN_14000ca80(uint param_1,longlong param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  longlong lVar3;
  longlong lVar4;
  HANDLE hObject;
  undefined8 uVar5;
  
  lVar3 = FUN_140008690(param_1);
  if (lVar3 != -1) {
    if (((param_1 == 1) && ((*(byte *)(DAT_140019190 + 200) & 1) != 0)) ||
       ((param_1 == 2 && ((*(byte *)(DAT_140019190 + 0x80) & 1) != 0)))) {
      lVar3 = FUN_140008690(2);
      lVar4 = FUN_140008690(1);
      if (lVar4 == lVar3) goto LAB_14000caa2;
    }
    hObject = (HANDLE)FUN_140008690(param_1);
    BVar1 = CloseHandle(hObject);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      goto LAB_14000cb00;
    }
  }
LAB_14000caa2:
  DVar2 = 0;
LAB_14000cb00:
  FUN_1400085d4(param_1);
  *(undefined1 *)
   ((&DAT_140019190)[(longlong)(int)param_1 >> 6] + 0x38 + (ulonglong)(param_1 & 0x3f) * 0x48) = 0;
  if (DVar2 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_140006ea0(DVar2,param_2);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}


// Function: FUN_14000c944
// Address: 14000c944
// Size: 119 bytes
============================================================


ulonglong FUN_14000c944(undefined8 param_1,uint *param_2,undefined8 *param_3,uint *param_4)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  FUN_140008584(*param_2);
  uVar1 = *(uint *)*param_3;
  lVar2 = param_3[1];
  if ((*(byte *)((&DAT_140019190)[(longlong)(int)uVar1 >> 6] + 0x38 +
                (ulonglong)(uVar1 & 0x3f) * 0x48) & 1) == 0) {
    *(undefined1 *)(lVar2 + 0x30) = 1;
    *(undefined4 *)(lVar2 + 0x2c) = 9;
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = FUN_14000ca80(uVar1,lVar2);
    uVar3 = uVar3 & 0xffffffff;
  }
  FUN_1400085ac(*param_4);
  return uVar3;
}


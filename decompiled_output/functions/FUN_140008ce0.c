// Function: FUN_140008ce0
// Address: 140008ce0
// Size: 409 bytes
============================================================


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_140008ce0(__crt_locale_pointers *param_1,DWORD param_2,undefined8 param_3,
                  undefined8 param_4,LPWORD param_5,uint param_6,int param_7)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  undefined1 (*lpSrcStr) [32];
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined4 local_60;
  longlong local_58;
  longlong local_50;
  char local_40;
  ulonglong local_38;
  
  puVar6 = auStack_88;
  puVar8 = auStack_88;
  puVar7 = auStack_88;
  local_38 = DAT_140018038 ^ (ulonglong)&local_58;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_58,param_1);
  if (param_6 == 0) {
    param_6 = *(uint *)(local_50 + 0xc);
  }
  local_60 = 0;
  local_68 = 0;
  iVar2 = __acrt_MultiByteToWideChar(param_6,(ulonglong)((-(uint)(param_7 != 0) & 8) + 1));
  if (iVar2 == 0) goto LAB_140008e40;
  uVar5 = (longlong)iVar2 * 2;
  uVar4 = -(ulonglong)(uVar5 < uVar5 + 0x10) & uVar5 + 0x10;
  if (uVar4 == 0) {
    lpSrcStr = (undefined1 (*) [32])0x0;
LAB_140008e28:
    puVar8 = puVar7;
    if (lpSrcStr == (undefined1 (*) [32])0x0) goto LAB_140008e40;
  }
  else {
    if (uVar4 < 0x401) {
      uVar3 = uVar4 + 0xf;
      if (uVar3 <= uVar4) {
        uVar3 = 0xffffffffffffff0;
      }
      lVar1 = -(uVar3 & 0xfffffffffffffff0);
      puVar6 = auStack_88 + lVar1;
      lpSrcStr = (undefined1 (*) [32])((longlong)&local_58 + lVar1);
      puVar7 = auStack_88 + lVar1;
      if (lpSrcStr != (undefined1 (*) [32])0x0) {
        *(undefined4 *)*lpSrcStr = 0xcccc;
LAB_140008dcc:
        lpSrcStr = (undefined1 (*) [32])((longlong)*lpSrcStr + 0x10);
        puVar7 = puVar6;
      }
    }
    else {
      lpSrcStr = (undefined1 (*) [32])_malloc_base(uVar4);
      puVar7 = auStack_88;
      if (lpSrcStr != (undefined1 (*) [32])0x0) {
        *(undefined4 *)*lpSrcStr = 0xdddd;
        goto LAB_140008dcc;
      }
    }
    if (lpSrcStr == (undefined1 (*) [32])0x0) goto LAB_140008e28;
    *(undefined8 *)(puVar7 + -8) = 0x140008de5;
    FUN_140001e70(lpSrcStr,0,uVar5);
    *(int *)(puVar7 + 0x28) = iVar2;
    *(undefined1 (**) [32])(puVar7 + 0x20) = lpSrcStr;
    *(undefined8 *)(puVar7 + -8) = 0x140008e01;
    iVar2 = __acrt_MultiByteToWideChar(param_6,1);
    if (iVar2 == 0) goto LAB_140008e28;
    *(undefined8 *)(puVar7 + -8) = 0x140008e1f;
    GetStringTypeW(param_2,(LPCWSTR)lpSrcStr,iVar2,param_5);
  }
  puVar8 = puVar7;
  if (*(int *)(lpSrcStr[-1] + 0x10) == 0xdddd) {
    *(undefined8 *)(puVar7 + -8) = 0x140008e40;
    FUN_140006f7c(lpSrcStr[-1] + 0x10);
  }
LAB_140008e40:
  if (local_40 != '\0') {
    *(uint *)(local_58 + 0x3a8) = *(uint *)(local_58 + 0x3a8) & 0xfffffffd;
  }
  uVar5 = local_38 ^ (ulonglong)&local_58;
  *(undefined8 *)(puVar8 + -8) = 0x140008e5f;
  FUN_14000d520(uVar5);
  return;
}


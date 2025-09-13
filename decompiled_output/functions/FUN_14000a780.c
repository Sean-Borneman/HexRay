// Function: FUN_14000a780
// Address: 14000a780
// Size: 799 bytes
============================================================


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_14000a780(longlong *param_1,ushort *param_2,uint param_3,char *param_4,int param_5,
                  undefined8 param_6,int param_7,uint param_8,int param_9)

{
  longlong lVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  ulonglong uVar5;
  LPCWSTR pWVar6;
  undefined4 *puVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined4 local_60;
  ushort *local_38;
  ulonglong local_30;
  
  puVar9 = auStack_88;
  puVar11 = auStack_88;
  local_30 = DAT_140018038 ^ (ulonglong)&local_38;
  local_38 = param_2;
  if (0 < param_5) {
    __strncnt(param_4,(longlong)param_5);
  }
  if (param_8 == 0) {
    param_8 = *(uint *)(*param_1 + 0xc);
  }
  local_60 = 0;
  local_68 = 0;
  iVar3 = __acrt_MultiByteToWideChar(param_8,(ulonglong)((-(uint)(param_9 != 0) & 8) + 1));
  puVar12 = auStack_88;
  if (iVar3 == 0) goto LAB_14000aa79;
  uVar5 = (longlong)iVar3 * 2 + 0x10;
  uVar5 = -(ulonglong)((ulonglong)((longlong)iVar3 * 2) < uVar5) & uVar5;
  if (uVar5 == 0) {
    pWVar6 = (LPCWSTR)0x0;
LAB_14000aa5f:
    puVar12 = puVar11;
    if (pWVar6 == (LPCWSTR)0x0) goto LAB_14000aa79;
  }
  else {
    if (uVar5 < 0x401) {
      uVar8 = uVar5 + 0xf;
      if (uVar8 <= uVar5) {
        uVar8 = 0xffffffffffffff0;
      }
      lVar1 = -(uVar8 & 0xfffffffffffffff0);
      puVar9 = auStack_88 + lVar1;
      pWVar6 = (LPCWSTR)((longlong)&local_38 + lVar1);
      puVar11 = auStack_88 + lVar1;
      if (pWVar6 != (LPCWSTR)0x0) {
        pWVar6[0] = L'쳌';
        pWVar6[1] = L'\0';
LAB_14000a885:
        pWVar6 = pWVar6 + 8;
        puVar11 = puVar9;
      }
    }
    else {
      pWVar6 = (LPCWSTR)_malloc_base(uVar5);
      puVar11 = auStack_88;
      if (pWVar6 != (LPCWSTR)0x0) {
        pWVar6[0] = L'\xdddd';
        pWVar6[1] = L'\0';
        goto LAB_14000a885;
      }
    }
    if (pWVar6 == (LPCWSTR)0x0) goto LAB_14000aa5f;
    *(int *)(puVar11 + 0x28) = iVar3;
    *(LPCWSTR *)(puVar11 + 0x20) = pWVar6;
    *(undefined8 *)(puVar11 + -8) = 0x14000a8b2;
    iVar4 = __acrt_MultiByteToWideChar(param_8,1);
    if (iVar4 == 0) goto LAB_14000aa5f;
    *(undefined8 *)(puVar11 + 0x40) = 0;
    *(undefined8 *)(puVar11 + 0x38) = 0;
    *(undefined8 *)(puVar11 + 0x30) = 0;
    puVar2 = local_38;
    *(undefined4 *)(puVar11 + 0x28) = 0;
    *(undefined8 *)(puVar11 + 0x20) = 0;
    *(undefined8 *)(puVar11 + -8) = 0x14000a8ec;
    iVar4 = FUN_140009530(puVar2,param_3,pWVar6,iVar3,*(LPWSTR *)(puVar11 + 0x20),
                          *(int *)(puVar11 + 0x28),*(undefined8 *)(puVar11 + 0x30),
                          *(undefined8 *)(puVar11 + 0x38),*(undefined8 *)(puVar11 + 0x40));
    if (iVar4 == 0) goto LAB_14000aa5f;
    if ((param_3 & 0x400) == 0) {
      uVar5 = (longlong)iVar4 * 2 + 0x10;
      uVar5 = -(ulonglong)((ulonglong)((longlong)iVar4 * 2) < uVar5) & uVar5;
      if (uVar5 != 0) {
        if (uVar5 < 0x401) {
          uVar8 = uVar5 + 0xf;
          if (uVar8 <= uVar5) {
            uVar8 = 0xffffffffffffff0;
          }
          *(undefined8 *)(puVar11 + -8) = 0x14000a98d;
          lVar1 = -(uVar8 & 0xfffffffffffffff0);
          puVar10 = puVar11 + lVar1;
          puVar7 = (undefined4 *)(puVar11 + lVar1 + 0x50);
          puVar11 = puVar11 + lVar1;
          if (puVar7 == (undefined4 *)0x0) goto LAB_14000aa66;
          *puVar7 = 0xcccc;
          puVar11 = puVar10;
LAB_14000a9b9:
          puVar7 = puVar7 + 4;
        }
        else {
          *(undefined8 *)(puVar11 + -8) = 0x14000a9ab;
          puVar7 = (undefined4 *)_malloc_base(uVar5);
          if (puVar7 != (undefined4 *)0x0) {
            *puVar7 = 0xdddd;
            goto LAB_14000a9b9;
          }
        }
        if (puVar7 != (undefined4 *)0x0) {
          *(undefined8 *)(puVar11 + 0x40) = 0;
          *(undefined8 *)(puVar11 + 0x38) = 0;
          *(undefined8 *)(puVar11 + 0x30) = 0;
          *(int *)(puVar11 + 0x28) = iVar4;
          *(undefined4 **)(puVar11 + 0x20) = puVar7;
          *(undefined8 *)(puVar11 + -8) = 0x14000a9ee;
          iVar3 = FUN_140009530(puVar2,param_3,pWVar6,iVar3,*(LPWSTR *)(puVar11 + 0x20),
                                *(int *)(puVar11 + 0x28),*(undefined8 *)(puVar11 + 0x30),
                                *(undefined8 *)(puVar11 + 0x38),*(undefined8 *)(puVar11 + 0x40));
          if (iVar3 != 0) {
            *(undefined8 *)(puVar11 + 0x38) = 0;
            *(undefined8 *)(puVar11 + 0x30) = 0;
            if (param_7 == 0) {
              *(undefined4 *)(puVar11 + 0x28) = 0;
              *(undefined8 *)(puVar11 + 0x20) = 0;
            }
            else {
              *(int *)(puVar11 + 0x28) = param_7;
              *(undefined8 *)(puVar11 + 0x20) = param_6;
            }
            *(undefined8 *)(puVar11 + -8) = 0x14000aa1d;
            iVar3 = __acrt_WideCharToMultiByte(param_8,0,puVar7,iVar4);
            if (iVar3 != 0) {
              if (puVar7[-4] == 0xdddd) {
                *(undefined8 *)(puVar11 + -8) = 0x14000aa5b;
                FUN_140006f7c(puVar7 + -4);
              }
              goto LAB_14000aa66;
            }
          }
          if (puVar7[-4] == 0xdddd) {
            *(undefined8 *)(puVar11 + -8) = 0x14000aa34;
            FUN_140006f7c(puVar7 + -4);
          }
        }
      }
    }
    else if (param_7 != 0) {
      if (iVar4 <= param_7) {
        *(undefined8 *)(puVar11 + 0x40) = 0;
        *(undefined8 *)(puVar11 + 0x38) = 0;
        *(undefined8 *)(puVar11 + 0x30) = 0;
        *(int *)(puVar11 + 0x28) = param_7;
        *(undefined8 *)(puVar11 + 0x20) = param_6;
        *(undefined8 *)(puVar11 + -8) = 0x14000a944;
        iVar3 = FUN_140009530(puVar2,param_3,pWVar6,iVar3,*(LPWSTR *)(puVar11 + 0x20),
                              *(int *)(puVar11 + 0x28),*(undefined8 *)(puVar11 + 0x30),
                              *(undefined8 *)(puVar11 + 0x38),*(undefined8 *)(puVar11 + 0x40));
        if (iVar3 != 0) goto LAB_14000aa66;
      }
      goto LAB_14000aa5f;
    }
  }
LAB_14000aa66:
  puVar12 = puVar11;
  if (*(int *)(pWVar6 + -8) == 0xdddd) {
    *(undefined8 *)(puVar11 + -8) = 0x14000aa77;
    FUN_140006f7c(pWVar6 + -8);
  }
LAB_14000aa79:
  uVar5 = local_30 ^ (ulonglong)&local_38;
  *(undefined8 *)(puVar12 + -8) = 0x14000aa85;
  FUN_14000d520(uVar5);
  return;
}


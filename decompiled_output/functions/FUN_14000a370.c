// Function: FUN_14000a370
// Address: 14000a370
// Size: 1034 bytes
============================================================


void FUN_14000a370(undefined1 *param_1,ulonglong param_2,ulonglong param_3,undefined *param_4)

{
  undefined1 uVar1;
  int iVar2;
  __acrt_ptd *p_Var3;
  undefined1 *puVar4;
  longlong lVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  ulonglong uVar9;
  undefined1 *puVar10;
  undefined1 auStack_468 [32];
  longlong local_448;
  undefined8 auStack_438 [62];
  undefined8 auStack_248 [62];
  ulonglong local_58;
  
  local_58 = DAT_140018038 ^ (ulonglong)auStack_468;
  if ((((param_1 == (undefined1 *)0x0) && (param_2 != 0)) || (param_3 == 0)) ||
     (param_4 == (undefined *)0x0)) {
    p_Var3 = FUN_140006ee4();
    *(undefined4 *)p_Var3 = 0x16;
    FUN_140006c8c();
  }
  else if (1 < param_2) {
    local_448 = 0;
    puVar10 = param_1 + (param_2 - 1) * param_3;
LAB_14000a410:
    while (uVar9 = (ulonglong)((longlong)puVar10 - (longlong)param_1) / param_3 + 1, 8 < uVar9) {
      lVar5 = (uVar9 >> 1) * param_3;
      puVar7 = param_1 + lVar5;
      iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(param_1,puVar7);
      if ((0 < iVar2) && (puVar6 = puVar7, uVar9 = param_3, param_1 != puVar7)) {
        do {
          uVar1 = puVar6[-lVar5];
          puVar6[-lVar5] = *puVar6;
          *puVar6 = uVar1;
          uVar9 = uVar9 - 1;
          puVar6 = puVar6 + 1;
        } while (uVar9 != 0);
      }
      iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(param_1,puVar10);
      if ((0 < iVar2) && (param_1 != puVar10)) {
        puVar6 = puVar10;
        uVar9 = param_3;
        do {
          uVar1 = puVar6[(longlong)param_1 - (longlong)puVar10];
          puVar6[(longlong)param_1 - (longlong)puVar10] = *puVar6;
          *puVar6 = uVar1;
          puVar6 = puVar6 + 1;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
      iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(puVar7);
      puVar6 = param_1;
      puVar8 = puVar10;
      if ((0 < iVar2) && (puVar7 != puVar10)) {
        puVar4 = puVar10;
        uVar9 = param_3;
        do {
          uVar1 = puVar4[(longlong)puVar7 - (longlong)puVar10];
          puVar4[(longlong)puVar7 - (longlong)puVar10] = *puVar4;
          *puVar4 = uVar1;
          puVar4 = puVar4 + 1;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
LAB_14000a5c0:
      puVar4 = puVar7;
      if (puVar6 < puVar4) {
        do {
          puVar6 = puVar6 + param_3;
          if (puVar4 <= puVar6) goto LAB_14000a5f0;
          iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(puVar6);
        } while (iVar2 < 1);
      }
      else {
LAB_14000a5f0:
        do {
          puVar6 = puVar6 + param_3;
          if (puVar10 < puVar6) break;
          iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(puVar6);
        } while (iVar2 < 1);
      }
      do {
        puVar7 = puVar8;
        puVar8 = puVar7 + -param_3;
        if (puVar8 <= puVar4) break;
        iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(puVar8);
      } while (0 < iVar2);
      if (puVar6 <= puVar8) {
        if (puVar8 != puVar6) {
          puVar7 = puVar8;
          uVar9 = param_3;
          do {
            uVar1 = puVar7[(longlong)puVar6 - (longlong)puVar8];
            puVar7[(longlong)puVar6 - (longlong)puVar8] = *puVar7;
            *puVar7 = uVar1;
            puVar7 = puVar7 + 1;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        puVar7 = puVar6;
        if (puVar4 != puVar8) {
          puVar7 = puVar4;
        }
        goto LAB_14000a5c0;
      }
      if (puVar4 < puVar7) {
        do {
          puVar7 = puVar7 + -param_3;
          if (puVar7 <= puVar4) goto LAB_14000a6a7;
          iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(puVar7);
        } while (iVar2 == 0);
      }
      else {
LAB_14000a6a7:
        do {
          puVar7 = puVar7 + -param_3;
          if (puVar7 <= param_1) break;
          iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(puVar7);
        } while (iVar2 == 0);
      }
      if ((longlong)puVar7 - (longlong)param_1 < (longlong)puVar10 - (longlong)puVar6)
      goto LAB_14000a70d;
      if (param_1 < puVar7) {
        auStack_438[local_448] = param_1;
        auStack_248[local_448] = puVar7;
        local_448 = local_448 + 1;
      }
      param_1 = puVar6;
      if (puVar10 <= puVar6) goto LAB_14000a4a3;
    }
    for (; puVar6 = param_1, puVar7 = param_1, param_1 < puVar10; puVar10 = puVar10 + -param_3) {
      while (puVar7 = puVar7 + param_3, puVar7 <= puVar10) {
        iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(puVar7,puVar6);
        if (0 < iVar2) {
          puVar6 = puVar7;
        }
      }
      if (puVar6 != puVar10) {
        puVar7 = puVar10;
        uVar9 = param_3;
        do {
          uVar1 = puVar7[(longlong)puVar6 - (longlong)puVar10];
          puVar7[(longlong)puVar6 - (longlong)puVar10] = *puVar7;
          *puVar7 = uVar1;
          puVar7 = puVar7 + 1;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
    }
    goto LAB_14000a4a3;
  }
LAB_14000a760:
  FUN_14000d520(local_58 ^ (ulonglong)auStack_468);
  return;
LAB_14000a70d:
  if (puVar6 < puVar10) {
    auStack_438[local_448] = puVar6;
    auStack_248[local_448] = puVar10;
    local_448 = local_448 + 1;
  }
  puVar10 = puVar7;
  if (puVar7 <= param_1) {
LAB_14000a4a3:
    local_448 = local_448 + -1;
    if (-1 < local_448) {
      param_1 = (undefined1 *)auStack_438[local_448];
      puVar10 = (undefined1 *)auStack_248[local_448];
      goto LAB_14000a410;
    }
    goto LAB_14000a760;
  }
  goto LAB_14000a410;
}


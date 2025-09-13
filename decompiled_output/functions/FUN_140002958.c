// Function: FUN_140002958
// Address: 140002958
// Size: 317 bytes
============================================================


undefined8 *
FUN_140002958(undefined8 *param_1,undefined8 param_2,int param_3,ulonglong *param_4,longlong param_5
             )

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  int iVar5;
  int *piVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  int iVar11;
  int iVar12;
  ulonglong uVar13;
  undefined4 uStack_3c;
  undefined4 uStack_2c;
  ulonglong uVar10;
  
  uVar3 = *(uint *)(param_5 + 0xc);
  iVar5 = FUN_140003454(param_5,param_4);
  uVar10 = 0;
  if (uVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  uVar4 = param_4[1];
  lVar8 = (longlong)*(int *)(param_5 + 0x10);
  iVar11 = -1;
  uVar13 = 0xffffffff;
  uVar9 = uVar3;
  do {
    uVar1 = uVar9 - 1;
    lVar2 = uVar4 + (ulonglong)uVar1 * 0x14;
    if ((*(int *)(lVar2 + 4 + lVar8) < iVar5) && (iVar5 <= *(int *)(lVar2 + 8 + lVar8))) break;
    uVar9 = uVar1;
  } while (uVar1 != 0);
  uVar7 = uVar10;
  if (uVar9 != 0) {
    uVar7 = lVar8 + (ulonglong)(uVar9 - 1) * 0x14 + uVar4;
  }
  piVar6 = (int *)(uVar4 + lVar8);
  do {
    iVar5 = iVar11;
    if ((((uVar7 == 0) || ((*(int *)(uVar7 + 4) < *piVar6 && (piVar6[1] <= *(int *)(uVar7 + 8)))))
        && (*piVar6 <= param_3)) &&
       ((param_3 <= piVar6[1] && (uVar13 = uVar10, iVar5 = (int)uVar10, iVar11 != -1)))) {
      iVar5 = iVar11;
    }
    iVar11 = iVar5;
    uVar9 = (int)uVar10 + 1;
    uVar10 = (ulonglong)uVar9;
    piVar6 = piVar6 + 5;
  } while (uVar9 < uVar3);
  iVar5 = 0;
  if (iVar11 != -1) {
    iVar5 = iVar11;
  }
  iVar12 = 0;
  if (iVar11 != -1) {
    iVar12 = (int)uVar13 + 1;
  }
  *param_1 = param_2;
  param_1[1] = CONCAT44(uStack_3c,iVar5);
  param_1[2] = param_2;
  param_1[3] = CONCAT44(uStack_2c,iVar12);
  return param_1;
}


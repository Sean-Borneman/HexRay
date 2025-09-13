// Function: FUN_140001a70
// Address: 140001a70
// Size: 503 bytes
============================================================


undefined8 FUN_140001a70(PEXCEPTION_RECORD param_1,PVOID param_2,longlong param_3,longlong *param_4)

{
  uint uVar1;
  longlong lVar2;
  uint *puVar3;
  int iVar4;
  BOOL BVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  uint uVar11;
  ulonglong uVar12;
  PEXCEPTION_RECORD local_38;
  longlong local_30;
  
  __except_validate_context_record(param_3);
  lVar2 = param_4[1];
  puVar3 = (uint *)param_4[7];
  uVar12 = *param_4 - lVar2;
  uVar8 = *(uint *)(param_4 + 9);
  local_38 = param_1;
  local_30 = param_3;
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    for (; uVar8 < *puVar3; uVar8 = uVar8 + 1) {
      uVar7 = (ulonglong)uVar8;
      if (((puVar3[uVar7 * 4 + 1] <= uVar12) && (uVar12 < puVar3[uVar7 * 4 + 2])) &&
         (puVar3[uVar7 * 4 + 4] != 0)) {
        if (puVar3[uVar7 * 4 + 3] != 1) {
          iVar4 = (*(code *)((ulonglong)puVar3[uVar7 * 4 + 3] + lVar2))(&local_38,param_2);
          if (iVar4 < 0) {
            return 0;
          }
          if (iVar4 < 1) goto LAB_140001b8a;
        }
        if (((param_1->ExceptionCode == 0xe06d7363) &&
            (PTR___DestructExceptionObject_14000e350 != (undefined *)0x0)) &&
           (BVar5 = _IsNonwritableInCurrentImage((PBYTE)&PTR___DestructExceptionObject_14000e350),
           BVar5 != 0)) {
          (*(code *)PTR___DestructExceptionObject_14000e350)(param_1,1);
        }
        _NLG_Notify();
        RtlUnwindEx(param_2,(PVOID)((ulonglong)puVar3[uVar7 * 4 + 4] + lVar2),param_1,
                    (PVOID)(ulonglong)param_1->ExceptionCode,(PCONTEXT)param_4[5],
                    (PUNWIND_HISTORY_TABLE)param_4[8]);
        FUN_140002240();
      }
LAB_140001b8a:
    }
  }
  else {
    uVar7 = param_4[4] - lVar2;
    for (; uVar1 = *puVar3, uVar8 < uVar1; uVar8 = uVar8 + 1) {
      uVar6 = (ulonglong)uVar8;
      if ((puVar3[uVar6 * 4 + 1] <= uVar12) && (uVar12 < puVar3[uVar6 * 4 + 2])) {
        uVar11 = param_1->ExceptionFlags & 0x20;
        if (uVar11 != 0) {
          uVar10 = 0;
          if (uVar1 != 0) {
            do {
              if ((((puVar3[uVar10 * 4 + 1] <= uVar7) && (uVar7 < puVar3[uVar10 * 4 + 2])) &&
                  (puVar3[uVar10 * 4 + 4] == puVar3[uVar6 * 4 + 4])) &&
                 (puVar3[uVar10 * 4 + 3] == puVar3[uVar6 * 4 + 3])) break;
              uVar9 = (int)uVar10 + 1;
              uVar10 = (ulonglong)uVar9;
            } while (uVar9 < uVar1);
          }
          if ((uint)uVar10 != uVar1) {
            return 1;
          }
        }
        if (puVar3[uVar6 * 4 + 4] == 0) {
          *(uint *)(param_4 + 9) = uVar8 + 1;
          (*(code *)((ulonglong)puVar3[uVar6 * 4 + 3] + lVar2))
                    (CONCAT71((int7)(uVar6 * 2 >> 8),1),param_2);
        }
        else if ((uVar7 == puVar3[uVar6 * 4 + 4]) && (uVar11 != 0)) {
          return 1;
        }
      }
    }
  }
  return 1;
}


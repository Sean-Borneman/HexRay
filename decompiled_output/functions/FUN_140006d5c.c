// Function: FUN_140006d5c
// Address: 140006d5c
// Size: 252 bytes
============================================================


undefined4 FUN_140006d5c(short *param_1,longlong param_2,longlong param_3,longlong param_4)

{
  short sVar1;
  __acrt_ptd *p_Var2;
  longlong lVar3;
  short *psVar4;
  undefined4 uVar5;
  longlong lVar6;
  longlong lVar7;
  
  if (param_4 == 0) {
    if (param_1 == (short *)0x0) {
      if (param_2 == 0) {
        return 0;
      }
    }
    else {
LAB_140006daf:
      if (param_2 != 0) {
        if (param_4 == 0) {
          *param_1 = 0;
          return 0;
        }
        if (param_3 != 0) {
          psVar4 = param_1;
          lVar3 = param_4;
          lVar7 = param_2;
          if (param_4 == -1) {
            do {
              sVar1 = *(short *)((param_3 - (longlong)param_1) + (longlong)psVar4);
              *psVar4 = sVar1;
              psVar4 = psVar4 + 1;
              if (sVar1 == 0) {
                return 0;
              }
              lVar7 = lVar7 + -1;
            } while (lVar7 != 0);
            lVar7 = 0;
          }
          else {
            do {
              lVar6 = lVar3;
              sVar1 = *(short *)((param_3 - (longlong)param_1) + (longlong)psVar4);
              *psVar4 = sVar1;
              psVar4 = psVar4 + 1;
              if (sVar1 == 0) {
                return 0;
              }
              lVar7 = lVar7 + -1;
            } while ((lVar7 != 0) && (lVar3 = lVar6 + -1, lVar6 + -1 != 0));
            lVar3 = lVar6 + -1;
            if (lVar7 == 0) {
              lVar3 = lVar6;
            }
            if (lVar3 == 0) {
              *psVar4 = 0;
            }
          }
          if (lVar7 != 0) {
            return 0;
          }
          if (param_4 == -1) {
            param_1[param_2 + -1] = 0;
            return 0x50;
          }
          *param_1 = 0;
          p_Var2 = FUN_140006ee4();
          uVar5 = 0x22;
          goto LAB_140006d8d;
        }
        *param_1 = 0;
      }
    }
  }
  else if (param_1 != (short *)0x0) goto LAB_140006daf;
  p_Var2 = FUN_140006ee4();
  uVar5 = 0x16;
LAB_140006d8d:
  *(undefined4 *)p_Var2 = uVar5;
  FUN_140006c8c();
  return uVar5;
}


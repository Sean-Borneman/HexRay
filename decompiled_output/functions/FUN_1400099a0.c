// Function: FUN_1400099a0
// Address: 1400099a0
// Size: 638 bytes
============================================================


undefined8 FUN_1400099a0(uint param_1)

{
  code *pcVar1;
  bool bVar2;
  __acrt_ptd *p_Var3;
  longlong lVar4;
  undefined8 uVar5;
  byte bVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong *puVar9;
  __acrt_ptd *p_Var10;
  undefined4 local_res10;
  longlong local_res18;
  
  p_Var3 = (__acrt_ptd *)0x0;
  p_Var10 = (__acrt_ptd *)0x0;
  local_res10 = 0;
  bVar2 = true;
  if (param_1 == 2) {
LAB_1400099e9:
    if (param_1 == 2) {
      puVar9 = (ulonglong *)&DAT_140019748;
    }
    else if (param_1 == 6) {
LAB_140009a86:
      puVar9 = (ulonglong *)&DAT_140019758;
      p_Var10 = p_Var3;
    }
    else if (param_1 == 0xf) {
      puVar9 = (ulonglong *)&DAT_140019760;
    }
    else if (param_1 == 0x15) {
      puVar9 = (ulonglong *)&DAT_140019750;
      p_Var10 = p_Var3;
    }
    else {
      if (param_1 == 0x16) goto LAB_140009a86;
      puVar9 = (ulonglong *)0x0;
      p_Var10 = p_Var3;
    }
  }
  else {
    if (param_1 != 4) {
      if (param_1 != 6) {
        if ((param_1 == 8) || (param_1 == 0xb)) goto LAB_140009a19;
        if ((param_1 != 0xf) && (1 < param_1 - 0x15)) goto LAB_140009a66;
      }
      goto LAB_1400099e9;
    }
LAB_140009a19:
    p_Var10 = FUN_14000671c();
    if (p_Var10 == (__acrt_ptd *)0x0) {
      return 0xffffffff;
    }
    lVar4 = *(longlong *)p_Var10;
    lVar7 = DAT_14000f430 * 0x10 + lVar4;
    for (; lVar4 != lVar7; lVar4 = lVar4 + 0x10) {
      if (*(uint *)(lVar4 + 4) == param_1) goto LAB_140009a61;
    }
    lVar4 = 0;
LAB_140009a61:
    if (lVar4 == 0) {
LAB_140009a66:
      p_Var10 = FUN_140006ee4();
      *(undefined4 *)p_Var10 = 0x16;
      FUN_140006c8c();
      return 0xffffffff;
    }
    puVar9 = (ulonglong *)(lVar4 + 8);
    bVar2 = false;
  }
  local_res18 = 0;
  if (bVar2) {
    __acrt_lock(3);
  }
  uVar8 = *puVar9;
  if (bVar2) {
    bVar6 = (byte)DAT_140018038 & 0x3f;
    uVar8 = (uVar8 ^ DAT_140018038) >> bVar6 | (uVar8 ^ DAT_140018038) << 0x40 - bVar6;
  }
  if (uVar8 == 1) goto LAB_140009b7f;
  if (uVar8 == 0) {
    if (bVar2) {
      __acrt_unlock(3);
    }
    FUN_140005800(3);
    pcVar1 = (code *)swi(3);
    uVar5 = (*pcVar1)();
    return uVar5;
  }
  if ((param_1 < 0xc) && ((0x910U >> (param_1 & 0x1f) & 1) != 0)) {
    local_res18 = *(longlong *)(p_Var10 + 8);
    *(longlong *)(p_Var10 + 8) = 0;
    if (param_1 == 8) {
      p_Var3 = FUN_1400065a4();
      local_res10 = *(undefined4 *)(p_Var3 + 0x10);
      p_Var3 = FUN_1400065a4();
      *(undefined4 *)(p_Var3 + 0x10) = 0x8c;
      goto LAB_140009b36;
    }
  }
  else {
LAB_140009b36:
    if (param_1 == 8) {
      lVar4 = DAT_14000f438 * 0x10 + *(longlong *)p_Var10;
      lVar7 = DAT_14000f440 * 0x10 + lVar4;
      for (; lVar4 != lVar7; lVar4 = lVar4 + 0x10) {
        *(undefined8 *)(lVar4 + 8) = 0;
      }
      goto LAB_140009b7f;
    }
  }
  *puVar9 = DAT_140018038;
LAB_140009b7f:
  if (bVar2) {
    __acrt_unlock(3);
  }
  if (uVar8 != 1) {
    if (param_1 == 8) {
      p_Var3 = FUN_1400065a4();
      (*(code *)PTR__guard_dispatch_icall_14000e268)(8,*(undefined4 *)(p_Var3 + 0x10));
    }
    else {
      (*(code *)PTR__guard_dispatch_icall_14000e268)(param_1);
    }
    if (((param_1 < 0xc) && ((0x910U >> (param_1 & 0x1f) & 1) != 0)) &&
       (*(longlong *)(p_Var10 + 8) = local_res18, param_1 == 8)) {
      p_Var10 = FUN_1400065a4();
      *(undefined4 *)(p_Var10 + 0x10) = local_res10;
    }
  }
  return 0;
}


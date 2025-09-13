// Function: FUN_140007e60
// Address: 140007e60
// Size: 701 bytes
============================================================


void FUN_140007e60(int param_1,longlong param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  BOOL BVar5;
  uint *puVar6;
  byte *pbVar7;
  undefined *puVar8;
  longlong lVar9;
  BYTE *pBVar10;
  ulonglong uVar11;
  byte *pbVar12;
  undefined2 *puVar13;
  undefined *puVar14;
  undefined *puVar15;
  undefined4 uVar16;
  uint uVar17;
  uint uVar18;
  byte *pbVar19;
  undefined1 auStack_68 [32];
  _cpinfo local_48;
  ulonglong local_30;
  
  local_30 = DAT_140018038 ^ (ulonglong)auStack_68;
  uVar4 = getSystemCP(param_1);
  puVar14 = (undefined *)0x0;
  if (uVar4 != 0) {
    puVar6 = &DAT_1400184c0;
    uVar16 = 1;
    puVar8 = puVar14;
LAB_140007ea9:
    if (*puVar6 != uVar4) goto code_r0x000140007eb1;
    FUN_140001e70((undefined1 (*) [32])(param_2 + 0x18),0,0x101);
    pbVar19 = &DAT_1400184b0;
    lVar9 = 4;
    pbVar7 = &DAT_1400184d0 + (longlong)puVar8 * 0x30;
    do {
      bVar2 = *pbVar7;
      pbVar12 = pbVar7;
      while ((bVar2 != 0 && (pbVar12[1] != 0))) {
        bVar2 = *pbVar12;
        uVar18 = (uint)bVar2;
        if (bVar2 <= pbVar12[1]) {
          uVar17 = (uint)bVar2;
          do {
            uVar17 = uVar17 + 1;
            if (0x100 < uVar17) break;
            uVar18 = uVar18 + 1;
            pbVar1 = (byte *)((ulonglong)uVar17 + 0x18 + param_2);
            *pbVar1 = *pbVar1 | *pbVar19;
          } while (uVar18 <= pbVar12[1]);
        }
        pbVar12 = pbVar12 + 2;
        bVar2 = *pbVar12;
      }
      pbVar7 = pbVar7 + 8;
      pbVar19 = pbVar19 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    *(uint *)(param_2 + 4) = uVar4;
    *(undefined4 *)(param_2 + 8) = 1;
    puVar15 = PTR_u_ja_JP_14000f778;
    if (((uVar4 != 0x3a4) && (puVar15 = PTR_u_zh_CN_14000f780, uVar4 != 0x3a8)) &&
       ((puVar15 = PTR_u_ko_KR_14000f788, uVar4 != 0x3b5 && (puVar15 = puVar14, uVar4 == 0x3b6)))) {
      puVar15 = PTR_u_zh_TW_14000f790;
    }
    *(undefined **)(param_2 + 0x220) = puVar15;
    puVar13 = (undefined2 *)(param_2 + 0xc);
    lVar9 = 6;
    do {
      *puVar13 = *(undefined2 *)
                  (((longlong)puVar8 * 0x30 - param_2) + 0x1400184b8 + (longlong)puVar13);
      puVar13 = puVar13 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    goto LAB_140007f05;
  }
LAB_1400080ed:
  FUN_14000783c(param_2);
LAB_1400080f7:
  FUN_14000d520(local_30 ^ (ulonglong)auStack_68);
  return;
code_r0x000140007eb1:
  uVar18 = (int)puVar8 + 1;
  puVar8 = (undefined *)(ulonglong)uVar18;
  puVar6 = puVar6 + 0xc;
  if (4 < uVar18) goto code_r0x000140007ebe;
  goto LAB_140007ea9;
code_r0x000140007ebe:
  if ((uVar4 == 65000) || (BVar5 = IsValidCodePage(uVar4 & 0xffff), BVar5 == 0)) goto LAB_1400080f7;
  if (uVar4 == 0xfde9) {
    *(undefined8 *)(param_2 + 4) = 0xfde9;
    *(undefined8 *)(param_2 + 0x220) = 0;
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined2 *)(param_2 + 0x1c) = 0;
  }
  else {
    BVar5 = GetCPInfo(uVar4,&local_48);
    if (BVar5 == 0) {
      if (DAT_140018f10 == 0) goto LAB_1400080f7;
      goto LAB_1400080ed;
    }
    FUN_140001e70((undefined1 (*) [32])(param_2 + 0x18),0,0x101);
    *(uint *)(param_2 + 4) = uVar4;
    *(undefined8 *)(param_2 + 0x220) = 0;
    if (local_48.MaxCharSize == 2) {
      pBVar10 = local_48.LeadByte;
      while ((local_48.LeadByte[0] != 0 && (pBVar10[1] != 0))) {
        bVar2 = *pBVar10;
        if ((uint)bVar2 <= (uint)pBVar10[1]) {
          uVar4 = (uint)bVar2;
          uVar11 = (ulonglong)(((uint)pBVar10[1] - (uint)bVar2) + 1);
          do {
            uVar4 = uVar4 + 1;
            pbVar7 = (byte *)((ulonglong)uVar4 + 0x18 + param_2);
            *pbVar7 = *pbVar7 | 4;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        pBVar10 = pBVar10 + 2;
        local_48.LeadByte[0] = *pBVar10;
      }
      pbVar7 = (byte *)(param_2 + 0x1a);
      lVar9 = 0xfe;
      do {
        *pbVar7 = *pbVar7 | 8;
        pbVar7 = pbVar7 + 1;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
      iVar3 = *(int *)(param_2 + 4);
      puVar8 = PTR_u_ja_JP_14000f778;
      if ((((iVar3 != 0x3a4) && (puVar8 = PTR_u_zh_CN_14000f780, iVar3 != 0x3a8)) &&
          (puVar8 = PTR_u_ko_KR_14000f788, iVar3 != 0x3b5)) &&
         (puVar8 = PTR_u_zh_TW_14000f790, iVar3 != 0x3b6)) {
        puVar8 = puVar14;
      }
      *(undefined **)(param_2 + 0x220) = puVar8;
    }
    else {
      uVar16 = 0;
    }
    *(undefined4 *)(param_2 + 8) = uVar16;
  }
  puVar13 = (undefined2 *)(param_2 + 0xc);
  for (lVar9 = 6; lVar9 != 0; lVar9 = lVar9 + -1) {
    *puVar13 = 0;
    puVar13 = puVar13 + 1;
  }
LAB_140007f05:
  FUN_1400078d4(param_2);
  goto LAB_1400080f7;
}


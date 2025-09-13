// Function: FUN_14000c070
// Address: 14000c070
// Size: 1386 bytes
============================================================


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_14000c070(void)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  ulonglong uVar13;
  ulonglong uVar14;
  double dVar15;
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 in_ZMM0 [64];
  double dVar20;
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  double dVar23;
  double dVar24;
  undefined1 auVar25 [16];
  double dVar26;
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  double dVar37;
  
  dVar15 = in_ZMM0._0_8_;
  auVar16 = in_ZMM0._0_16_;
  if (DAT_14001979c == 0) {
    if ((double)((ulonglong)dVar15 & (ulonglong)DAT_140013d10) == DAT_140013d10) {
      if (dVar15 == DAT_140013d10) {
        return dVar15;
      }
      if (dVar15 != DAT_140013d00) {
        return (double)((ulonglong)dVar15 | _DAT_140013d30);
      }
    }
    else {
      dVar37 = (double)(int)(((ulonglong)dVar15 >> 0x34) - _DAT_140013d40);
      if (0.0 < dVar15) {
        dVar23 = (double)((ulonglong)dVar15 & (ulonglong)DAT_140013d60);
        dVar20 = dVar15;
        if (dVar37 == DAT_140013e80) {
          dVar37 = (double)((ulonglong)dVar23 | (ulonglong)DAT_140013df0) - DAT_140013df0;
          dVar20 = (double)((ulonglong)dVar37 & (ulonglong)DAT_140013d60);
          dVar37 = (double)(int)((uint)((ulonglong)dVar37 >> 0x34) - _DAT_140013e90);
          dVar23 = dVar20;
        }
        uVar13 = ((ulonglong)dVar20 & _DAT_140013d70) + ((ulonglong)dVar20 & _DAT_140013d80) * 2;
        if ((double)((ulonglong)(dVar15 - DAT_140013df0) & _DAT_140013ee0) < DAT_140013ea0) {
          dVar15 = dVar15 - DAT_140013df0;
          dVar37 = dVar15 / (DAT_140013de0 + dVar15);
          dVar20 = dVar37 + dVar37;
          dVar23 = dVar20 * dVar20;
          dVar24 = dVar23 * dVar20;
          dVar26 = (double)((ulonglong)dVar15 & (ulonglong)DAT_140013f30);
          dVar15 = (((DAT_140013f00 * dVar23 + DAT_140013ef0) * dVar24 +
                    (DAT_140013f20 * dVar23 + DAT_140013f10) * dVar24 * dVar24 * dVar20) -
                   dVar15 * dVar37) + (dVar15 - dVar26);
          return dVar26 * DAT_140013db0 + dVar15 * DAT_140013db0 + dVar15 * DAT_140013da0 +
                 dVar26 * DAT_140013da0;
        }
        uVar14 = uVar13 >> 0x2c;
        dVar20 = ((double)(uVar13 | DAT_140013e00) - (double)((ulonglong)dVar23 | DAT_140013e00)) *
                 *(double *)(&DAT_140014f80 + uVar14 * 8);
        dVar15 = dVar20 * dVar20;
        return *(double *)(&DAT_140013f60 + uVar14 * 8) + DAT_140013dc0 * dVar37 +
               *(double *)(&DAT_140014770 + uVar14 * 8) +
               (DAT_140013dd0 * dVar37 -
               ((DAT_140013e40 * dVar20 + _DAT_140013e30) * dVar15 + dVar20 +
               ((DAT_140013e70 * dVar20 + DAT_140013e60) * dVar20 + DAT_140013e50) * dVar15 * dVar15
               ) * DAT_140013d90);
      }
      if (dVar15 == 0.0) {
        dVar15 = (double)FUN_14000ce30(dVar15,DAT_140013d00,DAT_140013f40);
        return dVar15;
      }
    }
    dVar15 = (double)FUN_14000ce30(dVar15,DAT_140013d20,DAT_140013f44);
    return dVar15;
  }
  auVar27 = vpsrlq_avx(auVar16,0x34);
  auVar36._8_8_ = _UNK_140013d48;
  auVar36._0_8_ = _DAT_140013d40;
  auVar36 = vpsubq_avx(auVar27,auVar36);
  auVar36 = vcvtdq2pd_avx(auVar36);
  auVar27._8_8_ = _UNK_140013d18;
  auVar27._0_8_ = DAT_140013d10;
  auVar27 = vpand_avx(auVar16,auVar27);
  if (auVar27._0_8_ == DAT_140013d10) {
    if (dVar15 != DAT_140013d10) {
      if (dVar15 == DAT_140013d00) goto LAB_14000c5c0;
      dVar15 = (double)FUN_14000ce30(dVar15,(ulonglong)dVar15 | _DAT_140013d30,DAT_140013f48);
    }
    return dVar15;
  }
  if (0.0 < dVar15) {
    auVar27 = vpand_avx(auVar16,_DAT_140013d60);
    if (auVar36._0_8_ == DAT_140013e80) {
      auVar16._8_8_ = _UNK_140013df8;
      auVar16._0_8_ = DAT_140013df0;
      auVar16 = vpor_avx(auVar27,auVar16);
      auVar28._8_8_ = 0;
      auVar28._0_8_ = auVar16._0_8_ - DAT_140013df0;
      auVar36 = vpsrlq_avx(auVar28,0x34);
      auVar16 = vpand_avx(auVar28,_DAT_140013d60);
      auVar7._4_12_ = _UNK_140013e94;
      auVar7._0_4_ = _DAT_140013e90;
      auVar36 = vpsubd_avx(auVar36,auVar7);
      auVar36 = vcvtdq2pd_avx(auVar36);
      auVar27 = auVar16;
    }
    auVar8._8_8_ = _UNK_140013d78;
    auVar8._0_8_ = _DAT_140013d70;
    auVar7 = vpand_avx(auVar16,auVar8);
    auVar9._8_8_ = _UNK_140013d88;
    auVar9._0_8_ = _DAT_140013d80;
    auVar28 = vpand_avx(auVar16,auVar9);
    auVar28 = vpsllq_avx(auVar28,1);
    auVar7 = vpaddq_avx(auVar28,auVar7);
    auVar30._8_8_ = 0;
    auVar30._0_8_ = dVar15 - DAT_140013df0;
    auVar12._8_8_ = _UNK_140013ee8;
    auVar12._0_8_ = _DAT_140013ee0;
    auVar28 = vpand_avx(auVar30,auVar12);
    if (auVar28._0_8_ < DAT_140013ea0) {
      dVar20 = auVar16._0_8_ - DAT_140013df0;
      dVar23 = dVar20 / (DAT_140013de0 + dVar20);
      auVar32._8_8_ = 0;
      auVar32._0_8_ = DAT_140013f00;
      auVar35._8_8_ = 0;
      auVar35._0_8_ = DAT_140013f20;
      dVar15 = dVar23 + dVar23;
      auVar5._8_8_ = 0;
      auVar5._0_8_ = DAT_140013ef0;
      auVar25._8_8_ = 0;
      auVar25._0_8_ = dVar15 * dVar15;
      auVar36 = vfmadd213sd_fma(auVar32,auVar25,auVar5);
      auVar6._8_8_ = 0;
      auVar6._0_8_ = DAT_140013f10;
      auVar27 = vfmadd213sd_fma(auVar35,auVar25,auVar6);
      dVar37 = dVar15 * dVar15 * dVar15;
      auVar19._8_8_ = 0;
      auVar19._0_8_ = dVar20;
      auVar16 = vpand_avx(auVar19,_DAT_140013f30);
      dVar24 = auVar16._0_8_;
      dVar15 = ((auVar36._0_8_ * dVar37 + auVar27._0_8_ * dVar37 * dVar37 * dVar15) -
               dVar20 * dVar23) + (dVar20 - dVar24);
      return dVar24 * DAT_140013db0 + dVar15 * DAT_140013db0 + dVar15 * DAT_140013da0 +
             dVar24 * DAT_140013da0;
    }
    uVar13 = auVar7._0_8_ >> 0x2c;
    auVar10._8_8_ = _UNK_140013e08;
    auVar10._0_8_ = DAT_140013e00;
    auVar16 = vpor_avx(auVar27,auVar10);
    auVar11._8_8_ = _UNK_140013e08;
    auVar11._0_8_ = DAT_140013e00;
    auVar27 = vpor_avx(auVar7,auVar11);
    dVar15 = (auVar27._0_8_ - auVar16._0_8_) * *(double *)(&DAT_140014f80 + uVar13 * 8);
    dVar37 = dVar15 * dVar15;
    auVar29._8_8_ = 0;
    auVar29._0_8_ = DAT_140013e70;
    auVar33._8_8_ = 0;
    auVar33._0_8_ = DAT_140013e40;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = DAT_140013e60;
    auVar21._8_8_ = 0;
    auVar21._0_8_ = dVar15;
    auVar16 = vfmadd213sd_fma(auVar29,auVar21,auVar1);
    auVar2._8_8_ = 0;
    auVar2._0_8_ = DAT_140013e00;
    auVar27 = vfmadd213sd_fma(auVar33,auVar21,auVar2);
    auVar3._8_8_ = 0;
    auVar3._0_8_ = DAT_140013e50;
    auVar16 = vfmadd213sd_fma(auVar16,auVar21,auVar3);
    auVar17._8_8_ = 0;
    auVar17._0_8_ = dVar37;
    auVar27 = vfmadd231sd_fma(auVar21,auVar27,auVar17);
    auVar31._8_8_ = 0;
    auVar31._0_8_ = dVar37 * dVar37;
    auVar16 = vfmadd231sd_fma(auVar27,auVar16,auVar31);
    auVar34._8_8_ = 0;
    auVar34._0_8_ = DAT_140013dd0;
    auVar22._8_8_ = 0;
    auVar22._0_8_ = auVar16._0_8_ * DAT_140013d90;
    auVar27 = vfmsub213sd_fma(auVar34,auVar36,auVar22);
    auVar4._8_8_ = 0;
    auVar4._0_8_ = DAT_140013dc0;
    auVar18._8_8_ = 0;
    auVar18._0_8_ = *(ulonglong *)(&DAT_140013f60 + uVar13 * 8);
    auVar16 = vfmadd231sd_fma(auVar18,auVar36,auVar4);
    return auVar16._0_8_ + *(double *)(&DAT_140014770 + uVar13 * 8) + auVar27._0_8_;
  }
  if (dVar15 == 0.0) {
    dVar15 = (double)FUN_14000ce30(dVar15,DAT_140013d00,DAT_140013f40);
    return dVar15;
  }
LAB_14000c5c0:
  dVar15 = (double)FUN_14000ce30(dVar15,DAT_140013d20,DAT_140013f44);
  return dVar15;
}


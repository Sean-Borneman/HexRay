// Function: FUN_140002d40
// Address: 140002d40
// Size: 1363 bytes
============================================================


undefined8 * FUN_140002d40(undefined8 *param_1,undefined8 *param_2,ulonglong param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 auVar3 [32];
  undefined1 auVar4 [32];
  undefined1 auVar5 [32];
  undefined1 auVar6 [32];
  undefined1 uVar7;
  undefined2 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 *puVar23;
  undefined1 (*pauVar24) [32];
  undefined1 (*pauVar25) [32];
  undefined1 (*pauVar26) [32];
  undefined1 (*pauVar27) [32];
  undefined8 *puVar28;
  ulonglong uVar29;
  longlong lVar30;
  ulonglong uVar31;
  undefined8 uVar32;
  undefined8 uVar33;
  
  puVar23 = param_1;
  switch(param_3) {
  case 0:
    return puVar23;
  case 1:
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    return puVar23;
  case 2:
    *(undefined2 *)param_1 = *(undefined2 *)param_2;
    return puVar23;
  case 3:
    uVar7 = *(undefined1 *)((longlong)param_2 + 2);
    *(undefined2 *)param_1 = *(undefined2 *)param_2;
    *(undefined1 *)((longlong)param_1 + 2) = uVar7;
    return puVar23;
  case 4:
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    return puVar23;
  case 5:
    uVar7 = *(undefined1 *)((longlong)param_2 + 4);
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    *(undefined1 *)((longlong)param_1 + 4) = uVar7;
    return puVar23;
  case 6:
    uVar8 = *(undefined2 *)((longlong)param_2 + 4);
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    *(undefined2 *)((longlong)param_1 + 4) = uVar8;
    return puVar23;
  case 7:
    uVar8 = *(undefined2 *)((longlong)param_2 + 4);
    uVar7 = *(undefined1 *)((longlong)param_2 + 6);
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    *(undefined2 *)((longlong)param_1 + 4) = uVar8;
    *(undefined1 *)((longlong)param_1 + 6) = uVar7;
    return puVar23;
  case 8:
    *param_1 = *param_2;
    return puVar23;
  case 9:
    uVar7 = *(undefined1 *)(param_2 + 1);
    *param_1 = *param_2;
    *(undefined1 *)(param_1 + 1) = uVar7;
    return puVar23;
  case 10:
    uVar8 = *(undefined2 *)(param_2 + 1);
    *param_1 = *param_2;
    *(undefined2 *)(param_1 + 1) = uVar8;
    return puVar23;
  case 0xb:
    uVar8 = *(undefined2 *)(param_2 + 1);
    uVar7 = *(undefined1 *)((longlong)param_2 + 10);
    *param_1 = *param_2;
    *(undefined2 *)(param_1 + 1) = uVar8;
    *(undefined1 *)((longlong)param_1 + 10) = uVar7;
    return puVar23;
  case 0xc:
    uVar9 = *(undefined4 *)(param_2 + 1);
    *param_1 = *param_2;
    *(undefined4 *)(param_1 + 1) = uVar9;
    return puVar23;
  case 0xd:
    uVar9 = *(undefined4 *)(param_2 + 1);
    uVar7 = *(undefined1 *)((longlong)param_2 + 0xc);
    *param_1 = *param_2;
    *(undefined4 *)(param_1 + 1) = uVar9;
    *(undefined1 *)((longlong)param_1 + 0xc) = uVar7;
    return puVar23;
  case 0xe:
    uVar9 = *(undefined4 *)(param_2 + 1);
    uVar8 = *(undefined2 *)((longlong)param_2 + 0xc);
    *param_1 = *param_2;
    *(undefined4 *)(param_1 + 1) = uVar9;
    *(undefined2 *)((longlong)param_1 + 0xc) = uVar8;
    return puVar23;
  case 0xf:
    uVar9 = *(undefined4 *)(param_2 + 1);
    uVar8 = *(undefined2 *)((longlong)param_2 + 0xc);
    uVar7 = *(undefined1 *)((longlong)param_2 + 0xe);
    *param_1 = *param_2;
    *(undefined4 *)(param_1 + 1) = uVar9;
    *(undefined2 *)((longlong)param_1 + 0xc) = uVar8;
    *(undefined1 *)((longlong)param_1 + 0xe) = uVar7;
    return puVar23;
  }
  if (param_3 < 0x21) {
    uVar10 = param_2[1];
    puVar28 = (undefined8 *)((longlong)param_2 + (param_3 - 0x10));
    uVar11 = *puVar28;
    uVar32 = puVar28[1];
    *param_1 = *param_2;
    param_1[1] = uVar10;
    puVar28 = (undefined8 *)((longlong)param_1 + (param_3 - 0x10));
    *puVar28 = uVar11;
    puVar28[1] = uVar32;
    return puVar23;
  }
  if ((param_2 < param_1) && (param_1 < (undefined8 *)((longlong)param_2 + param_3))) {
    lVar30 = (longlong)param_2 - (longlong)param_1;
    puVar23 = (undefined8 *)((longlong)param_1 + lVar30 + (param_3 - 0x10));
    uVar10 = *puVar23;
    uVar11 = puVar23[1];
    puVar28 = (undefined8 *)((longlong)param_1 + (param_3 - 0x10));
    uVar29 = param_3 - 0x10;
    puVar23 = puVar28;
    uVar32 = uVar10;
    uVar33 = uVar11;
    if (((ulonglong)puVar28 & 0xf) != 0) {
      puVar23 = (undefined8 *)((ulonglong)puVar28 & 0xfffffffffffffff0);
      uVar32 = *(undefined8 *)((longlong)puVar23 + lVar30);
      uVar33 = ((undefined8 *)((longlong)puVar23 + lVar30))[1];
      *puVar28 = uVar10;
      *(undefined8 *)((longlong)param_1 + (param_3 - 8)) = uVar11;
      uVar29 = (longlong)puVar23 - (longlong)param_1;
    }
    uVar31 = uVar29 >> 7;
    if (uVar31 != 0) {
      *puVar23 = uVar32;
      puVar23[1] = uVar33;
      puVar28 = puVar23;
      while( true ) {
        puVar1 = (undefined8 *)((longlong)puVar28 + lVar30 + -0x10);
        uVar10 = puVar1[1];
        puVar23 = (undefined8 *)((longlong)puVar28 + lVar30 + -0x20);
        uVar11 = *puVar23;
        uVar32 = puVar23[1];
        puVar23 = puVar28 + -0x10;
        puVar28[-2] = *puVar1;
        puVar28[-1] = uVar10;
        puVar28[-4] = uVar11;
        puVar28[-3] = uVar32;
        puVar1 = (undefined8 *)((longlong)puVar28 + lVar30 + -0x30);
        uVar10 = puVar1[1];
        puVar2 = (undefined8 *)((longlong)puVar28 + lVar30 + -0x40);
        uVar11 = *puVar2;
        uVar32 = puVar2[1];
        uVar31 = uVar31 - 1;
        puVar28[-6] = *puVar1;
        puVar28[-5] = uVar10;
        puVar28[-8] = uVar11;
        puVar28[-7] = uVar32;
        puVar1 = (undefined8 *)((longlong)puVar28 + lVar30 + -0x50);
        uVar10 = puVar1[1];
        puVar2 = (undefined8 *)((longlong)puVar28 + lVar30 + -0x60);
        uVar11 = *puVar2;
        uVar32 = puVar2[1];
        puVar28[-10] = *puVar1;
        puVar28[-9] = uVar10;
        puVar28[-0xc] = uVar11;
        puVar28[-0xb] = uVar32;
        puVar1 = (undefined8 *)((longlong)puVar28 + lVar30 + -0x70);
        uVar10 = *puVar1;
        uVar11 = puVar1[1];
        uVar32 = *(undefined8 *)((longlong)puVar23 + lVar30);
        uVar33 = ((undefined8 *)((longlong)puVar23 + lVar30))[1];
        if (uVar31 == 0) break;
        puVar28[-0xe] = uVar10;
        puVar28[-0xd] = uVar11;
        *puVar23 = uVar32;
        puVar28[-0xf] = uVar33;
        puVar28 = puVar23;
      }
      puVar28[-0xe] = uVar10;
      puVar28[-0xd] = uVar11;
      uVar29 = uVar29 & 0x7f;
    }
    for (uVar31 = uVar29 >> 4; uVar31 != 0; uVar31 = uVar31 - 1) {
      *puVar23 = uVar32;
      puVar23[1] = uVar33;
      puVar23 = puVar23 + -2;
      uVar32 = *(undefined8 *)((longlong)puVar23 + lVar30);
      uVar33 = ((undefined8 *)((longlong)puVar23 + lVar30))[1];
    }
    if ((uVar29 & 0xf) != 0) {
      uVar10 = param_2[1];
      *param_1 = *param_2;
      param_1[1] = uVar10;
    }
    *puVar23 = uVar32;
    puVar23[1] = uVar33;
    return param_1;
  }
  if (DAT_140018018 < 3) {
    if ((param_3 < 0x801) || (((byte)DAT_140018af4 & 2) == 0)) {
      if (0x80 < param_3) {
        lVar30 = ((ulonglong)param_1 & 0xf) - 0x10;
        puVar23 = (undefined8 *)((longlong)param_1 - lVar30);
        puVar28 = (undefined8 *)((longlong)param_2 - lVar30);
        param_3 = param_3 + lVar30;
        if (0x80 < param_3) {
          do {
            uVar10 = puVar28[1];
            uVar11 = puVar28[2];
            uVar32 = puVar28[3];
            uVar33 = puVar28[4];
            uVar12 = puVar28[5];
            uVar13 = puVar28[6];
            uVar14 = puVar28[7];
            *puVar23 = *puVar28;
            puVar23[1] = uVar10;
            puVar23[2] = uVar11;
            puVar23[3] = uVar32;
            puVar23[4] = uVar33;
            puVar23[5] = uVar12;
            puVar23[6] = uVar13;
            puVar23[7] = uVar14;
            uVar10 = puVar28[9];
            uVar11 = puVar28[10];
            uVar32 = puVar28[0xb];
            uVar33 = puVar28[0xc];
            uVar12 = puVar28[0xd];
            uVar13 = puVar28[0xe];
            uVar14 = puVar28[0xf];
            puVar23[8] = puVar28[8];
            puVar23[9] = uVar10;
            puVar23[10] = uVar11;
            puVar23[0xb] = uVar32;
            puVar23[0xc] = uVar33;
            puVar23[0xd] = uVar12;
            puVar23[0xe] = uVar13;
            puVar23[0xf] = uVar14;
            puVar23 = puVar23 + 0x10;
            puVar28 = puVar28 + 0x10;
            param_3 = param_3 - 0x80;
          } while (0x7f < param_3);
        }
      }
                    /* WARNING: Could not recover jumptable at 0x000140003256. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      puVar23 = (undefined8 *)
                (*(code *)(IMAGE_DOS_HEADER_140000000.e_magic +
                          *(uint *)(&DAT_14001b138 + (param_3 + 0xf >> 4) * 4)))();
      return puVar23;
    }
  }
  else if (((param_3 < 0x2001) || (0x180000 < param_3)) || (((byte)DAT_140018af4 & 2) == 0)) {
    uVar10 = *param_2;
    uVar11 = param_2[1];
    uVar32 = param_2[2];
    uVar33 = param_2[3];
    puVar28 = (undefined8 *)((longlong)param_2 + (param_3 - 0x20));
    uVar12 = *puVar28;
    uVar13 = puVar28[1];
    uVar14 = puVar28[2];
    uVar15 = puVar28[3];
    if (0x100 < param_3) {
      lVar30 = ((ulonglong)param_1 & 0x1f) - 0x20;
      pauVar24 = (undefined1 (*) [32])((longlong)param_1 - lVar30);
      pauVar26 = (undefined1 (*) [32])((longlong)param_2 - lVar30);
      param_3 = param_3 + lVar30;
      if (0x100 < param_3) {
        if (0x180000 < param_3) {
          do {
            uVar29 = param_3;
            pauVar27 = pauVar26;
            pauVar25 = pauVar24;
            auVar3 = pauVar27[1];
            auVar4 = pauVar27[2];
            auVar5 = pauVar27[3];
            auVar6 = vmovntdq_avx(*pauVar27);
            *pauVar25 = auVar6;
            auVar3 = vmovntdq_avx(auVar3);
            pauVar25[1] = auVar3;
            auVar3 = vmovntdq_avx(auVar4);
            pauVar25[2] = auVar3;
            auVar3 = vmovntdq_avx(auVar5);
            pauVar25[3] = auVar3;
            auVar3 = pauVar27[5];
            auVar4 = pauVar27[6];
            auVar5 = pauVar27[7];
            auVar6 = vmovntdq_avx(pauVar27[4]);
            pauVar25[4] = auVar6;
            auVar3 = vmovntdq_avx(auVar3);
            pauVar25[5] = auVar3;
            auVar3 = vmovntdq_avx(auVar4);
            pauVar25[6] = auVar3;
            auVar3 = vmovntdq_avx(auVar5);
            pauVar25[7] = auVar3;
            pauVar24 = pauVar25 + 8;
            pauVar26 = pauVar27 + 8;
            param_3 = uVar29 - 0x100;
          } while (0xff < uVar29 - 0x100);
          uVar31 = uVar29 - 0xe1 & 0xffffffffffffffe0;
          switch(uVar29) {
          case 0x1e1:
          case 0x1e2:
          case 0x1e3:
          case 0x1e4:
          case 0x1e5:
          case 0x1e6:
          case 0x1e7:
          case 0x1e8:
          case 0x1e9:
          case 0x1ea:
          case 0x1eb:
          case 0x1ec:
          case 0x1ed:
          case 0x1ee:
          case 0x1ef:
          case 0x1f0:
          case 0x1f1:
          case 0x1f2:
          case 499:
          case 500:
          case 0x1f5:
          case 0x1f6:
          case 0x1f7:
          case 0x1f8:
          case 0x1f9:
          case 0x1fa:
          case 0x1fb:
          case 0x1fc:
          case 0x1fd:
          case 0x1fe:
          case 0x1ff:
            auVar3 = vmovntdq_avx(*(undefined1 (*) [32])(*pauVar27 + uVar31));
            *(undefined1 (*) [32])(*pauVar25 + uVar31) = auVar3;
          case 0x1c1:
          case 0x1c2:
          case 0x1c3:
          case 0x1c4:
          case 0x1c5:
          case 0x1c6:
          case 0x1c7:
          case 0x1c8:
          case 0x1c9:
          case 0x1ca:
          case 0x1cb:
          case 0x1cc:
          case 0x1cd:
          case 0x1ce:
          case 0x1cf:
          case 0x1d0:
          case 0x1d1:
          case 0x1d2:
          case 0x1d3:
          case 0x1d4:
          case 0x1d5:
          case 0x1d6:
          case 0x1d7:
          case 0x1d8:
          case 0x1d9:
          case 0x1da:
          case 0x1db:
          case 0x1dc:
          case 0x1dd:
          case 0x1de:
          case 0x1df:
          case 0x1e0:
            auVar3 = vmovntdq_avx(*(undefined1 (*) [32])(pauVar27[1] + uVar31));
            *(undefined1 (*) [32])(pauVar25[1] + uVar31) = auVar3;
          case 0x1a1:
          case 0x1a2:
          case 0x1a3:
          case 0x1a4:
          case 0x1a5:
          case 0x1a6:
          case 0x1a7:
          case 0x1a8:
          case 0x1a9:
          case 0x1aa:
          case 0x1ab:
          case 0x1ac:
          case 0x1ad:
          case 0x1ae:
          case 0x1af:
          case 0x1b0:
          case 0x1b1:
          case 0x1b2:
          case 0x1b3:
          case 0x1b4:
          case 0x1b5:
          case 0x1b6:
          case 0x1b7:
          case 0x1b8:
          case 0x1b9:
          case 0x1ba:
          case 0x1bb:
          case 0x1bc:
          case 0x1bd:
          case 0x1be:
          case 0x1bf:
          case 0x1c0:
            auVar3 = vmovntdq_avx(*(undefined1 (*) [32])(pauVar27[2] + uVar31));
            *(undefined1 (*) [32])(pauVar25[2] + uVar31) = auVar3;
          case 0x181:
          case 0x182:
          case 0x183:
          case 0x184:
          case 0x185:
          case 0x186:
          case 0x187:
          case 0x188:
          case 0x189:
          case 0x18a:
          case 0x18b:
          case 0x18c:
          case 0x18d:
          case 0x18e:
          case 399:
          case 400:
          case 0x191:
          case 0x192:
          case 0x193:
          case 0x194:
          case 0x195:
          case 0x196:
          case 0x197:
          case 0x198:
          case 0x199:
          case 0x19a:
          case 0x19b:
          case 0x19c:
          case 0x19d:
          case 0x19e:
          case 0x19f:
          case 0x1a0:
            auVar3 = vmovntdq_avx(*(undefined1 (*) [32])(pauVar27[3] + uVar31));
            *(undefined1 (*) [32])(pauVar25[3] + uVar31) = auVar3;
          case 0x161:
          case 0x162:
          case 0x163:
          case 0x164:
          case 0x165:
          case 0x166:
          case 0x167:
          case 0x168:
          case 0x169:
          case 0x16a:
          case 0x16b:
          case 0x16c:
          case 0x16d:
          case 0x16e:
          case 0x16f:
          case 0x170:
          case 0x171:
          case 0x172:
          case 0x173:
          case 0x174:
          case 0x175:
          case 0x176:
          case 0x177:
          case 0x178:
          case 0x179:
          case 0x17a:
          case 0x17b:
          case 0x17c:
          case 0x17d:
          case 0x17e:
          case 0x17f:
          case 0x180:
            auVar3 = vmovntdq_avx(*(undefined1 (*) [32])(pauVar27[4] + uVar31));
            *(undefined1 (*) [32])(pauVar25[4] + uVar31) = auVar3;
          case 0x141:
          case 0x142:
          case 0x143:
          case 0x144:
          case 0x145:
          case 0x146:
          case 0x147:
          case 0x148:
          case 0x149:
          case 0x14a:
          case 0x14b:
          case 0x14c:
          case 0x14d:
          case 0x14e:
          case 0x14f:
          case 0x150:
          case 0x151:
          case 0x152:
          case 0x153:
          case 0x154:
          case 0x155:
          case 0x156:
          case 0x157:
          case 0x158:
          case 0x159:
          case 0x15a:
          case 0x15b:
          case 0x15c:
          case 0x15d:
          case 0x15e:
          case 0x15f:
          case 0x160:
            auVar3 = vmovntdq_avx(*(undefined1 (*) [32])(pauVar27[5] + uVar31));
            *(undefined1 (*) [32])(pauVar25[5] + uVar31) = auVar3;
          case 0x121:
          case 0x122:
          case 0x123:
          case 0x124:
          case 0x125:
          case 0x126:
          case 0x127:
          case 0x128:
          case 0x129:
          case 0x12a:
          case 299:
          case 300:
          case 0x12d:
          case 0x12e:
          case 0x12f:
          case 0x130:
          case 0x131:
          case 0x132:
          case 0x133:
          case 0x134:
          case 0x135:
          case 0x136:
          case 0x137:
          case 0x138:
          case 0x139:
          case 0x13a:
          case 0x13b:
          case 0x13c:
          case 0x13d:
          case 0x13e:
          case 0x13f:
          case 0x140:
            auVar3 = vmovntdq_avx(*(undefined1 (*) [32])(pauVar27[6] + uVar31));
            *(undefined1 (*) [32])(pauVar25[6] + uVar31) = auVar3;
          default:
            puVar28 = (undefined8 *)(pauVar25[-1] + uVar29);
            *puVar28 = uVar12;
            puVar28[1] = uVar13;
            puVar28[2] = uVar14;
            puVar28[3] = uVar15;
          case 0x100:
            *param_1 = uVar10;
            param_1[1] = uVar11;
            param_1[2] = uVar32;
            param_1[3] = uVar33;
            return puVar23;
          }
        }
        do {
          uVar10 = *(undefined8 *)(*pauVar26 + 8);
          uVar11 = *(undefined8 *)(*pauVar26 + 0x10);
          uVar32 = *(undefined8 *)(*pauVar26 + 0x18);
          uVar33 = *(undefined8 *)pauVar26[1];
          uVar12 = *(undefined8 *)(pauVar26[1] + 8);
          uVar13 = *(undefined8 *)(pauVar26[1] + 0x10);
          uVar14 = *(undefined8 *)(pauVar26[1] + 0x18);
          uVar15 = *(undefined8 *)pauVar26[2];
          uVar16 = *(undefined8 *)(pauVar26[2] + 8);
          uVar17 = *(undefined8 *)(pauVar26[2] + 0x10);
          uVar18 = *(undefined8 *)(pauVar26[2] + 0x18);
          uVar19 = *(undefined8 *)pauVar26[3];
          uVar20 = *(undefined8 *)(pauVar26[3] + 8);
          uVar21 = *(undefined8 *)(pauVar26[3] + 0x10);
          uVar22 = *(undefined8 *)(pauVar26[3] + 0x18);
          *(undefined8 *)*pauVar24 = *(undefined8 *)*pauVar26;
          *(undefined8 *)(*pauVar24 + 8) = uVar10;
          *(undefined8 *)(*pauVar24 + 0x10) = uVar11;
          *(undefined8 *)(*pauVar24 + 0x18) = uVar32;
          *(undefined8 *)pauVar24[1] = uVar33;
          *(undefined8 *)(pauVar24[1] + 8) = uVar12;
          *(undefined8 *)(pauVar24[1] + 0x10) = uVar13;
          *(undefined8 *)(pauVar24[1] + 0x18) = uVar14;
          *(undefined8 *)pauVar24[2] = uVar15;
          *(undefined8 *)(pauVar24[2] + 8) = uVar16;
          *(undefined8 *)(pauVar24[2] + 0x10) = uVar17;
          *(undefined8 *)(pauVar24[2] + 0x18) = uVar18;
          *(undefined8 *)pauVar24[3] = uVar19;
          *(undefined8 *)(pauVar24[3] + 8) = uVar20;
          *(undefined8 *)(pauVar24[3] + 0x10) = uVar21;
          *(undefined8 *)(pauVar24[3] + 0x18) = uVar22;
          uVar10 = *(undefined8 *)(pauVar26[4] + 8);
          uVar11 = *(undefined8 *)(pauVar26[4] + 0x10);
          uVar32 = *(undefined8 *)(pauVar26[4] + 0x18);
          uVar33 = *(undefined8 *)pauVar26[5];
          uVar12 = *(undefined8 *)(pauVar26[5] + 8);
          uVar13 = *(undefined8 *)(pauVar26[5] + 0x10);
          uVar14 = *(undefined8 *)(pauVar26[5] + 0x18);
          uVar15 = *(undefined8 *)pauVar26[6];
          uVar16 = *(undefined8 *)(pauVar26[6] + 8);
          uVar17 = *(undefined8 *)(pauVar26[6] + 0x10);
          uVar18 = *(undefined8 *)(pauVar26[6] + 0x18);
          uVar19 = *(undefined8 *)pauVar26[7];
          uVar20 = *(undefined8 *)(pauVar26[7] + 8);
          uVar21 = *(undefined8 *)(pauVar26[7] + 0x10);
          uVar22 = *(undefined8 *)(pauVar26[7] + 0x18);
          *(undefined8 *)pauVar24[4] = *(undefined8 *)pauVar26[4];
          *(undefined8 *)(pauVar24[4] + 8) = uVar10;
          *(undefined8 *)(pauVar24[4] + 0x10) = uVar11;
          *(undefined8 *)(pauVar24[4] + 0x18) = uVar32;
          *(undefined8 *)pauVar24[5] = uVar33;
          *(undefined8 *)(pauVar24[5] + 8) = uVar12;
          *(undefined8 *)(pauVar24[5] + 0x10) = uVar13;
          *(undefined8 *)(pauVar24[5] + 0x18) = uVar14;
          *(undefined8 *)pauVar24[6] = uVar15;
          *(undefined8 *)(pauVar24[6] + 8) = uVar16;
          *(undefined8 *)(pauVar24[6] + 0x10) = uVar17;
          *(undefined8 *)(pauVar24[6] + 0x18) = uVar18;
          *(undefined8 *)pauVar24[7] = uVar19;
          *(undefined8 *)(pauVar24[7] + 8) = uVar20;
          *(undefined8 *)(pauVar24[7] + 0x10) = uVar21;
          *(undefined8 *)(pauVar24[7] + 0x18) = uVar22;
          pauVar24 = pauVar24 + 8;
          pauVar26 = pauVar26 + 8;
          param_3 = param_3 - 0x100;
        } while (0xff < param_3);
      }
    }
                    /* WARNING: Could not recover jumptable at 0x000140002fb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    puVar23 = (undefined8 *)
              (*(code *)(IMAGE_DOS_HEADER_140000000.e_magic +
                        *(uint *)(&DAT_14001b0f0 + (param_3 + 0x1f >> 5) * 4)))();
    return puVar23;
  }
  for (; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_2 = (undefined8 *)((longlong)param_2 + 1);
    param_1 = (undefined8 *)((longlong)param_1 + 1);
  }
  return puVar23;
}


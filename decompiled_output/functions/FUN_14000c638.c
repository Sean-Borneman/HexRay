// Function: FUN_14000c638
// Address: 14000c638
// Size: 473 bytes
============================================================


void FUN_14000c638(ulonglong param_1,byte *param_2,ulonglong param_3,uint *param_4,longlong param_5)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  ulonglong uVar4;
  byte *pbVar5;
  byte bVar6;
  ulonglong uVar7;
  uint *puVar8;
  uint *puVar9;
  ulonglong uVar10;
  undefined1 auStack_78 [24];
  uint auStack_60 [6];
  ulonglong local_48;
  
  local_48 = DAT_140018038 ^ (ulonglong)auStack_78;
  puVar8 = (uint *)&DAT_140019790;
  if (param_4 != (uint *)0x0) {
    puVar8 = param_4;
  }
  pbVar5 = (byte *)0x14000eb52;
  if (param_2 != (byte *)0x0) {
    pbVar5 = param_2;
  }
  uVar10 = 1;
  if (param_2 != (byte *)0x0) {
    uVar10 = param_3;
  }
  puVar9 = (uint *)(-(ulonglong)(param_2 != (byte *)0x0) & param_1);
  if (uVar10 == 0) goto LAB_14000c7f5;
  if (*(short *)((longlong)puVar8 + 6) == 0) {
    bVar3 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    if (-1 < (char)bVar3) {
      if (puVar9 != (uint *)0x0) {
        *puVar9 = (uint)bVar3;
      }
      goto LAB_14000c7f5;
    }
    if ((bVar3 & 0xe0) == 0xc0) {
      bVar6 = 2;
    }
    else if ((bVar3 & 0xf0) == 0xe0) {
      bVar6 = 3;
    }
    else {
      if ((bVar3 & 0xf8) != 0xf0) goto LAB_14000c7ea;
      bVar6 = 4;
    }
    uVar2 = (1 << (7 - bVar6 & 0x1f)) - 1U & (uint)bVar3;
    bVar3 = bVar6;
LAB_14000c740:
    uVar4 = (ulonglong)bVar3;
    uVar7 = (ulonglong)bVar3;
    if (uVar10 <= uVar4) {
      uVar7 = uVar10;
    }
    while ((ulonglong)((longlong)pbVar5 - (longlong)param_2) < uVar7) {
      bVar1 = *pbVar5;
      pbVar5 = pbVar5 + 1;
      if ((bVar1 & 0xc0) != 0x80) goto LAB_14000c7ea;
      uVar2 = bVar1 & 0x3f | uVar2 << 6;
    }
    if (uVar7 < uVar4) {
      *(ushort *)(puVar8 + 1) = (ushort)bVar6;
      *(ushort *)((longlong)puVar8 + 6) = (ushort)(byte)(bVar3 - (char)uVar7);
      *puVar8 = uVar2;
      goto LAB_14000c7f5;
    }
    if ((0x7ff < uVar2 - 0xd800) && (uVar2 < 0x110000)) {
      auStack_60[2] = 0x80;
      auStack_60[3] = 0x800;
      auStack_60[4] = 0x10000;
      if (auStack_60[bVar6] <= uVar2) {
        if (puVar9 != (uint *)0x0) {
          *puVar9 = uVar2;
        }
        FUN_14000c61c(-(ulonglong)(uVar2 != 0) & uVar4,(undefined8 *)puVar8);
        goto LAB_14000c7f5;
      }
    }
  }
  else {
    bVar6 = (byte)puVar8[1];
    uVar2 = *puVar8;
    bVar3 = *(byte *)((longlong)puVar8 + 6);
    if ((((byte)(bVar6 - 2) < 3) && (bVar3 != 0)) && (bVar3 < bVar6)) goto LAB_14000c740;
  }
LAB_14000c7ea:
  FUN_14000c624((undefined8 *)puVar8,param_5);
LAB_14000c7f5:
  FUN_14000d520(local_48 ^ (ulonglong)auStack_78);
  return;
}


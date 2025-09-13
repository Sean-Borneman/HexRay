// Function: FUN_1400018b4
// Address: 1400018b4
// Size: 428 bytes
============================================================


/* WARNING: Removing unreachable block (ram,0x00014000197e) */
/* WARNING: Removing unreachable block (ram,0x0001400018ee) */
/* WARNING: Removing unreachable block (ram,0x0001400018c7) */

undefined8 FUN_1400018b4(void)

{
  int *piVar1;
  uint *puVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  uVar6 = 0;
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar4 = puVar2[3];
  if ((piVar1[2] == 0x49656e69 && piVar1[3] == 0x6c65746e) && piVar1[1] == 0x756e6547) {
    DAT_140018028 = 0xffffffffffffffff;
    uVar5 = *puVar2 & 0xfff3ff0;
    DAT_140018020 = 0x8000;
    if ((((uVar5 == 0x106c0) || (uVar5 == 0x20660)) || (uVar5 == 0x20670)) ||
       ((uVar5 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar5 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_140018af4 = DAT_140018af4 | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar6 = *(uint *)(lVar3 + 4);
    if ((uVar6 >> 9 & 1) != 0) {
      DAT_140018af4 = DAT_140018af4 | 2;
    }
  }
  DAT_140018018 = 1;
  DAT_14001801c = 2;
  if ((uVar4 >> 0x14 & 1) != 0) {
    DAT_140018018 = 2;
    DAT_14001801c = 6;
    if ((((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) && ((in_XCR0 & 6) == 6)) {
      DAT_14001801c = 0xe;
      DAT_140018018 = 3;
      if ((uVar6 & 0x20) != 0) {
        DAT_140018018 = 5;
        DAT_14001801c = 0x2e;
        if (((uVar6 & 0xd0030000) == 0xd0030000) && ((in_XCR0 & 0xe0) == 0xe0)) {
          DAT_14001801c = 0x6e;
          DAT_140018018 = 6;
        }
      }
    }
  }
  return 0;
}


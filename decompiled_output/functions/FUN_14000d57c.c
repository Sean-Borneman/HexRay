// Function: FUN_14000d57c
// Address: 14000d57c
// Size: 210 bytes
============================================================


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14000d57c(void)

{
  code *pcVar1;
  BOOL BVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
  puVar3 = auStack_38;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(2);
    puVar3 = auStack_30;
  }
  *(undefined8 *)(puVar3 + -8) = 0x14000d5a7;
  capture_previous_context((PCONTEXT)&DAT_140019840);
  _DAT_1400197b0 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_1400198d8 = puVar3 + 0x40;
  _DAT_1400198c0 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_1400197a0 = 0xc0000409;
  _DAT_1400197a4 = 1;
  _DAT_1400197b8 = 1;
  DAT_1400197c0 = 2;
  *(undefined8 *)(puVar3 + 0x20) = DAT_140018038;
  *(undefined8 *)(puVar3 + 0x28) = DAT_140018030;
  *(undefined8 *)(puVar3 + -8) = 0x14000d649;
  DAT_140019938 = _DAT_1400197b0;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_1400157c0);
  return;
}


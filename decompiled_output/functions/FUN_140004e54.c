// Function: FUN_140004e54
// Address: 140004e54
// Size: 37 bytes
============================================================


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140004e54(ulonglong param_1)

{
  byte bVar1;
  
  bVar1 = 0x40 - ((byte)DAT_140018038 & 0x3f) & 0x3f;
  _DAT_140018c68 = (param_1 >> bVar1 | param_1 << 0x40 - bVar1) ^ DAT_140018038;
  return;
}


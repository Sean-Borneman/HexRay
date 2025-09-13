// Function: FUN_14000580c
// Address: 14000580c
// Size: 62 bytes
============================================================


void FUN_14000580c(ulonglong param_1)

{
  code *pcVar1;
  byte bVar2;
  
  if (DAT_140018ea8 == DAT_140018038) {
    bVar2 = 0x40 - ((byte)DAT_140018038 & 0x3f) & 0x3f;
    DAT_140018ea8 = (param_1 >> bVar2 | param_1 << 0x40 - bVar2) ^ DAT_140018038;
    return;
  }
  FUN_140005f70();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


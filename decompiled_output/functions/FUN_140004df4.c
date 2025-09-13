// Function: FUN_140004df4
// Address: 140004df4
// Size: 29 bytes
============================================================


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_140004df4(void)

{
  byte bVar1;
  
  bVar1 = (byte)DAT_140018038 & 0x3f;
  return (DAT_140018038 ^ _DAT_140018c68) >> bVar1 != 0 ||
         (DAT_140018038 ^ _DAT_140018c68) << 0x40 - bVar1 != 0;
}


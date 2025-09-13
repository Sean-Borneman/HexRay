// Function: FUN_140004e1c
// Address: 140004e1c
// Size: 56 bytes
============================================================


/* WARNING: Switch with 1 destination removed at 0x000140004e4d */
/* WARNING: Switch with 1 destination removed at 0x00014000d920 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140004e1c(undefined8 param_1)

{
  undefined8 uVar1;
  byte bVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  bVar2 = (byte)DAT_140018038 & 0x3f;
  UNRECOVERED_JUMPTABLE =
       (code *)((DAT_140018038 ^ _DAT_140018c68) >> bVar2 |
               (DAT_140018038 ^ _DAT_140018c68) << 0x40 - bVar2);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00014000d900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(param_1);
    return uVar1;
  }
  return 0;
}


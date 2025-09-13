// Function: FUN_14000967c
// Address: 14000967c
// Size: 49 bytes
============================================================


undefined8 FUN_14000967c(void)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  
  uVar1 = DAT_140018038;
  puVar3 = &DAT_140019640;
  for (lVar2 = 0x1e; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
  }
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}


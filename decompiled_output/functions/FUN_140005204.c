// Function: FUN_140005204
// Address: 140005204
// Size: 110 bytes
============================================================


undefined8 FUN_140005204(void)

{
  undefined8 *puVar1;
  LPWCH pWVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  uVar3 = 0;
  if (DAT_140018e88 == (undefined8 *)0x0) {
    pWVar2 = FUN_140008254();
    if (pWVar2 == (LPWCH)0x0) {
      FUN_140006f7c((LPVOID)0x0);
      uVar3 = 0xffffffff;
    }
    else {
      puVar4 = FUN_140005274(pWVar2);
      puVar1 = puVar4;
      if (puVar4 == (undefined8 *)0x0) {
        uVar3 = 0xffffffff;
        puVar4 = DAT_140018e88;
        puVar1 = DAT_140018e90;
      }
      DAT_140018e90 = puVar1;
      DAT_140018e88 = puVar4;
      FUN_140006f7c((LPVOID)0x0);
      FUN_140006f7c(pWVar2);
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


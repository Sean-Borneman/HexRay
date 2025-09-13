// Function: FUN_140005ee4
// Address: 140005ee4
// Size: 64 bytes
============================================================


undefined8 FUN_140005ee4(void)

{
  uint uVar1;
  ulonglong uVar2;
  
  LOCK();
  uVar1 = *DAT_140018f08;
  uVar2 = (ulonglong)uVar1;
  *DAT_140018f08 = *DAT_140018f08 - 1;
  UNLOCK();
  if ((uVar1 == 1) && (DAT_140018f08 != (uint *)&DAT_140018070)) {
    uVar2 = FUN_140006f7c(DAT_140018f08);
    DAT_140018f08 = (uint *)&DAT_140018070;
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}


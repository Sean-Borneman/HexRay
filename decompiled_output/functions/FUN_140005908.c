// Function: FUN_140005908
// Address: 140005908
// Size: 12 bytes
============================================================


undefined4 FUN_140005908(void)

{
  undefined4 uVar1;
  
  uVar1 = DAT_140018eb4;
  LOCK();
  DAT_140018eb4 = 1;
  UNLOCK();
  return uVar1;
}


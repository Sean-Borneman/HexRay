// Function: FUN_14000a164
// Address: 14000a164
// Size: 49 bytes
============================================================


void FUN_14000a164(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  
  if ((*param_2 != DAT_140018f08) && ((DAT_1400187c0 & *(uint *)(param_1 + 0x3a8)) == 0)) {
    lVar1 = FUN_140007e44();
    *param_2 = lVar1;
  }
  return;
}


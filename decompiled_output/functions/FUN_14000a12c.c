// Function: FUN_14000a12c
// Address: 14000a12c
// Size: 53 bytes
============================================================


void FUN_14000a12c(longlong param_1,longlong *param_2,longlong param_3)

{
  undefined **ppuVar1;
  
  if ((*param_2 != (&DAT_140019598)[param_3]) && ((DAT_1400187c0 & *(uint *)(param_1 + 0x3a8)) == 0)
     ) {
    ppuVar1 = FUN_1400091b0();
    *param_2 = (longlong)ppuVar1;
  }
  return;
}


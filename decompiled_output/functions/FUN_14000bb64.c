// Function: FUN_14000bb64
// Address: 14000bb64
// Size: 95 bytes
============================================================


byte FUN_14000bb64(uint param_1)

{
  __acrt_ptd *p_Var1;
  
  if (param_1 == 0xfffffffe) {
    p_Var1 = FUN_140006ee4();
    *(undefined4 *)p_Var1 = 9;
  }
  else {
    if ((-1 < (int)param_1) && (param_1 < DAT_140019590)) {
      return *(byte *)((&DAT_140019190)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x38 +
                      (ulonglong)(param_1 & 0x3f) * 0x48) & 0x40;
    }
    p_Var1 = FUN_140006ee4();
    *(undefined4 *)p_Var1 = 9;
    FUN_140006c8c();
  }
  return 0;
}


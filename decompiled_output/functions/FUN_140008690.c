// Function: FUN_140008690
// Address: 140008690
// Size: 117 bytes
============================================================


undefined8 FUN_140008690(uint param_1)

{
  __acrt_ptd *p_Var1;
  
  if (param_1 == 0xfffffffe) {
    p_Var1 = FUN_140006ec4();
    *(undefined4 *)p_Var1 = 0;
    p_Var1 = FUN_140006ee4();
    *(undefined4 *)p_Var1 = 9;
  }
  else {
    if ((-1 < (int)param_1) && (param_1 < DAT_140019590)) {
      if ((*(byte *)((&DAT_140019190)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x38 +
                    (ulonglong)(param_1 & 0x3f) * 0x48) & 1) != 0) {
        return *(undefined8 *)
                ((&DAT_140019190)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x28 +
                (ulonglong)(param_1 & 0x3f) * 0x48);
      }
    }
    p_Var1 = FUN_140006ec4();
    *(undefined4 *)p_Var1 = 0;
    p_Var1 = FUN_140006ee4();
    *(undefined4 *)p_Var1 = 9;
    FUN_140006c8c();
  }
  return 0xffffffffffffffff;
}


// Function: FUN_1400085d4
// Address: 1400085d4
// Size: 186 bytes
============================================================


undefined8 FUN_1400085d4(uint param_1)

{
  int iVar1;
  ulonglong uVar2;
  __acrt_ptd *p_Var3;
  DWORD nStdHandle;
  
  if ((-1 < (int)param_1) && (param_1 < DAT_140019590)) {
    uVar2 = (ulonglong)(param_1 & 0x3f);
    if (((*(byte *)((&DAT_140019190)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x38 + uVar2 * 0x48)
         & 1) != 0) &&
       (*(longlong *)
         ((&DAT_140019190)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x28 + uVar2 * 0x48) != -1)) {
      iVar1 = FUN_140004de4();
      if (iVar1 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_140008654;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_140008654:
      *(undefined8 *)
       ((&DAT_140019190)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x28 + uVar2 * 0x48) =
           0xffffffffffffffff;
      return 0;
    }
  }
  p_Var3 = FUN_140006ee4();
  *(undefined4 *)p_Var3 = 9;
  p_Var3 = FUN_140006ec4();
  *(undefined4 *)p_Var3 = 0;
  return 0xffffffff;
}


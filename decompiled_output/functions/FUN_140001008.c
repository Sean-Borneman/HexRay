// Function: FUN_140001008
// Address: 140001008
// Size: 182 bytes
============================================================


void FUN_140001008(void)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  undefined7 extraout_var;
  
  FUN_140004dec(2);
  uVar5 = FUN_14000157c();
  _set_fmode((int)uVar5);
  uVar5 = FUN_140001570();
  puVar6 = (undefined4 *)FUN_1400059e4();
  *puVar6 = (int)uVar5;
  uVar5 = __scrt_initialize_onexit_tables(1);
  if ((char)uVar5 != '\0') {
    FUN_14000183c();
    atexit(FUN_140001878);
    uVar5 = FUN_140001574();
    iVar4 = _configure_wide_argv((int)uVar5);
    if (iVar4 == 0) {
      FUN_140001584();
      bVar2 = FUN_1400015c8();
      if ((int)CONCAT71(extraout_var,bVar2) != 0) {
        FUN_140004e54(0x140001570);
      }
      _guard_check_icall();
      _guard_check_icall();
      uVar5 = FUN_140001570();
      _configthreadlocale((int)uVar5);
      cVar3 = FUN_140001594();
      if (cVar3 != '\0') {
        thunk_FUN_140005204();
      }
      FUN_140001570();
      uVar5 = thunk_FUN_140001570();
      if ((int)uVar5 == 0) {
        return;
      }
    }
  }
  FUN_1400015ec(7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


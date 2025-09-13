// Function: FUN_1400010ec
// Address: 1400010ec
// Size: 345 bytes
============================================================


ulonglong FUN_1400010ec(void)

{
  code *pcVar1;
  bool bVar2;
  WORD WVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  ulonglong *puVar9;
  ushort *puVar10;
  undefined8 unaff_RBX;
  
  uVar4 = (uint)unaff_RBX;
  uVar5 = __scrt_initialize_crt(1);
  if ((char)uVar5 == '\0') {
    FUN_1400015ec(7);
  }
  else {
    bVar2 = false;
    uVar5 = __scrt_acquire_startup_lock();
    uVar4 = (uint)CONCAT71((int7)((ulonglong)unaff_RBX >> 8),(char)uVar5);
    if (DAT_140018a88 != 1) {
      if (DAT_140018a88 == 0) {
        DAT_140018a88 = 1;
        uVar6 = FUN_1400054f0((undefined8 *)&DAT_14000e2a0,(undefined8 *)&DAT_14000e2d8);
        if ((int)uVar6 != 0) {
          return 0xff;
        }
        FUN_1400054ac((undefined8 *)&DAT_14000e288,(undefined8 *)&DAT_14000e298);
        DAT_140018a88 = 2;
      }
      else {
        bVar2 = true;
      }
      __scrt_release_startup_lock((char)uVar5);
      plVar7 = (longlong *)FUN_1400015d4();
      if ((*plVar7 != 0) && (uVar8 = FUN_140001388((longlong)plVar7), (char)uVar8 != '\0')) {
        (*(code *)PTR__guard_dispatch_icall_14000e260)(0);
      }
      puVar9 = (ulonglong *)FUN_1400015dc();
      if ((*puVar9 != 0) && (uVar8 = FUN_140001388((longlong)puVar9), (char)uVar8 != '\0')) {
        FUN_14000580c(*puVar9);
      }
      WVar3 = __scrt_get_show_window_mode();
      puVar10 = _get_wide_winmain_command_line();
      uVar4 = UnityMain(&IMAGE_DOS_HEADER_140000000,0,puVar10,WVar3);
      uVar8 = FUN_14000177c();
      if ((char)uVar8 != '\0') {
        if (!bVar2) {
          FUN_1400057f0();
        }
        __scrt_uninitialize_crt(true,'\0');
        return (ulonglong)uVar4;
      }
      goto LAB_14000124d;
    }
  }
  FUN_1400015ec(7);
LAB_14000124d:
  FUN_14000584c(uVar4);
  FUN_140005800(uVar4);
  pcVar1 = (code *)swi(3);
  uVar8 = (*pcVar1)();
  return uVar8;
}


// Function: abort
// Address: 140006018
// Size: 86 bytes
============================================================


/* Library Function - Single Match
    abort
   
   Library: Visual Studio 2019 Release */

void __cdecl abort(void)

{
  code *pcVar1;
  BOOL BVar2;
  longlong lVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
  puVar4 = auStack_28;
  lVar3 = __acrt_get_sigabrt_handler();
  if (lVar3 != 0) {
    FUN_1400099a0(0x16);
  }
  if ((DAT_140018050 & 2) != 0) {
    BVar2 = IsProcessorFeaturePresent(0x17);
    puVar4 = auStack_28;
    if (BVar2 != 0) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(7);
      puVar4 = auStack_20;
    }
    *(undefined8 *)(puVar4 + -8) = 0x140006063;
    __acrt_call_reportfault(3,0x40000015,1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x14000606d;
  FUN_140005800(3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


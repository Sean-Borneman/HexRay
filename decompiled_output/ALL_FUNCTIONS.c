/*==============================================================================
 * CONSOLIDATED DECOMPILED FUNCTIONS
 * Program: MoSimulator.exe
 * Generated: Fri Sep 12 23:38:43 EDT 2025
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************************
 * Function: UnityMain
 * Address: 140001000
 * Size: 7 bytes
 *****************************************************************************/


void UnityMain(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UnityMain();
  return;
}



/*****************************************************************************
 * Function: FUN_140001008
 * Address: 140001008
 * Size: 182 bytes
 *****************************************************************************/


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



/*****************************************************************************
 * Function: FUN_1400010c0
 * Address: 1400010c0
 * Size: 16 bytes
 *****************************************************************************/


undefined8 FUN_1400010c0(void)

{
  FUN_1400015ac();
  return 0;
}



/*****************************************************************************
 * Function: FUN_1400010d0
 * Address: 1400010d0
 * Size: 25 bytes
 *****************************************************************************/


void FUN_1400010d0(void)

{
  undefined8 uVar1;
  
  FUN_1400017d0();
  uVar1 = FUN_140001570();
  FUN_1400059b8((uint)uVar1);
  return;
}



/*****************************************************************************
 * Function: FUN_1400010ec
 * Address: 1400010ec
 * Size: 345 bytes
 *****************************************************************************/


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



/*****************************************************************************
 * Function: entry
 * Address: 140001260
 * Size: 18 bytes
 *****************************************************************************/


void entry(void)

{
  __security_init_cookie();
  FUN_1400010ec();
  return;
}



/*****************************************************************************
 * Function: FUN_140001388
 * Address: 140001388
 * Size: 150 bytes
 *****************************************************************************/


ulonglong FUN_140001388(longlong param_1)

{
  word *pwVar1;
  ulonglong uVar2;
  uint7 uVar3;
  longlong lVar4;
  word *pwVar5;
  
  uVar2 = 0x5a4d;
  if (IMAGE_DOS_HEADER_140000000.e_magic == (char  [2])0x5a4d) {
    lVar4 = (longlong)(int)IMAGE_DOS_HEADER_140000000.e_lfanew;
    if ((*(int *)(IMAGE_DOS_HEADER_140000000.e_magic + lVar4) == 0x4550) &&
       (uVar2 = 0x20b,
       *(short *)((longlong)IMAGE_DOS_HEADER_140000000.e_res_4_ + lVar4 + -4) == 0x20b)) {
      pwVar5 = (word *)(IMAGE_DOS_HEADER_140000000.e_magic + lVar4 +
                       (ulonglong)
                       *(ushort *)((longlong)IMAGE_DOS_HEADER_140000000.e_res_4_ + lVar4 + -8) +
                       0x18);
      uVar2 = (ulonglong)*(ushort *)(IMAGE_DOS_HEADER_140000000.e_magic + lVar4 + 6);
      pwVar1 = pwVar5 + uVar2 * 0x14;
      for (; pwVar5 != pwVar1; pwVar5 = pwVar5 + 0x14) {
        if (((ulonglong)*(uint *)(pwVar5 + 6) <= param_1 - 0x140000000U) &&
           (uVar2 = (ulonglong)(*(int *)(pwVar5 + 4) + *(uint *)(pwVar5 + 6)),
           param_1 - 0x140000000U < uVar2)) goto LAB_1400013fe;
      }
      pwVar5 = (word *)0x0;
LAB_1400013fe:
      if (pwVar5 == (word *)0x0) {
        return uVar2 & 0xffffffffffffff00;
      }
      uVar3 = (uint7)(uVar2 >> 8);
      if (*(int *)(pwVar5 + 0x12) < 0) {
        return (ulonglong)uVar3 << 8;
      }
      return CONCAT71(uVar3,1);
    }
  }
  return uVar2 & 0xffffffffffffff00;
}



/*****************************************************************************
 * Function: _onexit
 * Address: 140001470
 * Size: 58 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _onexit
   
   Library: Visual Studio 2019 Release */

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_140018aa0 == -1) {
    iVar1 = FUN_140005d34(_Func);
  }
  else {
    iVar1 = _register_onexit_function(&DAT_140018aa0,_Func);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}



/*****************************************************************************
 * Function: atexit
 * Address: 1400014ac
 * Size: 23 bytes
 *****************************************************************************/


/* Library Function - Single Match
    atexit
   
   Library: Visual Studio 2019 Release */

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



/*****************************************************************************
 * Function: FUN_140001570
 * Address: 140001570
 * Size: 3 bytes
 *****************************************************************************/


undefined8 FUN_140001570(void)

{
  return 0;
}



/*****************************************************************************
 * Function: FUN_140001574
 * Address: 140001574
 * Size: 6 bytes
 *****************************************************************************/


undefined8 FUN_140001574(void)

{
  return 1;
}



/*****************************************************************************
 * Function: FUN_14000157c
 * Address: 14000157c
 * Size: 6 bytes
 *****************************************************************************/


undefined8 FUN_14000157c(void)

{
  return 0x4000;
}



/*****************************************************************************
 * Function: FUN_140001584
 * Address: 140001584
 * Size: 14 bytes
 *****************************************************************************/


void FUN_140001584(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000158b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&DAT_140018ad0);
  return;
}



/*****************************************************************************
 * Function: FUN_140001594
 * Address: 140001594
 * Size: 3 bytes
 *****************************************************************************/


undefined1 FUN_140001594(void)

{
  return 1;
}



/*****************************************************************************
 * Function: _guard_check_icall
 * Address: 140001598
 * Size: 3 bytes
 *****************************************************************************/


void _guard_check_icall(void)

{
  return;
}



/*****************************************************************************
 * Function: FUN_14000159c
 * Address: 14000159c
 * Size: 8 bytes
 *****************************************************************************/


undefined * FUN_14000159c(void)

{
  return &DAT_140018ae0;
}



/*****************************************************************************
 * Function: FUN_1400015a4
 * Address: 1400015a4
 * Size: 8 bytes
 *****************************************************************************/


undefined * FUN_1400015a4(void)

{
  return &DAT_140018ae8;
}



/*****************************************************************************
 * Function: FUN_1400015ac
 * Address: 1400015ac
 * Size: 27 bytes
 *****************************************************************************/


void FUN_1400015ac(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_14000159c();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)FUN_1400015a4();
  *puVar1 = *puVar1 | 2;
  return;
}



/*****************************************************************************
 * Function: FUN_1400015c8
 * Address: 1400015c8
 * Size: 12 bytes
 *****************************************************************************/


bool FUN_1400015c8(void)

{
  return DAT_140018014 == 0;
}



/*****************************************************************************
 * Function: FUN_1400015d4
 * Address: 1400015d4
 * Size: 8 bytes
 *****************************************************************************/


undefined * FUN_1400015d4(void)

{
  return &DAT_140019d20;
}



/*****************************************************************************
 * Function: FUN_1400015dc
 * Address: 1400015dc
 * Size: 8 bytes
 *****************************************************************************/


undefined * FUN_1400015dc(void)

{
  return &DAT_140019d18;
}



/*****************************************************************************
 * Function: FUN_1400015e4
 * Address: 1400015e4
 * Size: 8 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400015e4(void)

{
  _DAT_140018af0 = 0;
  return;
}



/*****************************************************************************
 * Function: FUN_1400015ec
 * Address: 1400015ec
 * Size: 331 bytes
 *****************************************************************************/


void FUN_1400015ec(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  LONG LVar3;
  PRUNTIME_FUNCTION FunctionEntry;
  undefined1 *puVar4;
  undefined8 unaff_retaddr;
  DWORD64 local_res10;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  undefined1 auStack_5c8 [8];
  undefined1 auStack_5c0 [232];
  undefined1 local_4d8 [152];
  undefined1 *local_440;
  DWORD64 local_3e0;
  
  puVar4 = auStack_5c8;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar4 = auStack_5c0;
  }
  *(undefined8 *)(puVar4 + -8) = 0x140001620;
  FUN_1400015e4();
  *(undefined8 *)(puVar4 + -8) = 0x140001631;
  FUN_140001e70((undefined1 (*) [32])local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x14000163b;
  RtlCaptureContext(local_4d8);
  *(undefined8 *)(puVar4 + -8) = 0x140001655;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    *(undefined1 **)(puVar4 + 0x30) = local_res18;
    *(undefined1 **)(puVar4 + 0x28) = local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x140001696;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = &stack0x00000008;
  *(undefined8 *)(puVar4 + -8) = 0x1400016c8;
  FUN_140001e70((undefined1 (*) [32])(puVar4 + 0x50),0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x1400016ea;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x14000170b;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x140001716;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x140001726;
    FUN_1400015e4();
  }
  return;
}



/*****************************************************************************
 * Function: thunk_FUN_140001570
 * Address: 140001774
 * Size: 5 bytes
 *****************************************************************************/


undefined8 thunk_FUN_140001570(void)

{
  return 0;
}



/*****************************************************************************
 * Function: FUN_14000177c
 * Address: 14000177c
 * Size: 81 bytes
 *****************************************************************************/


ulonglong FUN_14000177c(void)

{
  HMODULE pHVar1;
  ulonglong uVar2;
  int *piVar3;
  
  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  if ((((pHVar1 == (HMODULE)0x0) || ((short)pHVar1->unused != 0x5a4d)) ||
      (piVar3 = (int *)((longlong)&pHVar1->unused + (longlong)pHVar1[0xf].unused), *piVar3 != 0x4550
      )) || ((pHVar1 = (HMODULE)0x20b, (short)piVar3[6] != 0x20b || ((uint)piVar3[0x21] < 0xf)))) {
    uVar2 = (ulonglong)pHVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = CONCAT71(2,piVar3[0x3e] != 0);
  }
  return uVar2;
}



/*****************************************************************************
 * Function: FUN_1400017d0
 * Address: 1400017d0
 * Size: 14 bytes
 *****************************************************************************/


void FUN_1400017d0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400017d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetUnhandledExceptionFilter(__scrt_unhandled_exception_filter);
  return;
}



/*****************************************************************************
 * Function: FUN_14000183c
 * Address: 14000183c
 * Size: 60 bytes
 *****************************************************************************/


void FUN_14000183c(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_140015fc8; plVar1 < &DAT_140015fc8; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_14000e260)();
    }
  }
  return;
}



/*****************************************************************************
 * Function: FUN_140001878
 * Address: 140001878
 * Size: 60 bytes
 *****************************************************************************/


void FUN_140001878(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_140015fd8; plVar1 < &DAT_140015fd8; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_14000e260)();
    }
  }
  return;
}



/*****************************************************************************
 * Function: FUN_1400018b4
 * Address: 1400018b4
 * Size: 428 bytes
 *****************************************************************************/


/* WARNING: Removing unreachable block (ram,0x00014000197e) */
/* WARNING: Removing unreachable block (ram,0x0001400018ee) */
/* WARNING: Removing unreachable block (ram,0x0001400018c7) */

undefined8 FUN_1400018b4(void)

{
  int *piVar1;
  uint *puVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  uVar6 = 0;
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar4 = puVar2[3];
  if ((piVar1[2] == 0x49656e69 && piVar1[3] == 0x6c65746e) && piVar1[1] == 0x756e6547) {
    DAT_140018028 = 0xffffffffffffffff;
    uVar5 = *puVar2 & 0xfff3ff0;
    DAT_140018020 = 0x8000;
    if ((((uVar5 == 0x106c0) || (uVar5 == 0x20660)) || (uVar5 == 0x20670)) ||
       ((uVar5 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar5 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_140018af4 = DAT_140018af4 | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar6 = *(uint *)(lVar3 + 4);
    if ((uVar6 >> 9 & 1) != 0) {
      DAT_140018af4 = DAT_140018af4 | 2;
    }
  }
  DAT_140018018 = 1;
  DAT_14001801c = 2;
  if ((uVar4 >> 0x14 & 1) != 0) {
    DAT_140018018 = 2;
    DAT_14001801c = 6;
    if ((((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) && ((in_XCR0 & 6) == 6)) {
      DAT_14001801c = 0xe;
      DAT_140018018 = 3;
      if ((uVar6 & 0x20) != 0) {
        DAT_140018018 = 5;
        DAT_14001801c = 0x2e;
        if (((uVar6 & 0xd0030000) == 0xd0030000) && ((in_XCR0 & 0xe0) == 0xe0)) {
          DAT_14001801c = 0x6e;
          DAT_140018018 = 6;
        }
      }
    }
  }
  return 0;
}



/*****************************************************************************
 * Function: FUN_140001a70
 * Address: 140001a70
 * Size: 503 bytes
 *****************************************************************************/


undefined8 FUN_140001a70(PEXCEPTION_RECORD param_1,PVOID param_2,longlong param_3,longlong *param_4)

{
  uint uVar1;
  longlong lVar2;
  uint *puVar3;
  int iVar4;
  BOOL BVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  uint uVar11;
  ulonglong uVar12;
  PEXCEPTION_RECORD local_38;
  longlong local_30;
  
  __except_validate_context_record(param_3);
  lVar2 = param_4[1];
  puVar3 = (uint *)param_4[7];
  uVar12 = *param_4 - lVar2;
  uVar8 = *(uint *)(param_4 + 9);
  local_38 = param_1;
  local_30 = param_3;
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    for (; uVar8 < *puVar3; uVar8 = uVar8 + 1) {
      uVar7 = (ulonglong)uVar8;
      if (((puVar3[uVar7 * 4 + 1] <= uVar12) && (uVar12 < puVar3[uVar7 * 4 + 2])) &&
         (puVar3[uVar7 * 4 + 4] != 0)) {
        if (puVar3[uVar7 * 4 + 3] != 1) {
          iVar4 = (*(code *)((ulonglong)puVar3[uVar7 * 4 + 3] + lVar2))(&local_38,param_2);
          if (iVar4 < 0) {
            return 0;
          }
          if (iVar4 < 1) goto LAB_140001b8a;
        }
        if (((param_1->ExceptionCode == 0xe06d7363) &&
            (PTR___DestructExceptionObject_14000e350 != (undefined *)0x0)) &&
           (BVar5 = _IsNonwritableInCurrentImage((PBYTE)&PTR___DestructExceptionObject_14000e350),
           BVar5 != 0)) {
          (*(code *)PTR___DestructExceptionObject_14000e350)(param_1,1);
        }
        _NLG_Notify();
        RtlUnwindEx(param_2,(PVOID)((ulonglong)puVar3[uVar7 * 4 + 4] + lVar2),param_1,
                    (PVOID)(ulonglong)param_1->ExceptionCode,(PCONTEXT)param_4[5],
                    (PUNWIND_HISTORY_TABLE)param_4[8]);
        FUN_140002240();
      }
LAB_140001b8a:
    }
  }
  else {
    uVar7 = param_4[4] - lVar2;
    for (; uVar1 = *puVar3, uVar8 < uVar1; uVar8 = uVar8 + 1) {
      uVar6 = (ulonglong)uVar8;
      if ((puVar3[uVar6 * 4 + 1] <= uVar12) && (uVar12 < puVar3[uVar6 * 4 + 2])) {
        uVar11 = param_1->ExceptionFlags & 0x20;
        if (uVar11 != 0) {
          uVar10 = 0;
          if (uVar1 != 0) {
            do {
              if ((((puVar3[uVar10 * 4 + 1] <= uVar7) && (uVar7 < puVar3[uVar10 * 4 + 2])) &&
                  (puVar3[uVar10 * 4 + 4] == puVar3[uVar6 * 4 + 4])) &&
                 (puVar3[uVar10 * 4 + 3] == puVar3[uVar6 * 4 + 3])) break;
              uVar9 = (int)uVar10 + 1;
              uVar10 = (ulonglong)uVar9;
            } while (uVar9 < uVar1);
          }
          if ((uint)uVar10 != uVar1) {
            return 1;
          }
        }
        if (puVar3[uVar6 * 4 + 4] == 0) {
          *(uint *)(param_4 + 9) = uVar8 + 1;
          (*(code *)((ulonglong)puVar3[uVar6 * 4 + 3] + lVar2))
                    (CONCAT71((int7)(uVar6 * 2 >> 8),1),param_2);
        }
        else if ((uVar7 == puVar3[uVar6 * 4 + 4]) && (uVar11 != 0)) {
          return 1;
        }
      }
    }
  }
  return 1;
}



/*****************************************************************************
 * Function: FUN_140001d44
 * Address: 140001d44
 * Size: 3 bytes
 *****************************************************************************/


void FUN_140001d44(undefined8 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
                    /* WARNING: Could not recover jumptable at 0x000140001d44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



/*****************************************************************************
 * Function: _IsExceptionObjectToBeDestroyed
 * Address: 140001d48
 * Size: 47 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _IsExceptionObjectToBeDestroyed
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 _IsExceptionObjectToBeDestroyed(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  
  lVar1 = __vcrt_getptd();
  plVar2 = *(longlong **)(lVar1 + 0x58);
  while( true ) {
    if (plVar2 == (longlong *)0x0) {
      return 1;
    }
    if (*plVar2 == param_1) break;
    plVar2 = (longlong *)plVar2[1];
  }
  return 0;
}



/*****************************************************************************
 * Function: Unwind@140001e2c
 * Address: 140001e2c
 * Size: 10 bytes
 *****************************************************************************/


void Unwind_140001e2c(void)

{
  code *pcVar1;
  
  FUN_140005f70();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/*****************************************************************************
 * Function: FUN_140001e50
 * Address: 140001e50
 * Size: 16 bytes
 *****************************************************************************/


undefined8 FUN_140001e50(undefined1 *param_1,undefined1 param_2,longlong param_3,undefined8 param_4)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_1 = param_2;
    param_1 = param_1 + 1;
  }
  return param_4;
}



/*****************************************************************************
 * Function: FUN_140001e70
 * Address: 140001e70
 * Size: 725 bytes
 *****************************************************************************/


undefined1 (*) [32] FUN_140001e70(undefined1 (*param_1) [32],byte param_2,ulonglong param_3)

{
  undefined1 auVar1 [32];
  undefined1 (*pauVar2) [32];
  undefined1 (*pauVar3) [32];
  undefined1 (*pauVar4) [16];
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined1 uVar8;
  longlong lVar11;
  undefined1 auVar12 [16];
  undefined1 auVar13 [32];
  undefined2 uVar9;
  undefined4 uVar10;
  
  uVar5 = (ulonglong)param_2;
  lVar11 = uVar5 * 0x101010101010101;
  uVar8 = (undefined1)lVar11;
  uVar9 = (undefined2)lVar11;
  uVar10 = (undefined4)lVar11;
  switch(param_3) {
  case 0:
    return param_1;
  case 8:
    *(longlong *)(param_1[-1] + param_3 + 0x18) = lVar11;
    return param_1;
  case 9:
    *(longlong *)(param_1[-1] + param_3 + 0x17) = lVar11;
    param_1[-1][param_3 + 0x1f] = uVar8;
    return param_1;
  case 10:
    *(longlong *)(param_1[-1] + param_3 + 0x16) = lVar11;
    *(undefined2 *)(param_1[-1] + param_3 + 0x1e) = uVar9;
    return param_1;
  case 0xb:
    *(longlong *)(param_1[-1] + param_3 + 0x15) = lVar11;
    *(undefined2 *)(param_1[-1] + param_3 + 0x1d) = uVar9;
    param_1[-1][param_3 + 0x1f] = uVar8;
    return param_1;
  case 0xc:
    *(longlong *)(param_1[-1] + param_3 + 0x14) = lVar11;
  case 4:
    *(undefined4 *)(param_1[-1] + param_3 + 0x1c) = uVar10;
    return param_1;
  case 0xd:
    *(longlong *)(param_1[-1] + param_3 + 0x13) = lVar11;
  case 5:
    *(undefined4 *)(param_1[-1] + param_3 + 0x1b) = uVar10;
    param_1[-1][param_3 + 0x1f] = uVar8;
    return param_1;
  case 0xe:
    *(longlong *)(param_1[-1] + param_3 + 0x12) = lVar11;
  case 6:
    *(undefined4 *)(param_1[-1] + param_3 + 0x1a) = uVar10;
  case 2:
    *(undefined2 *)(param_1[-1] + param_3 + 0x1e) = uVar9;
    return param_1;
  case 0xf:
    *(longlong *)(param_1[-1] + param_3 + 0x11) = lVar11;
  case 7:
    *(undefined4 *)(param_1[-1] + param_3 + 0x19) = uVar10;
  case 3:
    *(undefined2 *)(param_1[-1] + param_3 + 0x1d) = uVar9;
  case 1:
    param_1[-1][param_3 + 0x1f] = uVar8;
    return param_1;
  }
  auVar12._8_8_ = lVar11;
  auVar12._0_8_ = lVar11;
  if (param_3 < 0x21) {
    *(undefined1 (*) [16])*param_1 = auVar12;
    *(undefined1 (*) [16])(param_1[-1] + param_3 + 0x10) = auVar12;
    return param_1;
  }
  pauVar2 = param_1;
  if (DAT_140018018 < 3) {
    if ((param_3 <= DAT_140018020) || (((byte)DAT_140018af4 & 2) == 0)) {
      lVar11 = ((ulonglong)param_1 & 0xf) - 0x10;
      pauVar4 = (undefined1 (*) [16])((longlong)param_1 - lVar11);
      uVar6 = param_3 + lVar11;
      if (0x80 < uVar6) {
        do {
          *pauVar4 = auVar12;
          pauVar4[1] = auVar12;
          pauVar4[2] = auVar12;
          pauVar4[3] = auVar12;
          pauVar4[4] = auVar12;
          pauVar4[5] = auVar12;
          pauVar4[6] = auVar12;
          pauVar4[7] = auVar12;
          pauVar4 = pauVar4 + 8;
          uVar6 = uVar6 - 0x80;
        } while (0x7f < uVar6);
      }
                    /* WARNING: Could not recover jumptable at 0x0001400021b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pauVar2 = (undefined1 (*) [32])
                (*(code *)(IMAGE_DOS_HEADER_140000000.e_magic +
                          *(uint *)(&DAT_14001b088 + (uVar6 + 0xf >> 4) * 4)))
                          (pauVar4,uVar5 - lVar11);
      return pauVar2;
    }
  }
  else if (((param_3 <= DAT_140018020) || (DAT_140018028 < param_3)) ||
          (((byte)DAT_140018af4 & 2) == 0)) {
    auVar13._16_16_ = auVar12;
    auVar13._0_16_ = auVar12;
    lVar7 = ((ulonglong)param_1 & 0x1f) - 0x20;
    pauVar2 = (undefined1 (*) [32])((longlong)param_1 - lVar7);
    uVar6 = param_3 + lVar7;
    if (0x100 < uVar6) {
      if (DAT_140018028 < uVar6) {
        do {
          uVar5 = uVar6;
          pauVar3 = pauVar2;
          auVar1 = vmovntdq_avx(auVar13);
          *pauVar3 = auVar1;
          auVar1 = vmovntdq_avx(auVar13);
          pauVar3[1] = auVar1;
          auVar1 = vmovntdq_avx(auVar13);
          pauVar3[2] = auVar1;
          auVar1 = vmovntdq_avx(auVar13);
          pauVar3[3] = auVar1;
          auVar1 = vmovntdq_avx(auVar13);
          pauVar3[4] = auVar1;
          auVar1 = vmovntdq_avx(auVar13);
          pauVar3[5] = auVar1;
          auVar1 = vmovntdq_avx(auVar13);
          pauVar3[6] = auVar1;
          auVar1 = vmovntdq_avx(auVar13);
          pauVar3[7] = auVar1;
          pauVar2 = pauVar3 + 8;
          uVar6 = uVar5 - 0x100;
        } while (0xff < uVar5 - 0x100);
        uVar6 = uVar5 - 0xe1 & 0xffffffffffffffe0;
        switch(uVar5) {
        case 0x1e1:
        case 0x1e2:
        case 0x1e3:
        case 0x1e4:
        case 0x1e5:
        case 0x1e6:
        case 0x1e7:
        case 0x1e8:
        case 0x1e9:
        case 0x1ea:
        case 0x1eb:
        case 0x1ec:
        case 0x1ed:
        case 0x1ee:
        case 0x1ef:
        case 0x1f0:
        case 0x1f1:
        case 0x1f2:
        case 499:
        case 500:
        case 0x1f5:
        case 0x1f6:
        case 0x1f7:
        case 0x1f8:
        case 0x1f9:
        case 0x1fa:
        case 0x1fb:
        case 0x1fc:
        case 0x1fd:
        case 0x1fe:
        case 0x1ff:
          auVar1 = vmovntdq_avx(auVar13);
          *(undefined1 (*) [32])(*pauVar3 + uVar6) = auVar1;
        case 0x1c1:
        case 0x1c2:
        case 0x1c3:
        case 0x1c4:
        case 0x1c5:
        case 0x1c6:
        case 0x1c7:
        case 0x1c8:
        case 0x1c9:
        case 0x1ca:
        case 0x1cb:
        case 0x1cc:
        case 0x1cd:
        case 0x1ce:
        case 0x1cf:
        case 0x1d0:
        case 0x1d1:
        case 0x1d2:
        case 0x1d3:
        case 0x1d4:
        case 0x1d5:
        case 0x1d6:
        case 0x1d7:
        case 0x1d8:
        case 0x1d9:
        case 0x1da:
        case 0x1db:
        case 0x1dc:
        case 0x1dd:
        case 0x1de:
        case 0x1df:
        case 0x1e0:
          auVar1 = vmovntdq_avx(auVar13);
          *(undefined1 (*) [32])(pauVar3[1] + uVar6) = auVar1;
        case 0x1a1:
        case 0x1a2:
        case 0x1a3:
        case 0x1a4:
        case 0x1a5:
        case 0x1a6:
        case 0x1a7:
        case 0x1a8:
        case 0x1a9:
        case 0x1aa:
        case 0x1ab:
        case 0x1ac:
        case 0x1ad:
        case 0x1ae:
        case 0x1af:
        case 0x1b0:
        case 0x1b1:
        case 0x1b2:
        case 0x1b3:
        case 0x1b4:
        case 0x1b5:
        case 0x1b6:
        case 0x1b7:
        case 0x1b8:
        case 0x1b9:
        case 0x1ba:
        case 0x1bb:
        case 0x1bc:
        case 0x1bd:
        case 0x1be:
        case 0x1bf:
        case 0x1c0:
          auVar1 = vmovntdq_avx(auVar13);
          *(undefined1 (*) [32])(pauVar3[2] + uVar6) = auVar1;
        case 0x181:
        case 0x182:
        case 0x183:
        case 0x184:
        case 0x185:
        case 0x186:
        case 0x187:
        case 0x188:
        case 0x189:
        case 0x18a:
        case 0x18b:
        case 0x18c:
        case 0x18d:
        case 0x18e:
        case 399:
        case 400:
        case 0x191:
        case 0x192:
        case 0x193:
        case 0x194:
        case 0x195:
        case 0x196:
        case 0x197:
        case 0x198:
        case 0x199:
        case 0x19a:
        case 0x19b:
        case 0x19c:
        case 0x19d:
        case 0x19e:
        case 0x19f:
        case 0x1a0:
          auVar1 = vmovntdq_avx(auVar13);
          *(undefined1 (*) [32])(pauVar3[3] + uVar6) = auVar1;
        case 0x161:
        case 0x162:
        case 0x163:
        case 0x164:
        case 0x165:
        case 0x166:
        case 0x167:
        case 0x168:
        case 0x169:
        case 0x16a:
        case 0x16b:
        case 0x16c:
        case 0x16d:
        case 0x16e:
        case 0x16f:
        case 0x170:
        case 0x171:
        case 0x172:
        case 0x173:
        case 0x174:
        case 0x175:
        case 0x176:
        case 0x177:
        case 0x178:
        case 0x179:
        case 0x17a:
        case 0x17b:
        case 0x17c:
        case 0x17d:
        case 0x17e:
        case 0x17f:
        case 0x180:
          auVar1 = vmovntdq_avx(auVar13);
          *(undefined1 (*) [32])(pauVar3[4] + uVar6) = auVar1;
        case 0x141:
        case 0x142:
        case 0x143:
        case 0x144:
        case 0x145:
        case 0x146:
        case 0x147:
        case 0x148:
        case 0x149:
        case 0x14a:
        case 0x14b:
        case 0x14c:
        case 0x14d:
        case 0x14e:
        case 0x14f:
        case 0x150:
        case 0x151:
        case 0x152:
        case 0x153:
        case 0x154:
        case 0x155:
        case 0x156:
        case 0x157:
        case 0x158:
        case 0x159:
        case 0x15a:
        case 0x15b:
        case 0x15c:
        case 0x15d:
        case 0x15e:
        case 0x15f:
        case 0x160:
          auVar1 = vmovntdq_avx(auVar13);
          *(undefined1 (*) [32])(pauVar3[5] + uVar6) = auVar1;
        case 0x121:
        case 0x122:
        case 0x123:
        case 0x124:
        case 0x125:
        case 0x126:
        case 0x127:
        case 0x128:
        case 0x129:
        case 0x12a:
        case 299:
        case 300:
        case 0x12d:
        case 0x12e:
        case 0x12f:
        case 0x130:
        case 0x131:
        case 0x132:
        case 0x133:
        case 0x134:
        case 0x135:
        case 0x136:
        case 0x137:
        case 0x138:
        case 0x139:
        case 0x13a:
        case 0x13b:
        case 0x13c:
        case 0x13d:
        case 0x13e:
        case 0x13f:
        case 0x140:
          auVar1 = vmovntdq_avx(auVar13);
          *(undefined1 (*) [32])(pauVar3[6] + uVar6) = auVar1;
        default:
          *(undefined1 (*) [32])(pauVar3[-1] + uVar5) = auVar13;
        case 0x100:
          *param_1 = auVar13;
          return param_1;
        }
      }
      do {
        *pauVar2 = auVar13;
        pauVar2[1] = auVar13;
        pauVar2[2] = auVar13;
        pauVar2[3] = auVar13;
        pauVar2[4] = auVar13;
        pauVar2[5] = auVar13;
        pauVar2[6] = auVar13;
        pauVar2[7] = auVar13;
        pauVar2 = pauVar2 + 8;
        uVar6 = uVar6 - 0x100;
      } while (0xff < uVar6);
    }
                    /* WARNING: Could not recover jumptable at 0x000140002004. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pauVar2 = (undefined1 (*) [32])
              (*(code *)(IMAGE_DOS_HEADER_140000000.e_magic +
                        *(uint *)(&DAT_14001b040 + (uVar6 + 0x1f >> 5) * 4)))(lVar11,uVar5 - lVar7);
    return pauVar2;
  }
  for (; param_3 != 0; param_3 = param_3 - 1) {
    (*pauVar2)[0] = param_2;
    pauVar2 = (undefined1 (*) [32])(*pauVar2 + 1);
  }
  return param_1;
}



/*****************************************************************************
 * Function: _NLG_Notify
 * Address: 140002210
 * Size: 24 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _NLG_Notify
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void _NLG_Notify(void)

{
  FUN_140002230();
  return;
}



/*****************************************************************************
 * Function: FUN_140002230
 * Address: 140002230
 * Size: 1 bytes
 *****************************************************************************/


void FUN_140002230(void)

{
  return;
}



/*****************************************************************************
 * Function: FUN_140002240
 * Address: 140002240
 * Size: 1 bytes
 *****************************************************************************/


void FUN_140002240(void)

{
  return;
}



/*****************************************************************************
 * Function: FUN_14000227c
 * Address: 14000227c
 * Size: 31 bytes
 *****************************************************************************/


void FUN_14000227c(undefined *param_1)

{
  if ((param_1 != (undefined *)0x0) && (param_1 != &DAT_140018b00)) {
    FUN_140005f9c(param_1);
  }
  return;
}



/*****************************************************************************
 * Function: FUN_140002464
 * Address: 140002464
 * Size: 334 bytes
 *****************************************************************************/


FARPROC FUN_140002464(uint param_1,LPCSTR param_2,uint *param_3,uint *param_4)

{
  longlong lVar1;
  wchar_t *lpLibFileName;
  DWORD DVar2;
  int iVar3;
  HMODULE hLibModule;
  FARPROC pFVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  bool bVar7;
  
  uVar6 = (ulonglong)param_1;
  pFVar4 = *(FARPROC *)(&DAT_140018c30 + uVar6 * 8);
  if (pFVar4 != (FARPROC)0xffffffffffffffff) {
    if (pFVar4 != (FARPROC)0x0) {
      return pFVar4;
    }
    bVar7 = param_3 == param_4;
    while (!bVar7) {
      uVar5 = (ulonglong)*param_3;
      hLibModule = *(HMODULE *)(&DAT_140018c18 + uVar5 * 8);
      if (hLibModule == (HMODULE)0x0) {
        lpLibFileName = (wchar_t *)(&PTR_u_api_ms_win_core_fibers_l1_1_1_14000f138)[uVar5];
        hLibModule = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0x800);
        if ((hLibModule != (HMODULE)0x0) ||
           (((DVar2 = GetLastError(), DVar2 == 0x57 &&
             (iVar3 = wcsncmp(lpLibFileName,L"api-ms-",7), iVar3 != 0)) &&
            (hLibModule = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0), hLibModule != (HMODULE)0x0)))
           ) {
          LOCK();
          lVar1 = *(longlong *)(&DAT_140018c18 + uVar5 * 8);
          *(HMODULE *)(&DAT_140018c18 + uVar5 * 8) = hLibModule;
          UNLOCK();
          if (lVar1 != 0) {
            FreeLibrary(hLibModule);
          }
          goto LAB_14000256d;
        }
        LOCK();
        *(undefined8 *)(&DAT_140018c18 + uVar5 * 8) = 0xffffffffffffffff;
        UNLOCK();
      }
      else if (hLibModule != (HMODULE)0xffffffffffffffff) {
LAB_14000256d:
        pFVar4 = GetProcAddress(hLibModule,param_2);
        if (pFVar4 != (FARPROC)0x0) {
          LOCK();
          *(FARPROC *)(&DAT_140018c30 + uVar6 * 8) = pFVar4;
          UNLOCK();
          return pFVar4;
        }
        break;
      }
      param_3 = param_3 + 1;
      bVar7 = param_3 == param_4;
    }
    LOCK();
    *(undefined8 *)(&DAT_140018c30 + uVar6 * 8) = 0xffffffffffffffff;
    UNLOCK();
  }
  return (FARPROC)0x0;
}



/*****************************************************************************
 * Function: _CallSETranslator<>
 * Address: 140002744
 * Size: 81 bytes
 *****************************************************************************/


/* Library Function - Multiple Matches With Same Base Name
    int __cdecl _CallSETranslator<class __FrameHandler3>(struct EHExceptionRecord * __ptr64,unsigned
   __int64 * __ptr64,struct _CONTEXT * __ptr64,struct _xDISPATCHER_CONTEXT * __ptr64,struct
   _s_FuncInfo const * __ptr64,unsigned long,unsigned __int64 * __ptr64)
    int __cdecl _CallSETranslator<class __FrameHandler3>(struct EHExceptionRecord * __ptr64,unsigned
   __int64 * __ptr64,struct _CONTEXT * __ptr64,struct _xDISPATCHER_CONTEXT * __ptr64,struct
   _s_FuncInfo const * __ptr64,unsigned long,unsigned __int64 * __ptr64,int)
    int __cdecl _CallSETranslator<class __FrameHandler4>(struct EHExceptionRecord * __ptr64,unsigned
   __int64 * __ptr64,struct _CONTEXT * __ptr64,struct _xDISPATCHER_CONTEXT * __ptr64,struct
   FuncInfo4 * __ptr64,unsigned long,unsigned __int64 * __ptr64)
    int __cdecl _CallSETranslator<class __FrameHandler4>(struct EHExceptionRecord * __ptr64,unsigned
   __int64 * __ptr64,struct _CONTEXT * __ptr64,struct _xDISPATCHER_CONTEXT * __ptr64,struct
   FH4::FuncInfo4 * __ptr64,unsigned long,unsigned __int64 * __ptr64,int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 _CallSETranslator<>(undefined4 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 *local_20;
  undefined8 local_18;
  
  local_20 = param_1;
  local_18 = param_3;
  __vcrt_getptd();
  (*(code *)PTR__guard_dispatch_icall_14000e260)(*param_1,&local_20);
  return 0;
}



/*****************************************************************************
 * Function: FUN_140002798
 * Address: 140002798
 * Size: 98 bytes
 *****************************************************************************/


longlong FUN_140002798(longlong param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0xc);
  do {
    if (uVar2 == 0) {
      return 0;
    }
    uVar2 = uVar2 - 1;
    lVar1 = __vcrt_getptd();
    lVar1 = (longlong)*(int *)(param_1 + 0x10) +
            *(longlong *)(lVar1 + 0x60) + (ulonglong)uVar2 * 0x14;
  } while ((param_2 <= *(int *)(lVar1 + 4)) || (*(int *)(lVar1 + 8) < param_2));
  return lVar1;
}



/*****************************************************************************
 * Function: FUN_1400027fc
 * Address: 1400027fc
 * Size: 42 bytes
 *****************************************************************************/


bool FUN_1400027fc(ulonglong *param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = FUN_140003454(param_2,param_1);
  lVar2 = FUN_140002798(param_2,iVar1);
  return lVar2 != 0;
}



/*****************************************************************************
 * Function: FrameUnwindToEmptyState
 * Address: 140002828
 * Size: 100 bytes
 *****************************************************************************/


/* Library Function - Single Match
    public: static void __cdecl __FrameHandler3::FrameUnwindToEmptyState(unsigned __int64 *
   __ptr64,struct _xDISPATCHER_CONTEXT * __ptr64,struct _s_FuncInfo const * __ptr64)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl
__FrameHandler3::FrameUnwindToEmptyState
          (__uint64 *param_1,_xDISPATCHER_CONTEXT *param_2,_s_FuncInfo *param_3)

{
  int iVar1;
  __uint64 *p_Var2;
  longlong lVar3;
  longlong local_res20;
  
  p_Var2 = (__uint64 *)
           FUN_14000288c((longlong *)param_1,(ulonglong *)param_2,(longlong)param_3,&local_res20);
  iVar1 = FUN_140003454((longlong)param_3,(ulonglong *)param_2);
  lVar3 = FUN_140002798((longlong)param_3,iVar1);
  if (lVar3 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = *(int *)(lVar3 + 4);
  }
  FUN_140004628(p_Var2,(ulonglong *)param_2,param_3,iVar1);
  return;
}



/*****************************************************************************
 * Function: FUN_14000288c
 * Address: 14000288c
 * Size: 204 bytes
 *****************************************************************************/


longlong * FUN_14000288c(longlong *param_1,ulonglong *param_2,longlong param_3,longlong *param_4)

{
  uint uVar1;
  int iVar2;
  PRUNTIME_FUNCTION p_Var3;
  uint uVar4;
  ulonglong uVar5;
  int *piVar6;
  longlong lVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong local_res8;
  
  uVar8 = *(uint *)(param_3 + 0xc);
  iVar2 = FUN_140003454(param_3,param_2);
  *param_4 = *param_1;
  do {
    do {
      if (uVar8 == 0) {
        return param_4;
      }
      uVar8 = uVar8 - 1;
      lVar7 = (longlong)*(int *)(param_3 + 0x10) + (ulonglong)uVar8 * 0x14 + param_2[1];
    } while ((iVar2 <= *(int *)(lVar7 + 4)) || (*(int *)(lVar7 + 8) < iVar2));
    p_Var3 = RtlLookupFunctionEntry(*param_2,&local_res8,(PUNWIND_HISTORY_TABLE)0x0);
    uVar5 = 0;
    lVar9 = (longlong)*(int *)(lVar7 + 0x10) + local_res8;
    uVar1 = *(uint *)(lVar7 + 0xc);
    if (uVar1 != 0) {
      piVar6 = (int *)(lVar9 + 0xc);
      do {
        if ((longlong)*piVar6 == (ulonglong)p_Var3->BeginAddress) break;
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
        piVar6 = piVar6 + 5;
      } while (uVar4 < uVar1);
    }
    if ((uint)uVar5 < uVar1) {
      *param_4 = *(longlong *)((longlong)*(int *)(lVar9 + 0x10 + uVar5 * 0x14) + *param_1);
      return param_4;
    }
  } while( true );
}



/*****************************************************************************
 * Function: FUN_140002958
 * Address: 140002958
 * Size: 317 bytes
 *****************************************************************************/


undefined8 *
FUN_140002958(undefined8 *param_1,undefined8 param_2,int param_3,ulonglong *param_4,longlong param_5
             )

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  int iVar5;
  int *piVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  int iVar11;
  int iVar12;
  ulonglong uVar13;
  undefined4 uStack_3c;
  undefined4 uStack_2c;
  ulonglong uVar10;
  
  uVar3 = *(uint *)(param_5 + 0xc);
  iVar5 = FUN_140003454(param_5,param_4);
  uVar10 = 0;
  if (uVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  uVar4 = param_4[1];
  lVar8 = (longlong)*(int *)(param_5 + 0x10);
  iVar11 = -1;
  uVar13 = 0xffffffff;
  uVar9 = uVar3;
  do {
    uVar1 = uVar9 - 1;
    lVar2 = uVar4 + (ulonglong)uVar1 * 0x14;
    if ((*(int *)(lVar2 + 4 + lVar8) < iVar5) && (iVar5 <= *(int *)(lVar2 + 8 + lVar8))) break;
    uVar9 = uVar1;
  } while (uVar1 != 0);
  uVar7 = uVar10;
  if (uVar9 != 0) {
    uVar7 = lVar8 + (ulonglong)(uVar9 - 1) * 0x14 + uVar4;
  }
  piVar6 = (int *)(uVar4 + lVar8);
  do {
    iVar5 = iVar11;
    if ((((uVar7 == 0) || ((*(int *)(uVar7 + 4) < *piVar6 && (piVar6[1] <= *(int *)(uVar7 + 8)))))
        && (*piVar6 <= param_3)) &&
       ((param_3 <= piVar6[1] && (uVar13 = uVar10, iVar5 = (int)uVar10, iVar11 != -1)))) {
      iVar5 = iVar11;
    }
    iVar11 = iVar5;
    uVar9 = (int)uVar10 + 1;
    uVar10 = (ulonglong)uVar9;
    piVar6 = piVar6 + 5;
  } while (uVar9 < uVar3);
  iVar5 = 0;
  if (iVar11 != -1) {
    iVar5 = iVar11;
  }
  iVar12 = 0;
  if (iVar11 != -1) {
    iVar12 = (int)uVar13 + 1;
  }
  *param_1 = param_2;
  param_1[1] = CONCAT44(uStack_3c,iVar5);
  param_1[2] = param_2;
  param_1[3] = CONCAT44(uStack_2c,iVar12);
  return param_1;
}



/*****************************************************************************
 * Function: FUN_140002a98
 * Address: 140002a98
 * Size: 259 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140002a98(undefined8 *param_1,ULONG_PTR param_2,ULONG_PTR param_3,ULONG_PTR param_4,
                  ULONG_PTR param_5,ULONG_PTR param_6,int param_7,undefined8 param_8,
                  undefined8 param_9,undefined8 *param_10,byte param_11)

{
  undefined1 auStackY_e8 [32];
  EXCEPTION_RECORD local_b8;
  ulonglong local_18;
  
  local_18 = DAT_140018038 ^ (ulonglong)auStackY_e8;
  local_b8._0_8_ = _DAT_14000f280;
  local_b8.ExceptionRecord = _UNK_14000f288;
  local_b8.ExceptionAddress = _DAT_14000f290;
  local_b8._24_8_ = _UNK_14000f298;
  local_b8.ExceptionInformation[9] = _UNK_14000f2e8;
  local_b8.ExceptionInformation[10]._0_4_ = _DAT_14000f2f0;
  local_b8.ExceptionInformation[10]._4_4_ = _UNK_14000f2f4;
  local_b8.ExceptionInformation[0xb]._0_4_ = _UNK_14000f2f8;
  local_b8.ExceptionInformation[0xb]._4_4_ = _UNK_14000f2fc;
  local_b8.ExceptionInformation[0xc]._0_4_ = _DAT_14000f300;
  local_b8.ExceptionInformation[0xc]._4_4_ = _UNK_14000f304;
  local_b8.ExceptionInformation[0xd]._0_4_ = _UNK_14000f308;
  local_b8.ExceptionInformation[0xd]._4_4_ = _UNK_14000f30c;
  local_b8.ExceptionInformation[0xe] = DAT_14000f310;
  local_b8.ExceptionInformation[0] = (ULONG_PTR)__FrameHandler3::CxxCallCatchBlock;
  local_b8.ExceptionInformation[2] = param_5;
  local_b8.ExceptionInformation[3] = (ULONG_PTR)param_7;
  local_b8.ExceptionInformation[5] = param_6;
  local_b8.ExceptionInformation[7] = (ULONG_PTR)param_11;
  local_b8.ExceptionInformation[8] = 0x19930520;
  local_b8.ExceptionInformation[1] = param_4;
  local_b8.ExceptionInformation[4] = param_3;
  local_b8.ExceptionInformation[6] = param_2;
  RtlUnwindEx((PVOID)*param_1,(PVOID)*param_10,&local_b8,(PVOID)0x0,(PCONTEXT)param_10[5],
              (PUNWIND_HISTORY_TABLE)param_10[8]);
  FUN_14000d520(local_18 ^ (ulonglong)auStackY_e8);
  return;
}



/*****************************************************************************
 * Function: _CreateFrameInfo
 * Address: 140002b9c
 * Size: 58 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _CreateFrameInfo
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined8 * _CreateFrameInfo(undefined8 *param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  *param_1 = param_2;
  lVar1 = __vcrt_getptd();
  if (param_1 < *(undefined8 **)(lVar1 + 0x58)) {
    lVar1 = __vcrt_getptd();
    uVar2 = *(undefined8 *)(lVar1 + 0x58);
  }
  else {
    uVar2 = 0;
  }
  param_1[1] = uVar2;
  lVar1 = __vcrt_getptd();
  *(undefined8 **)(lVar1 + 0x58) = param_1;
  return param_1;
}



/*****************************************************************************
 * Function: _FindAndUnlinkFrame
 * Address: 140002bd8
 * Size: 82 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _FindAndUnlinkFrame
   
   Library: Visual Studio 2019 Release */

void _FindAndUnlinkFrame(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  
  lVar2 = __vcrt_getptd();
  if (param_1 == *(longlong *)(lVar2 + 0x58)) {
    lVar2 = __vcrt_getptd();
    lVar2 = *(longlong *)(lVar2 + 0x58);
    while (lVar2 != 0) {
      lVar1 = *(longlong *)(lVar2 + 8);
      bVar3 = param_1 == lVar2;
      lVar2 = lVar1;
      if (bVar3) {
        lVar2 = __vcrt_getptd();
        *(longlong *)(lVar2 + 0x58) = lVar1;
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  abort();
}



/*****************************************************************************
 * Function: _GetImageBase
 * Address: 140002c2c
 * Size: 18 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _GetImageBase
   
   Library: Visual Studio 2019 Release */

undefined8 _GetImageBase(void)

{
  longlong lVar1;
  
  lVar1 = __vcrt_getptd();
  return *(undefined8 *)(lVar1 + 0x60);
}



/*****************************************************************************
 * Function: _GetThrowImageBase
 * Address: 140002c40
 * Size: 18 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _GetThrowImageBase
   
   Library: Visual Studio 2019 Release */

undefined8 _GetThrowImageBase(void)

{
  longlong lVar1;
  
  lVar1 = __vcrt_getptd();
  return *(undefined8 *)(lVar1 + 0x68);
}



/*****************************************************************************
 * Function: FUN_140002c54
 * Address: 140002c54
 * Size: 24 bytes
 *****************************************************************************/


void FUN_140002c54(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = __vcrt_getptd();
  *(undefined8 *)(lVar1 + 0x60) = param_1;
  return;
}



/*****************************************************************************
 * Function: FUN_140002c6c
 * Address: 140002c6c
 * Size: 24 bytes
 *****************************************************************************/


void FUN_140002c6c(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = __vcrt_getptd();
  *(undefined8 *)(lVar1 + 0x68) = param_1;
  return;
}



/*****************************************************************************
 * Function: FUN_140002c84
 * Address: 140002c84
 * Size: 134 bytes
 *****************************************************************************/


void FUN_140002c84(EHExceptionRecord *param_1,__uint64 param_2,_CONTEXT *param_3,
                  _xDISPATCHER_CONTEXT *param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  __uint64 local_res8;
  
  uVar1 = *(undefined8 *)(param_4 + 8);
  local_res8 = param_2;
  lVar2 = __vcrt_getptd();
  *(undefined8 *)(lVar2 + 0x60) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x38);
  lVar2 = __vcrt_getptd();
  *(undefined8 *)(lVar2 + 0x68) = uVar1;
  lVar2 = __vcrt_getptd();
  thunk_FUN_14000408c(param_1,&local_res8,param_3,param_4,
                      (_s_FuncInfo *)
                      ((ulonglong)**(uint **)(param_4 + 0x38) + *(longlong *)(lVar2 + 0x60)),0,
                      (__uint64 *)0x0,0);
  return;
}



/*****************************************************************************
 * Function: FUN_140002d20
 * Address: 140002d20
 * Size: 16 bytes
 *****************************************************************************/


void FUN_140002d20(undefined1 *param_1,undefined1 *param_2,longlong param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}



/*****************************************************************************
 * Function: FUN_140002d40
 * Address: 140002d40
 * Size: 1363 bytes
 *****************************************************************************/


undefined8 * FUN_140002d40(undefined8 *param_1,undefined8 *param_2,ulonglong param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 auVar3 [32];
  undefined1 auVar4 [32];
  undefined1 auVar5 [32];
  undefined1 auVar6 [32];
  undefined1 uVar7;
  undefined2 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 *puVar23;
  undefined1 (*pauVar24) [32];
  undefined1 (*pauVar25) [32];
  undefined1 (*pauVar26) [32];
  undefined1 (*pauVar27) [32];
  undefined8 *puVar28;
  ulonglong uVar29;
  longlong lVar30;
  ulonglong uVar31;
  undefined8 uVar32;
  undefined8 uVar33;
  
  puVar23 = param_1;
  switch(param_3) {
  case 0:
    return puVar23;
  case 1:
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    return puVar23;
  case 2:
    *(undefined2 *)param_1 = *(undefined2 *)param_2;
    return puVar23;
  case 3:
    uVar7 = *(undefined1 *)((longlong)param_2 + 2);
    *(undefined2 *)param_1 = *(undefined2 *)param_2;
    *(undefined1 *)((longlong)param_1 + 2) = uVar7;
    return puVar23;
  case 4:
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    return puVar23;
  case 5:
    uVar7 = *(undefined1 *)((longlong)param_2 + 4);
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    *(undefined1 *)((longlong)param_1 + 4) = uVar7;
    return puVar23;
  case 6:
    uVar8 = *(undefined2 *)((longlong)param_2 + 4);
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    *(undefined2 *)((longlong)param_1 + 4) = uVar8;
    return puVar23;
  case 7:
    uVar8 = *(undefined2 *)((longlong)param_2 + 4);
    uVar7 = *(undefined1 *)((longlong)param_2 + 6);
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    *(undefined2 *)((longlong)param_1 + 4) = uVar8;
    *(undefined1 *)((longlong)param_1 + 6) = uVar7;
    return puVar23;
  case 8:
    *param_1 = *param_2;
    return puVar23;
  case 9:
    uVar7 = *(undefined1 *)(param_2 + 1);
    *param_1 = *param_2;
    *(undefined1 *)(param_1 + 1) = uVar7;
    return puVar23;
  case 10:
    uVar8 = *(undefined2 *)(param_2 + 1);
    *param_1 = *param_2;
    *(undefined2 *)(param_1 + 1) = uVar8;
    return puVar23;
  case 0xb:
    uVar8 = *(undefined2 *)(param_2 + 1);
    uVar7 = *(undefined1 *)((longlong)param_2 + 10);
    *param_1 = *param_2;
    *(undefined2 *)(param_1 + 1) = uVar8;
    *(undefined1 *)((longlong)param_1 + 10) = uVar7;
    return puVar23;
  case 0xc:
    uVar9 = *(undefined4 *)(param_2 + 1);
    *param_1 = *param_2;
    *(undefined4 *)(param_1 + 1) = uVar9;
    return puVar23;
  case 0xd:
    uVar9 = *(undefined4 *)(param_2 + 1);
    uVar7 = *(undefined1 *)((longlong)param_2 + 0xc);
    *param_1 = *param_2;
    *(undefined4 *)(param_1 + 1) = uVar9;
    *(undefined1 *)((longlong)param_1 + 0xc) = uVar7;
    return puVar23;
  case 0xe:
    uVar9 = *(undefined4 *)(param_2 + 1);
    uVar8 = *(undefined2 *)((longlong)param_2 + 0xc);
    *param_1 = *param_2;
    *(undefined4 *)(param_1 + 1) = uVar9;
    *(undefined2 *)((longlong)param_1 + 0xc) = uVar8;
    return puVar23;
  case 0xf:
    uVar9 = *(undefined4 *)(param_2 + 1);
    uVar8 = *(undefined2 *)((longlong)param_2 + 0xc);
    uVar7 = *(undefined1 *)((longlong)param_2 + 0xe);
    *param_1 = *param_2;
    *(undefined4 *)(param_1 + 1) = uVar9;
    *(undefined2 *)((longlong)param_1 + 0xc) = uVar8;
    *(undefined1 *)((longlong)param_1 + 0xe) = uVar7;
    return puVar23;
  }
  if (param_3 < 0x21) {
    uVar10 = param_2[1];
    puVar28 = (undefined8 *)((longlong)param_2 + (param_3 - 0x10));
    uVar11 = *puVar28;
    uVar32 = puVar28[1];
    *param_1 = *param_2;
    param_1[1] = uVar10;
    puVar28 = (undefined8 *)((longlong)param_1 + (param_3 - 0x10));
    *puVar28 = uVar11;
    puVar28[1] = uVar32;
    return puVar23;
  }
  if ((param_2 < param_1) && (param_1 < (undefined8 *)((longlong)param_2 + param_3))) {
    lVar30 = (longlong)param_2 - (longlong)param_1;
    puVar23 = (undefined8 *)((longlong)param_1 + lVar30 + (param_3 - 0x10));
    uVar10 = *puVar23;
    uVar11 = puVar23[1];
    puVar28 = (undefined8 *)((longlong)param_1 + (param_3 - 0x10));
    uVar29 = param_3 - 0x10;
    puVar23 = puVar28;
    uVar32 = uVar10;
    uVar33 = uVar11;
    if (((ulonglong)puVar28 & 0xf) != 0) {
      puVar23 = (undefined8 *)((ulonglong)puVar28 & 0xfffffffffffffff0);
      uVar32 = *(undefined8 *)((longlong)puVar23 + lVar30);
      uVar33 = ((undefined8 *)((longlong)puVar23 + lVar30))[1];
      *puVar28 = uVar10;
      *(undefined8 *)((longlong)param_1 + (param_3 - 8)) = uVar11;
      uVar29 = (longlong)puVar23 - (longlong)param_1;
    }
    uVar31 = uVar29 >> 7;
    if (uVar31 != 0) {
      *puVar23 = uVar32;
      puVar23[1] = uVar33;
      puVar28 = puVar23;
      while( true ) {
        puVar1 = (undefined8 *)((longlong)puVar28 + lVar30 + -0x10);
        uVar10 = puVar1[1];
        puVar23 = (undefined8 *)((longlong)puVar28 + lVar30 + -0x20);
        uVar11 = *puVar23;
        uVar32 = puVar23[1];
        puVar23 = puVar28 + -0x10;
        puVar28[-2] = *puVar1;
        puVar28[-1] = uVar10;
        puVar28[-4] = uVar11;
        puVar28[-3] = uVar32;
        puVar1 = (undefined8 *)((longlong)puVar28 + lVar30 + -0x30);
        uVar10 = puVar1[1];
        puVar2 = (undefined8 *)((longlong)puVar28 + lVar30 + -0x40);
        uVar11 = *puVar2;
        uVar32 = puVar2[1];
        uVar31 = uVar31 - 1;
        puVar28[-6] = *puVar1;
        puVar28[-5] = uVar10;
        puVar28[-8] = uVar11;
        puVar28[-7] = uVar32;
        puVar1 = (undefined8 *)((longlong)puVar28 + lVar30 + -0x50);
        uVar10 = puVar1[1];
        puVar2 = (undefined8 *)((longlong)puVar28 + lVar30 + -0x60);
        uVar11 = *puVar2;
        uVar32 = puVar2[1];
        puVar28[-10] = *puVar1;
        puVar28[-9] = uVar10;
        puVar28[-0xc] = uVar11;
        puVar28[-0xb] = uVar32;
        puVar1 = (undefined8 *)((longlong)puVar28 + lVar30 + -0x70);
        uVar10 = *puVar1;
        uVar11 = puVar1[1];
        uVar32 = *(undefined8 *)((longlong)puVar23 + lVar30);
        uVar33 = ((undefined8 *)((longlong)puVar23 + lVar30))[1];
        if (uVar31 == 0) break;
        puVar28[-0xe] = uVar10;
        puVar28[-0xd] = uVar11;
        *puVar23 = uVar32;
        puVar28[-0xf] = uVar33;
        puVar28 = puVar23;
      }
      puVar28[-0xe] = uVar10;
      puVar28[-0xd] = uVar11;
      uVar29 = uVar29 & 0x7f;
    }
    for (uVar31 = uVar29 >> 4; uVar31 != 0; uVar31 = uVar31 - 1) {
      *puVar23 = uVar32;
      puVar23[1] = uVar33;
      puVar23 = puVar23 + -2;
      uVar32 = *(undefined8 *)((longlong)puVar23 + lVar30);
      uVar33 = ((undefined8 *)((longlong)puVar23 + lVar30))[1];
    }
    if ((uVar29 & 0xf) != 0) {
      uVar10 = param_2[1];
      *param_1 = *param_2;
      param_1[1] = uVar10;
    }
    *puVar23 = uVar32;
    puVar23[1] = uVar33;
    return param_1;
  }
  if (DAT_140018018 < 3) {
    if ((param_3 < 0x801) || (((byte)DAT_140018af4 & 2) == 0)) {
      if (0x80 < param_3) {
        lVar30 = ((ulonglong)param_1 & 0xf) - 0x10;
        puVar23 = (undefined8 *)((longlong)param_1 - lVar30);
        puVar28 = (undefined8 *)((longlong)param_2 - lVar30);
        param_3 = param_3 + lVar30;
        if (0x80 < param_3) {
          do {
            uVar10 = puVar28[1];
            uVar11 = puVar28[2];
            uVar32 = puVar28[3];
            uVar33 = puVar28[4];
            uVar12 = puVar28[5];
            uVar13 = puVar28[6];
            uVar14 = puVar28[7];
            *puVar23 = *puVar28;
            puVar23[1] = uVar10;
            puVar23[2] = uVar11;
            puVar23[3] = uVar32;
            puVar23[4] = uVar33;
            puVar23[5] = uVar12;
            puVar23[6] = uVar13;
            puVar23[7] = uVar14;
            uVar10 = puVar28[9];
            uVar11 = puVar28[10];
            uVar32 = puVar28[0xb];
            uVar33 = puVar28[0xc];
            uVar12 = puVar28[0xd];
            uVar13 = puVar28[0xe];
            uVar14 = puVar28[0xf];
            puVar23[8] = puVar28[8];
            puVar23[9] = uVar10;
            puVar23[10] = uVar11;
            puVar23[0xb] = uVar32;
            puVar23[0xc] = uVar33;
            puVar23[0xd] = uVar12;
            puVar23[0xe] = uVar13;
            puVar23[0xf] = uVar14;
            puVar23 = puVar23 + 0x10;
            puVar28 = puVar28 + 0x10;
            param_3 = param_3 - 0x80;
          } while (0x7f < param_3);
        }
      }
                    /* WARNING: Could not recover jumptable at 0x000140003256. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      puVar23 = (undefined8 *)
                (*(code *)(IMAGE_DOS_HEADER_140000000.e_magic +
                          *(uint *)(&DAT_14001b138 + (param_3 + 0xf >> 4) * 4)))();
      return puVar23;
    }
  }
  else if (((param_3 < 0x2001) || (0x180000 < param_3)) || (((byte)DAT_140018af4 & 2) == 0)) {
    uVar10 = *param_2;
    uVar11 = param_2[1];
    uVar32 = param_2[2];
    uVar33 = param_2[3];
    puVar28 = (undefined8 *)((longlong)param_2 + (param_3 - 0x20));
    uVar12 = *puVar28;
    uVar13 = puVar28[1];
    uVar14 = puVar28[2];
    uVar15 = puVar28[3];
    if (0x100 < param_3) {
      lVar30 = ((ulonglong)param_1 & 0x1f) - 0x20;
      pauVar24 = (undefined1 (*) [32])((longlong)param_1 - lVar30);
      pauVar26 = (undefined1 (*) [32])((longlong)param_2 - lVar30);
      param_3 = param_3 + lVar30;
      if (0x100 < param_3) {
        if (0x180000 < param_3) {
          do {
            uVar29 = param_3;
            pauVar27 = pauVar26;
            pauVar25 = pauVar24;
            auVar3 = pauVar27[1];
            auVar4 = pauVar27[2];
            auVar5 = pauVar27[3];
            auVar6 = vmovntdq_avx(*pauVar27);
            *pauVar25 = auVar6;
            auVar3 = vmovntdq_avx(auVar3);
            pauVar25[1] = auVar3;
            auVar3 = vmovntdq_avx(auVar4);
            pauVar25[2] = auVar3;
            auVar3 = vmovntdq_avx(auVar5);
            pauVar25[3] = auVar3;
            auVar3 = pauVar27[5];
            auVar4 = pauVar27[6];
            auVar5 = pauVar27[7];
            auVar6 = vmovntdq_avx(pauVar27[4]);
            pauVar25[4] = auVar6;
            auVar3 = vmovntdq_avx(auVar3);
            pauVar25[5] = auVar3;
            auVar3 = vmovntdq_avx(auVar4);
            pauVar25[6] = auVar3;
            auVar3 = vmovntdq_avx(auVar5);
            pauVar25[7] = auVar3;
            pauVar24 = pauVar25 + 8;
            pauVar26 = pauVar27 + 8;
            param_3 = uVar29 - 0x100;
          } while (0xff < uVar29 - 0x100);
          uVar31 = uVar29 - 0xe1 & 0xffffffffffffffe0;
          switch(uVar29) {
          case 0x1e1:
          case 0x1e2:
          case 0x1e3:
          case 0x1e4:
          case 0x1e5:
          case 0x1e6:
          case 0x1e7:
          case 0x1e8:
          case 0x1e9:
          case 0x1ea:
          case 0x1eb:
          case 0x1ec:
          case 0x1ed:
          case 0x1ee:
          case 0x1ef:
          case 0x1f0:
          case 0x1f1:
          case 0x1f2:
          case 499:
          case 500:
          case 0x1f5:
          case 0x1f6:
          case 0x1f7:
          case 0x1f8:
          case 0x1f9:
          case 0x1fa:
          case 0x1fb:
          case 0x1fc:
          case 0x1fd:
          case 0x1fe:
          case 0x1ff:
            auVar3 = vmovntdq_avx(*(undefined1 (*) [32])(*pauVar27 + uVar31));
            *(undefined1 (*) [32])(*pauVar25 + uVar31) = auVar3;
          case 0x1c1:
          case 0x1c2:
          case 0x1c3:
          case 0x1c4:
          case 0x1c5:
          case 0x1c6:
          case 0x1c7:
          case 0x1c8:
          case 0x1c9:
          case 0x1ca:
          case 0x1cb:
          case 0x1cc:
          case 0x1cd:
          case 0x1ce:
          case 0x1cf:
          case 0x1d0:
          case 0x1d1:
          case 0x1d2:
          case 0x1d3:
          case 0x1d4:
          case 0x1d5:
          case 0x1d6:
          case 0x1d7:
          case 0x1d8:
          case 0x1d9:
          case 0x1da:
          case 0x1db:
          case 0x1dc:
          case 0x1dd:
          case 0x1de:
          case 0x1df:
          case 0x1e0:
            auVar3 = vmovntdq_avx(*(undefined1 (*) [32])(pauVar27[1] + uVar31));
            *(undefined1 (*) [32])(pauVar25[1] + uVar31) = auVar3;
          case 0x1a1:
          case 0x1a2:
          case 0x1a3:
          case 0x1a4:
          case 0x1a5:
          case 0x1a6:
          case 0x1a7:
          case 0x1a8:
          case 0x1a9:
          case 0x1aa:
          case 0x1ab:
          case 0x1ac:
          case 0x1ad:
          case 0x1ae:
          case 0x1af:
          case 0x1b0:
          case 0x1b1:
          case 0x1b2:
          case 0x1b3:
          case 0x1b4:
          case 0x1b5:
          case 0x1b6:
          case 0x1b7:
          case 0x1b8:
          case 0x1b9:
          case 0x1ba:
          case 0x1bb:
          case 0x1bc:
          case 0x1bd:
          case 0x1be:
          case 0x1bf:
          case 0x1c0:
            auVar3 = vmovntdq_avx(*(undefined1 (*) [32])(pauVar27[2] + uVar31));
            *(undefined1 (*) [32])(pauVar25[2] + uVar31) = auVar3;
          case 0x181:
          case 0x182:
          case 0x183:
          case 0x184:
          case 0x185:
          case 0x186:
          case 0x187:
          case 0x188:
          case 0x189:
          case 0x18a:
          case 0x18b:
          case 0x18c:
          case 0x18d:
          case 0x18e:
          case 399:
          case 400:
          case 0x191:
          case 0x192:
          case 0x193:
          case 0x194:
          case 0x195:
          case 0x196:
          case 0x197:
          case 0x198:
          case 0x199:
          case 0x19a:
          case 0x19b:
          case 0x19c:
          case 0x19d:
          case 0x19e:
          case 0x19f:
          case 0x1a0:
            auVar3 = vmovntdq_avx(*(undefined1 (*) [32])(pauVar27[3] + uVar31));
            *(undefined1 (*) [32])(pauVar25[3] + uVar31) = auVar3;
          case 0x161:
          case 0x162:
          case 0x163:
          case 0x164:
          case 0x165:
          case 0x166:
          case 0x167:
          case 0x168:
          case 0x169:
          case 0x16a:
          case 0x16b:
          case 0x16c:
          case 0x16d:
          case 0x16e:
          case 0x16f:
          case 0x170:
          case 0x171:
          case 0x172:
          case 0x173:
          case 0x174:
          case 0x175:
          case 0x176:
          case 0x177:
          case 0x178:
          case 0x179:
          case 0x17a:
          case 0x17b:
          case 0x17c:
          case 0x17d:
          case 0x17e:
          case 0x17f:
          case 0x180:
            auVar3 = vmovntdq_avx(*(undefined1 (*) [32])(pauVar27[4] + uVar31));
            *(undefined1 (*) [32])(pauVar25[4] + uVar31) = auVar3;
          case 0x141:
          case 0x142:
          case 0x143:
          case 0x144:
          case 0x145:
          case 0x146:
          case 0x147:
          case 0x148:
          case 0x149:
          case 0x14a:
          case 0x14b:
          case 0x14c:
          case 0x14d:
          case 0x14e:
          case 0x14f:
          case 0x150:
          case 0x151:
          case 0x152:
          case 0x153:
          case 0x154:
          case 0x155:
          case 0x156:
          case 0x157:
          case 0x158:
          case 0x159:
          case 0x15a:
          case 0x15b:
          case 0x15c:
          case 0x15d:
          case 0x15e:
          case 0x15f:
          case 0x160:
            auVar3 = vmovntdq_avx(*(undefined1 (*) [32])(pauVar27[5] + uVar31));
            *(undefined1 (*) [32])(pauVar25[5] + uVar31) = auVar3;
          case 0x121:
          case 0x122:
          case 0x123:
          case 0x124:
          case 0x125:
          case 0x126:
          case 0x127:
          case 0x128:
          case 0x129:
          case 0x12a:
          case 299:
          case 300:
          case 0x12d:
          case 0x12e:
          case 0x12f:
          case 0x130:
          case 0x131:
          case 0x132:
          case 0x133:
          case 0x134:
          case 0x135:
          case 0x136:
          case 0x137:
          case 0x138:
          case 0x139:
          case 0x13a:
          case 0x13b:
          case 0x13c:
          case 0x13d:
          case 0x13e:
          case 0x13f:
          case 0x140:
            auVar3 = vmovntdq_avx(*(undefined1 (*) [32])(pauVar27[6] + uVar31));
            *(undefined1 (*) [32])(pauVar25[6] + uVar31) = auVar3;
          default:
            puVar28 = (undefined8 *)(pauVar25[-1] + uVar29);
            *puVar28 = uVar12;
            puVar28[1] = uVar13;
            puVar28[2] = uVar14;
            puVar28[3] = uVar15;
          case 0x100:
            *param_1 = uVar10;
            param_1[1] = uVar11;
            param_1[2] = uVar32;
            param_1[3] = uVar33;
            return puVar23;
          }
        }
        do {
          uVar10 = *(undefined8 *)(*pauVar26 + 8);
          uVar11 = *(undefined8 *)(*pauVar26 + 0x10);
          uVar32 = *(undefined8 *)(*pauVar26 + 0x18);
          uVar33 = *(undefined8 *)pauVar26[1];
          uVar12 = *(undefined8 *)(pauVar26[1] + 8);
          uVar13 = *(undefined8 *)(pauVar26[1] + 0x10);
          uVar14 = *(undefined8 *)(pauVar26[1] + 0x18);
          uVar15 = *(undefined8 *)pauVar26[2];
          uVar16 = *(undefined8 *)(pauVar26[2] + 8);
          uVar17 = *(undefined8 *)(pauVar26[2] + 0x10);
          uVar18 = *(undefined8 *)(pauVar26[2] + 0x18);
          uVar19 = *(undefined8 *)pauVar26[3];
          uVar20 = *(undefined8 *)(pauVar26[3] + 8);
          uVar21 = *(undefined8 *)(pauVar26[3] + 0x10);
          uVar22 = *(undefined8 *)(pauVar26[3] + 0x18);
          *(undefined8 *)*pauVar24 = *(undefined8 *)*pauVar26;
          *(undefined8 *)(*pauVar24 + 8) = uVar10;
          *(undefined8 *)(*pauVar24 + 0x10) = uVar11;
          *(undefined8 *)(*pauVar24 + 0x18) = uVar32;
          *(undefined8 *)pauVar24[1] = uVar33;
          *(undefined8 *)(pauVar24[1] + 8) = uVar12;
          *(undefined8 *)(pauVar24[1] + 0x10) = uVar13;
          *(undefined8 *)(pauVar24[1] + 0x18) = uVar14;
          *(undefined8 *)pauVar24[2] = uVar15;
          *(undefined8 *)(pauVar24[2] + 8) = uVar16;
          *(undefined8 *)(pauVar24[2] + 0x10) = uVar17;
          *(undefined8 *)(pauVar24[2] + 0x18) = uVar18;
          *(undefined8 *)pauVar24[3] = uVar19;
          *(undefined8 *)(pauVar24[3] + 8) = uVar20;
          *(undefined8 *)(pauVar24[3] + 0x10) = uVar21;
          *(undefined8 *)(pauVar24[3] + 0x18) = uVar22;
          uVar10 = *(undefined8 *)(pauVar26[4] + 8);
          uVar11 = *(undefined8 *)(pauVar26[4] + 0x10);
          uVar32 = *(undefined8 *)(pauVar26[4] + 0x18);
          uVar33 = *(undefined8 *)pauVar26[5];
          uVar12 = *(undefined8 *)(pauVar26[5] + 8);
          uVar13 = *(undefined8 *)(pauVar26[5] + 0x10);
          uVar14 = *(undefined8 *)(pauVar26[5] + 0x18);
          uVar15 = *(undefined8 *)pauVar26[6];
          uVar16 = *(undefined8 *)(pauVar26[6] + 8);
          uVar17 = *(undefined8 *)(pauVar26[6] + 0x10);
          uVar18 = *(undefined8 *)(pauVar26[6] + 0x18);
          uVar19 = *(undefined8 *)pauVar26[7];
          uVar20 = *(undefined8 *)(pauVar26[7] + 8);
          uVar21 = *(undefined8 *)(pauVar26[7] + 0x10);
          uVar22 = *(undefined8 *)(pauVar26[7] + 0x18);
          *(undefined8 *)pauVar24[4] = *(undefined8 *)pauVar26[4];
          *(undefined8 *)(pauVar24[4] + 8) = uVar10;
          *(undefined8 *)(pauVar24[4] + 0x10) = uVar11;
          *(undefined8 *)(pauVar24[4] + 0x18) = uVar32;
          *(undefined8 *)pauVar24[5] = uVar33;
          *(undefined8 *)(pauVar24[5] + 8) = uVar12;
          *(undefined8 *)(pauVar24[5] + 0x10) = uVar13;
          *(undefined8 *)(pauVar24[5] + 0x18) = uVar14;
          *(undefined8 *)pauVar24[6] = uVar15;
          *(undefined8 *)(pauVar24[6] + 8) = uVar16;
          *(undefined8 *)(pauVar24[6] + 0x10) = uVar17;
          *(undefined8 *)(pauVar24[6] + 0x18) = uVar18;
          *(undefined8 *)pauVar24[7] = uVar19;
          *(undefined8 *)(pauVar24[7] + 8) = uVar20;
          *(undefined8 *)(pauVar24[7] + 0x10) = uVar21;
          *(undefined8 *)(pauVar24[7] + 0x18) = uVar22;
          pauVar24 = pauVar24 + 8;
          pauVar26 = pauVar26 + 8;
          param_3 = param_3 - 0x100;
        } while (0xff < param_3);
      }
    }
                    /* WARNING: Could not recover jumptable at 0x000140002fb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    puVar23 = (undefined8 *)
              (*(code *)(IMAGE_DOS_HEADER_140000000.e_magic +
                        *(uint *)(&DAT_14001b0f0 + (param_3 + 0x1f >> 5) * 4)))();
    return puVar23;
  }
  for (; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_2 = (undefined8 *)((longlong)param_2 + 1);
    param_1 = (undefined8 *)((longlong)param_1 + 1);
  }
  return puVar23;
}



/*****************************************************************************
 * Function: FUN_1400033b8
 * Address: 1400033b8
 * Size: 39 bytes
 *****************************************************************************/


void FUN_1400033b8(longlong *param_1,ulonglong *param_2,longlong param_3)

{
  if (*(int *)((longlong)*(int *)(param_3 + 0x1c) + *param_1) == -2) {
    FUN_14000345c(param_3,(longlong)param_2,*param_2);
  }
  return;
}



/*****************************************************************************
 * Function: GetUnwindTryBlock
 * Address: 1400033e0
 * Size: 41 bytes
 *****************************************************************************/


/* Library Function - Single Match
    public: static int __cdecl __FrameHandler3::GetUnwindTryBlock(unsigned __int64 * __ptr64,struct
   _xDISPATCHER_CONTEXT * __ptr64,struct _s_FuncInfo const * __ptr64)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl
__FrameHandler3::GetUnwindTryBlock
          (__uint64 *param_1,_xDISPATCHER_CONTEXT *param_2,_s_FuncInfo *param_3)

{
  longlong *plVar1;
  longlong local_res18 [2];
  
  plVar1 = FUN_14000288c((longlong *)param_1,(ulonglong *)param_2,(longlong)param_3,local_res18);
  return *(int *)((longlong)param_3->dispUnwindHelp + 4 + *plVar1);
}



/*****************************************************************************
 * Function: SetState
 * Address: 14000340c
 * Size: 12 bytes
 *****************************************************************************/


/* Library Function - Single Match
    public: static void __cdecl __FrameHandler3::SetState(unsigned __int64 * __ptr64,struct
   _s_FuncInfo const * __ptr64,int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __FrameHandler3::SetState(__uint64 *param_1,_s_FuncInfo *param_2,int param_3)

{
  *(int *)((longlong)param_2->dispUnwindHelp + *param_1) = param_3;
  return;
}



/*****************************************************************************
 * Function: SetUnwindTryBlock
 * Address: 140003418
 * Size: 59 bytes
 *****************************************************************************/


/* Library Function - Single Match
    public: static void __cdecl __FrameHandler3::SetUnwindTryBlock(unsigned __int64 * __ptr64,struct
   _xDISPATCHER_CONTEXT * __ptr64,struct _s_FuncInfo const * __ptr64,int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl
__FrameHandler3::SetUnwindTryBlock
          (__uint64 *param_1,_xDISPATCHER_CONTEXT *param_2,_s_FuncInfo *param_3,int param_4)

{
  longlong *plVar1;
  longlong local_res18 [2];
  
  plVar1 = FUN_14000288c((longlong *)param_1,(ulonglong *)param_2,(longlong)param_3,local_res18);
  if (*(int *)((longlong)param_3->dispUnwindHelp + 4 + *plVar1) < param_4) {
    *(int *)((longlong)param_3->dispUnwindHelp + 4 + *plVar1) = param_4;
  }
  return;
}



/*****************************************************************************
 * Function: FUN_140003454
 * Address: 140003454
 * Size: 8 bytes
 *****************************************************************************/


void FUN_140003454(longlong param_1,ulonglong *param_2)

{
  FUN_14000345c(param_1,(longlong)param_2,*param_2);
  return;
}



/*****************************************************************************
 * Function: FUN_14000345c
 * Address: 14000345c
 * Size: 101 bytes
 *****************************************************************************/


undefined4 FUN_14000345c(longlong param_1,longlong param_2,ulonglong param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  if (param_1 != 0) {
    lVar4 = (longlong)*(int *)(param_1 + 0x18);
    lVar1 = *(longlong *)(param_2 + 8);
    if (lVar1 + lVar4 != 0) {
      uVar3 = 0;
      if (*(uint *)(param_1 + 0x14) != 0) {
        do {
          if (param_3 < (ulonglong)(*(int *)(lVar4 + uVar3 * 8 + lVar1) + lVar1)) break;
          uVar2 = (int)uVar3 + 1;
          uVar3 = (ulonglong)uVar2;
        } while (uVar2 < *(uint *)(param_1 + 0x14));
        if ((int)uVar3 != 0) {
          return *(undefined4 *)(lVar1 + (ulonglong)((int)uVar3 - 1) * 8 + 4 + lVar4);
        }
      }
      return 0xffffffff;
    }
  }
                    /* WARNING: Subroutine does not return */
  abort();
}



/*****************************************************************************
 * Function: FUN_1400034c4
 * Address: 1400034c4
 * Size: 503 bytes
 *****************************************************************************/


char FUN_1400034c4(longlong param_1,longlong *param_2,byte *param_3,byte *param_4)

{
  longlong lVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int iVar5;
  ulonglong uVar6;
  int iVar7;
  
  uVar4 = 0;
  uVar6 = 0;
  iVar5 = 0;
  uVar3 = uVar4;
  iVar7 = iVar5;
  if (*(int *)(param_3 + 4) != 0) {
    iVar7 = *(int *)(param_3 + 4);
    lVar1 = _GetImageBase();
    uVar3 = iVar7 + lVar1;
  }
  if (uVar3 == 0) {
    return '\0';
  }
  uVar3 = uVar4;
  if (iVar7 != 0) {
    lVar1 = _GetImageBase();
    uVar3 = lVar1 + *(int *)(param_3 + 4);
  }
  if (*(char *)(uVar3 + 0x10) == '\0') {
    return '\0';
  }
  if ((*(int *)(param_3 + 8) == 0) && (-1 < *(int *)param_3)) {
    return '\0';
  }
  if (-1 < *(int *)param_3) {
    param_2 = (longlong *)((longlong)*(int *)(param_3 + 8) + *param_2);
  }
  if ((((*param_3 & 0x80) == 0) || ((*param_4 & 0x10) == 0)) || (DAT_140018af8 == 0)) {
    if ((*param_3 & 8) == 0) {
      if ((*param_4 & 1) == 0) {
        uVar3 = uVar4;
        if (*(int *)(param_4 + 0x18) != 0) {
          iVar5 = *(int *)(param_4 + 0x18);
          lVar1 = _GetThrowImageBase();
          uVar3 = iVar5 + lVar1;
        }
        if (uVar3 != 0) {
          if ((*(longlong *)(param_1 + 0x28) != 0) && (param_2 != (longlong *)0x0)) {
            if (iVar5 != 0) {
              lVar1 = _GetThrowImageBase();
              uVar4 = lVar1 + *(int *)(param_4 + 0x18);
            }
            if (uVar4 != 0) {
              uVar6 = (ulonglong)(((*param_4 & 4) != 0) + 1);
              goto LAB_140003682;
            }
          }
                    /* WARNING: Subroutine does not return */
          abort();
        }
        if ((*(longlong *)(param_1 + 0x28) == 0) || (param_2 == (longlong *)0x0)) {
                    /* WARNING: Subroutine does not return */
          abort();
        }
        iVar7 = *(int *)(param_4 + 0x14);
        puVar2 = (undefined8 *)__AdjustPointer(*(longlong *)(param_1 + 0x28),(int *)(param_4 + 8));
        FUN_140002d40(param_2,puVar2,(longlong)iVar7);
        goto LAB_140003682;
      }
      if ((*(undefined8 **)(param_1 + 0x28) == (undefined8 *)0x0) || (param_2 == (longlong *)0x0)) {
                    /* WARNING: Subroutine does not return */
        abort();
      }
      FUN_140002d40(param_2,*(undefined8 **)(param_1 + 0x28),(longlong)*(int *)(param_4 + 0x14));
      uVar6 = uVar4;
      if ((*(int *)(param_4 + 0x14) != 8) || (*param_2 == 0)) goto LAB_140003682;
      lVar1 = *param_2;
    }
    else {
      lVar1 = *(longlong *)(param_1 + 0x28);
      if ((lVar1 == 0) || (param_2 == (longlong *)0x0)) {
                    /* WARNING: Subroutine does not return */
        abort();
      }
      *param_2 = lVar1;
    }
  }
  else {
    lVar1 = (*(code *)PTR__guard_dispatch_icall_14000e260)();
    if ((lVar1 == 0) || (param_2 == (longlong *)0x0)) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
    *param_2 = lVar1;
  }
  lVar1 = __AdjustPointer(lVar1,(int *)(param_4 + 8));
  *param_2 = lVar1;
  uVar6 = uVar4;
LAB_140003682:
  return (char)uVar6;
}



/*****************************************************************************
 * Function: BuildCatchObjectInternal<class___FrameHandler3>
 * Address: 1400036c4
 * Size: 186 bytes
 *****************************************************************************/


/* Library Function - Single Match
    void __cdecl BuildCatchObjectInternal<class __FrameHandler3>(struct EHExceptionRecord *
   __ptr64,void * __ptr64,struct _s_HandlerType const * __ptr64,struct _s_CatchableType const *
   __ptr64)
   
   Library: Visual Studio 2019 Release */

void __cdecl
BuildCatchObjectInternal<class___FrameHandler3>
          (EHExceptionRecord *param_1,void *param_2,_s_HandlerType *param_3,
          _s_CatchableType *param_4)

{
  char cVar1;
  int iVar2;
  undefined7 extraout_var;
  void *pvVar3;
  longlong lVar4;
  longlong lVar5;
  undefined *UNRECOVERED_JUMPTABLE;
  void *pvVar6;
  
  UNRECOVERED_JUMPTABLE = (undefined *)0x0;
  pvVar6 = param_2;
  if (-1 < *(int *)param_3) {
                    /* WARNING: Load size is inaccurate */
    pvVar6 = (void *)((longlong)*(int *)(param_3 + 8) + *param_2);
  }
  cVar1 = FUN_1400034c4((longlong)param_1,(longlong *)param_2,(byte *)param_3,(byte *)param_4);
  iVar2 = (int)CONCAT71(extraout_var,cVar1);
  if (iVar2 == 1) {
    lVar4 = __AdjustPointer(*(longlong *)(param_1 + 0x28),(int *)(param_4 + 8));
    if (*(int *)(param_4 + 0x18) != 0) {
      lVar5 = _GetThrowImageBase();
      UNRECOVERED_JUMPTABLE = (undefined *)(*(int *)(param_4 + 0x18) + lVar5);
    }
    FUN_1400049c4(pvVar6,UNRECOVERED_JUMPTABLE,lVar4);
  }
  else if (iVar2 == 2) {
    pvVar3 = (void *)__AdjustPointer(*(longlong *)(param_1 + 0x28),(int *)(param_4 + 8));
    if (*(int *)(param_4 + 0x18) != 0) {
      lVar4 = _GetThrowImageBase();
      UNRECOVERED_JUMPTABLE = (undefined *)(*(int *)(param_4 + 0x18) + lVar4);
    }
    _CallMemberFunction2(pvVar6,UNRECOVERED_JUMPTABLE,pvVar3,1);
  }
  return;
}



/*****************************************************************************
 * Function: CatchIt<class___FrameHandler3>
 * Address: 140003784
 * Size: 209 bytes
 *****************************************************************************/


/* Library Function - Single Match
    void __cdecl CatchIt<class __FrameHandler3>(struct EHExceptionRecord * __ptr64,unsigned __int64
   * __ptr64,struct _CONTEXT * __ptr64,struct _xDISPATCHER_CONTEXT * __ptr64,struct _s_FuncInfo
   const * __ptr64,struct _s_HandlerType const * __ptr64,struct _s_CatchableType const *
   __ptr64,struct _s_TryBlockMapEntry const * __ptr64,int,unsigned __int64 * __ptr64,unsigned
   char,unsigned char)
   
   Library: Visual Studio 2019 Release */

void __cdecl
CatchIt<class___FrameHandler3>
          (EHExceptionRecord *param_1,__uint64 *param_2,_CONTEXT *param_3,
          _xDISPATCHER_CONTEXT *param_4,_s_FuncInfo *param_5,_s_HandlerType *param_6,
          _s_CatchableType *param_7,_s_TryBlockMapEntry *param_8,int param_9,__uint64 *param_10,
          uchar param_11,uchar param_12)

{
  undefined4 uVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong local_res10;
  _CONTEXT *local_res18;
  undefined4 in_stack_ffffffffffffffa4;
  
  local_res18 = param_3;
  plVar3 = FUN_14000288c((longlong *)param_2,(ulonglong *)param_4,(longlong)param_5,&local_res10);
  if (param_7 != (_s_CatchableType *)0x0) {
    BuildCatchObjectInternal<class___FrameHandler3>(param_1,plVar3,param_6,param_7);
  }
  uVar1 = *(undefined4 *)(param_8 + 8);
  iVar2 = *(int *)param_8;
  lVar4 = _GetImageBase();
  FUN_140002a98(param_2,(ULONG_PTR)param_1,(ULONG_PTR)local_res18,(ULONG_PTR)plVar3,
                lVar4 + *(int *)(param_6 + 0xc),(ULONG_PTR)param_5,iVar2,
                CONCAT44(in_stack_ffffffffffffffa4,uVar1),param_6,(undefined8 *)param_4,param_12);
  return;
}



/*****************************************************************************
 * Function: FUN_140003858
 * Address: 140003858
 * Size: 1235 bytes
 *****************************************************************************/


void FUN_140003858(EHExceptionRecord *param_1,__uint64 *param_2,_CONTEXT *param_3,
                  _xDISPATCHER_CONTEXT *param_4,_s_FuncInfo *param_5,byte param_6,int param_7,
                  __uint64 *param_8)

{
  undefined8 *puVar1;
  _s_ESTypeList *p_Var2;
  longlong lVar3;
  code *pcVar4;
  uint uVar5;
  char cVar6;
  uchar uVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  longlong lVar12;
  int *piVar13;
  longlong *plVar14;
  uint uVar15;
  uint uVar17;
  undefined1 auStackY_168 [32];
  _s_TryBlockMapEntry *in_stack_fffffffffffffed0;
  undefined4 uVar18;
  uchar local_108;
  _CONTEXT *local_100;
  _s_CatchableType *local_e0;
  longlong local_d8;
  __uint64 *local_d0;
  int local_c8;
  int iStack_c4;
  int iStack_c0;
  uint uStack_bc;
  int local_b8;
  _s_FuncInfo *local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 uStack_9c;
  uint uStack_98;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined4 uStack_8c;
  uint uStack_88;
  undefined4 uStack_84;
  uint local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  ulonglong local_58;
  ulonglong uVar16;
  
  local_58 = DAT_140018038 ^ (ulonglong)auStackY_168;
  local_d0 = param_8;
  local_108 = '\0';
  iVar9 = __FrameHandler3::GetHandlerSearchState(param_2,param_4,param_5);
  if ((-2 < iVar9) && (iVar9 < param_5->maxState)) {
    local_100 = param_3;
    if ((*(int *)param_1 == -0x1f928c9d) &&
       (((*(int *)(param_1 + 0x18) == 4 && (*(int *)(param_1 + 0x20) + 0xe66cfae0U < 3)) &&
        (*(longlong *)(param_1 + 0x30) == 0)))) {
      lVar12 = __vcrt_getptd();
      if (*(longlong *)(lVar12 + 0x20) == 0) goto LAB_140003cc0;
      lVar12 = __vcrt_getptd();
      param_1 = *(EHExceptionRecord **)(lVar12 + 0x20);
      lVar12 = __vcrt_getptd();
      local_108 = '\x01';
      local_100 = *(_CONTEXT **)(lVar12 + 0x28);
      FUN_140002c6c(*(undefined8 *)(param_1 + 0x38));
      if (((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x18) == 4)) &&
         ((*(int *)(param_1 + 0x20) + 0xe66cfae0U < 3 && (*(longlong *)(param_1 + 0x30) == 0))))
      goto LAB_140003d27;
      lVar12 = __vcrt_getptd();
      if (*(longlong *)(lVar12 + 0x38) != 0) {
        lVar12 = __vcrt_getptd();
        p_Var2 = *(_s_ESTypeList **)(lVar12 + 0x38);
        lVar12 = __vcrt_getptd();
        *(undefined8 *)(lVar12 + 0x38) = 0;
        cVar6 = FUN_14000484c((longlong)param_1,(int *)p_Var2);
        if (cVar6 == '\0') {
          uVar7 = Is_bad_exception_allowed(p_Var2);
          if (uVar7 != '\0') {
            __DestructExceptionObject((int *)param_1);
            FUN_140004308(&local_70);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(&local_70,(ThrowInfo *)&DAT_140016cd0);
          }
          FUN_140005f70();
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
      }
    }
    uVar18 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
    local_a8 = *(undefined8 *)(param_4 + 8);
    local_b0 = param_5;
    if (((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x18) == 4)) &&
       (*(int *)(param_1 + 0x20) + 0xe66cfae0U < 3)) {
      if (param_5->nTryBlocks != 0) {
        FUN_140002958((undefined8 *)&local_90,&local_b0,iVar9,(ulonglong *)param_4,(longlong)param_5
                     );
        uVar18 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
        local_a0 = local_90;
        uStack_9c = uStack_8c;
        uStack_98 = uStack_88;
        uStack_94 = uStack_84;
        if (uStack_88 < local_78) {
          uVar17 = uStack_88;
          do {
            uVar16 = 0;
            lVar3 = *(longlong *)(CONCAT44(uStack_8c,local_90) + 8);
            lVar12 = (longlong)*(int *)(*(longlong *)CONCAT44(uStack_9c,local_a0) + 0x10) +
                     (ulonglong)uVar17 * 0x14;
            piVar13 = (int *)(lVar12 + lVar3);
            local_c8 = *piVar13;
            iStack_c4 = piVar13[1];
            iStack_c0 = piVar13[2];
            uVar5 = piVar13[3];
            local_b8 = *(int *)(lVar12 + 0x10 + lVar3);
            uStack_bc = uVar5;
            if (((local_c8 <= iVar9) && (iVar9 <= iStack_c4)) &&
               (local_d8 = (longlong)local_b8 + *(longlong *)(param_4 + 8), uVar5 != 0)) {
              do {
                puVar1 = (undefined8 *)(local_d8 + uVar16 * 0x14);
                local_70 = *puVar1;
                uStack_68 = puVar1[1];
                local_60 = *(undefined4 *)(local_d8 + 0x10 + uVar16 * 0x14);
                lVar12 = _GetThrowImageBase();
                piVar13 = (int *)(lVar12 + 4 +
                                 (longlong)*(int *)(*(longlong *)(param_1 + 0x30) + 0xc));
                lVar12 = _GetThrowImageBase();
                for (iVar11 = *(int *)(lVar12 + *(int *)(*(longlong *)(param_1 + 0x30) + 0xc));
                    0 < iVar11; iVar11 = iVar11 + -1) {
                  lVar12 = _GetThrowImageBase();
                  local_e0 = (_s_CatchableType *)(lVar12 + *piVar13);
                  iVar10 = TypeMatchHelper<class___FrameHandler3>
                                     ((_s_HandlerType *)&local_70,local_e0,
                                      *(_s_ThrowInfo **)(param_1 + 0x30));
                  if (iVar10 != 0) {
                    in_stack_fffffffffffffed0 = (_s_TryBlockMapEntry *)&local_c8;
                    CatchIt<class___FrameHandler3>
                              (param_1,param_2,local_100,param_4,param_5,(_s_HandlerType *)&local_70
                               ,local_e0,in_stack_fffffffffffffed0,param_7,local_d0,local_108,
                               param_6);
                    goto LAB_140003b9b;
                  }
                  piVar13 = piVar13 + 1;
                }
                uVar15 = (int)uVar16 + 1;
                uVar16 = (ulonglong)uVar15;
              } while (uVar15 != uVar5);
            }
LAB_140003b9b:
            uVar18 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
            uVar17 = uVar17 + 1;
          } while (uVar17 < local_78);
        }
      }
      piVar13 = (int *)0x0;
      if ((0x19930520 < (param_5->magicNumber_and_bbtFlags & 0x1fffffff)) &&
         (((param_5->dispESTypeList != 0 &&
           (lVar12 = _GetImageBase(), lVar12 + (int)param_5->dispESTypeList != 0)) ||
          ((((uint)param_5->EHFlags >> 2 & 1) != 0 &&
           (bVar8 = FUN_1400027fc((ulonglong *)param_4,(longlong)param_5), !bVar8)))))) {
        if (((uint)param_5->EHFlags >> 2 & 1) != 0) {
          lVar12 = __vcrt_getptd();
          *(EHExceptionRecord **)(lVar12 + 0x20) = param_1;
          lVar12 = __vcrt_getptd();
          *(_CONTEXT **)(lVar12 + 0x28) = local_100;
          FUN_140005f70();
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        if (param_5->dispESTypeList != 0) {
          lVar12 = _GetImageBase();
          piVar13 = (int *)(lVar12 + (int)param_5->dispESTypeList);
        }
        cVar6 = FUN_14000484c((longlong)param_1,piVar13);
        if (cVar6 == '\0') {
          plVar14 = FUN_14000288c((longlong *)param_2,(ulonglong *)param_4,(longlong)param_5,
                                  (longlong *)&local_e0);
          FUN_140002a98(param_2,(ULONG_PTR)param_1,(ULONG_PTR)local_100,(ULONG_PTR)plVar14,0,
                        (ULONG_PTR)param_5,-1,CONCAT44(uVar18,0xffffffff),0,(undefined8 *)param_4,
                        param_6);
        }
      }
    }
    else if (param_5->nTryBlocks != 0) {
      if (param_6 != 0) goto LAB_140003d27;
      FUN_140003d30(param_1,param_2,local_100,param_4,param_5,iVar9,param_7,param_8);
    }
    lVar12 = __vcrt_getptd();
    if (*(longlong *)(lVar12 + 0x38) == 0) {
LAB_140003cc0:
      FUN_14000d520(local_58 ^ (ulonglong)auStackY_168);
      return;
    }
  }
LAB_140003d27:
                    /* WARNING: Subroutine does not return */
  abort();
}



/*****************************************************************************
 * Function: FUN_140003d30
 * Address: 140003d30
 * Size: 536 bytes
 *****************************************************************************/


void FUN_140003d30(EHExceptionRecord *param_1,__uint64 *param_2,_CONTEXT *param_3,
                  _xDISPATCHER_CONTEXT *param_4,_s_FuncInfo *param_5,int param_6,int param_7,
                  __uint64 *param_8)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  PVOID pvVar5;
  _s_HandlerType *p_Var6;
  uint uVar7;
  _s_FuncInfo *local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 uStack_84;
  uint uStack_80;
  undefined4 uStack_7c;
  int local_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  int local_68;
  undefined4 local_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  uint local_48;
  
  if (*(int *)param_1 != -0x7ffffffd) {
    lVar4 = __vcrt_getptd();
    if (*(longlong *)(lVar4 + 0x10) != 0) {
      pvVar5 = EncodePointer((PVOID)0x0);
      lVar4 = __vcrt_getptd();
      if ((((*(PVOID *)(lVar4 + 0x10) != pvVar5) && (*(int *)param_1 != -0x1fbcb0b3)) &&
          (*(int *)param_1 != -0x1fbcbcae)) &&
         (iVar3 = _CallSETranslator<>((undefined4 *)param_1,param_2,param_3), iVar3 != 0)) {
        return;
      }
    }
    local_90 = *(undefined8 *)(param_4 + 8);
    local_98 = param_5;
    if (param_5->nTryBlocks == 0) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
    FUN_140002958((undefined8 *)&local_60,&local_98,param_6,(ulonglong *)param_4,(longlong)param_5);
    local_88 = local_60;
    uStack_84 = uStack_5c;
    uStack_80 = uStack_58;
    uStack_7c = uStack_54;
    if (uStack_58 < local_48) {
      uVar7 = uStack_58;
      do {
        lVar2 = *(longlong *)(CONCAT44(uStack_5c,local_60) + 8);
        lVar4 = (longlong)*(int *)(*(longlong *)CONCAT44(uStack_84,local_88) + 0x10) +
                (ulonglong)uVar7 * 0x14;
        piVar1 = (int *)(lVar4 + lVar2);
        local_78 = *piVar1;
        iStack_74 = piVar1[1];
        iStack_70 = (int)*(ulonglong *)(piVar1 + 2);
        iStack_6c = piVar1[3];
        local_68 = *(int *)(lVar4 + 0x10 + lVar2);
        if ((local_78 <= param_6) && (param_6 <= iStack_74)) {
          p_Var6 = (_s_HandlerType *)
                   (*(longlong *)(param_4 + 8) + -0x14 +
                   (longlong)local_68 + (*(ulonglong *)(piVar1 + 2) >> 0x20) * 0x14);
          if (*(int *)(p_Var6 + 4) != 0) {
            iVar3 = *(int *)(p_Var6 + 4);
            lVar4 = _GetImageBase();
            if (lVar4 + iVar3 != 0) {
              if (iVar3 == 0) {
                lVar4 = 0;
              }
              else {
                lVar4 = _GetImageBase();
                lVar4 = lVar4 + *(int *)(p_Var6 + 4);
              }
              if (*(char *)(lVar4 + 0x10) != '\0') goto LAB_140003f29;
            }
          }
          if (((byte)*p_Var6 & 0x40) == 0) {
            CatchIt<class___FrameHandler3>
                      (param_1,param_2,param_3,param_4,param_5,p_Var6,(_s_CatchableType *)0x0,
                       (_s_TryBlockMapEntry *)&local_78,param_7,param_8,'\x01','\0');
          }
        }
LAB_140003f29:
        uVar7 = uVar7 + 1;
      } while (uVar7 < local_48);
    }
  }
  return;
}



/*****************************************************************************
 * Function: TypeMatchHelper<class___FrameHandler3>
 * Address: 140003f4c
 * Size: 317 bytes
 *****************************************************************************/


/* Library Function - Single Match
    int __cdecl TypeMatchHelper<class __FrameHandler3>(struct _s_HandlerType const * __ptr64,struct
   _s_CatchableType const * __ptr64,struct _s_ThrowInfo const * __ptr64)
   
   Library: Visual Studio 2019 Release */

int __cdecl
TypeMatchHelper<class___FrameHandler3>
          (_s_HandlerType *param_1,_s_CatchableType *param_2,_s_ThrowInfo *param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  char *pcVar6;
  int iVar7;
  longlong lVar8;
  
  lVar8 = 0;
  iVar7 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar3 = *(int *)(param_1 + 4);
    lVar4 = _GetImageBase();
    if (lVar4 + iVar3 != 0) {
      lVar4 = lVar8;
      if (iVar3 != 0) {
        iVar7 = *(int *)(param_1 + 4);
        lVar4 = _GetImageBase();
        lVar4 = iVar7 + lVar4;
      }
      if ((*(char *)(lVar4 + 0x10) != '\0') &&
         ((((byte)*param_1 & 0x80) == 0 || (((byte)*param_2 & 0x10) == 0)))) {
        lVar4 = lVar8;
        if (iVar7 != 0) {
          lVar4 = _GetImageBase();
          lVar4 = lVar4 + *(int *)(param_1 + 4);
        }
        lVar5 = _GetThrowImageBase();
        if (lVar4 != lVar5 + *(int *)(param_2 + 4)) {
          lVar4 = lVar8;
          if (*(int *)(param_1 + 4) != 0) {
            lVar4 = _GetImageBase();
            lVar4 = lVar4 + *(int *)(param_1 + 4);
          }
          lVar5 = _GetThrowImageBase();
          pcVar6 = (char *)(lVar4 + 0x10);
          lVar4 = ((longlong)*(int *)(param_2 + 4) + 0x10 + lVar5) - (longlong)pcVar6;
          do {
            cVar1 = *pcVar6;
            cVar2 = pcVar6[lVar4];
            if (cVar1 != cVar2) break;
            pcVar6 = pcVar6 + 1;
          } while (cVar2 != '\0');
          if (cVar1 != cVar2) {
            return 0;
          }
        }
        if (((((((byte)*param_2 & 2) == 0) || (((byte)*param_1 & 8) != 0)) &&
             (((param_3->attributes & 1) == 0 || (((byte)*param_1 & 1) != 0)))) &&
            (((param_3->attributes & 4) == 0 || (((byte)*param_1 & 4) != 0)))) &&
           (((param_3->attributes & 2) == 0 || (lVar8 = 0, ((byte)*param_1 & 2) != 0)))) {
          lVar8 = 1;
        }
        return (int)lVar8;
      }
    }
  }
  return 1;
}



/*****************************************************************************
 * Function: FUN_14000408c
 * Address: 14000408c
 * Size: 566 bytes
 *****************************************************************************/


undefined8
FUN_14000408c(EHExceptionRecord *param_1,__uint64 *param_2,_CONTEXT *param_3,
             _xDISPATCHER_CONTEXT *param_4,_s_FuncInfo *param_5,int param_6,__uint64 *param_7,
             byte param_8)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 in_stack_ffffffffffffffe0;
  undefined4 uVar4;
  
  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  __except_validate_context_record((longlong)param_3);
  lVar2 = __vcrt_getptd();
  if ((*(int *)(lVar2 + 0x40) == 0) && (*(int *)param_1 != -0x1f928c9d)) {
    if (*(int *)param_1 == -0x7fffffd7) {
      if (*(int *)(param_1 + 0x18) == 0xf) {
        if (*(longlong *)(param_1 + 0x60) == 0x19930520) goto LAB_14000410e;
        goto LAB_1400040f2;
      }
    }
    else {
LAB_1400040f2:
      if (*(int *)param_1 == -0x7fffffda) goto LAB_14000410e;
    }
    if ((0x19930521 < (param_5->magicNumber_and_bbtFlags & 0x1fffffff)) &&
       ((param_5->EHFlags & 1) != 0)) {
      return 1;
    }
  }
LAB_14000410e:
  if (((byte)param_1[4] & 0x66) == 0) {
    if ((param_5->nTryBlocks == 0) &&
       ((((param_5->magicNumber_and_bbtFlags & 0x1fffffff) < 0x19930521 ||
         (param_5->dispESTypeList == 0)) ||
        (lVar2 = _GetImageBase(), lVar2 + (int)param_5->dispESTypeList == 0)))) {
      if ((param_5->magicNumber_and_bbtFlags & 0x1fffffff) < 0x19930522) {
        return 1;
      }
      if (((uint)param_5->EHFlags >> 2 & 1) == 0) {
        return 1;
      }
    }
    if (((*(int *)param_1 == -0x1f928c9d) && (2 < *(uint *)(param_1 + 0x18))) &&
       ((0x19930522 < *(uint *)(param_1 + 0x20) &&
        ((*(int *)(*(longlong *)(param_1 + 0x30) + 8) != 0 &&
         (lVar2 = _GetThrowImageBase(), lVar2 + *(int *)(*(longlong *)(param_1 + 0x30) + 8) != 0))))
       )) {
      uVar3 = (*(code *)PTR__guard_dispatch_icall_14000e260)
                        (param_1,param_2,param_3,param_4,param_5,param_6,param_7,
                         CONCAT44(uVar4,(uint)param_8));
      return uVar3;
    }
    FUN_140003858(param_1,param_2,param_3,param_4,param_5,param_8,param_6,param_7);
    return 1;
  }
  if (param_5->maxState == 0) {
    return 1;
  }
  if (param_6 != 0) {
    return 1;
  }
  if (((byte)param_1[4] & 0x20) == 0) {
LAB_140004193:
    __FrameHandler3::FrameUnwindToEmptyState(param_2,param_4,param_5);
  }
  else {
    if (*(int *)param_1 == -0x7fffffda) {
      iVar1 = FUN_14000345c((longlong)param_5,(longlong)param_4,*(ulonglong *)(param_4 + 0x20));
      if ((iVar1 < -1) || (param_5->maxState <= iVar1)) {
LAB_1400042bd:
                    /* WARNING: Subroutine does not return */
        abort();
      }
    }
    else {
      if (*(int *)param_1 != -0x7fffffd7) goto LAB_140004193;
      iVar1 = *(int *)(param_1 + 0x38);
      if ((iVar1 < -1) || (param_5->maxState <= iVar1)) goto LAB_1400042bd;
      param_2 = *(__uint64 **)(param_1 + 0x28);
    }
    FUN_140004628(param_2,(ulonglong *)param_4,param_5,iVar1);
  }
  return 1;
}



/*****************************************************************************
 * Function: thunk_FUN_14000408c
 * Address: 1400042c4
 * Size: 5 bytes
 *****************************************************************************/


undefined8
thunk_FUN_14000408c(EHExceptionRecord *param_1,__uint64 *param_2,_CONTEXT *param_3,
                   _xDISPATCHER_CONTEXT *param_4,_s_FuncInfo *param_5,int param_6,__uint64 *param_7,
                   byte param_8)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined8 in_stack_ffffffffffffffe0;
  
  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  __except_validate_context_record((longlong)param_3);
  lVar2 = __vcrt_getptd();
  if ((*(int *)(lVar2 + 0x40) == 0) && (*(int *)param_1 != -0x1f928c9d)) {
    if (*(int *)param_1 == -0x7fffffd7) {
      if (*(int *)(param_1 + 0x18) == 0xf) {
        if (*(longlong *)(param_1 + 0x60) == 0x19930520) goto LAB_14000410e;
        goto LAB_1400040f2;
      }
    }
    else {
LAB_1400040f2:
      if (*(int *)param_1 == -0x7fffffda) goto LAB_14000410e;
    }
    if ((0x19930521 < (param_5->magicNumber_and_bbtFlags & 0x1fffffff)) &&
       ((param_5->EHFlags & 1) != 0)) {
      return 1;
    }
  }
LAB_14000410e:
  if (((byte)param_1[4] & 0x66) == 0) {
    if ((param_5->nTryBlocks == 0) &&
       ((((param_5->magicNumber_and_bbtFlags & 0x1fffffff) < 0x19930521 ||
         (param_5->dispESTypeList == 0)) ||
        (lVar2 = _GetImageBase(), lVar2 + (int)param_5->dispESTypeList == 0)))) {
      if ((param_5->magicNumber_and_bbtFlags & 0x1fffffff) < 0x19930522) {
        return 1;
      }
      if (((uint)param_5->EHFlags >> 2 & 1) == 0) {
        return 1;
      }
    }
    if (((*(int *)param_1 == -0x1f928c9d) && (2 < *(uint *)(param_1 + 0x18))) &&
       ((0x19930522 < *(uint *)(param_1 + 0x20) &&
        ((*(int *)(*(longlong *)(param_1 + 0x30) + 8) != 0 &&
         (lVar2 = _GetThrowImageBase(), lVar2 + *(int *)(*(longlong *)(param_1 + 0x30) + 8) != 0))))
       )) {
      uVar3 = (*(code *)PTR__guard_dispatch_icall_14000e260)
                        (param_1,param_2,param_3,param_4,param_5,param_6,param_7,
                         CONCAT44(uVar4,(uint)param_8));
      return uVar3;
    }
    FUN_140003858(param_1,param_2,param_3,param_4,param_5,param_8,param_6,param_7);
    return 1;
  }
  if (param_5->maxState == 0) {
    return 1;
  }
  if (param_6 != 0) {
    return 1;
  }
  if (((byte)param_1[4] & 0x20) == 0) {
LAB_140004193:
    __FrameHandler3::FrameUnwindToEmptyState(param_2,param_4,param_5);
  }
  else {
    if (*(int *)param_1 == -0x7fffffda) {
      iVar1 = FUN_14000345c((longlong)param_5,(longlong)param_4,*(ulonglong *)(param_4 + 0x20));
      if ((iVar1 < -1) || (param_5->maxState <= iVar1)) {
LAB_1400042bd:
                    /* WARNING: Subroutine does not return */
        abort();
      }
    }
    else {
      if (*(int *)param_1 != -0x7fffffd7) goto LAB_140004193;
      iVar1 = *(int *)(param_1 + 0x38);
      if ((iVar1 < -1) || (param_5->maxState <= iVar1)) goto LAB_1400042bd;
      param_2 = *(__uint64 **)(param_1 + 0x28);
    }
    FUN_140004628(param_2,(ulonglong *)param_4,param_5,iVar1);
  }
  return 1;
}



/*****************************************************************************
 * Function: FUN_1400042cc
 * Address: 1400042cc
 * Size: 60 bytes
 *****************************************************************************/


undefined8 * FUN_1400042cc(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy((longlong *)(param_2 + 8),param_1 + 1);
  *param_1 = std::bad_exception::vftable;
  return param_1;
}



/*****************************************************************************
 * Function: FUN_140004308
 * Address: 140004308
 * Size: 30 bytes
 *****************************************************************************/


undefined8 * FUN_140004308(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad exception";
  *param_1 = std::bad_exception::vftable;
  return param_1;
}



/*****************************************************************************
 * Function: exception
 * Address: 140004328
 * Size: 50 bytes
 *****************************************************************************/


/* Library Function - Single Match
    public: __cdecl std::exception::exception(class std::exception const & __ptr64) __ptr64
   
   Library: Visual Studio 2019 Release */

exception * __thiscall std::exception::exception(exception *this,exception *param_1)

{
  *(undefined ***)this = vftable;
  *(longlong *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  __std_exception_copy((longlong *)(param_1 + 8),(longlong *)(this + 8));
  return this;
}



/*****************************************************************************
 * Function: FUN_140004370
 * Address: 140004370
 * Size: 66 bytes
 *****************************************************************************/


undefined8 * FUN_140004370(undefined8 *param_1,uint param_2)

{
  *param_1 = std::exception::vftable;
  __std_exception_destroy(param_1 + 1);
  if ((param_2 & 1) != 0) {
    thunk_FUN_140005f9c(param_1);
  }
  return param_1;
}



/*****************************************************************************
 * Function: CxxCallCatchBlock
 * Address: 1400043b4
 * Size: 370 bytes
 *****************************************************************************/


/* Library Function - Single Match
    public: static void * __ptr64 __cdecl __FrameHandler3::CxxCallCatchBlock(struct
   _EXCEPTION_RECORD * __ptr64)
   
   Library: Visual Studio 2019 Release */

void * __cdecl __FrameHandler3::CxxCallCatchBlock(_EXCEPTION_RECORD *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int *piVar3;
  ULONG_PTR UVar4;
  ULONG_PTR UVar5;
  longlong *plVar6;
  int iVar7;
  longlong lVar8;
  undefined8 *puVar9;
  void *pvVar10;
  undefined8 local_48 [2];
  
  lVar8 = __vcrt_getptd();
  uVar1 = *(undefined8 *)(lVar8 + 0x28);
  lVar8 = __vcrt_getptd();
  uVar2 = *(undefined8 *)(lVar8 + 0x20);
  piVar3 = (int *)param_1->ExceptionInformation[6];
  UVar4 = param_1->ExceptionInformation[5];
  UVar5 = param_1->ExceptionInformation[4];
  plVar6 = (longlong *)param_1->ExceptionInformation[1];
  __except_validate_context_record(UVar5);
  lVar8 = __vcrt_getptd();
  *(int **)(lVar8 + 0x20) = piVar3;
  lVar8 = __vcrt_getptd();
  *(ULONG_PTR *)(lVar8 + 0x28) = UVar5;
  lVar8 = __vcrt_getptd();
  puVar9 = _CreateFrameInfo(local_48,*(undefined8 *)(*(longlong *)(lVar8 + 0x20) + 0x28));
  if (param_1->ExceptionInformation[7] != 0) {
    __vcrt_getptd();
  }
  pvVar10 = (void *)_CallSettingFrame();
  _FindAndUnlinkFrame((longlong)puVar9);
  if ((((*piVar3 == -0x1f928c9d) && (piVar3[6] == 4)) && (piVar3[8] + 0xe66cfae0U < 3)) &&
     (iVar7 = _IsExceptionObjectToBeDestroyed(*(longlong *)(piVar3 + 10)), iVar7 != 0)) {
    __DestructExceptionObject(piVar3);
  }
  lVar8 = __vcrt_getptd();
  *(undefined8 *)(lVar8 + 0x20) = uVar2;
  lVar8 = __vcrt_getptd();
  *(undefined8 *)(lVar8 + 0x28) = uVar1;
  *(undefined8 *)((longlong)*(int *)(UVar4 + 0x1c) + *plVar6) = 0xfffffffffffffffe;
  return pvVar10;
}



/*****************************************************************************
 * Function: ExFilterRethrow
 * Address: 1400045a0
 * Size: 134 bytes
 *****************************************************************************/


/* Library Function - Single Match
    int __cdecl ExFilterRethrow(struct _EXCEPTION_POINTERS * __ptr64,struct EHExceptionRecord *
   __ptr64,int * __ptr64)
   
   Library: Visual Studio 2015 Release */

int __cdecl ExFilterRethrow(_EXCEPTION_POINTERS *param_1,EHExceptionRecord *param_2,int *param_3)

{
  PEXCEPTION_RECORD pEVar1;
  longlong lVar2;
  int iVar3;
  
  pEVar1 = param_1->ExceptionRecord;
  *param_3 = 0;
  if (pEVar1->ExceptionCode == 0xe06d7363) {
    if ((pEVar1->NumberParameters == 4) && ((int)pEVar1->ExceptionInformation[0] + 0xe66cfae0U < 3))
    {
      iVar3 = *param_3;
      if (pEVar1->ExceptionInformation[1] == *(ULONG_PTR *)(param_2 + 0x28)) {
        iVar3 = 1;
      }
      *param_3 = iVar3;
    }
    if ((((pEVar1->ExceptionCode == 0xe06d7363) && (pEVar1->NumberParameters == 4)) &&
        ((int)pEVar1->ExceptionInformation[0] + 0xe66cfae0U < 3)) &&
       (pEVar1->ExceptionInformation[2] == 0)) {
      lVar2 = __vcrt_getptd();
      *(undefined4 *)(lVar2 + 0x40) = 1;
      *param_3 = 1;
      return 1;
    }
  }
  return 0;
}



/*****************************************************************************
 * Function: FUN_140004628
 * Address: 140004628
 * Size: 362 bytes
 *****************************************************************************/


void FUN_140004628(__uint64 *param_1,ulonglong *param_2,_s_FuncInfo *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  
  uVar3 = _GetImageBase();
  iVar2 = FUN_1400033b8((longlong *)param_1,param_2,(longlong)param_3);
  lVar4 = __vcrt_getptd();
  *(int *)(lVar4 + 0x30) = *(int *)(lVar4 + 0x30) + 1;
  while ((iVar2 != -1 && (param_4 < iVar2))) {
    if ((iVar2 < 0) || (param_3->maxState <= iVar2)) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
    lVar5 = (longlong)iVar2;
    lVar4 = _GetImageBase();
    iVar2 = *(int *)((longlong)(int)param_3->dispUnwindMap + lVar4 + lVar5 * 8);
    lVar4 = _GetImageBase();
    if (*(int *)((longlong)(int)param_3->dispUnwindMap + 4 + lVar4 + lVar5 * 8) == 0) {
      lVar4 = 0;
    }
    else {
      lVar4 = _GetImageBase();
      iVar1 = *(int *)((longlong)(int)param_3->dispUnwindMap + 4 + lVar4 + lVar5 * 8);
      lVar4 = _GetImageBase();
      lVar4 = lVar4 + iVar1;
    }
    if (lVar4 != 0) {
      __FrameHandler3::SetState(param_1,param_3,iVar2);
      lVar4 = _GetImageBase();
      if (*(int *)((longlong)(int)param_3->dispUnwindMap + 4 + lVar4 + lVar5 * 8) != 0) {
        _GetImageBase();
        _GetImageBase();
      }
      _CallSettingFrame();
      FUN_140002c54(uVar3);
    }
  }
  lVar4 = __vcrt_getptd();
  if (0 < *(int *)(lVar4 + 0x30)) {
    lVar4 = __vcrt_getptd();
    *(int *)(lVar4 + 0x30) = *(int *)(lVar4 + 0x30) + -1;
  }
  if ((iVar2 != -1) && (param_4 < iVar2)) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  __FrameHandler3::SetState(param_1,param_3,iVar2);
  return;
}



/*****************************************************************************
 * Function: GetHandlerSearchState
 * Address: 1400047b4
 * Size: 150 bytes
 *****************************************************************************/


/* Library Function - Single Match
    public: static int __cdecl __FrameHandler3::GetHandlerSearchState(unsigned __int64 *
   __ptr64,struct _xDISPATCHER_CONTEXT * __ptr64,struct _s_FuncInfo const * __ptr64)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl
__FrameHandler3::GetHandlerSearchState
          (__uint64 *param_1,_xDISPATCHER_CONTEXT *param_2,_s_FuncInfo *param_3)

{
  int iVar1;
  int iVar2;
  __uint64 local_res20;
  
  iVar1 = FUN_140003454((longlong)param_3,(ulonglong *)param_2);
  FUN_14000288c((longlong *)param_1,(ulonglong *)param_2,(longlong)param_3,(longlong *)&local_res20)
  ;
  iVar2 = GetUnwindTryBlock(param_1,param_2,param_3);
  if (iVar2 < iVar1) {
    SetState(&local_res20,param_3,iVar1);
    SetUnwindTryBlock(param_1,param_2,param_3,iVar1);
  }
  else {
    iVar1 = GetUnwindTryBlock(param_1,param_2,param_3);
  }
  return iVar1;
}



/*****************************************************************************
 * Function: FUN_14000484c
 * Address: 14000484c
 * Size: 236 bytes
 *****************************************************************************/


undefined1 FUN_14000484c(longlong param_1,int *param_2)

{
  _s_ThrowInfo *p_Var1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined1 uVar8;
  
  if (param_2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  uVar8 = 0;
  iVar5 = 0;
  if (0 < *param_2) {
    do {
      lVar3 = _GetThrowImageBase();
      piVar6 = (int *)((longlong)*(int *)(*(longlong *)(param_1 + 0x30) + 0xc) + 4 + lVar3);
      lVar3 = _GetThrowImageBase();
      iVar7 = *(int *)(lVar3 + *(int *)(*(longlong *)(param_1 + 0x30) + 0xc));
      if (0 < iVar7) {
        do {
          lVar3 = _GetThrowImageBase();
          p_Var1 = *(_s_ThrowInfo **)(param_1 + 0x30);
          iVar2 = *piVar6;
          lVar4 = _GetImageBase();
          iVar2 = TypeMatchHelper<class___FrameHandler3>
                            ((_s_HandlerType *)
                             ((longlong)param_2[1] + lVar4 + (longlong)iVar5 * 0x14),
                             (_s_CatchableType *)(lVar3 + iVar2),p_Var1);
          if (iVar2 != 0) {
            uVar8 = 1;
            break;
          }
          iVar7 = iVar7 + -1;
          piVar6 = piVar6 + 1;
        } while (0 < iVar7);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *param_2);
  }
  return uVar8;
}



/*****************************************************************************
 * Function: Is_bad_exception_allowed
 * Address: 14000493c
 * Size: 136 bytes
 *****************************************************************************/


/* Library Function - Single Match
    unsigned char __cdecl Is_bad_exception_allowed(struct _s_ESTypeList const * __ptr64)
   
   Library: Visual Studio 2019 Release */

uchar __cdecl Is_bad_exception_allowed(_s_ESTypeList *param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  
  iVar4 = 0;
  if (0 < *(int *)param_1) {
    lVar5 = 0;
    do {
      lVar3 = _GetImageBase();
      if (*(int *)((longlong)*(int *)(param_1 + 4) + 4 + lVar3 + lVar5) == 0) {
        lVar3 = 0;
      }
      else {
        lVar3 = _GetImageBase();
        iVar1 = *(int *)((longlong)*(int *)(param_1 + 4) + 4 + lVar3 + lVar5);
        lVar3 = _GetImageBase();
        lVar3 = lVar3 + iVar1;
      }
      uVar2 = __std_type_info_compare(lVar3 + 8,0x140018a18);
      if (uVar2 == 0) {
        return '\x01';
      }
      iVar4 = iVar4 + 1;
      lVar5 = lVar5 + 0x14;
    } while (iVar4 < *(int *)param_1);
  }
  return '\0';
}



/*****************************************************************************
 * Function: FUN_1400049c4
 * Address: 1400049c4
 * Size: 9 bytes
 *****************************************************************************/


void FUN_1400049c4(undefined8 param_1,undefined *UNRECOVERED_JUMPTABLE,undefined8 param_3)

{
                    /* WARNING: Could not recover jumptable at 0x0001400049ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)(param_1,param_3);
  return;
}



/*****************************************************************************
 * Function: _CallMemberFunction2
 * Address: 1400049d0
 * Size: 15 bytes
 *****************************************************************************/


/* Library Function - Single Match
    void __cdecl _CallMemberFunction2(void * __ptr64 const,void * __ptr64 const,void * __ptr64
   const,int)
   
   Library: Visual Studio 2019 Release */

void __cdecl _CallMemberFunction2(void *param_1,void *param_2,void *param_3,int param_4)

{
                    /* WARNING: Could not recover jumptable at 0x0001400049dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_2)(param_1,param_3,param_4);
  return;
}



/*****************************************************************************
 * Function: FUN_1400049e0
 * Address: 1400049e0
 * Size: 18 bytes
 *****************************************************************************/


char * FUN_1400049e0(longlong param_1)

{
  char *pcVar1;
  
  pcVar1 = "Unknown exception";
  if (*(longlong *)(param_1 + 8) != 0) {
    pcVar1 = *(char **)(param_1 + 8);
  }
  return pcVar1;
}



/*****************************************************************************
 * Function: _CallSettingFrame
 * Address: 140004a10
 * Size: 64 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _CallSettingFrame
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void _CallSettingFrame(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)_NLG_Notify();
  (*pcVar1)();
  FUN_140002240();
  _NLG_Notify();
  return;
}



/*****************************************************************************
 * Function: _CallSettingFrame_LookupContinuationIndex
 * Address: 140004a60
 * Size: 42 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _CallSettingFrame_LookupContinuationIndex
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void _CallSettingFrame_LookupContinuationIndex(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)_NLG_Notify();
  (*pcVar1)();
  FUN_140002240();
  return;
}



/*****************************************************************************
 * Function: _CallSettingFrame_NotifyContinuationAddr
 * Address: 140004a90
 * Size: 38 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _CallSettingFrame_NotifyContinuationAddr
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void _CallSettingFrame_NotifyContinuationAddr(void)

{
  _NLG_Notify();
  return;
}



/*****************************************************************************
 * Function: _CallSettingFrameEncoded
 * Address: 140004ac0
 * Size: 71 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _CallSettingFrameEncoded
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void _CallSettingFrameEncoded(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)_NLG_Notify();
  (*pcVar1)(param_3);
  FUN_140002240();
  _NLG_Notify();
  return;
}



/*****************************************************************************
 * Function: _CxxThrowException
 * Address: 140004bc0
 * Size: 160 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _CxxThrowException
   
   Library: Visual Studio 2019 Release */

void __stdcall _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
  ULONG_PTR UVar1;
  PVOID local_38;
  ULONG_PTR local_30;
  void *local_28;
  ThrowInfo *local_20;
  PVOID local_18;
  
  UVar1 = 0x19930520;
  if ((pThrowInfo != (ThrowInfo *)0x0) && ((pThrowInfo->attributes & 0x10) != 0)) {
                    /* WARNING: Load size is inaccurate */
    pThrowInfo = *(ThrowInfo **)(*(longlong *)(*pExceptionObject + -8) + 0x30);
    (*(code *)PTR__guard_dispatch_icall_14000e260)();
  }
  local_38 = RtlPcToFileHeader(pThrowInfo,&local_38);
  if ((pThrowInfo != (ThrowInfo *)0x0) &&
     (((pThrowInfo->attributes & 8) != 0 || (local_38 == (PVOID)0x0)))) {
    UVar1 = 0x1994000;
  }
  local_30 = UVar1;
  local_28 = pExceptionObject;
  local_20 = pThrowInfo;
  local_18 = local_38;
  RaiseException(0xe06d7363,1,4,&local_30);
  return;
}



/*****************************************************************************
 * Function: FUN_140004c60
 * Address: 140004c60
 * Size: 385 bytes
 *****************************************************************************/


undefined4 FUN_140004c60(int param_1,undefined8 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  longlong lVar3;
  undefined8 uVar4;
  __acrt_ptd *p_Var5;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  
  p_Var5 = FUN_14000671c();
  if (p_Var5 != (__acrt_ptd *)0x0) {
    piVar2 = *(int **)p_Var5;
    for (piVar6 = piVar2; piVar6 != piVar2 + 0x30; piVar6 = piVar6 + 4) {
      if (*piVar6 == param_1) {
        if (piVar6 == (int *)0x0) {
          return 0;
        }
        lVar3 = *(longlong *)(piVar6 + 2);
        if (lVar3 == 0) {
          return 0;
        }
        if (lVar3 == 5) {
          piVar6[2] = 0;
          piVar6[3] = 0;
          return 1;
        }
        if (lVar3 != 1) {
          uVar4 = *(undefined8 *)(p_Var5 + 8);
          *(undefined8 *)(p_Var5 + 8) = param_2;
          if (piVar6[1] == 8) {
            for (piVar7 = piVar2 + 0xc; piVar7 != piVar2 + 0x30; piVar7 = piVar7 + 4) {
              piVar7[2] = 0;
              piVar7[3] = 0;
            }
            uVar1 = *(undefined4 *)(p_Var5 + 0x10);
            if (*piVar6 == -0x3fffff73) {
              uVar8 = 0x82;
LAB_140004d9e:
              *(undefined4 *)(p_Var5 + 0x10) = uVar8;
            }
            else {
              if (*piVar6 == -0x3fffff72) {
                uVar8 = 0x83;
                goto LAB_140004d9e;
              }
              if (*piVar6 == -0x3fffff71) {
                uVar8 = 0x86;
                goto LAB_140004d9e;
              }
              if (*piVar6 == -0x3fffff70) {
                uVar8 = 0x81;
                goto LAB_140004d9e;
              }
              if (*piVar6 == -0x3fffff6f) {
                uVar8 = 0x84;
                goto LAB_140004d9e;
              }
              if (*piVar6 == -0x3fffff6e) {
                uVar8 = 0x8a;
                goto LAB_140004d9e;
              }
              if (*piVar6 == -0x3fffff6d) {
                uVar8 = 0x85;
                goto LAB_140004d9e;
              }
              if (*piVar6 == -0x3ffffd4c) {
                uVar8 = 0x8e;
                goto LAB_140004d9e;
              }
              uVar8 = uVar1;
              if (*piVar6 == -0x3ffffd4b) {
                uVar8 = 0x8d;
                goto LAB_140004d9e;
              }
            }
            (*(code *)PTR__guard_dispatch_icall_14000e268)(8,uVar8);
            *(undefined4 *)(p_Var5 + 0x10) = uVar1;
          }
          else {
            piVar6[2] = 0;
            piVar6[3] = 0;
            (*(code *)PTR__guard_dispatch_icall_14000e268)(piVar6[1]);
          }
          *(undefined8 *)(p_Var5 + 8) = uVar4;
        }
        return 0xffffffff;
      }
    }
  }
  return 0;
}



/*****************************************************************************
 * Function: FUN_140004de4
 * Address: 140004de4
 * Size: 7 bytes
 *****************************************************************************/


undefined4 FUN_140004de4(void)

{
  return DAT_140018c60;
}



/*****************************************************************************
 * Function: FUN_140004dec
 * Address: 140004dec
 * Size: 7 bytes
 *****************************************************************************/


void FUN_140004dec(undefined4 param_1)

{
  DAT_140018c60 = param_1;
  return;
}



/*****************************************************************************
 * Function: FUN_140004df4
 * Address: 140004df4
 * Size: 29 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_140004df4(void)

{
  byte bVar1;
  
  bVar1 = (byte)DAT_140018038 & 0x3f;
  return (DAT_140018038 ^ _DAT_140018c68) >> bVar1 != 0 ||
         (DAT_140018038 ^ _DAT_140018c68) << 0x40 - bVar1 != 0;
}



/*****************************************************************************
 * Function: FUN_140004e14
 * Address: 140004e14
 * Size: 8 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140004e14(undefined8 param_1)

{
  _DAT_140018c68 = param_1;
  return;
}



/*****************************************************************************
 * Function: FUN_140004e1c
 * Address: 140004e1c
 * Size: 56 bytes
 *****************************************************************************/


/* WARNING: Switch with 1 destination removed at 0x000140004e4d */
/* WARNING: Switch with 1 destination removed at 0x00014000d920 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140004e1c(undefined8 param_1)

{
  undefined8 uVar1;
  byte bVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  bVar2 = (byte)DAT_140018038 & 0x3f;
  UNRECOVERED_JUMPTABLE =
       (code *)((DAT_140018038 ^ _DAT_140018c68) >> bVar2 |
               (DAT_140018038 ^ _DAT_140018c68) << 0x40 - bVar2);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00014000d900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)(param_1);
    return uVar1;
  }
  return 0;
}



/*****************************************************************************
 * Function: FUN_140004e54
 * Address: 140004e54
 * Size: 37 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140004e54(ulonglong param_1)

{
  byte bVar1;
  
  bVar1 = 0x40 - ((byte)DAT_140018038 & 0x3f) & 0x3f;
  _DAT_140018c68 = (param_1 >> bVar1 | param_1 << 0x40 - bVar1) ^ DAT_140018038;
  return;
}



/*****************************************************************************
 * Function: FUN_140004e7c
 * Address: 140004e7c
 * Size: 418 bytes
 *****************************************************************************/


void FUN_140004e7c(short *param_1,undefined8 *param_2,short *param_3,longlong *param_4,
                  longlong *param_5)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  bVar1 = false;
  do {
    sVar4 = 0x22;
    if (*param_1 == 0x22) {
      bVar1 = !bVar1;
    }
    else {
      *param_5 = *param_5 + 1;
      if (param_3 != (short *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      sVar4 = *param_1;
      if (sVar4 == 0) goto LAB_140004f13;
    }
    param_1 = param_1 + 1;
  } while ((bVar1) || ((sVar4 != 0x20 && (sVar4 != 9))));
  if (param_3 != (short *)0x0) {
    param_3[-1] = 0;
  }
LAB_140004f13:
  bVar1 = false;
  while (sVar4 = *param_1, sVar4 != 0) {
    while ((sVar4 == 0x20 || (sVar4 == 9))) {
      param_1 = param_1 + 1;
      sVar4 = *param_1;
    }
    if (sVar4 == 0) break;
    if (param_2 != (undefined8 *)0x0) {
      *param_2 = param_3;
      param_2 = param_2 + 1;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      uVar3 = 1;
      uVar2 = 0;
      for (; *param_1 == 0x5c; param_1 = param_1 + 1) {
        uVar2 = uVar2 + 1;
      }
      if (*param_1 == 0x22) {
        if ((uVar2 & 1) == 0) {
          if ((bVar1) && (param_1[1] == 0x22)) {
            param_1 = param_1 + 1;
          }
          else {
            bVar1 = !bVar1;
            uVar3 = 0;
          }
        }
        uVar2 = uVar2 >> 1;
      }
      while (uVar2 != 0) {
        uVar2 = uVar2 - 1;
        if (param_3 != (short *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      sVar4 = *param_1;
      if ((sVar4 == 0) || ((!bVar1 && ((sVar4 == 0x20 || (sVar4 == 9)))))) break;
      if (uVar3 != 0) {
        if (param_3 != (short *)0x0) {
          *param_3 = sVar4;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      param_1 = param_1 + 1;
    }
    if (param_3 != (short *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *param_5 = *param_5 + 1;
  }
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}



/*****************************************************************************
 * Function: _configure_wide_argv
 * Address: 140005080
 * Size: 386 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _configure_wide_argv
   
   Library: Visual Studio 2019 Release */

int _configure_wide_argv(int param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  __acrt_ptd *p_Var4;
  longlong *plVar5;
  longlong *plVar6;
  int iVar7;
  short *psVar8;
  longlong *local_res10;
  ulonglong local_res18;
  ulonglong local_res20;
  
  iVar7 = 0;
  if (param_1 != 0) {
    if (param_1 - 1U < 2) {
      GetModuleFileNameW((HMODULE)0x0,(LPWSTR)&DAT_140018c70,0x104);
      _DAT_140018f18 = &DAT_140018c70;
      if ((DAT_140018f40 == (short *)0x0) || (psVar8 = DAT_140018f40, *DAT_140018f40 == 0)) {
        psVar8 = (short *)&DAT_140018c70;
      }
      local_res18 = 0;
      local_res20 = 0;
      FUN_140004e7c(psVar8,(undefined8 *)0x0,(short *)0x0,(longlong *)&local_res18,
                    (longlong *)&local_res20);
      uVar2 = local_res18;
      plVar5 = (longlong *)__acrt_allocate_buffer_for_argv(local_res18,local_res20,2);
      if (plVar5 == (longlong *)0x0) {
        p_Var4 = FUN_140006ee4();
        iVar7 = 0xc;
        *(undefined4 *)p_Var4 = 0xc;
        FUN_140006f7c((LPVOID)0x0);
      }
      else {
        FUN_140004e7c(psVar8,plVar5,(short *)(plVar5 + uVar2),(longlong *)&local_res18,
                      (longlong *)&local_res20);
        if (param_1 == 1) {
          _DAT_140018f20 = (int)local_res18 + -1;
          plVar6 = (longlong *)0x0;
          DAT_140018f30 = plVar5;
        }
        else {
          local_res10 = (longlong *)0x0;
          iVar3 = thunk_FUN_140006fcc(plVar5,&local_res10);
          plVar6 = local_res10;
          if (iVar3 != 0) {
            FUN_140006f7c(local_res10);
            local_res10 = (longlong *)0x0;
            FUN_140006f7c(plVar5);
            return iVar3;
          }
          _DAT_140018f20 = 0;
          lVar1 = *local_res10;
          while (lVar1 != 0) {
            local_res10 = local_res10 + 1;
            _DAT_140018f20 = _DAT_140018f20 + 1;
            lVar1 = *local_res10;
          }
          local_res10 = (longlong *)0x0;
          DAT_140018f30 = plVar6;
          FUN_140006f7c((LPVOID)0x0);
          local_res10 = (longlong *)0x0;
          plVar6 = plVar5;
        }
        FUN_140006f7c(plVar6);
      }
    }
    else {
      p_Var4 = FUN_140006ee4();
      iVar7 = 0x16;
      *(undefined4 *)p_Var4 = 0x16;
      FUN_140006c8c();
    }
  }
  return iVar7;
}



/*****************************************************************************
 * Function: FUN_140005204
 * Address: 140005204
 * Size: 110 bytes
 *****************************************************************************/


undefined8 FUN_140005204(void)

{
  undefined8 *puVar1;
  LPWCH pWVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  uVar3 = 0;
  if (DAT_140018e88 == (undefined8 *)0x0) {
    pWVar2 = FUN_140008254();
    if (pWVar2 == (LPWCH)0x0) {
      FUN_140006f7c((LPVOID)0x0);
      uVar3 = 0xffffffff;
    }
    else {
      puVar4 = FUN_140005274(pWVar2);
      puVar1 = puVar4;
      if (puVar4 == (undefined8 *)0x0) {
        uVar3 = 0xffffffff;
        puVar4 = DAT_140018e88;
        puVar1 = DAT_140018e90;
      }
      DAT_140018e90 = puVar1;
      DAT_140018e88 = puVar4;
      FUN_140006f7c((LPVOID)0x0);
      FUN_140006f7c(pWVar2);
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/*****************************************************************************
 * Function: FUN_140005274
 * Address: 140005274
 * Size: 282 bytes
 *****************************************************************************/


undefined8 * FUN_140005274(wchar_t *param_1)

{
  errno_t eVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  wchar_t *pwVar5;
  wchar_t wVar6;
  longlong lVar7;
  ulonglong _SizeInWords;
  undefined8 *puVar8;
  
  wVar6 = *param_1;
  lVar7 = 0;
  pwVar5 = param_1;
  while (wVar6 != L'\0') {
    lVar2 = lVar7 + 1;
    if (wVar6 == L'=') {
      lVar2 = lVar7;
    }
    lVar7 = -1;
    do {
      lVar3 = lVar7;
      lVar7 = lVar3 + 1;
    } while (pwVar5[lVar7] != L'\0');
    pwVar5 = pwVar5 + lVar3 + 2;
    lVar7 = lVar2;
    wVar6 = *pwVar5;
  }
  puVar4 = (undefined8 *)_calloc_base(lVar7 + 1,8);
  puVar8 = puVar4;
  if (puVar4 == (undefined8 *)0x0) {
LAB_1400052df:
    FUN_140006f7c((LPVOID)0x0);
    puVar4 = (undefined8 *)0x0;
  }
  else {
    for (; *param_1 != L'\0'; param_1 = param_1 + _SizeInWords) {
      lVar7 = -1;
      do {
        lVar2 = lVar7;
        lVar7 = lVar2 + 1;
      } while (param_1[lVar7] != L'\0');
      _SizeInWords = lVar2 + 2;
      if (*param_1 != L'=') {
        pwVar5 = (wchar_t *)_calloc_base(_SizeInWords,2);
        if (pwVar5 == (wchar_t *)0x0) {
          free_environment<>(puVar4);
          FUN_140006f7c((LPVOID)0x0);
          goto LAB_1400052df;
        }
        eVar1 = wcscpy_s(pwVar5,_SizeInWords,param_1);
        if (eVar1 != 0) {
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        *puVar8 = pwVar5;
        puVar8 = puVar8 + 1;
        FUN_140006f7c((LPVOID)0x0);
      }
    }
    FUN_140006f7c((LPVOID)0x0);
  }
  return puVar4;
}



/*****************************************************************************
 * Function: free_environment<>
 * Address: 140005390
 * Size: 65 bytes
 *****************************************************************************/


/* Library Function - Multiple Matches With Same Base Name
    void __cdecl free_environment<char>(char * __ptr64 * __ptr64 const)
    void __cdecl free_environment<wchar_t>(wchar_t * __ptr64 * __ptr64 const)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void free_environment<>(undefined8 *param_1)

{
  LPVOID pvVar1;
  undefined8 *puVar2;
  
  if (param_1 != (undefined8 *)0x0) {
    pvVar1 = (LPVOID)*param_1;
    puVar2 = param_1;
    while (pvVar1 != (LPVOID)0x0) {
      FUN_140006f7c(pvVar1);
      puVar2 = puVar2 + 1;
      pvVar1 = (LPVOID)*puVar2;
    }
    FUN_140006f7c(param_1);
  }
  return;
}



/*****************************************************************************
 * Function: uninitialize_environment_internal<>
 * Address: 1400053d4
 * Size: 26 bytes
 *****************************************************************************/


/* Library Function - Multiple Matches With Same Base Name
    void __cdecl uninitialize_environment_internal<char>(char * __ptr64 * __ptr64 & __ptr64)
    void __cdecl uninitialize_environment_internal<wchar_t>(wchar_t * __ptr64 * __ptr64 & __ptr64)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void uninitialize_environment_internal<>(undefined8 *param_1)

{
  if ((undefined8 *)*param_1 != DAT_140018e98) {
    free_environment<>((undefined8 *)*param_1);
  }
  return;
}



/*****************************************************************************
 * Function: uninitialize_environment_internal<>
 * Address: 1400053f0
 * Size: 26 bytes
 *****************************************************************************/


/* Library Function - Multiple Matches With Same Base Name
    void __cdecl uninitialize_environment_internal<char>(char * __ptr64 * __ptr64 & __ptr64)
    void __cdecl uninitialize_environment_internal<wchar_t>(wchar_t * __ptr64 * __ptr64 & __ptr64)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void uninitialize_environment_internal<>(undefined8 *param_1)

{
  if ((undefined8 *)*param_1 != DAT_140018e90) {
    free_environment<>((undefined8 *)*param_1);
  }
  return;
}



/*****************************************************************************
 * Function: FUN_14000540c
 * Address: 14000540c
 * Size: 67 bytes
 *****************************************************************************/


void FUN_14000540c(void)

{
  uninitialize_environment_internal<>((undefined8 *)&DAT_140018e80);
  uninitialize_environment_internal<>(&DAT_140018e88);
  free_environment<>(DAT_140018e98);
  free_environment<>(DAT_140018e90);
  return;
}



/*****************************************************************************
 * Function: thunk_FUN_140005204
 * Address: 140005450
 * Size: 5 bytes
 *****************************************************************************/


undefined8 thunk_FUN_140005204(void)

{
  undefined8 *puVar1;
  LPWCH pWVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  uVar3 = 0;
  if (DAT_140018e88 == (undefined8 *)0x0) {
    pWVar2 = FUN_140008254();
    if (pWVar2 == (LPWCH)0x0) {
      FUN_140006f7c((LPVOID)0x0);
      uVar3 = 0xffffffff;
    }
    else {
      puVar4 = FUN_140005274(pWVar2);
      puVar1 = puVar4;
      if (puVar4 == (undefined8 *)0x0) {
        uVar3 = 0xffffffff;
        puVar4 = DAT_140018e88;
        puVar1 = DAT_140018e90;
      }
      DAT_140018e90 = puVar1;
      DAT_140018e88 = puVar4;
      FUN_140006f7c((LPVOID)0x0);
      FUN_140006f7c(pWVar2);
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/*****************************************************************************
 * Function: _get_wide_winmain_command_line
 * Address: 140005458
 * Size: 84 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _get_wide_winmain_command_line
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

ushort * _get_wide_winmain_command_line(void)

{
  bool bVar1;
  ushort uVar2;
  ushort *puVar3;
  
  puVar3 = &DAT_140018ea0;
  bVar1 = false;
  if (DAT_140018f40 != (ushort *)0x0) {
    puVar3 = DAT_140018f40;
    bVar1 = false;
  }
  do {
    uVar2 = *puVar3;
    if (uVar2 < 0x21) {
      if (uVar2 == 0) {
        return puVar3;
      }
      if (!bVar1) {
        do {
          if (0x20 < uVar2) {
            return puVar3;
          }
          puVar3 = puVar3 + 1;
          uVar2 = *puVar3;
        } while (uVar2 != 0);
        return puVar3;
      }
    }
    if (uVar2 == 0x22) {
      bVar1 = !bVar1;
    }
    puVar3 = puVar3 + 1;
  } while( true );
}



/*****************************************************************************
 * Function: FUN_1400054ac
 * Address: 1400054ac
 * Size: 65 bytes
 *****************************************************************************/


void FUN_1400054ac(undefined8 *param_1,undefined8 *param_2)

{
  if (param_1 != param_2) {
    do {
      if (*param_1 != 0) {
        (*(code *)PTR__guard_dispatch_icall_14000e268)();
      }
      param_1 = param_1 + 1;
    } while (param_1 != param_2);
  }
  return;
}



/*****************************************************************************
 * Function: FUN_1400054f0
 * Address: 1400054f0
 * Size: 71 bytes
 *****************************************************************************/


undefined8 FUN_1400054f0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  bool bVar2;
  
  bVar2 = param_1 == param_2;
  while( true ) {
    if (bVar2) {
      return 0;
    }
    if ((*param_1 != 0) &&
       (uVar1 = (*(code *)PTR__guard_dispatch_icall_14000e268)(), (int)uVar1 != 0)) break;
    param_1 = param_1 + 1;
    bVar2 = param_1 == param_2;
  }
  return uVar1;
}



/*****************************************************************************
 * Function: operator()<>
 * Address: 140005538
 * Size: 56 bytes
 *****************************************************************************/


/* Library Function - Multiple Matches With Same Base Name
    public: void __cdecl __crt_seh_guarded_call<void>::operator()<class
   <lambda_99476a1ad63dd22509b5d3e65b0ffc95>,class <lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c> &
   __ptr64,class <lambda_f7424dd8d45958661754dc4f2697e9c3> >(class
   <lambda_99476a1ad63dd22509b5d3e65b0ffc95> && __ptr64,class
   <lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c> & __ptr64,class
   <lambda_f7424dd8d45958661754dc4f2697e9c3> && __ptr64) __ptr64
    public: void __cdecl __crt_seh_guarded_call<void>::operator()<class
   <lambda_d80eeec6fff315bfe5c115232f3240e3>,class <lambda_6e4b09c48022b2350581041d5f6b0c4c> &
   __ptr64,class <lambda_2358e3775559c9db80273638284d5e45> >(class
   <lambda_d80eeec6fff315bfe5c115232f3240e3> && __ptr64,class
   <lambda_6e4b09c48022b2350581041d5f6b0c4c> & __ptr64,class
   <lambda_2358e3775559c9db80273638284d5e45> && __ptr64) __ptr64
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void operator()<>(undefined8 param_1,int *param_2,undefined8 *param_3,int *param_4)

{
  __acrt_lock(*param_2);
  FUN_140005570(param_3);
  __acrt_unlock(*param_4);
  return;
}



/*****************************************************************************
 * Function: FUN_140005570
 * Address: 140005570
 * Size: 197 bytes
 *****************************************************************************/


void FUN_140005570(undefined8 *param_1)

{
  undefined *puVar1;
  
  if (DAT_140018eb0 != '\0') {
    return;
  }
  LOCK();
  DAT_140018ea4 = 1;
  UNLOCK();
  if (*(int *)*param_1 == 0) {
    if (DAT_140018ea8 != DAT_140018038) {
      (*(code *)PTR__guard_dispatch_icall_14000e268)(0,0,0);
    }
    puVar1 = &DAT_140018ec0;
  }
  else {
    if (*(int *)*param_1 != 1) goto LAB_1400055ea;
    puVar1 = &DAT_140018ed8;
  }
  FUN_140005d44(puVar1);
LAB_1400055ea:
  if (*(int *)*param_1 == 0) {
    FUN_1400054ac((undefined8 *)&DAT_14000e2e0,(undefined8 *)&DAT_14000e300);
  }
  FUN_1400054ac((undefined8 *)&DAT_14000e308,(undefined8 *)&DAT_14000e310);
  if (*(int *)param_1[1] == 0) {
    DAT_140018eb0 = '\x01';
    *(undefined1 *)param_1[2] = 1;
  }
  return;
}



/*****************************************************************************
 * Function: FUN_14000563c
 * Address: 14000563c
 * Size: 197 bytes
 *****************************************************************************/


void FUN_14000563c(UINT param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  HMODULE pHVar2;
  int *piVar3;
  undefined4 local_res10 [2];
  int local_res18 [2];
  undefined1 local_res20 [8];
  undefined1 local_38 [4];
  int local_34 [3];
  undefined8 local_28;
  undefined4 *local_20;
  int *local_18;
  undefined1 *local_10;
  
  local_28 = 0xfffffffffffffffe;
  local_res10[0] = param_2;
  local_res18[0] = param_3;
  if (param_3 == 0) {
    pHVar2 = GetModuleHandleW((LPCWSTR)0x0);
    if ((((pHVar2 != (HMODULE)0x0) && ((short)pHVar2->unused == 0x5a4d)) &&
        (piVar3 = (int *)((longlong)&pHVar2->unused + (longlong)pHVar2[0xf].unused),
        *piVar3 == 0x4550)) &&
       ((((short)piVar3[6] == 0x20b && (0xe < (uint)piVar3[0x21])) && (piVar3[0x3e] != 0)))) {
      FUN_140005768(param_1);
    }
  }
  local_res20[0] = 0;
  local_20 = local_res10;
  local_18 = local_res18;
  local_10 = local_res20;
  local_34[0] = 2;
  local_34[1] = 2;
  operator()<>(local_38,local_34 + 1,&local_20,local_34);
  if (local_res18[0] != 0) {
    return;
  }
  FUN_140005704(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/*****************************************************************************
 * Function: FUN_140005704
 * Address: 140005704
 * Size: 49 bytes
 *****************************************************************************/


void FUN_140005704(UINT param_1)

{
  undefined4 uVar1;
  HANDLE hProcess;
  
  uVar1 = FUN_140005738();
  if ((char)uVar1 != '\0') {
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,param_1);
  }
  FUN_140005768(param_1);
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}



/*****************************************************************************
 * Function: FUN_140005738
 * Address: 140005738
 * Size: 48 bytes
 *****************************************************************************/


int FUN_140005738(void)

{
  int iVar1;
  uint3 uVar2;
  
  iVar1 = __acrt_get_process_end_policy();
  uVar2 = (uint3)((uint)iVar1 >> 8);
  if ((iVar1 == 1) || ((*(uint *)((longlong)ProcessEnvironmentBlock + 0xbc) >> 8 & 1) != 0)) {
    iVar1 = (uint)uVar2 << 8;
  }
  else {
    iVar1 = CONCAT31(uVar2,1);
  }
  return iVar1;
}



/*****************************************************************************
 * Function: FUN_140005768
 * Address: 140005768
 * Size: 111 bytes
 *****************************************************************************/


void FUN_140005768(undefined4 param_1)

{
  BOOL BVar1;
  FARPROC pFVar2;
  HMODULE local_res10 [3];
  
  local_res10[0] = (HMODULE)0x0;
  BVar1 = GetModuleHandleExW(0,L"mscoree.dll",local_res10);
  if ((BVar1 != 0) &&
     (pFVar2 = GetProcAddress(local_res10[0],"CorExitProcess"), pFVar2 != (FARPROC)0x0)) {
    (*(code *)PTR__guard_dispatch_icall_14000e268)(param_1);
  }
  if (local_res10[0] != (HMODULE)0x0) {
    FreeLibrary(local_res10[0]);
  }
  return;
}



/*****************************************************************************
 * Function: FUN_1400057d8
 * Address: 1400057d8
 * Size: 8 bytes
 *****************************************************************************/


void FUN_1400057d8(undefined8 param_1)

{
  DAT_140018ea8 = param_1;
  return;
}



/*****************************************************************************
 * Function: FUN_1400057f0
 * Address: 1400057f0
 * Size: 13 bytes
 *****************************************************************************/


void FUN_1400057f0(void)

{
  FUN_14000563c(0,0,1);
  return;
}



/*****************************************************************************
 * Function: FUN_140005800
 * Address: 140005800
 * Size: 12 bytes
 *****************************************************************************/


void FUN_140005800(UINT param_1)

{
  FUN_14000563c(param_1,2,0);
  return;
}



/*****************************************************************************
 * Function: FUN_14000580c
 * Address: 14000580c
 * Size: 62 bytes
 *****************************************************************************/


void FUN_14000580c(ulonglong param_1)

{
  code *pcVar1;
  byte bVar2;
  
  if (DAT_140018ea8 == DAT_140018038) {
    bVar2 = 0x40 - ((byte)DAT_140018038 & 0x3f) & 0x3f;
    DAT_140018ea8 = (param_1 >> bVar2 | param_1 << 0x40 - bVar2) ^ DAT_140018038;
    return;
  }
  FUN_140005f70();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/*****************************************************************************
 * Function: FUN_14000584c
 * Address: 14000584c
 * Size: 10 bytes
 *****************************************************************************/


void FUN_14000584c(UINT param_1)

{
  FUN_14000563c(param_1,0,0);
  return;
}



/*****************************************************************************
 * Function: _set_fmode
 * Address: 140005858
 * Size: 61 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _set_fmode
   
   Library: Visual Studio 2012 Release */

errno_t __cdecl _set_fmode(int _Mode)

{
  errno_t eVar1;
  __acrt_ptd *p_Var2;
  
  if (((_Mode - 0x4000U & 0xffff3fff) == 0) && (_Mode != 0xc000)) {
    LOCK();
    UNLOCK();
    eVar1 = 0;
    DAT_140019184 = _Mode;
  }
  else {
    p_Var2 = FUN_140006ee4();
    *(undefined4 *)p_Var2 = 0x16;
    FUN_140006c8c();
    eVar1 = 0x16;
  }
  return eVar1;
}



/*****************************************************************************
 * Function: operator()<class_<lambda_410d79af7f07d98d83a3f525b3859a53>,class_<lambda_3e16ef9562a7dcce91392c22ab16ea36>&___ptr64,class_<lambda_38119f0e861e05405d8a144b9b982f0a>_>
 * Address: 140005898
 * Size: 110 bytes
 *****************************************************************************/


/* Library Function - Single Match
    public: void __cdecl __crt_seh_guarded_call<void>::operator()<class
   <lambda_410d79af7f07d98d83a3f525b3859a53>,class <lambda_3e16ef9562a7dcce91392c22ab16ea36> &
   __ptr64,class <lambda_38119f0e861e05405d8a144b9b982f0a> >(class
   <lambda_410d79af7f07d98d83a3f525b3859a53> && __ptr64,class
   <lambda_3e16ef9562a7dcce91392c22ab16ea36> & __ptr64,class
   <lambda_38119f0e861e05405d8a144b9b982f0a> && __ptr64) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<class_<lambda_410d79af7f07d98d83a3f525b3859a53>,class_<lambda_3e16ef9562a7dcce91392c22ab16ea36>&___ptr64,class_<lambda_38119f0e861e05405d8a144b9b982f0a>_>
          (__crt_seh_guarded_call<void> *this,<lambda_410d79af7f07d98d83a3f525b3859a53> *param_1,
          <lambda_3e16ef9562a7dcce91392c22ab16ea36> *param_2,
          <lambda_38119f0e861e05405d8a144b9b982f0a> *param_3)

{
  undefined **ppuVar1;
  longlong *plVar2;
  
  __acrt_lock(*(int *)param_1);
  for (plVar2 = &DAT_140019598; plVar2 != &DAT_1400195a0; plVar2 = plVar2 + 1) {
    if ((undefined **)*plVar2 != &PTR_DAT_1400185b0) {
      ppuVar1 = _updatetlocinfoEx_nolock(plVar2,&PTR_DAT_1400185b0);
      *plVar2 = (longlong)ppuVar1;
    }
  }
  __acrt_unlock(*(int *)param_3);
  return;
}



/*****************************************************************************
 * Function: FUN_140005908
 * Address: 140005908
 * Size: 12 bytes
 *****************************************************************************/


undefined4 FUN_140005908(void)

{
  undefined4 uVar1;
  
  uVar1 = DAT_140018eb4;
  LOCK();
  DAT_140018eb4 = 1;
  UNLOCK();
  return uVar1;
}



/*****************************************************************************
 * Function: _configthreadlocale
 * Address: 140005944
 * Size: 105 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _configthreadlocale
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl _configthreadlocale(int _Flag)

{
  uint uVar1;
  __acrt_ptd *p_Var2;
  uint uVar3;
  
  p_Var2 = FUN_1400065a4();
  uVar1 = *(uint *)(p_Var2 + 0x3a8);
  if (_Flag == -1) {
    DAT_1400187c0 = 0xffffffff;
  }
  else if (_Flag != 0) {
    if (_Flag == 1) {
      uVar3 = uVar1 | 2;
    }
    else {
      if (_Flag != 2) {
        p_Var2 = FUN_140006ee4();
        *(undefined4 *)p_Var2 = 0x16;
        FUN_140006c8c();
        return -1;
      }
      uVar3 = uVar1 & 0xfffffffd;
    }
    *(uint *)(p_Var2 + 0x3a8) = uVar3;
  }
  return 2 - (uint)((uVar1 & 2) != 0);
}



/*****************************************************************************
 * Function: FUN_1400059b0
 * Address: 1400059b0
 * Size: 7 bytes
 *****************************************************************************/


undefined4 FUN_1400059b0(void)

{
  return DAT_140018eb8;
}



/*****************************************************************************
 * Function: FUN_1400059b8
 * Address: 1400059b8
 * Size: 43 bytes
 *****************************************************************************/


uint FUN_1400059b8(uint param_1)

{
  uint uVar1;
  __acrt_ptd *p_Var2;
  
  if (param_1 < 2) {
    LOCK();
    UNLOCK();
    uVar1 = DAT_140018eb8;
    DAT_140018eb8 = param_1;
  }
  else {
    p_Var2 = FUN_140006ee4();
    *(undefined4 *)p_Var2 = 0x16;
    FUN_140006c8c();
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/*****************************************************************************
 * Function: FUN_1400059e4
 * Address: 1400059e4
 * Size: 8 bytes
 *****************************************************************************/


undefined * FUN_1400059e4(void)

{
  return &DAT_140018ebc;
}



/*****************************************************************************
 * Function: operator()<>
 * Address: 1400059ec
 * Size: 59 bytes
 *****************************************************************************/


/* Library Function - Multiple Matches With Same Base Name
    public: int __cdecl __crt_seh_guarded_call<int>::operator()<class
   <lambda_638799b9deba96c50f710eeac98168cd>,class <lambda_22ebabd17bc4fa466a2aca6d8deb888d> &
   __ptr64,class <lambda_a6f7d7db0129f75315ebf26d50c089f1> >(class
   <lambda_638799b9deba96c50f710eeac98168cd> && __ptr64,class
   <lambda_22ebabd17bc4fa466a2aca6d8deb888d> & __ptr64,class
   <lambda_a6f7d7db0129f75315ebf26d50c089f1> && __ptr64) __ptr64
    public: int __cdecl __crt_seh_guarded_call<int>::operator()<class
   <lambda_b8c45f8f788dd370798f47cfe8ac3a86>,class <lambda_4e60a939b0d047cfe11ddc22648dfba9> &
   __ptr64,class <lambda_332c3edc96d0294ec56c57d38c1cdfd5> >(class
   <lambda_b8c45f8f788dd370798f47cfe8ac3a86> && __ptr64,class
   <lambda_4e60a939b0d047cfe11ddc22648dfba9> & __ptr64,class
   <lambda_332c3edc96d0294ec56c57d38c1cdfd5> && __ptr64) __ptr64
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

ulonglong operator()<>(undefined8 param_1,int *param_2,undefined8 *param_3,int *param_4)

{
  ulonglong uVar1;
  
  __acrt_lock(*param_2);
  uVar1 = FUN_140005a64(param_3);
  __acrt_unlock(*param_4);
  return uVar1 & 0xffffffff;
}



/*****************************************************************************
 * Function: operator()<>
 * Address: 140005a28
 * Size: 59 bytes
 *****************************************************************************/


/* Library Function - Multiple Matches With Same Base Name
    public: int __cdecl __crt_seh_guarded_call<int>::operator()<class
   <lambda_638799b9deba96c50f710eeac98168cd>,class <lambda_22ebabd17bc4fa466a2aca6d8deb888d> &
   __ptr64,class <lambda_a6f7d7db0129f75315ebf26d50c089f1> >(class
   <lambda_638799b9deba96c50f710eeac98168cd> && __ptr64,class
   <lambda_22ebabd17bc4fa466a2aca6d8deb888d> & __ptr64,class
   <lambda_a6f7d7db0129f75315ebf26d50c089f1> && __ptr64) __ptr64
    public: int __cdecl __crt_seh_guarded_call<int>::operator()<class
   <lambda_7777bce6b2f8c936911f934f8298dc43>,class <lambda_f03950bc5685219e0bcd2087efbe011e> &
   __ptr64,class <lambda_3883c3dff614d5e0c5f61bb1ac94921c> >(class
   <lambda_7777bce6b2f8c936911f934f8298dc43> && __ptr64,class
   <lambda_f03950bc5685219e0bcd2087efbe011e> & __ptr64,class
   <lambda_3883c3dff614d5e0c5f61bb1ac94921c> && __ptr64) __ptr64
    public: int __cdecl __crt_seh_guarded_call<int>::operator()<class
   <lambda_8b90c8310d35b3462fe809c44bbb350d>,class <lambda_c1ccdfe150d00dafd355d15f2a9edeaa> &
   __ptr64,class <lambda_e797892004ba4c0bb152531b9d8c3715> >(class
   <lambda_8b90c8310d35b3462fe809c44bbb350d> && __ptr64,class
   <lambda_c1ccdfe150d00dafd355d15f2a9edeaa> & __ptr64,class
   <lambda_e797892004ba4c0bb152531b9d8c3715> && __ptr64) __ptr64
    public: int __cdecl __crt_seh_guarded_call<int>::operator()<class
   <lambda_b8c45f8f788dd370798f47cfe8ac3a86>,class <lambda_4e60a939b0d047cfe11ddc22648dfba9> &
   __ptr64,class <lambda_332c3edc96d0294ec56c57d38c1cdfd5> >(class
   <lambda_b8c45f8f788dd370798f47cfe8ac3a86> && __ptr64,class
   <lambda_4e60a939b0d047cfe11ddc22648dfba9> & __ptr64,class
   <lambda_332c3edc96d0294ec56c57d38c1cdfd5> && __ptr64) __ptr64
     5 names - too many to list
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

ulonglong operator()<>(undefined8 param_1,int *param_2,undefined8 *param_3,int *param_4)

{
  ulonglong uVar1;
  
  __acrt_lock(*param_2);
  uVar1 = FUN_140005c14(param_3);
  __acrt_unlock(*param_4);
  return uVar1 & 0xffffffff;
}



/*****************************************************************************
 * Function: FUN_140005a64
 * Address: 140005a64
 * Size: 432 bytes
 *****************************************************************************/


undefined8 FUN_140005a64(undefined8 *param_1)

{
  LPVOID pvVar1;
  undefined8 uVar2;
  byte bVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  LPVOID pvVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong *puVar9;
  ulonglong *puVar10;
  
  puVar4 = *(ulonglong **)*param_1;
  if (puVar4 == (ulonglong *)0x0) {
LAB_140005bf8:
    uVar2 = 0xffffffff;
  }
  else {
    bVar3 = (byte)DAT_140018038 & 0x3f;
    pvVar6 = (LPVOID)((*puVar4 ^ DAT_140018038) >> bVar3 | (*puVar4 ^ DAT_140018038) << 0x40 - bVar3
                     );
    puVar10 = (ulonglong *)
              ((puVar4[1] ^ DAT_140018038) >> bVar3 | (puVar4[1] ^ DAT_140018038) << 0x40 - bVar3);
    puVar4 = (ulonglong *)
             ((puVar4[2] ^ DAT_140018038) >> bVar3 | (puVar4[2] ^ DAT_140018038) << 0x40 - bVar3);
    if (puVar10 == puVar4) {
      uVar5 = (longlong)puVar4 - (longlong)pvVar6 >> 3;
      uVar7 = uVar5;
      if (0x200 < uVar5) {
        uVar7 = 0x200;
      }
      uVar8 = uVar7 + uVar5;
      if (uVar7 + uVar5 == 0) {
        uVar8 = 0x20;
      }
      if (uVar8 < uVar5) {
LAB_140005b06:
        uVar8 = uVar5 + 4;
        pvVar1 = _recalloc_base(pvVar6,uVar8,8);
        FUN_140006f7c((LPVOID)0x0);
        if (pvVar1 == (LPVOID)0x0) goto LAB_140005bf8;
      }
      else {
        pvVar1 = _recalloc_base(pvVar6,uVar8,8);
        FUN_140006f7c((LPVOID)0x0);
        if (pvVar1 == (LPVOID)0x0) goto LAB_140005b06;
      }
      pvVar6 = pvVar1;
      uVar7 = DAT_140018038;
      puVar10 = (ulonglong *)((longlong)pvVar6 + uVar5 * 8);
      puVar4 = (ulonglong *)((longlong)pvVar6 + uVar8 * 8);
      uVar5 = (ulonglong)((longlong)puVar4 + (7 - (longlong)puVar10)) >> 3;
      if (puVar4 < puVar10) {
        uVar5 = 0;
      }
      puVar9 = puVar10;
      if (uVar5 != 0) {
        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar9 = uVar7;
          puVar9 = puVar9 + 1;
        }
      }
    }
    bVar3 = -((byte)DAT_140018038 & 0x3f) & 0x3f;
    *puVar10 = (*(ulonglong *)param_1[1] >> bVar3 | *(ulonglong *)param_1[1] << 0x40 - bVar3) ^
               DAT_140018038;
    bVar3 = -((byte)DAT_140018038 & 0x3f) & 0x3f;
    **(ulonglong **)*param_1 =
         ((ulonglong)pvVar6 >> bVar3 | (longlong)pvVar6 << 0x40 - bVar3) ^ DAT_140018038;
    bVar3 = -((byte)DAT_140018038 & 0x3f) & 0x3f;
    *(ulonglong *)(*(longlong *)*param_1 + 8) =
         ((ulonglong)(puVar10 + 1) >> bVar3 | (longlong)(puVar10 + 1) << 0x40 - bVar3) ^
         DAT_140018038;
    bVar3 = 0x40 - ((byte)DAT_140018038 & 0x3f) & 0x3f;
    uVar2 = 0;
    *(ulonglong *)(*(longlong *)*param_1 + 0x10) =
         ((ulonglong)puVar4 >> bVar3 | (longlong)puVar4 << 0x40 - bVar3) ^ DAT_140018038;
  }
  return uVar2;
}



/*****************************************************************************
 * Function: FUN_140005c14
 * Address: 140005c14
 * Size: 288 bytes
 *****************************************************************************/


undefined8 FUN_140005c14(undefined8 *param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  byte bVar5;
  sbyte sVar6;
  uint uVar7;
  ulonglong *puVar8;
  ulonglong *puVar9;
  ulonglong *puVar10;
  ulonglong uVar11;
  ulonglong *puVar12;
  ulonglong *puVar13;
  
  uVar1 = DAT_140018038;
  puVar8 = *(ulonglong **)*param_1;
  if (puVar8 == (ulonglong *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    bVar5 = (byte)DAT_140018038 & 0x3f;
    puVar10 = (ulonglong *)
              ((*puVar8 ^ DAT_140018038) >> bVar5 | (*puVar8 ^ DAT_140018038) << 0x40 - bVar5);
    puVar8 = (ulonglong *)
             ((puVar8[1] ^ DAT_140018038) >> bVar5 | (puVar8[1] ^ DAT_140018038) << 0x40 - bVar5);
    if ((longlong)puVar10 - 1U < 0xfffffffffffffffe) {
      uVar7 = (uint)DAT_140018038 & 0x3f;
      puVar9 = puVar8;
      uVar3 = DAT_140018038;
      puVar13 = puVar10;
      while (puVar8 = puVar8 + -1, puVar10 <= puVar8) {
        if (*puVar8 != uVar1) {
          *puVar8 = uVar1;
          (*(code *)PTR__guard_dispatch_icall_14000e268)(uVar7);
          uVar7 = (uint)DAT_140018038 & 0x3f;
          uVar11 = **(ulonglong **)*param_1 ^ DAT_140018038;
          uVar3 = (*(ulonglong **)*param_1)[1] ^ DAT_140018038;
          sVar6 = (sbyte)uVar7;
          puVar12 = (ulonglong *)(uVar11 >> sVar6 | uVar11 << 0x40 - sVar6);
          puVar4 = (ulonglong *)(uVar3 >> sVar6 | uVar3 << 0x40 - sVar6);
          uVar3 = DAT_140018038;
          if ((puVar12 != puVar13) || (puVar4 != puVar9)) {
            puVar8 = puVar4;
            puVar9 = puVar4;
            puVar10 = puVar12;
            puVar13 = puVar12;
          }
        }
      }
      if (puVar10 != (ulonglong *)0xffffffffffffffff) {
        FUN_140006f7c(puVar10);
        uVar3 = DAT_140018038;
      }
      **(ulonglong **)*param_1 = uVar3;
      *(ulonglong *)(*(longlong *)*param_1 + 8) = uVar3;
      *(ulonglong *)(*(longlong *)*param_1 + 0x10) = uVar3;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*****************************************************************************
 * Function: FUN_140005d34
 * Address: 140005d34
 * Size: 15 bytes
 *****************************************************************************/


void FUN_140005d34(undefined8 param_1)

{
  _register_onexit_function(&DAT_140018ec0,param_1);
  return;
}



/*****************************************************************************
 * Function: FUN_140005d44
 * Address: 140005d44
 * Size: 67 bytes
 *****************************************************************************/


void FUN_140005d44(undefined8 param_1)

{
  undefined8 local_res8;
  undefined1 local_res10 [8];
  int local_res18 [2];
  int local_res20 [2];
  undefined8 *local_18;
  undefined8 local_10;
  
  local_10 = 0xfffffffffffffffe;
  local_18 = &local_res8;
  local_res18[0] = 2;
  local_res20[0] = 2;
  local_res8 = param_1;
  operator()<>(local_res10,local_res20,&local_18,local_res18);
  return;
}



/*****************************************************************************
 * Function: _initialize_onexit_table
 * Address: 140005d88
 * Size: 39 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _initialize_onexit_table
   
   Library: Visual Studio 2019 Release */

undefined8 _initialize_onexit_table(longlong *param_1)

{
  longlong lVar1;
  
  lVar1 = DAT_140018038;
  if (param_1 == (longlong *)0x0) {
    return 0xffffffff;
  }
  if (*param_1 == param_1[2]) {
    *param_1 = DAT_140018038;
    param_1[1] = lVar1;
    param_1[2] = lVar1;
  }
  return 0;
}



/*****************************************************************************
 * Function: _register_onexit_function
 * Address: 140005db0
 * Size: 72 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _register_onexit_function
   
   Library: Visual Studio 2019 Release */

void _register_onexit_function(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_res8;
  undefined8 local_res10;
  undefined1 local_res18 [8];
  int local_res20 [2];
  int local_28 [2];
  undefined8 *local_20;
  undefined8 *local_18;
  
  local_20 = &local_res8;
  local_18 = &local_res10;
  local_res20[0] = 2;
  local_28[0] = 2;
  local_res8 = param_1;
  local_res10 = param_2;
  operator()<>(local_res18,local_28,&local_20,local_res20);
  return;
}



/*****************************************************************************
 * Function: FUN_140005df8
 * Address: 140005df8
 * Size: 91 bytes
 *****************************************************************************/


undefined1 FUN_140005df8(void)

{
  FUN_140006f7c(DAT_140019778);
  DAT_140019778 = (LPVOID)0x0;
  FUN_140006f7c(DAT_140019780);
  DAT_140019780 = (LPVOID)0x0;
  FUN_140006f7c(DAT_140018f28);
  DAT_140018f28 = (LPVOID)0x0;
  FUN_140006f7c(DAT_140018f30);
  DAT_140018f30 = (LPVOID)0x0;
  return 1;
}



/*****************************************************************************
 * Function: FUN_140005e68
 * Address: 140005e68
 * Size: 35 bytes
 *****************************************************************************/


undefined8 FUN_140005e68(void)

{
  undefined8 uVar1;
  
  _initialize_onexit_table((longlong *)&DAT_140018ec0);
  uVar1 = _initialize_onexit_table((longlong *)&DAT_140018ed8);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



/*****************************************************************************
 * Function: FUN_140005e8c
 * Address: 140005e8c
 * Size: 16 bytes
 *****************************************************************************/


undefined1 FUN_140005e8c(void)

{
  FUN_14000540c();
  return 1;
}



/*****************************************************************************
 * Function: FUN_140005e9c
 * Address: 140005e9c
 * Size: 61 bytes
 *****************************************************************************/


undefined1 FUN_140005e9c(void)

{
  undefined8 uVar1;
  
  uVar1 = DAT_140018038;
  FUN_140006b18(DAT_140018038);
  FUN_140009890(uVar1);
  FUN_140009980(uVar1);
  FUN_140004e14(uVar1);
  FUN_1400057d8(uVar1);
  return 1;
}



/*****************************************************************************
 * Function: FUN_140005ee4
 * Address: 140005ee4
 * Size: 64 bytes
 *****************************************************************************/


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



/*****************************************************************************
 * Function: FUN_140005f24
 * Address: 140005f24
 * Size: 19 bytes
 *****************************************************************************/


void FUN_140005f24(void)

{
  FUN_1400097b4(&PTR_LAB_14000f510,(undefined8 *)&DAT_14000f610);
  return;
}



/*****************************************************************************
 * Function: FUN_140005f70
 * Address: 140005f70
 * Size: 41 bytes
 *****************************************************************************/


void FUN_140005f70(void)

{
  __acrt_ptd *p_Var1;
  
  p_Var1 = FUN_1400065a4();
  if (*(longlong *)(p_Var1 + 0x18) != 0) {
    (*(code *)PTR__guard_dispatch_icall_14000e268)();
  }
                    /* WARNING: Subroutine does not return */
  abort();
}



/*****************************************************************************
 * Function: FUN_140005f9c
 * Address: 140005f9c
 * Size: 17 bytes
 *****************************************************************************/


void FUN_140005f9c(LPVOID param_1)

{
  FUN_140006f7c(param_1);
  return;
}



/*****************************************************************************
 * Function: _malloc_base
 * Address: 140005fb0
 * Size: 5 bytes
 *****************************************************************************/


LPVOID _malloc_base(ulonglong param_1)

{
  int iVar1;
  undefined8 uVar2;
  LPVOID pvVar3;
  __acrt_ptd *p_Var4;
  
  if (param_1 < 0xffffffffffffffe1) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    do {
      pvVar3 = HeapAlloc(DAT_140019738,0,param_1);
      if (pvVar3 != (LPVOID)0x0) {
        return pvVar3;
      }
      iVar1 = FUN_1400059b0();
    } while ((iVar1 != 0) && (uVar2 = FUN_140009898(param_1), (int)uVar2 != 0));
  }
  p_Var4 = FUN_140006ee4();
  *(undefined4 *)p_Var4 = 0xc;
  return (LPVOID)0x0;
}



/*****************************************************************************
 * Function: strcpy_s
 * Address: 140005fb8
 * Size: 95 bytes
 *****************************************************************************/


/* Library Function - Single Match
    strcpy_s
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

errno_t __cdecl strcpy_s(char *_Dst,rsize_t _SizeInBytes,char *_Src)

{
  char cVar1;
  __acrt_ptd *p_Var2;
  errno_t eVar3;
  char *pcVar4;
  
  if ((_Dst != (char *)0x0) && (_SizeInBytes != 0)) {
    if (_Src != (char *)0x0) {
      pcVar4 = _Dst;
      do {
        cVar1 = pcVar4[(longlong)_Src - (longlong)_Dst];
        *pcVar4 = cVar1;
        pcVar4 = pcVar4 + 1;
        if (cVar1 == '\0') {
          return 0;
        }
        _SizeInBytes = _SizeInBytes - 1;
      } while (_SizeInBytes != 0);
      *_Dst = '\0';
      p_Var2 = FUN_140006ee4();
      eVar3 = 0x22;
      goto LAB_140005fdb;
    }
    *_Dst = '\0';
  }
  p_Var2 = FUN_140006ee4();
  eVar3 = 0x16;
LAB_140005fdb:
  *(errno_t *)p_Var2 = eVar3;
  FUN_140006c8c();
  return eVar3;
}



/*****************************************************************************
 * Function: abort
 * Address: 140006018
 * Size: 86 bytes
 *****************************************************************************/


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



/*****************************************************************************
 * Function: _calloc_base
 * Address: 140006070
 * Size: 5 bytes
 *****************************************************************************/


LPVOID _calloc_base(ulonglong param_1,ulonglong param_2)

{
  int iVar1;
  undefined8 uVar2;
  LPVOID pvVar3;
  __acrt_ptd *p_Var4;
  SIZE_T dwBytes;
  
  if ((param_1 == 0) || (param_2 <= 0xffffffffffffffe0 / param_1)) {
    dwBytes = param_1 * param_2;
    if (dwBytes == 0) {
      dwBytes = 1;
    }
    do {
      pvVar3 = HeapAlloc(DAT_140019738,8,dwBytes);
      if (pvVar3 != (LPVOID)0x0) {
        return pvVar3;
      }
      iVar1 = FUN_1400059b0();
    } while ((iVar1 != 0) && (uVar2 = FUN_140009898(dwBytes), (int)uVar2 != 0));
  }
  p_Var4 = FUN_140006ee4();
  *(undefined4 *)p_Var4 = 0xc;
  return (LPVOID)0x0;
}



/*****************************************************************************
 * Function: FUN_140006080
 * Address: 140006080
 * Size: 102 bytes
 *****************************************************************************/


longlong FUN_140006080(longlong *param_1)

{
  __acrt_ptd *p_Var1;
  longlong lVar2;
  DWORD local_res8 [2];
  
  if (*param_1 == 0) {
    local_res8[0] = GetLastError();
    if ((char)param_1[2] == '\0') {
      lVar2 = 0;
      *(undefined1 *)(param_1 + 2) = 1;
      param_1[1] = 0;
    }
    else {
      lVar2 = param_1[1];
    }
    p_Var1 = FUN_1400067e4(local_res8,lVar2);
    *param_1 = (longlong)p_Var1;
    SetLastError(local_res8[0]);
    if (p_Var1 == (__acrt_ptd *)0x0) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
  }
  return *param_1;
}



/*****************************************************************************
 * Function: FUN_1400060f0
 * Address: 1400060f0
 * Size: 118 bytes
 *****************************************************************************/


void FUN_1400060f0(longlong *param_1)

{
  longlong lVar1;
  
  lVar1 = FUN_140006080(param_1);
  param_1[3] = *(longlong *)(lVar1 + 0x90);
  param_1[4] = *(longlong *)(lVar1 + 0x88);
  FUN_14000a12c(lVar1,param_1 + 3,param_1[1]);
  FUN_14000a198(lVar1,param_1 + 4,param_1[1]);
  if ((*(uint *)(lVar1 + 0x3a8) & 2) == 0) {
    *(uint *)(lVar1 + 0x3a8) = *(uint *)(lVar1 + 0x3a8) | 2;
    *(undefined1 *)(param_1 + 5) = 2;
  }
  return;
}



/*****************************************************************************
 * Function: strncmp
 * Address: 140006180
 * Size: 125 bytes
 *****************************************************************************/


/* Library Function - Single Match
    strncmp
   
   Libraries: Visual Studio 2012, Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

int __cdecl strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  byte bVar1;
  ulonglong uVar2;
  longlong lVar3;
  bool bVar4;
  
  lVar3 = (longlong)_Str2 - (longlong)_Str1;
  if (_MaxCount != 0) {
    uVar2 = (ulonglong)_Str1 & 7;
    while( true ) {
      if (uVar2 == 0) {
        while ((((int)lVar3 + (int)_Str1 & 0xfffU) < 0xff9 &&
               (uVar2 = *(ulonglong *)_Str1, uVar2 == *(ulonglong *)(lVar3 + (longlong)_Str1)))) {
          _Str1 = (char *)((longlong)_Str1 + 8);
          bVar4 = _MaxCount < 8;
          _MaxCount = _MaxCount - 8;
          if (bVar4 || _MaxCount == 0) {
            return 0;
          }
          if ((~uVar2 & uVar2 + 0xfefefefefefefeff & 0x8080808080808080) != 0) {
            return 0;
          }
        }
      }
      bVar1 = (byte)*(ulonglong *)_Str1;
      if (bVar1 != *(byte *)(lVar3 + (longlong)_Str1)) {
        return -(uint)(bVar1 < *(byte *)(lVar3 + (longlong)_Str1)) | 1;
      }
      _Str1 = (char *)((longlong)_Str1 + 1);
      _MaxCount = _MaxCount - 1;
      if ((_MaxCount == 0) || (bVar1 == 0)) break;
      uVar2 = (ulonglong)_Str1 & 7;
    }
  }
  return 0;
}



/*****************************************************************************
 * Function: wcsncmp
 * Address: 140006200
 * Size: 44 bytes
 *****************************************************************************/


/* Library Function - Single Match
    wcsncmp
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl wcsncmp(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount)

{
  if (_MaxCount == 0) {
    return 0;
  }
  for (; ((_MaxCount = _MaxCount - 1, _MaxCount != 0 && (*_Str1 != L'\0')) && (*_Str1 == *_Str2));
      _Str1 = _Str1 + 1) {
    _Str2 = _Str2 + 1;
  }
  return (uint)(ushort)*_Str1 - (uint)(ushort)*_Str2;
}



/*****************************************************************************
 * Function: operator()<>
 * Address: 14000622c
 * Size: 63 bytes
 *****************************************************************************/


/* Library Function - Multiple Matches With Same Base Name
    public: void __cdecl __crt_seh_guarded_call<void>::operator()<class
   <lambda_0ae27a3a962d80f24befdcbee591983d>,class <lambda_8d0ee55de4b1038c4002e0adecdf1839> &
   __ptr64,class <lambda_dc504788e8f1664fe9b84e20bfb512f2> >(class
   <lambda_0ae27a3a962d80f24befdcbee591983d> && __ptr64,class
   <lambda_8d0ee55de4b1038c4002e0adecdf1839> & __ptr64,class
   <lambda_dc504788e8f1664fe9b84e20bfb512f2> && __ptr64) __ptr64
    public: void __cdecl __crt_seh_guarded_call<void>::operator()<class
   <lambda_72d1df2b273a38828b1ce30cbf4cdab5>,class <lambda_876a65b173b8412d3a47c70a915b0cf4> &
   __ptr64,class <lambda_41932305e351933ebe8f8be3ed8bb5dc> >(class
   <lambda_72d1df2b273a38828b1ce30cbf4cdab5> && __ptr64,class
   <lambda_876a65b173b8412d3a47c70a915b0cf4> & __ptr64,class
   <lambda_41932305e351933ebe8f8be3ed8bb5dc> && __ptr64) __ptr64
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void operator()<>(undefined8 param_1,int *param_2,undefined8 *param_3,int *param_4)

{
  __acrt_lock(*param_2);
  LOCK();
  **(int **)(*(longlong *)*param_3 + 0x88) = **(int **)(*(longlong *)*param_3 + 0x88) + 1;
  UNLOCK();
  __acrt_unlock(*param_4);
  return;
}



/*****************************************************************************
 * Function: operator()<>
 * Address: 14000626c
 * Size: 61 bytes
 *****************************************************************************/


/* Library Function - Multiple Matches With Same Base Name
    public: void __cdecl __crt_seh_guarded_call<void>::operator()<class
   <lambda_2d41944a1d46af3157314b8a01080d33>,class <lambda_8f455de75cd7d7f24b4096f044d8b9e6> &
   __ptr64,class <lambda_aa500f224e6afead328df44964fe2772> >(class
   <lambda_2d41944a1d46af3157314b8a01080d33> && __ptr64,class
   <lambda_8f455de75cd7d7f24b4096f044d8b9e6> & __ptr64,class
   <lambda_aa500f224e6afead328df44964fe2772> && __ptr64) __ptr64
    public: void __cdecl __crt_seh_guarded_call<void>::operator()<class
   <lambda_fb3a7dec4e47f37f22dae91bb15c9095>,class <lambda_698284760c8add0bfb0756c19673e34b> &
   __ptr64,class <lambda_dfb8eca1e75fef3034a8fb18dd509707> >(class
   <lambda_fb3a7dec4e47f37f22dae91bb15c9095> && __ptr64,class
   <lambda_698284760c8add0bfb0756c19673e34b> & __ptr64,class
   <lambda_dfb8eca1e75fef3034a8fb18dd509707> && __ptr64) __ptr64
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void operator()<>(undefined8 param_1,int *param_2,undefined8 *param_3,int *param_4)

{
  __acrt_lock(*param_2);
  replace_current_thread_locale_nolock(*(__acrt_ptd **)*param_3,(__crt_locale_data *)0x0);
  __acrt_unlock(*param_4);
  return;
}



/*****************************************************************************
 * Function: operator()<>
 * Address: 1400062ac
 * Size: 69 bytes
 *****************************************************************************/


/* Library Function - Multiple Matches With Same Base Name
    public: void __cdecl __crt_seh_guarded_call<void>::operator()<class
   <lambda_5e887d1dcbef67a5eb4283622ba103bf>,class <lambda_4466841279450cc726390878d4a41900> &
   __ptr64,class <lambda_341c25c0346d94847f1f3c463c57e077> >(class
   <lambda_5e887d1dcbef67a5eb4283622ba103bf> && __ptr64,class
   <lambda_4466841279450cc726390878d4a41900> & __ptr64,class
   <lambda_341c25c0346d94847f1f3c463c57e077> && __ptr64) __ptr64
    public: void __cdecl __crt_seh_guarded_call<void>::operator()<class
   <lambda_aa87e3671a710a21b5dc78c0bdf72e11>,class <lambda_92619d2358a28f41a33ba319515a20b9> &
   __ptr64,class <lambda_6992ecaafeb10aed2b74cb1fae11a551> >(class
   <lambda_aa87e3671a710a21b5dc78c0bdf72e11> && __ptr64,class
   <lambda_92619d2358a28f41a33ba319515a20b9> & __ptr64,class
   <lambda_6992ecaafeb10aed2b74cb1fae11a551> && __ptr64) __ptr64
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void operator()<>(undefined8 param_1,int *param_2,undefined8 *param_3,int *param_4)

{
  __acrt_lock(*param_2);
  replace_current_thread_locale_nolock
            (*(__acrt_ptd **)*param_3,(__crt_locale_data *)**(undefined8 **)param_3[1]);
  __acrt_unlock(*param_4);
  return;
}



/*****************************************************************************
 * Function: operator()<>
 * Address: 1400062f4
 * Size: 95 bytes
 *****************************************************************************/


/* Library Function - Multiple Matches With Same Base Name
    public: void __cdecl __crt_seh_guarded_call<void>::operator()<class
   <lambda_46352004c1216016012b18bd6f87e700>,class <lambda_3bd07e1a1191394380780325891bf33f> &
   __ptr64,class <lambda_334532d3f185bcaa59b5be82d7d22bff> >(class
   <lambda_46352004c1216016012b18bd6f87e700> && __ptr64,class
   <lambda_3bd07e1a1191394380780325891bf33f> & __ptr64,class
   <lambda_334532d3f185bcaa59b5be82d7d22bff> && __ptr64) __ptr64
    public: void __cdecl __crt_seh_guarded_call<void>::operator()<class
   <lambda_f2e299630e499de9f9a165e60fcd3db5>,class <lambda_2ae9d31cdba2644fcbeaf08da7c24588> &
   __ptr64,class <lambda_40d01ff24d0e7b3814fdbdcee8eab3c7> >(class
   <lambda_f2e299630e499de9f9a165e60fcd3db5> && __ptr64,class
   <lambda_2ae9d31cdba2644fcbeaf08da7c24588> & __ptr64,class
   <lambda_40d01ff24d0e7b3814fdbdcee8eab3c7> && __ptr64) __ptr64
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void operator()<>(undefined8 param_1,int *param_2,undefined8 *param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  
  __acrt_lock(*param_2);
  piVar2 = *(int **)(*(longlong *)*param_3 + 0x88);
  if (piVar2 != (int *)0x0) {
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if ((iVar1 == 1) && (piVar2 != (int *)&DAT_140018070)) {
      FUN_140006f7c(piVar2);
    }
  }
  __acrt_unlock(*param_4);
  return;
}



/*****************************************************************************
 * Function: construct_ptd_array
 * Address: 140006354
 * Size: 205 bytes
 *****************************************************************************/


/* Library Function - Single Match
    void __cdecl construct_ptd_array(struct __acrt_ptd * __ptr64 const)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl construct_ptd_array(__acrt_ptd *param_1)

{
  undefined1 local_res10 [8];
  int local_res18 [2];
  int local_res20 [2];
  int local_38 [2];
  __acrt_ptd *local_30;
  undefined8 *local_28;
  __acrt_ptd **local_20;
  __acrt_ptd **local_18;
  undefined8 **local_10;
  
  local_20 = &local_30;
  local_res18[0] = 5;
  local_res20[0] = 5;
  local_18 = &local_30;
  local_10 = &local_28;
  local_38[0] = 4;
  local_38[1] = 4;
  local_28 = &DAT_140019598;
  *(undefined4 *)(param_1 + 0x28) = 1;
  *(undefined **)param_1 = &DAT_14000f370;
  *(undefined4 *)(param_1 + 0x3a8) = 1;
  *(undefined **)(param_1 + 0x88) = &DAT_140018070;
  *(undefined2 *)(param_1 + 0xbc) = 0x43;
  *(undefined2 *)(param_1 + 0x1c2) = 0x43;
  *(undefined8 *)(param_1 + 0x3a0) = 0;
  local_30 = param_1;
  operator()<>(local_res10,local_res20,&local_20,local_res18);
  operator()<>(local_res10,local_38 + 1,&local_18,local_38);
  return;
}



/*****************************************************************************
 * Function: FUN_140006424
 * Address: 140006424
 * Size: 32 bytes
 *****************************************************************************/


void FUN_140006424(__acrt_ptd *param_1)

{
  if (param_1 != (__acrt_ptd *)0x0) {
    destroy_ptd_array(param_1);
    FUN_140006f7c(param_1);
  }
  return;
}



/*****************************************************************************
 * Function: destroy_ptd_array
 * Address: 140006444
 * Size: 245 bytes
 *****************************************************************************/


/* Library Function - Single Match
    void __cdecl destroy_ptd_array(struct __acrt_ptd * __ptr64 const)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl destroy_ptd_array(__acrt_ptd *param_1)

{
  undefined1 local_res10 [8];
  int local_res18 [2];
  int local_res20 [2];
  int local_28 [2];
  __acrt_ptd *local_20;
  __acrt_ptd **local_18;
  __acrt_ptd **local_10;
  
  local_18 = &local_20;
  local_res18[0] = 5;
  local_res20[0] = 5;
  local_10 = &local_20;
  local_28[0] = 4;
  local_28[1] = 4;
  local_20 = param_1;
  if (*(undefined **)param_1 != &DAT_14000f370) {
    FUN_140006f7c(*(undefined **)param_1);
  }
  FUN_140006f7c(*(LPVOID *)(local_20 + 0x70));
  FUN_140006f7c(*(LPVOID *)(local_20 + 0x58));
  FUN_140006f7c(*(LPVOID *)(local_20 + 0x60));
  FUN_140006f7c(*(LPVOID *)(local_20 + 0x68));
  FUN_140006f7c(*(LPVOID *)(local_20 + 0x48));
  FUN_140006f7c(*(LPVOID *)(local_20 + 0x50));
  FUN_140006f7c(*(LPVOID *)(local_20 + 0x78));
  FUN_140006f7c(*(LPVOID *)(local_20 + 0x80));
  FUN_140006f7c(*(LPVOID *)(local_20 + 0x3c0));
  operator()<>(local_res10,local_res20,&local_18,local_res18);
  operator()<>(local_res10,local_28 + 1,&local_10,local_28);
  return;
}



/*****************************************************************************
 * Function: replace_current_thread_locale_nolock
 * Address: 14000653c
 * Size: 103 bytes
 *****************************************************************************/


/* Library Function - Single Match
    void __cdecl replace_current_thread_locale_nolock(struct __acrt_ptd * __ptr64 const,struct
   __crt_locale_data * __ptr64 const)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl replace_current_thread_locale_nolock(__acrt_ptd *param_1,__crt_locale_data *param_2)

{
  undefined **ppuVar1;
  
  if (*(longlong *)(param_1 + 0x90) != 0) {
    __acrt_release_locale_ref(*(longlong *)(param_1 + 0x90));
    ppuVar1 = *(undefined ***)(param_1 + 0x90);
    if (((ppuVar1 != DAT_140019598) && (ppuVar1 != &PTR_DAT_1400185b0)) &&
       (*(int *)(ppuVar1 + 2) == 0)) {
      __acrt_free_locale(ppuVar1);
    }
  }
  *(__crt_locale_data **)(param_1 + 0x90) = param_2;
  if (param_2 != (__crt_locale_data *)0x0) {
    __acrt_add_locale_ref((longlong)param_2);
  }
  return;
}



/*****************************************************************************
 * Function: FUN_1400065a4
 * Address: 1400065a4
 * Size: 210 bytes
 *****************************************************************************/


__acrt_ptd * FUN_1400065a4(void)

{
  DWORD dwErrCode;
  BOOL BVar1;
  __acrt_ptd *lpFlsData;
  __acrt_ptd *p_Var2;
  
  dwErrCode = GetLastError();
  p_Var2 = (__acrt_ptd *)0x0;
  if ((DAT_140018060 == 0xffffffff) ||
     (lpFlsData = (__acrt_ptd *)FlsGetValue(DAT_140018060), lpFlsData == (__acrt_ptd *)0x0)) {
    BVar1 = FlsSetValue(DAT_140018060,(PVOID)0xffffffffffffffff);
    lpFlsData = p_Var2;
    if (BVar1 != 0) {
      lpFlsData = (__acrt_ptd *)_calloc_base(1,0x3c8);
      if (lpFlsData == (__acrt_ptd *)0x0) {
        FlsSetValue(DAT_140018060,(PVOID)0x0);
        lpFlsData = (__acrt_ptd *)0x0;
      }
      else {
        BVar1 = FlsSetValue(DAT_140018060,lpFlsData);
        if (BVar1 != 0) {
          construct_ptd_array(lpFlsData);
          FUN_140006f7c((LPVOID)0x0);
          goto LAB_140006651;
        }
        FlsSetValue(DAT_140018060,(PVOID)0x0);
      }
      FUN_140006f7c(lpFlsData);
      lpFlsData = p_Var2;
    }
  }
  else if (lpFlsData == (__acrt_ptd *)0xffffffffffffffff) {
    lpFlsData = p_Var2;
  }
LAB_140006651:
  SetLastError(dwErrCode);
  if (lpFlsData == (__acrt_ptd *)0x0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  return lpFlsData;
}



/*****************************************************************************
 * Function: FUN_140006678
 * Address: 140006678
 * Size: 161 bytes
 *****************************************************************************/


__acrt_ptd * FUN_140006678(void)

{
  BOOL BVar1;
  __acrt_ptd *p_Var2;
  
  if ((DAT_140018060 == 0xffffffff) ||
     (p_Var2 = (__acrt_ptd *)FlsGetValue(DAT_140018060), p_Var2 == (__acrt_ptd *)0x0)) {
    BVar1 = FlsSetValue(DAT_140018060,(PVOID)0xffffffffffffffff);
    if (BVar1 != 0) {
      p_Var2 = (__acrt_ptd *)_calloc_base(1,0x3c8);
      if (p_Var2 == (__acrt_ptd *)0x0) {
        FlsSetValue(DAT_140018060,(PVOID)0x0);
        p_Var2 = (__acrt_ptd *)0x0;
      }
      else {
        BVar1 = FlsSetValue(DAT_140018060,p_Var2);
        if (BVar1 != 0) {
          construct_ptd_array(p_Var2);
          FUN_140006f7c((LPVOID)0x0);
          return p_Var2;
        }
        FlsSetValue(DAT_140018060,(PVOID)0x0);
      }
      FUN_140006f7c(p_Var2);
    }
  }
  else if (p_Var2 != (__acrt_ptd *)0xffffffffffffffff) {
    return p_Var2;
  }
                    /* WARNING: Subroutine does not return */
  abort();
}



/*****************************************************************************
 * Function: FUN_14000671c
 * Address: 14000671c
 * Size: 200 bytes
 *****************************************************************************/


__acrt_ptd * FUN_14000671c(void)

{
  DWORD dwErrCode;
  BOOL BVar1;
  __acrt_ptd *lpFlsData;
  __acrt_ptd *p_Var2;
  
  dwErrCode = GetLastError();
  p_Var2 = (__acrt_ptd *)0x0;
  if ((DAT_140018060 == 0xffffffff) ||
     (lpFlsData = (__acrt_ptd *)FlsGetValue(DAT_140018060), lpFlsData == (__acrt_ptd *)0x0)) {
    BVar1 = FlsSetValue(DAT_140018060,(PVOID)0xffffffffffffffff);
    lpFlsData = p_Var2;
    if (BVar1 != 0) {
      lpFlsData = (__acrt_ptd *)_calloc_base(1,0x3c8);
      if (lpFlsData == (__acrt_ptd *)0x0) {
        FlsSetValue(DAT_140018060,(PVOID)0x0);
        lpFlsData = (__acrt_ptd *)0x0;
      }
      else {
        BVar1 = FlsSetValue(DAT_140018060,lpFlsData);
        if (BVar1 != 0) {
          construct_ptd_array(lpFlsData);
          FUN_140006f7c((LPVOID)0x0);
          goto LAB_1400067c9;
        }
        FlsSetValue(DAT_140018060,(PVOID)0x0);
      }
      FUN_140006f7c(lpFlsData);
      lpFlsData = p_Var2;
    }
  }
  else if (lpFlsData == (__acrt_ptd *)0xffffffffffffffff) {
    lpFlsData = p_Var2;
  }
LAB_1400067c9:
  SetLastError(dwErrCode);
  return lpFlsData;
}



/*****************************************************************************
 * Function: FUN_1400067e4
 * Address: 1400067e4
 * Size: 190 bytes
 *****************************************************************************/


__acrt_ptd * FUN_1400067e4(undefined8 param_1,longlong param_2)

{
  BOOL BVar1;
  __acrt_ptd *lpFlsData;
  __acrt_ptd *p_Var2;
  
  p_Var2 = (__acrt_ptd *)0x0;
  if ((DAT_140018060 == 0xffffffff) ||
     (lpFlsData = (__acrt_ptd *)FlsGetValue(DAT_140018060), lpFlsData == (__acrt_ptd *)0x0)) {
    BVar1 = FlsSetValue(DAT_140018060,(PVOID)0xffffffffffffffff);
    if (BVar1 == 0) {
      return (__acrt_ptd *)0x0;
    }
    lpFlsData = (__acrt_ptd *)_calloc_base(1,0x3c8);
    if (lpFlsData == (__acrt_ptd *)0x0) {
      FlsSetValue(DAT_140018060,(PVOID)0x0);
      lpFlsData = (__acrt_ptd *)0x0;
    }
    else {
      BVar1 = FlsSetValue(DAT_140018060,lpFlsData);
      if (BVar1 != 0) {
        construct_ptd_array(lpFlsData);
        FUN_140006f7c((LPVOID)0x0);
        goto LAB_140006885;
      }
      FlsSetValue(DAT_140018060,(PVOID)0x0);
    }
    FUN_140006f7c(lpFlsData);
  }
  else {
    if (lpFlsData == (__acrt_ptd *)0xffffffffffffffff) {
      return (__acrt_ptd *)0x0;
    }
LAB_140006885:
    p_Var2 = lpFlsData + param_2 * 0x3c8;
  }
  return p_Var2;
}



/*****************************************************************************
 * Function: FUN_140006904
 * Address: 140006904
 * Size: 106 bytes
 *****************************************************************************/


__acrt_ptd * FUN_140006904(longlong *param_1)

{
  __acrt_ptd *p_Var1;
  longlong lVar2;
  DWORD local_res8 [2];
  
  p_Var1 = (__acrt_ptd *)*param_1;
  lVar2 = 0;
  if (p_Var1 == (__acrt_ptd *)0x0) {
    local_res8[0] = GetLastError();
    if ((char)param_1[2] == '\0') {
      param_1[1] = 0;
      *(undefined1 *)(param_1 + 2) = 1;
    }
    else {
      lVar2 = param_1[1];
    }
    p_Var1 = FUN_1400067e4(local_res8,lVar2);
    *param_1 = (longlong)p_Var1;
    SetLastError(local_res8[0]);
  }
  return p_Var1;
}



/*****************************************************************************
 * Function: FUN_140006970
 * Address: 140006970
 * Size: 76 bytes
 *****************************************************************************/


longlong FUN_140006970(longlong param_1,longlong param_2)

{
  DWORD dwErrCode;
  longlong lVar1;
  
  lVar1 = 0;
  if (*(char *)(param_2 + 0x10) == '\0') {
    dwErrCode = GetLastError();
    *(undefined8 *)(param_2 + 8) = 0;
    *(undefined1 *)(param_2 + 0x10) = 1;
    SetLastError(dwErrCode);
  }
  else {
    lVar1 = *(longlong *)(param_2 + 8);
  }
  return param_1 + lVar1 * 8;
}



/*****************************************************************************
 * Function: FUN_140006b18
 * Address: 140006b18
 * Size: 8 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140006b18(undefined8 param_1)

{
  _DAT_140018ef0 = param_1;
  return;
}



/*****************************************************************************
 * Function: FUN_140006b20
 * Address: 140006b20
 * Size: 155 bytes
 *****************************************************************************/


void FUN_140006b20(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uintptr_t param_5
                  )

{
  longlong lVar1;
  longlong local_48 [2];
  undefined1 local_38;
  undefined *local_30;
  undefined *puStack_28;
  char local_20;
  undefined4 local_1c;
  char local_18;
  undefined4 local_14;
  char local_10;
  
  local_48[0] = 0;
  local_20 = DAT_140018eb4 == 0;
  local_38 = 0;
  local_18 = '\0';
  local_10 = '\0';
  if ((bool)local_20) {
    local_30 = PTR_PTR_140018708;
    puStack_28 = PTR_DAT_140018710;
  }
  FUN_140006bbc(param_1,param_2,param_3,param_4,param_5,local_48);
  if (local_20 == '\x02') {
    *(uint *)(local_48[0] + 0x3a8) = *(uint *)(local_48[0] + 0x3a8) & 0xfffffffd;
  }
  if (local_18 != '\0') {
    lVar1 = FUN_140006080(local_48);
    *(undefined4 *)(lVar1 + 0x20) = local_1c;
  }
  if (local_10 != '\0') {
    lVar1 = FUN_140006080(local_48);
    *(undefined4 *)(lVar1 + 0x24) = local_14;
  }
  return;
}



/*****************************************************************************
 * Function: FUN_140006bbc
 * Address: 140006bbc
 * Size: 206 bytes
 *****************************************************************************/


void FUN_140006bbc(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uintptr_t param_5
                  ,longlong *param_6)

{
  byte bVar1;
  __acrt_ptd *p_Var2;
  ulonglong *puVar3;
  
  p_Var2 = FUN_140006904(param_6);
  if (((p_Var2 == (__acrt_ptd *)0x0) || (*(longlong *)(p_Var2 + 0x3b8) == 0)) &&
     (puVar3 = (ulonglong *)FUN_140006970(0x140018ef0,(longlong)param_6),
     bVar1 = (byte)DAT_140018038 & 0x3f,
     (DAT_140018038 ^ *puVar3) >> bVar1 == 0 && (DAT_140018038 ^ *puVar3) << 0x40 - bVar1 == 0)) {
                    /* WARNING: Subroutine does not return */
    _invoke_watson(param_1,param_2,param_3,param_4,param_5);
  }
  (*(code *)PTR__guard_dispatch_icall_14000e268)(param_1,param_2,param_3,param_4,param_5);
  return;
}



/*****************************************************************************
 * Function: FUN_140006c8c
 * Address: 140006c8c
 * Size: 30 bytes
 *****************************************************************************/


void FUN_140006c8c(void)

{
  FUN_140006b20((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  return;
}



/*****************************************************************************
 * Function: _invoke_watson
 * Address: 140006cac
 * Size: 71 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _invoke_watson
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl
_invoke_watson(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uintptr_t param_5)

{
  code *pcVar1;
  BOOL BVar2;
  HANDLE hProcess;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
  puVar3 = auStack_28;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
    puVar3 = auStack_20;
  }
  *(undefined8 *)(puVar3 + -8) = 0x140006cda;
  __acrt_call_reportfault(2,0xc0000417,1);
  *(undefined8 *)(puVar3 + -8) = 0x140006ce0;
  hProcess = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x000140006cec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(hProcess,0xc0000417);
  return;
}



/*****************************************************************************
 * Function: wcscpy_s
 * Address: 140006cf4
 * Size: 101 bytes
 *****************************************************************************/


/* Library Function - Single Match
    wcscpy_s
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

errno_t __cdecl wcscpy_s(wchar_t *_Dst,rsize_t _SizeInWords,wchar_t *_Src)

{
  wchar_t wVar1;
  __acrt_ptd *p_Var2;
  errno_t eVar3;
  wchar_t *pwVar4;
  
  if ((_Dst != (wchar_t *)0x0) && (_SizeInWords != 0)) {
    if (_Src != (wchar_t *)0x0) {
      pwVar4 = _Dst;
      do {
        wVar1 = *(wchar_t *)(((longlong)_Src - (longlong)_Dst) + (longlong)pwVar4);
        *pwVar4 = wVar1;
        pwVar4 = pwVar4 + 1;
        if (wVar1 == L'\0') {
          return 0;
        }
        _SizeInWords = _SizeInWords - 1;
      } while (_SizeInWords != 0);
      *_Dst = L'\0';
      p_Var2 = FUN_140006ee4();
      eVar3 = 0x22;
      goto LAB_140006d18;
    }
    *_Dst = L'\0';
  }
  p_Var2 = FUN_140006ee4();
  eVar3 = 0x16;
LAB_140006d18:
  *(errno_t *)p_Var2 = eVar3;
  FUN_140006c8c();
  return eVar3;
}



/*****************************************************************************
 * Function: FUN_140006d5c
 * Address: 140006d5c
 * Size: 252 bytes
 *****************************************************************************/


undefined4 FUN_140006d5c(short *param_1,longlong param_2,longlong param_3,longlong param_4)

{
  short sVar1;
  __acrt_ptd *p_Var2;
  longlong lVar3;
  short *psVar4;
  undefined4 uVar5;
  longlong lVar6;
  longlong lVar7;
  
  if (param_4 == 0) {
    if (param_1 == (short *)0x0) {
      if (param_2 == 0) {
        return 0;
      }
    }
    else {
LAB_140006daf:
      if (param_2 != 0) {
        if (param_4 == 0) {
          *param_1 = 0;
          return 0;
        }
        if (param_3 != 0) {
          psVar4 = param_1;
          lVar3 = param_4;
          lVar7 = param_2;
          if (param_4 == -1) {
            do {
              sVar1 = *(short *)((param_3 - (longlong)param_1) + (longlong)psVar4);
              *psVar4 = sVar1;
              psVar4 = psVar4 + 1;
              if (sVar1 == 0) {
                return 0;
              }
              lVar7 = lVar7 + -1;
            } while (lVar7 != 0);
            lVar7 = 0;
          }
          else {
            do {
              lVar6 = lVar3;
              sVar1 = *(short *)((param_3 - (longlong)param_1) + (longlong)psVar4);
              *psVar4 = sVar1;
              psVar4 = psVar4 + 1;
              if (sVar1 == 0) {
                return 0;
              }
              lVar7 = lVar7 + -1;
            } while ((lVar7 != 0) && (lVar3 = lVar6 + -1, lVar6 + -1 != 0));
            lVar3 = lVar6 + -1;
            if (lVar7 == 0) {
              lVar3 = lVar6;
            }
            if (lVar3 == 0) {
              *psVar4 = 0;
            }
          }
          if (lVar7 != 0) {
            return 0;
          }
          if (param_4 == -1) {
            param_1[param_2 + -1] = 0;
            return 0x50;
          }
          *param_1 = 0;
          p_Var2 = FUN_140006ee4();
          uVar5 = 0x22;
          goto LAB_140006d8d;
        }
        *param_1 = 0;
      }
    }
  }
  else if (param_1 != (short *)0x0) goto LAB_140006daf;
  p_Var2 = FUN_140006ee4();
  uVar5 = 0x16;
LAB_140006d8d:
  *(undefined4 *)p_Var2 = uVar5;
  FUN_140006c8c();
  return uVar5;
}



/*****************************************************************************
 * Function: FUN_140006ea0
 * Address: 140006ea0
 * Size: 34 bytes
 *****************************************************************************/


void FUN_140006ea0(int param_1,longlong param_2)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_2 + 0x38) = 1;
  *(int *)(param_2 + 0x34) = param_1;
  uVar1 = __acrt_errno_from_os_error(param_1);
  *(undefined4 *)(param_2 + 0x2c) = uVar1;
  *(undefined1 *)(param_2 + 0x30) = 1;
  return;
}



/*****************************************************************************
 * Function: FUN_140006ec4
 * Address: 140006ec4
 * Size: 32 bytes
 *****************************************************************************/


__acrt_ptd * FUN_140006ec4(void)

{
  __acrt_ptd *p_Var1;
  
  p_Var1 = FUN_14000671c();
  if (p_Var1 == (__acrt_ptd *)0x0) {
    p_Var1 = (__acrt_ptd *)&DAT_140018068;
  }
  else {
    p_Var1 = p_Var1 + 0x24;
  }
  return p_Var1;
}



/*****************************************************************************
 * Function: FUN_140006ee4
 * Address: 140006ee4
 * Size: 32 bytes
 *****************************************************************************/


__acrt_ptd * FUN_140006ee4(void)

{
  __acrt_ptd *p_Var1;
  
  p_Var1 = FUN_14000671c();
  if (p_Var1 == (__acrt_ptd *)0x0) {
    p_Var1 = (__acrt_ptd *)&DAT_140018064;
  }
  else {
    p_Var1 = p_Var1 + 0x20;
  }
  return p_Var1;
}



/*****************************************************************************
 * Function: _calloc_base
 * Address: 140006f04
 * Size: 117 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _calloc_base
   
   Library: Visual Studio 2019 Release */

LPVOID _calloc_base(ulonglong param_1,ulonglong param_2)

{
  int iVar1;
  undefined8 uVar2;
  LPVOID pvVar3;
  __acrt_ptd *p_Var4;
  SIZE_T dwBytes;
  
  if ((param_1 == 0) || (param_2 <= 0xffffffffffffffe0 / param_1)) {
    dwBytes = param_1 * param_2;
    if (dwBytes == 0) {
      dwBytes = 1;
    }
    do {
      pvVar3 = HeapAlloc(DAT_140019738,8,dwBytes);
      if (pvVar3 != (LPVOID)0x0) {
        return pvVar3;
      }
      iVar1 = FUN_1400059b0();
    } while ((iVar1 != 0) && (uVar2 = FUN_140009898(dwBytes), (int)uVar2 != 0));
  }
  p_Var4 = FUN_140006ee4();
  *(undefined4 *)p_Var4 = 0xc;
  return (LPVOID)0x0;
}



/*****************************************************************************
 * Function: FUN_140006f7c
 * Address: 140006f7c
 * Size: 60 bytes
 *****************************************************************************/


void FUN_140006f7c(LPVOID param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined4 uVar3;
  __acrt_ptd *p_Var4;
  
  if ((param_1 != (LPVOID)0x0) && (BVar1 = HeapFree(DAT_140019738,0,param_1), BVar1 == 0)) {
    DVar2 = GetLastError();
    uVar3 = __acrt_errno_from_os_error(DVar2);
    p_Var4 = FUN_140006ee4();
    *(undefined4 *)p_Var4 = uVar3;
  }
  return;
}



/*****************************************************************************
 * Function: FUN_140006fcc
 * Address: 140006fcc
 * Size: 1004 bytes
 *****************************************************************************/


void FUN_140006fcc(undefined8 *param_1,undefined8 *param_2)

{
  byte bVar1;
  int iVar2;
  BOOL BVar3;
  __acrt_ptd *p_Var4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  HANDLE hFindFile;
  LPVOID pvVar7;
  ushort uVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  short *psVar13;
  ulonglong uVar14;
  longlong *plVar15;
  undefined1 auStackY_2f8 [32];
  longlong *local_2c8;
  longlong *plStack_2c0;
  undefined8 local_2b8;
  ulonglong local_2b0;
  undefined8 *local_2a8;
  _WIN32_FIND_DATAW local_298;
  short *local_48;
  ulonglong local_40;
  
  local_40 = DAT_140018038 ^ (ulonglong)auStackY_2f8;
  local_2a8 = param_2;
  if (param_2 == (undefined8 *)0x0) {
    p_Var4 = FUN_140006ee4();
    *(undefined4 *)p_Var4 = 0x16;
    FUN_140006c8c();
  }
  else {
    *param_2 = 0;
    pwVar5 = (wchar_t *)*param_1;
    local_2c8 = (longlong *)0x0;
    plStack_2c0 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    local_2b8 = 0;
    while (pwVar5 != (wchar_t *)0x0) {
      local_48 = (short *)CONCAT26(local_48._6_2_,0x3f002a);
      pwVar6 = wcspbrk(pwVar5,(wchar_t *)&local_48);
      pwVar5 = (wchar_t *)*param_1;
      if (pwVar6 == (wchar_t *)0x0) {
        iVar2 = copy_and_add_argument_to_buffer<wchar_t>
                          (pwVar5,(wchar_t *)0x0,0,(argument_list<wchar_t> *)&local_2c8);
        plVar12 = local_2c8;
        plVar10 = plStack_2c0;
        if (iVar2 != 0) {
          plVar10 = local_2c8;
          if (local_2c8 != plStack_2c0) {
            do {
              FUN_140006f7c((LPVOID)*plVar10);
              plVar10 = plVar10 + 1;
            } while (plVar10 != plStack_2c0);
          }
          goto LAB_1400072cf;
        }
      }
      else {
        while ((pwVar6 != pwVar5 &&
               ((0x2d < (ushort)(*pwVar6 + L'￑') ||
                ((0x200000000801U >> ((ulonglong)(ushort)(*pwVar6 + L'￑') & 0x3f) & 1) == 0))))) {
          pwVar6 = pwVar6 + -1;
        }
        if ((*pwVar6 != L':') || (pwVar6 == pwVar5 + 1)) {
          uVar8 = *pwVar6 + L'￑';
          if ((0x2d < uVar8) || (bVar1 = 1, (0x200000000801U >> ((ulonglong)uVar8 & 0x3f) & 1) == 0)
             ) {
            bVar1 = 0;
          }
          hFindFile = FindFirstFileExW(pwVar5,FindExInfoStandard,&local_298,FindExSearchNameMatch,
                                       (LPVOID)0x0,0);
          if (hFindFile != (HANDLE)0xffffffffffffffff) {
            lVar11 = (longlong)plVar10 - (longlong)plVar12 >> 3;
            do {
              if (((local_298.cFileName[0] != L'.') ||
                  ((local_298.cFileName[1] != L'\0' &&
                   ((local_298.cFileName[1] != L'.' || (local_298.cFileName[2] != L'\0')))))) &&
                 (iVar2 = copy_and_add_argument_to_buffer<wchar_t>
                                    (local_298.cFileName,pwVar5,
                                     -(ulonglong)bVar1 &
                                     ((longlong)pwVar6 - (longlong)pwVar5 >> 1) + 1U,
                                     (argument_list<wchar_t> *)&local_2c8), iVar2 != 0)) {
                FindClose(hFindFile);
                goto LAB_14000722c;
              }
              BVar3 = FindNextFileW(hFindFile,&local_298);
              plVar10 = plStack_2c0;
              plVar12 = local_2c8;
            } while (BVar3 != 0);
            lVar9 = (longlong)plStack_2c0 - (longlong)local_2c8 >> 3;
            if (lVar11 != lVar9) {
              FUN_14000a370((undefined1 *)(local_2c8 + lVar11),lVar9 - lVar11,8,&LAB_140006fb8);
            }
            FindClose(hFindFile);
            goto LAB_1400071f1;
          }
        }
        iVar2 = copy_and_add_argument_to_buffer<wchar_t>
                          (pwVar5,(wchar_t *)0x0,0,(argument_list<wchar_t> *)&local_2c8);
        plVar10 = plStack_2c0;
        plVar12 = local_2c8;
        if (iVar2 != 0) {
LAB_14000722c:
          plVar12 = local_2c8;
          plVar10 = local_2c8;
          if (local_2c8 != plStack_2c0) {
            do {
              FUN_140006f7c((LPVOID)*plVar10);
              plVar10 = plVar10 + 1;
            } while (plVar10 != plStack_2c0);
          }
          goto LAB_1400072cf;
        }
      }
LAB_1400071f1:
      param_1 = param_1 + 1;
      pwVar5 = (wchar_t *)*param_1;
    }
    uVar14 = ((longlong)plVar10 - (longlong)plVar12 >> 3) + 1;
    local_2b0 = 0;
    for (plVar15 = plVar12; plVar15 != plVar10; plVar15 = plVar15 + 1) {
      lVar11 = -1;
      do {
        lVar11 = lVar11 + 1;
      } while (*(short *)(*plVar15 + lVar11 * 2) != 0);
      local_2b0 = local_2b0 + 1 + lVar11;
    }
    pvVar7 = __acrt_allocate_buffer_for_argv(uVar14,local_2b0,2);
    if (pvVar7 == (LPVOID)0x0) {
      FUN_140006f7c((LPVOID)0x0);
      for (plVar15 = plVar12; plVar15 != plVar10; plVar15 = plVar15 + 1) {
        FUN_140006f7c((LPVOID)*plVar15);
      }
LAB_1400072cf:
      FUN_140006f7c(plVar12);
    }
    else {
      psVar13 = (short *)((longlong)pvVar7 + uVar14 * 8);
      local_48 = psVar13;
      if (plVar12 != plVar10) {
        plVar15 = plVar12;
        do {
          lVar11 = -1;
          do {
            lVar9 = lVar11;
            lVar11 = lVar9 + 1;
          } while (*(short *)(*plVar15 + lVar11 * 2) != 0);
          lVar9 = lVar9 + 2;
          iVar2 = FUN_140006d5c(psVar13,local_2b0 - ((longlong)psVar13 - (longlong)local_48 >> 1),
                                *plVar15,lVar9);
          if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          *(short **)((longlong)plVar15 + ((longlong)pvVar7 - (longlong)plVar12)) = psVar13;
          plVar15 = plVar15 + 1;
          psVar13 = psVar13 + lVar9;
        } while (plVar15 != plVar10);
      }
      *local_2a8 = pvVar7;
      FUN_140006f7c((LPVOID)0x0);
      for (plVar15 = plVar12; plVar15 != plVar10; plVar15 = plVar15 + 1) {
        FUN_140006f7c((LPVOID)*plVar15);
      }
      FUN_140006f7c(plVar12);
    }
  }
  FUN_14000d520(local_40 ^ (ulonglong)auStackY_2f8);
  return;
}



/*****************************************************************************
 * Function: copy_and_add_argument_to_buffer<wchar_t>
 * Address: 1400073bc
 * Size: 392 bytes
 *****************************************************************************/


/* Library Function - Single Match
    int __cdecl copy_and_add_argument_to_buffer<wchar_t>(wchar_t const * __ptr64 const,wchar_t const
   * __ptr64 const,unsigned __int64,class `anonymous namespace'::argument_list<wchar_t> & __ptr64)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl
copy_and_add_argument_to_buffer<wchar_t>
          (wchar_t *param_1,wchar_t *param_2,__uint64 param_3,argument_list<wchar_t> *param_4)

{
  int iVar1;
  short *psVar2;
  LPVOID pvVar3;
  undefined8 *puVar4;
  longlong lVar5;
  ulonglong uVar7;
  int iVar8;
  ulonglong uVar9;
  longlong lVar6;
  
  iVar8 = 0;
  lVar5 = -1;
  do {
    lVar6 = lVar5;
    lVar5 = lVar6 + 1;
  } while (param_1[lVar5] != L'\0');
  uVar7 = lVar6 + 2;
  if (~param_3 < uVar7) {
    return 0xc;
  }
  uVar9 = param_3 + 1 + uVar7;
  psVar2 = (short *)_calloc_base(uVar9,2);
  if (((param_3 != 0) && (iVar1 = FUN_140006d5c(psVar2,uVar9,(longlong)param_2,param_3), iVar1 != 0)
      ) || (iVar1 = FUN_140006d5c(psVar2 + param_3,uVar9 - param_3,(longlong)param_1,uVar7),
           iVar1 != 0)) {
                    /* WARNING: Subroutine does not return */
    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  puVar4 = *(undefined8 **)(param_4 + 8);
  if (puVar4 == *(undefined8 **)(param_4 + 0x10)) {
    if (*(longlong *)param_4 == 0) {
      pvVar3 = _calloc_base(4,8);
      *(LPVOID *)param_4 = pvVar3;
      FUN_140006f7c((LPVOID)0x0);
      puVar4 = *(undefined8 **)param_4;
      if (puVar4 != (undefined8 *)0x0) {
        *(undefined8 **)(param_4 + 8) = puVar4;
        *(undefined8 **)(param_4 + 0x10) = puVar4 + 4;
        goto LAB_140007527;
      }
    }
    else {
      uVar7 = (longlong)*(undefined8 **)(param_4 + 0x10) - *(longlong *)param_4 >> 3;
      if (uVar7 < 0x8000000000000000) {
        pvVar3 = _recalloc_base(*(LPVOID *)param_4,uVar7 * 2,8);
        if (pvVar3 != (LPVOID)0x0) {
          *(LPVOID *)param_4 = pvVar3;
          *(LPVOID *)(param_4 + 8) = (LPVOID)((longlong)pvVar3 + uVar7 * 8);
          *(LPVOID *)(param_4 + 0x10) = (LPVOID)((longlong)pvVar3 + uVar7 * 0x10);
          FUN_140006f7c((LPVOID)0x0);
          puVar4 = *(undefined8 **)(param_4 + 8);
          goto LAB_140007527;
        }
        FUN_140006f7c((LPVOID)0x0);
      }
    }
    FUN_140006f7c(psVar2);
    iVar8 = 0xc;
  }
  else {
LAB_140007527:
    *puVar4 = psVar2;
    *(longlong *)(param_4 + 8) = *(longlong *)(param_4 + 8) + 8;
  }
  FUN_140006f7c((LPVOID)0x0);
  return iVar8;
}



/*****************************************************************************
 * Function: _LocaleUpdate
 * Address: 140007548
 * Size: 155 bytes
 *****************************************************************************/


/* Library Function - Single Match
    public: __cdecl _LocaleUpdate::_LocaleUpdate(struct __crt_locale_pointers * __ptr64 const)
   __ptr64
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

_LocaleUpdate * __thiscall
_LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this,__crt_locale_pointers *param_1)

{
  _LocaleUpdate *p_Var1;
  uint uVar2;
  __acrt_ptd *p_Var3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  this[0x18] = (_LocaleUpdate)0x0;
  p_Var1 = this + 8;
  if (param_1 == (__crt_locale_pointers *)0x0) {
    uVar4 = PTR_PTR_140018708._0_4_;
    uVar5 = PTR_PTR_140018708._4_4_;
    uVar6 = PTR_DAT_140018710._0_4_;
    uVar7 = PTR_DAT_140018710._4_4_;
    if (DAT_140018eb4 != 0) {
      p_Var3 = FUN_1400065a4();
      *(__acrt_ptd **)this = p_Var3;
      *(longlong *)p_Var1 = *(longlong *)(p_Var3 + 0x90);
      *(undefined8 *)(this + 0x10) = *(undefined8 *)(p_Var3 + 0x88);
      FUN_14000a0f8((longlong)p_Var3,(longlong *)p_Var1);
      FUN_14000a164(*(longlong *)this,(longlong *)(this + 0x10));
      uVar2 = *(uint *)(*(longlong *)this + 0x3a8);
      if ((uVar2 & 2) != 0) {
        return this;
      }
      *(uint *)(*(longlong *)this + 0x3a8) = uVar2 | 2;
      this[0x18] = (_LocaleUpdate)0x1;
      return this;
    }
  }
  else {
    uVar4 = *(undefined4 *)param_1;
    uVar5 = *(undefined4 *)(param_1 + 4);
    uVar6 = *(undefined4 *)(param_1 + 8);
    uVar7 = *(undefined4 *)(param_1 + 0xc);
  }
  *(undefined4 *)p_Var1 = uVar4;
  *(undefined4 *)(this + 0xc) = uVar5;
  *(undefined4 *)(this + 0x10) = uVar6;
  *(undefined4 *)(this + 0x14) = uVar7;
  return this;
}



/*****************************************************************************
 * Function: thunk_FUN_140006fcc
 * Address: 1400075e4
 * Size: 5 bytes
 *****************************************************************************/


void thunk_FUN_140006fcc(undefined8 *param_1,undefined8 *param_2)

{
  byte bVar1;
  int iVar2;
  BOOL BVar3;
  __acrt_ptd *p_Var4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  HANDLE hFindFile;
  LPVOID pvVar7;
  ushort uVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  short *psVar13;
  ulonglong uVar14;
  longlong *plVar15;
  undefined1 auStackY_2f8 [32];
  longlong *plStack_2c8;
  longlong *plStack_2c0;
  undefined8 uStack_2b8;
  ulonglong uStack_2b0;
  undefined8 *puStack_2a8;
  _WIN32_FIND_DATAW _Stack_298;
  short *psStack_48;
  ulonglong uStack_40;
  
  uStack_40 = DAT_140018038 ^ (ulonglong)auStackY_2f8;
  puStack_2a8 = param_2;
  if (param_2 == (undefined8 *)0x0) {
    p_Var4 = FUN_140006ee4();
    *(undefined4 *)p_Var4 = 0x16;
    FUN_140006c8c();
  }
  else {
    *param_2 = 0;
    pwVar5 = (wchar_t *)*param_1;
    plStack_2c8 = (longlong *)0x0;
    plStack_2c0 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    uStack_2b8 = 0;
    while (pwVar5 != (wchar_t *)0x0) {
      psStack_48 = (short *)CONCAT26(psStack_48._6_2_,0x3f002a);
      pwVar6 = wcspbrk(pwVar5,(wchar_t *)&psStack_48);
      pwVar5 = (wchar_t *)*param_1;
      if (pwVar6 == (wchar_t *)0x0) {
        iVar2 = copy_and_add_argument_to_buffer<wchar_t>
                          (pwVar5,(wchar_t *)0x0,0,(argument_list<wchar_t> *)&plStack_2c8);
        plVar12 = plStack_2c8;
        plVar10 = plStack_2c0;
        if (iVar2 != 0) {
          plVar10 = plStack_2c8;
          if (plStack_2c8 != plStack_2c0) {
            do {
              FUN_140006f7c((LPVOID)*plVar10);
              plVar10 = plVar10 + 1;
            } while (plVar10 != plStack_2c0);
          }
          goto LAB_1400072cf;
        }
      }
      else {
        while ((pwVar6 != pwVar5 &&
               ((0x2d < (ushort)(*pwVar6 + L'￑') ||
                ((0x200000000801U >> ((ulonglong)(ushort)(*pwVar6 + L'￑') & 0x3f) & 1) == 0))))) {
          pwVar6 = pwVar6 + -1;
        }
        if ((*pwVar6 != L':') || (pwVar6 == pwVar5 + 1)) {
          uVar8 = *pwVar6 + L'￑';
          if ((0x2d < uVar8) || (bVar1 = 1, (0x200000000801U >> ((ulonglong)uVar8 & 0x3f) & 1) == 0)
             ) {
            bVar1 = 0;
          }
          hFindFile = FindFirstFileExW(pwVar5,FindExInfoStandard,&_Stack_298,FindExSearchNameMatch,
                                       (LPVOID)0x0,0);
          if (hFindFile != (HANDLE)0xffffffffffffffff) {
            lVar11 = (longlong)plVar10 - (longlong)plVar12 >> 3;
            do {
              if (((_Stack_298.cFileName[0] != L'.') ||
                  ((_Stack_298.cFileName[1] != L'\0' &&
                   ((_Stack_298.cFileName[1] != L'.' || (_Stack_298.cFileName[2] != L'\0')))))) &&
                 (iVar2 = copy_and_add_argument_to_buffer<wchar_t>
                                    (_Stack_298.cFileName,pwVar5,
                                     -(ulonglong)bVar1 &
                                     ((longlong)pwVar6 - (longlong)pwVar5 >> 1) + 1U,
                                     (argument_list<wchar_t> *)&plStack_2c8), iVar2 != 0)) {
                FindClose(hFindFile);
                goto LAB_14000722c;
              }
              BVar3 = FindNextFileW(hFindFile,&_Stack_298);
              plVar10 = plStack_2c0;
              plVar12 = plStack_2c8;
            } while (BVar3 != 0);
            lVar9 = (longlong)plStack_2c0 - (longlong)plStack_2c8 >> 3;
            if (lVar11 != lVar9) {
              FUN_14000a370((undefined1 *)(plStack_2c8 + lVar11),lVar9 - lVar11,8,&LAB_140006fb8);
            }
            FindClose(hFindFile);
            goto LAB_1400071f1;
          }
        }
        iVar2 = copy_and_add_argument_to_buffer<wchar_t>
                          (pwVar5,(wchar_t *)0x0,0,(argument_list<wchar_t> *)&plStack_2c8);
        plVar10 = plStack_2c0;
        plVar12 = plStack_2c8;
        if (iVar2 != 0) {
LAB_14000722c:
          plVar12 = plStack_2c8;
          plVar10 = plStack_2c8;
          if (plStack_2c8 != plStack_2c0) {
            do {
              FUN_140006f7c((LPVOID)*plVar10);
              plVar10 = plVar10 + 1;
            } while (plVar10 != plStack_2c0);
          }
          goto LAB_1400072cf;
        }
      }
LAB_1400071f1:
      param_1 = param_1 + 1;
      pwVar5 = (wchar_t *)*param_1;
    }
    uVar14 = ((longlong)plVar10 - (longlong)plVar12 >> 3) + 1;
    uStack_2b0 = 0;
    for (plVar15 = plVar12; plVar15 != plVar10; plVar15 = plVar15 + 1) {
      lVar11 = -1;
      do {
        lVar11 = lVar11 + 1;
      } while (*(short *)(*plVar15 + lVar11 * 2) != 0);
      uStack_2b0 = uStack_2b0 + 1 + lVar11;
    }
    pvVar7 = __acrt_allocate_buffer_for_argv(uVar14,uStack_2b0,2);
    if (pvVar7 == (LPVOID)0x0) {
      FUN_140006f7c((LPVOID)0x0);
      for (plVar15 = plVar12; plVar15 != plVar10; plVar15 = plVar15 + 1) {
        FUN_140006f7c((LPVOID)*plVar15);
      }
LAB_1400072cf:
      FUN_140006f7c(plVar12);
    }
    else {
      psVar13 = (short *)((longlong)pvVar7 + uVar14 * 8);
      psStack_48 = psVar13;
      if (plVar12 != plVar10) {
        plVar15 = plVar12;
        do {
          lVar11 = -1;
          do {
            lVar9 = lVar11;
            lVar11 = lVar9 + 1;
          } while (*(short *)(*plVar15 + lVar11 * 2) != 0);
          lVar9 = lVar9 + 2;
          iVar2 = FUN_140006d5c(psVar13,uStack_2b0 - ((longlong)psVar13 - (longlong)psStack_48 >> 1)
                                ,*plVar15,lVar9);
          if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          *(short **)((longlong)plVar15 + ((longlong)pvVar7 - (longlong)plVar12)) = psVar13;
          plVar15 = plVar15 + 1;
          psVar13 = psVar13 + lVar9;
        } while (plVar15 != plVar10);
      }
      *puStack_2a8 = pvVar7;
      FUN_140006f7c((LPVOID)0x0);
      for (plVar15 = plVar12; plVar15 != plVar10; plVar15 = plVar15 + 1) {
        FUN_140006f7c((LPVOID)*plVar15);
      }
      FUN_140006f7c(plVar12);
    }
  }
  FUN_14000d520(uStack_40 ^ (ulonglong)auStackY_2f8);
  return;
}



/*****************************************************************************
 * Function: FUN_1400075ec
 * Address: 1400075ec
 * Size: 462 bytes
 *****************************************************************************/


void FUN_1400075ec(undefined8 param_1,int *param_2,undefined8 *param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  __acrt_ptd *p_Var5;
  undefined1 (*pauVar6) [32];
  undefined1 (*pauVar7) [32];
  longlong lVar8;
  
  __acrt_lock(*param_2);
  puVar4 = (undefined8 *)(*(longlong *)(*(longlong *)*param_3 + 0x88) + 0x18);
  if (DAT_140018ef8 == (undefined1 (*) [32])0x0) {
LAB_14000769f:
    p_Var5 = FUN_140006ee4();
    *(undefined4 *)p_Var5 = 0x16;
    FUN_140006c8c();
  }
  else {
    if (puVar4 == (undefined8 *)0x0) {
      FUN_140001e70(DAT_140018ef8,0,0x101);
      goto LAB_14000769f;
    }
    lVar8 = 2;
    pauVar7 = DAT_140018ef8;
    do {
      uVar3 = puVar4[1];
      *(undefined8 *)*pauVar7 = *puVar4;
      *(undefined8 *)(*pauVar7 + 8) = uVar3;
      uVar3 = puVar4[3];
      *(undefined8 *)(*pauVar7 + 0x10) = puVar4[2];
      *(undefined8 *)(*pauVar7 + 0x18) = uVar3;
      uVar3 = puVar4[5];
      *(undefined8 *)pauVar7[1] = puVar4[4];
      *(undefined8 *)(pauVar7[1] + 8) = uVar3;
      uVar3 = puVar4[7];
      *(undefined8 *)(pauVar7[1] + 0x10) = puVar4[6];
      *(undefined8 *)(pauVar7[1] + 0x18) = uVar3;
      uVar3 = puVar4[9];
      *(undefined8 *)pauVar7[2] = puVar4[8];
      *(undefined8 *)(pauVar7[2] + 8) = uVar3;
      uVar3 = puVar4[0xb];
      *(undefined8 *)(pauVar7[2] + 0x10) = puVar4[10];
      *(undefined8 *)(pauVar7[2] + 0x18) = uVar3;
      uVar3 = puVar4[0xd];
      *(undefined8 *)pauVar7[3] = puVar4[0xc];
      *(undefined8 *)(pauVar7[3] + 8) = uVar3;
      pauVar6 = pauVar7 + 4;
      uVar3 = puVar4[0xf];
      *(undefined8 *)(pauVar7[3] + 0x10) = puVar4[0xe];
      *(undefined8 *)(pauVar7[3] + 0x18) = uVar3;
      puVar4 = puVar4 + 0x10;
      lVar8 = lVar8 + -1;
      pauVar7 = pauVar6;
    } while (lVar8 != 0);
    (*pauVar6)[0] = *(undefined1 *)puVar4;
  }
  lVar8 = 2;
  puVar4 = (undefined8 *)(*(longlong *)(*(longlong *)*param_3 + 0x88) + 0x119);
  if (DAT_140018f00 != (undefined1 (*) [32])0x0) {
    pauVar7 = DAT_140018f00;
    if (puVar4 != (undefined8 *)0x0) {
      do {
        uVar3 = puVar4[1];
        *(undefined8 *)*pauVar7 = *puVar4;
        *(undefined8 *)(*pauVar7 + 8) = uVar3;
        uVar3 = puVar4[3];
        *(undefined8 *)(*pauVar7 + 0x10) = puVar4[2];
        *(undefined8 *)(*pauVar7 + 0x18) = uVar3;
        uVar3 = puVar4[5];
        *(undefined8 *)pauVar7[1] = puVar4[4];
        *(undefined8 *)(pauVar7[1] + 8) = uVar3;
        uVar3 = puVar4[7];
        *(undefined8 *)(pauVar7[1] + 0x10) = puVar4[6];
        *(undefined8 *)(pauVar7[1] + 0x18) = uVar3;
        uVar3 = puVar4[9];
        *(undefined8 *)pauVar7[2] = puVar4[8];
        *(undefined8 *)(pauVar7[2] + 8) = uVar3;
        uVar3 = puVar4[0xb];
        *(undefined8 *)(pauVar7[2] + 0x10) = puVar4[10];
        *(undefined8 *)(pauVar7[2] + 0x18) = uVar3;
        uVar3 = puVar4[0xd];
        *(undefined8 *)pauVar7[3] = puVar4[0xc];
        *(undefined8 *)(pauVar7[3] + 8) = uVar3;
        uVar3 = puVar4[0xf];
        *(undefined8 *)(pauVar7[3] + 0x10) = puVar4[0xe];
        *(undefined8 *)(pauVar7[3] + 0x18) = uVar3;
        puVar4 = puVar4 + 0x10;
        lVar8 = lVar8 + -1;
        pauVar7 = pauVar7 + 4;
      } while (lVar8 != 0);
      goto LAB_140007750;
    }
    FUN_140001e70(DAT_140018f00,0,0x100);
  }
  p_Var5 = FUN_140006ee4();
  *(undefined4 *)p_Var5 = 0x16;
  FUN_140006c8c();
LAB_140007750:
  piVar2 = (int *)**(undefined8 **)param_3[1];
  LOCK();
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if ((iVar1 == 1) && ((undefined *)**(undefined8 **)param_3[1] != &DAT_140018070)) {
    FUN_140006f7c((LPVOID)**(undefined8 **)param_3[1]);
  }
  **(undefined8 **)param_3[1] = *(undefined8 *)(*(longlong *)*param_3 + 0x88);
  LOCK();
  **(int **)(*(longlong *)*param_3 + 0x88) = **(int **)(*(longlong *)*param_3 + 0x88) + 1;
  UNLOCK();
  __acrt_unlock(*param_4);
  return;
}



/*****************************************************************************
 * Function: getSystemCP
 * Address: 1400077bc
 * Size: 125 bytes
 *****************************************************************************/


/* Library Function - Single Match
    int __cdecl getSystemCP(int)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl getSystemCP(int param_1)

{
  longlong local_28;
  longlong local_20;
  char local_10;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_28,(__crt_locale_pointers *)0x0);
  DAT_140018f10 = 0;
  if (param_1 == -2) {
    DAT_140018f10 = 1;
    param_1 = GetOEMCP();
  }
  else if (param_1 == -3) {
    DAT_140018f10 = 1;
    param_1 = GetACP();
  }
  else if (param_1 == -4) {
    DAT_140018f10 = 1;
    param_1 = *(UINT *)(local_20 + 0xc);
  }
  if (local_10 != '\0') {
    *(uint *)(local_28 + 0x3a8) = *(uint *)(local_28 + 0x3a8) & 0xfffffffd;
  }
  return param_1;
}



/*****************************************************************************
 * Function: FUN_14000783c
 * Address: 14000783c
 * Size: 152 bytes
 *****************************************************************************/


void FUN_14000783c(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined2 *puVar3;
  longlong lVar4;
  
  FUN_140001e70((undefined1 (*) [32])(param_1 + 0x18),0,0x101);
  lVar2 = 0;
  *(undefined8 *)(param_1 + 4) = 0;
  *(undefined8 *)(param_1 + 0x220) = 0;
  puVar3 = (undefined2 *)(param_1 + 0xc);
  for (lVar1 = 6; lVar4 = lVar2, lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  do {
    lVar1 = lVar4 + 1;
    *(undefined1 *)(param_1 + lVar4 + 0x18) = (&DAT_140018088)[lVar4];
    lVar4 = lVar1;
  } while (lVar1 < 0x101);
  do {
    lVar1 = lVar2 + 1;
    *(undefined1 *)(param_1 + lVar2 + 0x119) = (&DAT_140018189)[lVar2];
    lVar2 = lVar1;
  } while (lVar1 < 0x100);
  return;
}



/*****************************************************************************
 * Function: FUN_1400078d4
 * Address: 1400078d4
 * Size: 487 bytes
 *****************************************************************************/


void FUN_1400078d4(longlong param_1)

{
  byte bVar1;
  BOOL BVar2;
  uint uVar3;
  byte *pbVar4;
  char *pcVar5;
  ulonglong uVar6;
  BYTE *pBVar7;
  WORD *pWVar8;
  longlong lVar9;
  undefined1 auStackY_788 [32];
  _cpinfo local_738;
  char local_718 [231];
  byte abStack_631 [25];
  undefined1 local_618 [231];
  byte abStack_531 [25];
  undefined1 local_518 [256];
  WORD local_418 [512];
  ulonglong local_18;
  
  local_18 = DAT_140018038 ^ (ulonglong)auStackY_788;
  if ((*(UINT *)(param_1 + 4) == 0xfde9) ||
     (BVar2 = GetCPInfo(*(UINT *)(param_1 + 4),&local_738), BVar2 == 0)) {
    uVar3 = 0;
    pbVar4 = (byte *)(param_1 + 0x19);
    do {
      if (uVar3 - 0x41 < 0x1a) {
        *pbVar4 = *pbVar4 | 0x10;
        bVar1 = (char)uVar3 + 0x20;
      }
      else if (uVar3 - 0x61 < 0x1a) {
        *pbVar4 = *pbVar4 | 0x20;
        bVar1 = (char)uVar3 - 0x20;
      }
      else {
        bVar1 = 0;
      }
      pbVar4[0x100] = bVar1;
      uVar3 = uVar3 + 1;
      pbVar4 = pbVar4 + 1;
    } while (uVar3 < 0x100);
  }
  else {
    uVar3 = 0;
    pcVar5 = local_718;
    lVar9 = 0x100;
    do {
      *pcVar5 = (char)uVar3;
      uVar3 = uVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (uVar3 < 0x100);
    pBVar7 = local_738.LeadByte;
    local_718[0] = ' ';
    while (local_738.LeadByte[0] != 0) {
      bVar1 = pBVar7[1];
      uVar6 = (ulonglong)local_738.LeadByte[0];
      while ((uVar3 = (uint)uVar6, uVar3 <= bVar1 && (uVar3 < 0x100))) {
        local_718[uVar6] = ' ';
        uVar6 = (ulonglong)(uVar3 + 1);
      }
      pBVar7 = pBVar7 + 2;
      local_738.LeadByte[0] = *pBVar7;
    }
    FUN_140008ce0((__crt_locale_pointers *)0x0,1,local_718,0x100,local_418,*(uint *)(param_1 + 4),0)
    ;
    __acrt_LCMapStringA((__crt_locale_pointers *)0x0,*(ushort **)(param_1 + 0x220),0x100,local_718,
                        0x100,local_618,0x100,*(uint *)(param_1 + 4),0);
    __acrt_LCMapStringA((__crt_locale_pointers *)0x0,*(ushort **)(param_1 + 0x220),0x200,local_718,
                        0x100,local_518,0x100,*(uint *)(param_1 + 4),0);
    pWVar8 = local_418;
    pbVar4 = (byte *)(param_1 + 0x19);
    do {
      if ((*pWVar8 & 1) == 0) {
        if ((*pWVar8 & 2) == 0) {
          bVar1 = 0;
        }
        else {
          *pbVar4 = *pbVar4 | 0x20;
          bVar1 = pbVar4[(longlong)(abStack_531 + -param_1)];
        }
      }
      else {
        *pbVar4 = *pbVar4 | 0x10;
        bVar1 = pbVar4[(longlong)(abStack_631 + -param_1)];
      }
      pbVar4[0x100] = bVar1;
      pWVar8 = pWVar8 + 1;
      pbVar4 = pbVar4 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
  }
  FUN_14000d520(local_18 ^ (ulonglong)auStackY_788);
  return;
}



/*****************************************************************************
 * Function: FUN_140007abc
 * Address: 140007abc
 * Size: 623 bytes
 *****************************************************************************/


int FUN_140007abc(int param_1,char param_2,__acrt_ptd *param_3,__crt_multibyte_data **param_4)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  int iVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  __acrt_ptd *p_Var12;
  undefined8 *puVar13;
  longlong lVar14;
  longlong lVar15;
  __acrt_ptd *local_res18;
  __crt_multibyte_data **local_res20;
  undefined1 local_268 [4];
  int local_264 [3];
  __acrt_ptd **local_258;
  __crt_multibyte_data ***local_250;
  undefined8 local_248 [70];
  
  local_res18 = param_3;
  local_res20 = param_4;
  update_thread_multibyte_data_internal(param_3,param_4);
  iVar9 = getSystemCP(param_1);
  if (iVar9 == *(int *)(*(longlong *)(local_res18 + 0x88) + 4)) {
    iVar9 = 0;
  }
  else {
    puVar10 = (undefined8 *)_malloc_base(0x228);
    if (puVar10 == (undefined8 *)0x0) {
      FUN_140006f7c((LPVOID)0x0);
      iVar9 = -1;
    }
    else {
      lVar14 = 4;
      lVar15 = 4;
      puVar7 = *(undefined8 **)(local_res18 + 0x88);
      puVar8 = local_248;
      do {
        puVar13 = puVar8;
        puVar11 = puVar7;
        uVar2 = puVar11[1];
        uVar4 = puVar11[2];
        uVar5 = puVar11[3];
        *puVar13 = *puVar11;
        puVar13[1] = uVar2;
        uVar2 = puVar11[4];
        uVar6 = puVar11[5];
        puVar13[2] = uVar4;
        puVar13[3] = uVar5;
        uVar4 = puVar11[6];
        uVar5 = puVar11[7];
        puVar13[4] = uVar2;
        puVar13[5] = uVar6;
        uVar2 = puVar11[8];
        uVar6 = puVar11[9];
        puVar13[6] = uVar4;
        puVar13[7] = uVar5;
        uVar4 = puVar11[10];
        uVar5 = puVar11[0xb];
        puVar13[8] = uVar2;
        puVar13[9] = uVar6;
        uVar2 = puVar11[0xc];
        uVar6 = puVar11[0xd];
        puVar13[10] = uVar4;
        puVar13[0xb] = uVar5;
        uVar4 = puVar11[0xe];
        uVar5 = puVar11[0xf];
        puVar13[0xc] = uVar2;
        puVar13[0xd] = uVar6;
        puVar13[0xe] = uVar4;
        puVar13[0xf] = uVar5;
        lVar15 = lVar15 + -1;
        puVar7 = puVar11 + 0x10;
        puVar8 = puVar13 + 0x10;
      } while (lVar15 != 0);
      uVar4 = puVar11[0x11];
      uVar5 = puVar11[0x12];
      uVar6 = puVar11[0x13];
      uVar2 = puVar11[0x14];
      puVar13[0x10] = puVar11[0x10];
      puVar13[0x11] = uVar4;
      puVar13[0x12] = uVar5;
      puVar13[0x13] = uVar6;
      puVar13[0x14] = uVar2;
      puVar7 = local_248;
      puVar8 = puVar10;
      do {
        puVar13 = puVar8;
        puVar11 = puVar7;
        uVar2 = puVar11[1];
        uVar4 = puVar11[2];
        uVar5 = puVar11[3];
        *puVar13 = *puVar11;
        puVar13[1] = uVar2;
        uVar2 = puVar11[4];
        uVar6 = puVar11[5];
        puVar13[2] = uVar4;
        puVar13[3] = uVar5;
        uVar4 = puVar11[6];
        uVar5 = puVar11[7];
        puVar13[4] = uVar2;
        puVar13[5] = uVar6;
        uVar2 = puVar11[8];
        uVar6 = puVar11[9];
        puVar13[6] = uVar4;
        puVar13[7] = uVar5;
        uVar4 = puVar11[10];
        uVar5 = puVar11[0xb];
        puVar13[8] = uVar2;
        puVar13[9] = uVar6;
        uVar2 = puVar11[0xc];
        uVar6 = puVar11[0xd];
        puVar13[10] = uVar4;
        puVar13[0xb] = uVar5;
        uVar4 = puVar11[0xe];
        uVar5 = puVar11[0xf];
        puVar13[0xc] = uVar2;
        puVar13[0xd] = uVar6;
        puVar13[0xe] = uVar4;
        puVar13[0xf] = uVar5;
        lVar14 = lVar14 + -1;
        puVar7 = puVar11 + 0x10;
        puVar8 = puVar13 + 0x10;
      } while (lVar14 != 0);
      uVar4 = puVar11[0x11];
      uVar5 = puVar11[0x12];
      uVar6 = puVar11[0x13];
      uVar2 = puVar11[0x14];
      puVar13[0x10] = puVar11[0x10];
      puVar13[0x11] = uVar4;
      puVar13[0x12] = uVar5;
      puVar13[0x13] = uVar6;
      puVar13[0x14] = uVar2;
      *(undefined4 *)puVar10 = 0;
      iVar9 = FUN_140007e60(iVar9,(longlong)puVar10);
      if (iVar9 == -1) {
        p_Var12 = FUN_140006ee4();
        *(undefined4 *)p_Var12 = 0x16;
        FUN_140006f7c(puVar10);
        iVar9 = -1;
      }
      else {
        if (param_2 == '\0') {
          FUN_140005908();
        }
        piVar3 = *(int **)(local_res18 + 0x88);
        LOCK();
        iVar1 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if ((iVar1 == 1) && (*(undefined **)(local_res18 + 0x88) != &DAT_140018070)) {
          FUN_140006f7c(*(undefined **)(local_res18 + 0x88));
        }
        *(undefined4 *)puVar10 = 1;
        *(undefined8 **)(local_res18 + 0x88) = puVar10;
        if ((DAT_1400187c0 & *(uint *)(local_res18 + 0x3a8)) == 0) {
          local_258 = &local_res18;
          local_250 = &local_res20;
          local_264[0] = 5;
          local_264[1] = 5;
          FUN_1400075ec(local_268,local_264 + 1,&local_258,local_264);
          if (param_2 != '\0') {
            PTR_DAT_140018710 = *local_res20;
          }
        }
        FUN_140006f7c((LPVOID)0x0);
      }
    }
  }
  return iVar9;
}



/*****************************************************************************
 * Function: update_thread_multibyte_data_internal
 * Address: 140007d2c
 * Size: 183 bytes
 *****************************************************************************/


/* Library Function - Single Match
    struct __crt_multibyte_data * __ptr64 __cdecl update_thread_multibyte_data_internal(struct
   __acrt_ptd * __ptr64 const,struct __crt_multibyte_data * __ptr64 * __ptr64 const)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

__crt_multibyte_data * __cdecl
update_thread_multibyte_data_internal(__acrt_ptd *param_1,__crt_multibyte_data **param_2)

{
  int iVar1;
  __crt_multibyte_data *p_Var2;
  
  if (((*(uint *)(param_1 + 0x3a8) & DAT_1400187c0) == 0) || (*(longlong *)(param_1 + 0x90) == 0)) {
    __acrt_lock(5);
    p_Var2 = *(__crt_multibyte_data **)(param_1 + 0x88);
    if (p_Var2 != *param_2) {
      if (p_Var2 != (__crt_multibyte_data *)0x0) {
        LOCK();
        iVar1 = *(int *)p_Var2;
        *(int *)p_Var2 = *(int *)p_Var2 + -1;
        UNLOCK();
        if ((iVar1 == 1) && (p_Var2 != (__crt_multibyte_data *)&DAT_140018070)) {
          FUN_140006f7c(p_Var2);
        }
      }
      p_Var2 = *param_2;
      *(__crt_multibyte_data **)(param_1 + 0x88) = p_Var2;
      LOCK();
      *(int *)p_Var2 = *(int *)p_Var2 + 1;
      UNLOCK();
    }
    __acrt_unlock(5);
  }
  else {
    p_Var2 = *(__crt_multibyte_data **)(param_1 + 0x88);
  }
  if (p_Var2 != (__crt_multibyte_data *)0x0) {
    return p_Var2;
  }
                    /* WARNING: Subroutine does not return */
  abort();
}



/*****************************************************************************
 * Function: FUN_140007e44
 * Address: 140007e44
 * Size: 28 bytes
 *****************************************************************************/


void FUN_140007e44(void)

{
  __acrt_ptd *p_Var1;
  
  p_Var1 = FUN_1400065a4();
  update_thread_multibyte_data_internal(p_Var1,(__crt_multibyte_data **)&DAT_140018f08);
  return;
}



/*****************************************************************************
 * Function: FUN_140007e60
 * Address: 140007e60
 * Size: 701 bytes
 *****************************************************************************/


void FUN_140007e60(int param_1,longlong param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  BOOL BVar5;
  uint *puVar6;
  byte *pbVar7;
  undefined *puVar8;
  longlong lVar9;
  BYTE *pBVar10;
  ulonglong uVar11;
  byte *pbVar12;
  undefined2 *puVar13;
  undefined *puVar14;
  undefined *puVar15;
  undefined4 uVar16;
  uint uVar17;
  uint uVar18;
  byte *pbVar19;
  undefined1 auStack_68 [32];
  _cpinfo local_48;
  ulonglong local_30;
  
  local_30 = DAT_140018038 ^ (ulonglong)auStack_68;
  uVar4 = getSystemCP(param_1);
  puVar14 = (undefined *)0x0;
  if (uVar4 != 0) {
    puVar6 = &DAT_1400184c0;
    uVar16 = 1;
    puVar8 = puVar14;
LAB_140007ea9:
    if (*puVar6 != uVar4) goto code_r0x000140007eb1;
    FUN_140001e70((undefined1 (*) [32])(param_2 + 0x18),0,0x101);
    pbVar19 = &DAT_1400184b0;
    lVar9 = 4;
    pbVar7 = &DAT_1400184d0 + (longlong)puVar8 * 0x30;
    do {
      bVar2 = *pbVar7;
      pbVar12 = pbVar7;
      while ((bVar2 != 0 && (pbVar12[1] != 0))) {
        bVar2 = *pbVar12;
        uVar18 = (uint)bVar2;
        if (bVar2 <= pbVar12[1]) {
          uVar17 = (uint)bVar2;
          do {
            uVar17 = uVar17 + 1;
            if (0x100 < uVar17) break;
            uVar18 = uVar18 + 1;
            pbVar1 = (byte *)((ulonglong)uVar17 + 0x18 + param_2);
            *pbVar1 = *pbVar1 | *pbVar19;
          } while (uVar18 <= pbVar12[1]);
        }
        pbVar12 = pbVar12 + 2;
        bVar2 = *pbVar12;
      }
      pbVar7 = pbVar7 + 8;
      pbVar19 = pbVar19 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    *(uint *)(param_2 + 4) = uVar4;
    *(undefined4 *)(param_2 + 8) = 1;
    puVar15 = PTR_u_ja_JP_14000f778;
    if (((uVar4 != 0x3a4) && (puVar15 = PTR_u_zh_CN_14000f780, uVar4 != 0x3a8)) &&
       ((puVar15 = PTR_u_ko_KR_14000f788, uVar4 != 0x3b5 && (puVar15 = puVar14, uVar4 == 0x3b6)))) {
      puVar15 = PTR_u_zh_TW_14000f790;
    }
    *(undefined **)(param_2 + 0x220) = puVar15;
    puVar13 = (undefined2 *)(param_2 + 0xc);
    lVar9 = 6;
    do {
      *puVar13 = *(undefined2 *)
                  (((longlong)puVar8 * 0x30 - param_2) + 0x1400184b8 + (longlong)puVar13);
      puVar13 = puVar13 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    goto LAB_140007f05;
  }
LAB_1400080ed:
  FUN_14000783c(param_2);
LAB_1400080f7:
  FUN_14000d520(local_30 ^ (ulonglong)auStack_68);
  return;
code_r0x000140007eb1:
  uVar18 = (int)puVar8 + 1;
  puVar8 = (undefined *)(ulonglong)uVar18;
  puVar6 = puVar6 + 0xc;
  if (4 < uVar18) goto code_r0x000140007ebe;
  goto LAB_140007ea9;
code_r0x000140007ebe:
  if ((uVar4 == 65000) || (BVar5 = IsValidCodePage(uVar4 & 0xffff), BVar5 == 0)) goto LAB_1400080f7;
  if (uVar4 == 0xfde9) {
    *(undefined8 *)(param_2 + 4) = 0xfde9;
    *(undefined8 *)(param_2 + 0x220) = 0;
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined2 *)(param_2 + 0x1c) = 0;
  }
  else {
    BVar5 = GetCPInfo(uVar4,&local_48);
    if (BVar5 == 0) {
      if (DAT_140018f10 == 0) goto LAB_1400080f7;
      goto LAB_1400080ed;
    }
    FUN_140001e70((undefined1 (*) [32])(param_2 + 0x18),0,0x101);
    *(uint *)(param_2 + 4) = uVar4;
    *(undefined8 *)(param_2 + 0x220) = 0;
    if (local_48.MaxCharSize == 2) {
      pBVar10 = local_48.LeadByte;
      while ((local_48.LeadByte[0] != 0 && (pBVar10[1] != 0))) {
        bVar2 = *pBVar10;
        if ((uint)bVar2 <= (uint)pBVar10[1]) {
          uVar4 = (uint)bVar2;
          uVar11 = (ulonglong)(((uint)pBVar10[1] - (uint)bVar2) + 1);
          do {
            uVar4 = uVar4 + 1;
            pbVar7 = (byte *)((ulonglong)uVar4 + 0x18 + param_2);
            *pbVar7 = *pbVar7 | 4;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        pBVar10 = pBVar10 + 2;
        local_48.LeadByte[0] = *pBVar10;
      }
      pbVar7 = (byte *)(param_2 + 0x1a);
      lVar9 = 0xfe;
      do {
        *pbVar7 = *pbVar7 | 8;
        pbVar7 = pbVar7 + 1;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
      iVar3 = *(int *)(param_2 + 4);
      puVar8 = PTR_u_ja_JP_14000f778;
      if ((((iVar3 != 0x3a4) && (puVar8 = PTR_u_zh_CN_14000f780, iVar3 != 0x3a8)) &&
          (puVar8 = PTR_u_ko_KR_14000f788, iVar3 != 0x3b5)) &&
         (puVar8 = PTR_u_zh_TW_14000f790, iVar3 != 0x3b6)) {
        puVar8 = puVar14;
      }
      *(undefined **)(param_2 + 0x220) = puVar8;
    }
    else {
      uVar16 = 0;
    }
    *(undefined4 *)(param_2 + 8) = uVar16;
  }
  puVar13 = (undefined2 *)(param_2 + 0xc);
  for (lVar9 = 6; lVar9 != 0; lVar9 = lVar9 + -1) {
    *puVar13 = 0;
    puVar13 = puVar13 + 1;
  }
LAB_140007f05:
  FUN_1400078d4(param_2);
  goto LAB_1400080f7;
}



/*****************************************************************************
 * Function: FUN_140008120
 * Address: 140008120
 * Size: 37 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_140008120(void)

{
  _DAT_140018f38 = GetCommandLineA();
  DAT_140018f40 = GetCommandLineW();
  return 1;
}



/*****************************************************************************
 * Function: FUN_140008254
 * Address: 140008254
 * Size: 156 bytes
 *****************************************************************************/


LPWCH FUN_140008254(void)

{
  WCHAR WVar1;
  ulonglong uVar2;
  LPWCH pWVar3;
  longlong lVar4;
  LPWCH pWVar6;
  LPWCH pWVar7;
  WCHAR *pWVar8;
  longlong lVar5;
  
  pWVar3 = GetEnvironmentStringsW();
  pWVar7 = pWVar3;
  if (pWVar3 != (LPWCH)0x0) {
    WVar1 = *pWVar3;
    pWVar8 = pWVar3;
    while (WVar1 != L'\0') {
      lVar4 = -1;
      do {
        lVar5 = lVar4;
        lVar4 = lVar5 + 1;
      } while (pWVar8[lVar4] != L'\0');
      pWVar8 = pWVar8 + lVar5 + 2;
      WVar1 = *pWVar8;
    }
    uVar2 = ((longlong)pWVar8 + (2 - (longlong)pWVar3) >> 1) * 2;
    pWVar6 = (LPWCH)_malloc_base(uVar2);
    pWVar7 = (LPWCH)0x0;
    if (pWVar6 != (LPWCH)0x0) {
      FUN_140002d40((undefined8 *)pWVar6,(undefined8 *)pWVar3,uVar2);
      pWVar7 = pWVar6;
    }
    FUN_140006f7c((LPVOID)0x0);
    FreeEnvironmentStringsW(pWVar3);
  }
  return pWVar7;
}



/*****************************************************************************
 * Function: FUN_140008584
 * Address: 140008584
 * Size: 39 bytes
 *****************************************************************************/


void FUN_140008584(uint param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001400085a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EnterCriticalSection
            ((&DAT_140019190)[(longlong)(int)param_1 >> 6] + (ulonglong)(param_1 & 0x3f) * 0x48);
  return;
}



/*****************************************************************************
 * Function: FUN_1400085ac
 * Address: 1400085ac
 * Size: 39 bytes
 *****************************************************************************/


void FUN_1400085ac(uint param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001400085cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LeaveCriticalSection
            ((&DAT_140019190)[(longlong)(int)param_1 >> 6] + (ulonglong)(param_1 & 0x3f) * 0x48);
  return;
}



/*****************************************************************************
 * Function: FUN_1400085d4
 * Address: 1400085d4
 * Size: 186 bytes
 *****************************************************************************/


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



/*****************************************************************************
 * Function: FUN_140008690
 * Address: 140008690
 * Size: 117 bytes
 *****************************************************************************/


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



/*****************************************************************************
 * Function: initialize_inherited_file_handles_nolock
 * Address: 140008724
 * Size: 237 bytes
 *****************************************************************************/


/* Library Function - Single Match
    void __cdecl initialize_inherited_file_handles_nolock(void)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl initialize_inherited_file_handles_nolock(void)

{
  longlong lVar1;
  DWORD DVar2;
  ulonglong uVar3;
  byte *pbVar4;
  longlong lVar5;
  uint *puVar6;
  uint uVar7;
  ulonglong uVar8;
  _STARTUPINFOW local_78;
  
  GetStartupInfoW(&local_78);
  lVar5 = 0;
  if ((local_78.cbReserved2 != 0) && ((uint *)local_78.lpReserved2 != (uint *)0x0)) {
    puVar6 = (uint *)((longlong)local_78.lpReserved2 + 4);
    pbVar4 = (byte *)((longlong)(int)*(uint *)local_78.lpReserved2 + (longlong)puVar6);
    uVar7 = 0x2000;
    if ((int)*(uint *)local_78.lpReserved2 < 0x2000) {
      uVar7 = *(uint *)local_78.lpReserved2;
    }
    __acrt_lowio_ensure_fh_exists(uVar7);
    if ((int)DAT_140019590 < (int)uVar7) {
      uVar7 = DAT_140019590;
    }
    uVar8 = (ulonglong)uVar7;
    if (uVar7 != 0) {
      do {
        if ((((*(longlong *)pbVar4 != -1) && (*(longlong *)pbVar4 != -2)) && ((*puVar6 & 1) != 0))
           && (((*puVar6 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)pbVar4), DVar2 != 0)))) {
          uVar3 = (ulonglong)((uint)lVar5 & 0x3f);
          lVar1 = (&DAT_140019190)[lVar5 >> 6];
          *(undefined8 *)(lVar1 + 0x28 + uVar3 * 0x48) = *(undefined8 *)pbVar4;
          *(byte *)(lVar1 + 0x38 + uVar3 * 0x48) = (byte)*puVar6;
        }
        lVar5 = lVar5 + 1;
        puVar6 = (uint *)((longlong)puVar6 + 1);
        pbVar4 = pbVar4 + 8;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
  }
  return;
}



/*****************************************************************************
 * Function: FUN_140008814
 * Address: 140008814
 * Size: 264 bytes
 *****************************************************************************/


void FUN_140008814(void)

{
  byte *pbVar1;
  longlong lVar2;
  DWORD DVar3;
  HANDLE hFile;
  ulonglong uVar4;
  uint uVar5;
  longlong lVar6;
  
  uVar5 = 0;
  lVar6 = 0;
  do {
    uVar4 = (ulonglong)(uVar5 & 0x3f);
    lVar2 = (&DAT_140019190)[(longlong)(int)uVar5 >> 6];
    if (*(longlong *)(lVar2 + 0x28 + uVar4 * 0x48) + 2U < 2) {
      *(undefined1 *)(lVar2 + 0x38 + uVar4 * 0x48) = 0x81;
      if (uVar5 == 0) {
        DVar3 = 0xfffffff6;
      }
      else if (uVar5 == 1) {
        DVar3 = 0xfffffff5;
      }
      else {
        DVar3 = 0xfffffff4;
      }
      hFile = GetStdHandle(DVar3);
      if (1 < (longlong)hFile + 1U) {
        DVar3 = GetFileType(hFile);
        if (DVar3 != 0) {
          *(HANDLE *)(lVar2 + 0x28 + uVar4 * 0x48) = hFile;
          if ((DVar3 & 0xff) == 2) {
            pbVar1 = (byte *)(lVar2 + 0x38 + uVar4 * 0x48);
            *pbVar1 = *pbVar1 | 0x40;
          }
          else if ((DVar3 & 0xff) == 3) {
            pbVar1 = (byte *)(lVar2 + 0x38 + uVar4 * 0x48);
            *pbVar1 = *pbVar1 | 8;
          }
          goto LAB_1400088f2;
        }
      }
      pbVar1 = (byte *)(lVar2 + 0x38 + uVar4 * 0x48);
      *pbVar1 = *pbVar1 | 0x40;
      *(undefined8 *)(lVar2 + 0x28 + uVar4 * 0x48) = 0xfffffffffffffffe;
      if (DAT_140019770 != 0) {
        *(undefined4 *)(*(longlong *)(lVar6 + DAT_140019770) + 0x18) = 0xfffffffe;
      }
    }
    else {
      pbVar1 = (byte *)(lVar2 + 0x38 + uVar4 * 0x48);
      *pbVar1 = *pbVar1 | 0x80;
    }
LAB_1400088f2:
    uVar5 = uVar5 + 1;
    lVar6 = lVar6 + 8;
    if (uVar5 == 3) {
      return;
    }
  } while( true );
}



/*****************************************************************************
 * Function: FUN_140008b10
 * Address: 140008b10
 * Size: 50 bytes
 *****************************************************************************/


void FUN_140008b10(undefined8 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = param_1 + param_2;
  if (param_1 != puVar1) {
    do {
      FUN_140006f7c((LPVOID)*param_1);
      param_1 = param_1 + 1;
    } while (param_1 != puVar1);
  }
  return;
}



/*****************************************************************************
 * Function: _malloc_base
 * Address: 140008c4c
 * Size: 94 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _malloc_base
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

LPVOID _malloc_base(ulonglong param_1)

{
  int iVar1;
  undefined8 uVar2;
  LPVOID pvVar3;
  __acrt_ptd *p_Var4;
  
  if (param_1 < 0xffffffffffffffe1) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    do {
      pvVar3 = HeapAlloc(DAT_140019738,0,param_1);
      if (pvVar3 != (LPVOID)0x0) {
        return pvVar3;
      }
      iVar1 = FUN_1400059b0();
    } while ((iVar1 != 0) && (uVar2 = FUN_140009898(param_1), (int)uVar2 != 0));
  }
  p_Var4 = FUN_140006ee4();
  *(undefined4 *)p_Var4 = 0xc;
  return (LPVOID)0x0;
}



/*****************************************************************************
 * Function: wcspbrk
 * Address: 140008cac
 * Size: 52 bytes
 *****************************************************************************/


/* Library Function - Single Match
    wcspbrk
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

wchar_t * __cdecl wcspbrk(wchar_t *_Str,wchar_t *_Control)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  
  do {
    if (*_Str == L'\0') {
      return (wchar_t *)0x0;
    }
    if (*_Control != L'\0') {
      wVar1 = *_Control;
      pwVar2 = _Control;
      do {
        if (wVar1 == *_Str) {
          return _Str;
        }
        pwVar2 = pwVar2 + 1;
        wVar1 = *pwVar2;
      } while (wVar1 != L'\0');
    }
    _Str = _Str + 1;
  } while( true );
}



/*****************************************************************************
 * Function: FUN_140008ce0
 * Address: 140008ce0
 * Size: 409 bytes
 *****************************************************************************/


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_140008ce0(__crt_locale_pointers *param_1,DWORD param_2,undefined8 param_3,
                  undefined8 param_4,LPWORD param_5,uint param_6,int param_7)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  undefined1 (*lpSrcStr) [32];
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined4 local_60;
  longlong local_58;
  longlong local_50;
  char local_40;
  ulonglong local_38;
  
  puVar6 = auStack_88;
  puVar8 = auStack_88;
  puVar7 = auStack_88;
  local_38 = DAT_140018038 ^ (ulonglong)&local_58;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_58,param_1);
  if (param_6 == 0) {
    param_6 = *(uint *)(local_50 + 0xc);
  }
  local_60 = 0;
  local_68 = 0;
  iVar2 = __acrt_MultiByteToWideChar(param_6,(ulonglong)((-(uint)(param_7 != 0) & 8) + 1));
  if (iVar2 == 0) goto LAB_140008e40;
  uVar5 = (longlong)iVar2 * 2;
  uVar4 = -(ulonglong)(uVar5 < uVar5 + 0x10) & uVar5 + 0x10;
  if (uVar4 == 0) {
    lpSrcStr = (undefined1 (*) [32])0x0;
LAB_140008e28:
    puVar8 = puVar7;
    if (lpSrcStr == (undefined1 (*) [32])0x0) goto LAB_140008e40;
  }
  else {
    if (uVar4 < 0x401) {
      uVar3 = uVar4 + 0xf;
      if (uVar3 <= uVar4) {
        uVar3 = 0xffffffffffffff0;
      }
      lVar1 = -(uVar3 & 0xfffffffffffffff0);
      puVar6 = auStack_88 + lVar1;
      lpSrcStr = (undefined1 (*) [32])((longlong)&local_58 + lVar1);
      puVar7 = auStack_88 + lVar1;
      if (lpSrcStr != (undefined1 (*) [32])0x0) {
        *(undefined4 *)*lpSrcStr = 0xcccc;
LAB_140008dcc:
        lpSrcStr = (undefined1 (*) [32])((longlong)*lpSrcStr + 0x10);
        puVar7 = puVar6;
      }
    }
    else {
      lpSrcStr = (undefined1 (*) [32])_malloc_base(uVar4);
      puVar7 = auStack_88;
      if (lpSrcStr != (undefined1 (*) [32])0x0) {
        *(undefined4 *)*lpSrcStr = 0xdddd;
        goto LAB_140008dcc;
      }
    }
    if (lpSrcStr == (undefined1 (*) [32])0x0) goto LAB_140008e28;
    *(undefined8 *)(puVar7 + -8) = 0x140008de5;
    FUN_140001e70(lpSrcStr,0,uVar5);
    *(int *)(puVar7 + 0x28) = iVar2;
    *(undefined1 (**) [32])(puVar7 + 0x20) = lpSrcStr;
    *(undefined8 *)(puVar7 + -8) = 0x140008e01;
    iVar2 = __acrt_MultiByteToWideChar(param_6,1);
    if (iVar2 == 0) goto LAB_140008e28;
    *(undefined8 *)(puVar7 + -8) = 0x140008e1f;
    GetStringTypeW(param_2,(LPCWSTR)lpSrcStr,iVar2,param_5);
  }
  puVar8 = puVar7;
  if (*(int *)(lpSrcStr[-1] + 0x10) == 0xdddd) {
    *(undefined8 *)(puVar7 + -8) = 0x140008e40;
    FUN_140006f7c(lpSrcStr[-1] + 0x10);
  }
LAB_140008e40:
  if (local_40 != '\0') {
    *(uint *)(local_58 + 0x3a8) = *(uint *)(local_58 + 0x3a8) & 0xfffffffd;
  }
  uVar5 = local_38 ^ (ulonglong)&local_58;
  *(undefined8 *)(puVar8 + -8) = 0x140008e5f;
  FUN_14000d520(uVar5);
  return;
}



/*****************************************************************************
 * Function: FUN_1400091b0
 * Address: 1400091b0
 * Size: 109 bytes
 *****************************************************************************/


undefined ** FUN_1400091b0(void)

{
  __acrt_ptd *p_Var1;
  undefined **ppuVar2;
  
  p_Var1 = FUN_1400065a4();
  if (((DAT_1400187c0 & *(uint *)(p_Var1 + 0x3a8)) == 0) ||
     (ppuVar2 = *(undefined ***)(p_Var1 + 0x90), ppuVar2 == (undefined **)0x0)) {
    __acrt_lock(4);
    ppuVar2 = _updatetlocinfoEx_nolock((undefined8 *)(p_Var1 + 0x90),DAT_140019598);
    __acrt_unlock(4);
    if (ppuVar2 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
  }
  return ppuVar2;
}



/*****************************************************************************
 * Function: _updatetlocinfoEx_nolock
 * Address: 140009220
 * Size: 101 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _updatetlocinfoEx_nolock
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined ** _updatetlocinfoEx_nolock(undefined8 *param_1,undefined **param_2)

{
  undefined **ppuVar1;
  
  if ((param_2 == (undefined **)0x0) || (param_1 == (undefined8 *)0x0)) {
    param_2 = (undefined **)0x0;
  }
  else {
    ppuVar1 = (undefined **)*param_1;
    if (ppuVar1 != param_2) {
      *param_1 = param_2;
      __acrt_add_locale_ref((longlong)param_2);
      if (((ppuVar1 != (undefined **)0x0) &&
          (__acrt_release_locale_ref((longlong)ppuVar1), *(int *)(ppuVar1 + 2) == 0)) &&
         (ppuVar1 != &PTR_DAT_1400185b0)) {
        __acrt_free_locale(ppuVar1);
      }
    }
  }
  return param_2;
}



/*****************************************************************************
 * Function: FUN_140009288
 * Address: 140009288
 * Size: 447 bytes
 *****************************************************************************/


FARPROC FUN_140009288(uint param_1,LPCSTR param_2,uint *param_3,uint *param_4)

{
  longlong lVar1;
  uint uVar2;
  wchar_t *lpLibFileName;
  byte bVar3;
  DWORD DVar4;
  int iVar5;
  HMODULE hLibModule;
  FARPROC pFVar6;
  
  bVar3 = (byte)DAT_140018038 & 0x3f;
  pFVar6 = (FARPROC)((DAT_140018038 ^ (&DAT_140019640)[param_1]) >> bVar3 |
                    (DAT_140018038 ^ (&DAT_140019640)[param_1]) << 0x40 - bVar3);
  if (pFVar6 != (FARPROC)0xffffffffffffffff) {
    if (pFVar6 != (FARPROC)0x0) {
      return pFVar6;
    }
    if (param_3 != param_4) {
      do {
        uVar2 = *param_3;
        hLibModule = (HMODULE)(&DAT_1400195a0)[uVar2];
        if (hLibModule == (HMODULE)0x0) {
          lpLibFileName = (wchar_t *)(&PTR_u_api_ms_win_core_datetime_l1_1_1_140010470)[uVar2];
          hLibModule = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0x800);
          if ((hLibModule != (HMODULE)0x0) ||
             ((((DVar4 = GetLastError(), DVar4 == 0x57 &&
                (iVar5 = wcsncmp(lpLibFileName,L"api-ms-",7), iVar5 != 0)) &&
               (iVar5 = wcsncmp(lpLibFileName,L"ext-ms-",7), iVar5 != 0)) &&
              (hLibModule = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0), hLibModule != (HMODULE)0x0)
              ))) {
            LOCK();
            lVar1 = (&DAT_1400195a0)[uVar2];
            (&DAT_1400195a0)[uVar2] = hLibModule;
            UNLOCK();
            if (lVar1 != 0) {
              FreeLibrary(hLibModule);
            }
            goto LAB_14000940d;
          }
          LOCK();
          (&DAT_1400195a0)[uVar2] = 0xffffffffffffffff;
          UNLOCK();
        }
        else if (hLibModule != (HMODULE)0xffffffffffffffff) {
LAB_14000940d:
          pFVar6 = GetProcAddress(hLibModule,param_2);
          if (pFVar6 != (FARPROC)0x0) {
            bVar3 = 0x40 - ((byte)DAT_140018038 & 0x3f) & 0x3f;
            LOCK();
            (&DAT_140019640)[param_1] =
                 ((ulonglong)pFVar6 >> bVar3 | (longlong)pFVar6 << 0x40 - bVar3) ^ DAT_140018038;
            UNLOCK();
            return pFVar6;
          }
          break;
        }
        param_3 = param_3 + 1;
      } while (param_3 != param_4);
    }
    bVar3 = 0x40 - ((byte)DAT_140018038 & 0x3f) & 0x3f;
    LOCK();
    (&DAT_140019640)[param_1] = (0xffffffffffffffffU >> bVar3 | -1L << 0x40 - bVar3) ^ DAT_140018038
    ;
    UNLOCK();
  }
  return (FARPROC)0x0;
}



/*****************************************************************************
 * Function: FUN_140009448
 * Address: 140009448
 * Size: 88 bytes
 *****************************************************************************/


/* WARNING: Switch with 1 destination removed at 0x00014000948e */
/* WARNING: Switch with 1 destination removed at 0x00014000d920 */

INT_PTR FUN_140009448(undefined8 param_1)

{
  FARPROC UNRECOVERED_JUMPTABLE;
  INT_PTR IVar1;
  
  UNRECOVERED_JUMPTABLE =
       FUN_140009288(0x18,"AppPolicyGetProcessTerminationMethod",(uint *)&DAT_1400109b4,
                     (uint *)"AppPolicyGetProcessTerminationMethod");
  if (UNRECOVERED_JUMPTABLE == (FARPROC)0x0) {
    return 0xc0000225;
  }
                    /* WARNING: Could not recover jumptable at 0x00014000d900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar1 = (*UNRECOVERED_JUMPTABLE)(0xfffffffffffffffa,param_1);
  return IVar1;
}



/*****************************************************************************
 * Function: FlsAlloc
 * Address: 1400094a0
 * Size: 7 bytes
 *****************************************************************************/


DWORD __stdcall FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400094a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = FlsAlloc(lpCallback);
  return DVar1;
}



/*****************************************************************************
 * Function: FlsFree
 * Address: 1400094a8
 * Size: 7 bytes
 *****************************************************************************/


BOOL __stdcall FlsFree(DWORD dwFlsIndex)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400094a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = FlsFree(dwFlsIndex);
  return BVar1;
}



/*****************************************************************************
 * Function: FlsGetValue
 * Address: 1400094b0
 * Size: 7 bytes
 *****************************************************************************/


PVOID __stdcall FlsGetValue(DWORD dwFlsIndex)

{
  PVOID pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400094b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = FlsGetValue(dwFlsIndex);
  return pvVar1;
}



/*****************************************************************************
 * Function: FlsSetValue
 * Address: 1400094b8
 * Size: 7 bytes
 *****************************************************************************/


BOOL __stdcall FlsSetValue(DWORD dwFlsIndex,PVOID lpFlsData)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400094b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = FlsSetValue(dwFlsIndex,lpFlsData);
  return BVar1;
}



/*****************************************************************************
 * Function: FUN_1400094c0
 * Address: 1400094c0
 * Size: 112 bytes
 *****************************************************************************/


void FUN_1400094c0(LPCRITICAL_SECTION param_1,DWORD param_2,undefined4 param_3)

{
  FARPROC pFVar1;
  
  pFVar1 = FUN_140009288(0xe,"InitializeCriticalSectionEx",(uint *)&DAT_140010978,
                         (uint *)&DAT_140010980);
  if (pFVar1 == (FARPROC)0x0) {
    InitializeCriticalSectionAndSpinCount(param_1,param_2);
  }
  else {
    (*(code *)PTR__guard_dispatch_icall_14000e268)(param_1,param_2,param_3);
  }
  return;
}



/*****************************************************************************
 * Function: FUN_140009530
 * Address: 140009530
 * Size: 236 bytes
 *****************************************************************************/


void FUN_140009530(ushort *param_1,DWORD param_2,LPCWSTR param_3,int param_4,LPWSTR param_5,
                  int param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9)

{
  LCID Locale;
  FARPROC pFVar1;
  
  pFVar1 = FUN_140009288(0x10,"LCMapStringEx",(uint *)&DAT_140010980,(uint *)"LCMapStringEx");
  if (pFVar1 == (FARPROC)0x0) {
    Locale = FUN_14000961c(param_1,0);
    LCMapStringW(Locale,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    (*(code *)PTR__guard_dispatch_icall_14000e268)
              (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



/*****************************************************************************
 * Function: FUN_14000961c
 * Address: 14000961c
 * Size: 93 bytes
 *****************************************************************************/


void FUN_14000961c(ushort *param_1,undefined4 param_2)

{
  FARPROC pFVar1;
  
  pFVar1 = FUN_140009288(0x12,"LocaleNameToLCID",(uint *)&DAT_140010998,(uint *)"LocaleNameToLCID");
  if (pFVar1 == (FARPROC)0x0) {
    FUN_14000ab9c(param_1);
  }
  else {
    (*(code *)PTR__guard_dispatch_icall_14000e268)(param_1,param_2);
  }
  return;
}



/*****************************************************************************
 * Function: FUN_14000967c
 * Address: 14000967c
 * Size: 49 bytes
 *****************************************************************************/


undefined8 FUN_14000967c(void)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  
  uVar1 = DAT_140018038;
  puVar3 = &DAT_140019640;
  for (lVar2 = 0x1e; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
  }
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



/*****************************************************************************
 * Function: _recalloc_base
 * Address: 1400096f4
 * Size: 149 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _recalloc_base
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

LPVOID _recalloc_base(LPVOID param_1,ulonglong param_2,ulonglong param_3)

{
  __acrt_ptd *p_Var1;
  ulonglong uVar2;
  LPVOID pvVar3;
  ulonglong uVar4;
  
  if ((param_2 == 0) || (param_3 <= 0xffffffffffffffe0 / param_2)) {
    if (param_1 == (LPVOID)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = _msize_base((longlong)param_1);
    }
    uVar4 = param_2 * param_3;
    pvVar3 = _realloc_base(param_1,uVar4);
    if ((pvVar3 != (LPVOID)0x0) && (uVar2 < uVar4)) {
      FUN_140001e70((undefined1 (*) [32])((longlong)pvVar3 + uVar2),0,uVar4 - uVar2);
    }
  }
  else {
    p_Var1 = FUN_140006ee4();
    *(undefined4 *)p_Var1 = 0xc;
    pvVar3 = (LPVOID)0x0;
  }
  return pvVar3;
}



/*****************************************************************************
 * Function: FUN_14000978c
 * Address: 14000978c
 * Size: 28 bytes
 *****************************************************************************/


bool FUN_14000978c(void)

{
  DAT_140019738 = GetProcessHeap();
  return DAT_140019738 != (HANDLE)0x0;
}



/*****************************************************************************
 * Function: FUN_1400097b4
 * Address: 1400097b4
 * Size: 148 bytes
 *****************************************************************************/


undefined8 FUN_1400097b4(undefined8 *param_1,undefined8 *param_2)

{
  longlong *in_RAX;
  longlong *plVar1;
  
  plVar1 = param_1;
  if (param_1 != param_2) {
    do {
      in_RAX = (longlong *)*plVar1;
      if ((in_RAX != (longlong *)0x0) &&
         (in_RAX = (longlong *)(*(code *)PTR__guard_dispatch_icall_14000e268)(),
         (char)in_RAX == '\0')) break;
      plVar1 = plVar1 + 2;
    } while (plVar1 != param_2);
    if (plVar1 != param_2) {
      if (plVar1 != param_1) {
        plVar1 = plVar1 + -1;
        do {
          if ((plVar1[-1] != 0) && (*plVar1 != 0)) {
            (*(code *)PTR__guard_dispatch_icall_14000e268)(0);
          }
          in_RAX = plVar1 + -1;
          plVar1 = plVar1 + -2;
        } while (in_RAX != param_1);
      }
      return (ulonglong)in_RAX & 0xffffffffffffff00;
    }
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



/*****************************************************************************
 * Function: FUN_140009848
 * Address: 140009848
 * Size: 70 bytes
 *****************************************************************************/


undefined8 FUN_140009848(longlong param_1,longlong param_2)

{
  longlong in_RAX;
  
  if (param_1 != param_2) {
    do {
      in_RAX = *(longlong *)(param_2 + -8);
      if (in_RAX != 0) {
        in_RAX = (*(code *)PTR__guard_dispatch_icall_14000e268)(0);
      }
      param_2 = param_2 + -0x10;
    } while (param_2 != param_1);
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



/*****************************************************************************
 * Function: FUN_140009890
 * Address: 140009890
 * Size: 8 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140009890(undefined8 param_1)

{
  _DAT_140019740 = param_1;
  return;
}



/*****************************************************************************
 * Function: FUN_140009898
 * Address: 140009898
 * Size: 57 bytes
 *****************************************************************************/


undefined8 FUN_140009898(undefined8 param_1)

{
  int iVar1;
  ulonglong uVar2;
  
  uVar2 = _query_new_handler();
  if ((uVar2 != 0) && (iVar1 = (*(code *)PTR__guard_dispatch_icall_14000e268)(param_1), iVar1 != 0))
  {
    return 1;
  }
  return 0;
}



/*****************************************************************************
 * Function: _query_new_handler
 * Address: 1400098d4
 * Size: 52 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _query_new_handler
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

ulonglong _query_new_handler(void)

{
  byte bVar1;
  ulonglong uVar2;
  
  __acrt_lock(0);
  bVar1 = (byte)DAT_140018038 & 0x3f;
  uVar2 = DAT_140018038 ^ _DAT_140019740;
  __acrt_unlock(0);
  return uVar2 >> bVar1 | uVar2 << 0x40 - bVar1;
}



/*****************************************************************************
 * Function: operator()<>
 * Address: 140009908
 * Size: 69 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Multiple Matches With Same Base Name
    public: void (__cdecl*__cdecl __crt_seh_guarded_call<void (__cdecl*)(int)>::operator()<class
   <lambda_450d765d439847d4c735a33c368b5fc0>,class <lambda_44731a7d0e6d81c3e6aa82d741081786> &
   __ptr64,class <lambda_601a2a7da3b7a96e9554ac7215c4b07c> >(class
   <lambda_450d765d439847d4c735a33c368b5fc0> && __ptr64,class
   <lambda_44731a7d0e6d81c3e6aa82d741081786> & __ptr64,class
   <lambda_601a2a7da3b7a96e9554ac7215c4b07c> && __ptr64) __ptr64)(int)
    public: void (__cdecl*__cdecl __crt_seh_guarded_call<void (__cdecl*)(int)>::operator()<class
   <lambda_c36588078e9f5dfd39652860aa6b3aaf>,class <lambda_ec61778202f4f5fc7e7711acc23c3bca> &
   __ptr64,class <lambda_dc9d2797ccde5d239b4a0efae8ebd7db> >(class
   <lambda_c36588078e9f5dfd39652860aa6b3aaf> && __ptr64,class
   <lambda_ec61778202f4f5fc7e7711acc23c3bca> & __ptr64,class
   <lambda_dc9d2797ccde5d239b4a0efae8ebd7db> && __ptr64) __ptr64)(int)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

ulonglong operator()<>(undefined8 param_1,int *param_2,undefined8 param_3,int *param_4)

{
  byte bVar1;
  ulonglong uVar2;
  
  __acrt_lock(*param_2);
  bVar1 = (byte)DAT_140018038 & 0x3f;
  uVar2 = DAT_140018038 ^ _DAT_140019758;
  __acrt_unlock(*param_4);
  return uVar2 >> bVar1 | uVar2 << 0x40 - bVar1;
}



/*****************************************************************************
 * Function: FUN_140009980
 * Address: 140009980
 * Size: 29 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140009980(undefined8 param_1)

{
  _DAT_140019748 = param_1;
  _DAT_140019750 = param_1;
  _DAT_140019758 = param_1;
  _DAT_140019760 = param_1;
  return;
}



/*****************************************************************************
 * Function: FUN_1400099a0
 * Address: 1400099a0
 * Size: 638 bytes
 *****************************************************************************/


undefined8 FUN_1400099a0(uint param_1)

{
  code *pcVar1;
  bool bVar2;
  __acrt_ptd *p_Var3;
  longlong lVar4;
  undefined8 uVar5;
  byte bVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong *puVar9;
  __acrt_ptd *p_Var10;
  undefined4 local_res10;
  longlong local_res18;
  
  p_Var3 = (__acrt_ptd *)0x0;
  p_Var10 = (__acrt_ptd *)0x0;
  local_res10 = 0;
  bVar2 = true;
  if (param_1 == 2) {
LAB_1400099e9:
    if (param_1 == 2) {
      puVar9 = (ulonglong *)&DAT_140019748;
    }
    else if (param_1 == 6) {
LAB_140009a86:
      puVar9 = (ulonglong *)&DAT_140019758;
      p_Var10 = p_Var3;
    }
    else if (param_1 == 0xf) {
      puVar9 = (ulonglong *)&DAT_140019760;
    }
    else if (param_1 == 0x15) {
      puVar9 = (ulonglong *)&DAT_140019750;
      p_Var10 = p_Var3;
    }
    else {
      if (param_1 == 0x16) goto LAB_140009a86;
      puVar9 = (ulonglong *)0x0;
      p_Var10 = p_Var3;
    }
  }
  else {
    if (param_1 != 4) {
      if (param_1 != 6) {
        if ((param_1 == 8) || (param_1 == 0xb)) goto LAB_140009a19;
        if ((param_1 != 0xf) && (1 < param_1 - 0x15)) goto LAB_140009a66;
      }
      goto LAB_1400099e9;
    }
LAB_140009a19:
    p_Var10 = FUN_14000671c();
    if (p_Var10 == (__acrt_ptd *)0x0) {
      return 0xffffffff;
    }
    lVar4 = *(longlong *)p_Var10;
    lVar7 = DAT_14000f430 * 0x10 + lVar4;
    for (; lVar4 != lVar7; lVar4 = lVar4 + 0x10) {
      if (*(uint *)(lVar4 + 4) == param_1) goto LAB_140009a61;
    }
    lVar4 = 0;
LAB_140009a61:
    if (lVar4 == 0) {
LAB_140009a66:
      p_Var10 = FUN_140006ee4();
      *(undefined4 *)p_Var10 = 0x16;
      FUN_140006c8c();
      return 0xffffffff;
    }
    puVar9 = (ulonglong *)(lVar4 + 8);
    bVar2 = false;
  }
  local_res18 = 0;
  if (bVar2) {
    __acrt_lock(3);
  }
  uVar8 = *puVar9;
  if (bVar2) {
    bVar6 = (byte)DAT_140018038 & 0x3f;
    uVar8 = (uVar8 ^ DAT_140018038) >> bVar6 | (uVar8 ^ DAT_140018038) << 0x40 - bVar6;
  }
  if (uVar8 == 1) goto LAB_140009b7f;
  if (uVar8 == 0) {
    if (bVar2) {
      __acrt_unlock(3);
    }
    FUN_140005800(3);
    pcVar1 = (code *)swi(3);
    uVar5 = (*pcVar1)();
    return uVar5;
  }
  if ((param_1 < 0xc) && ((0x910U >> (param_1 & 0x1f) & 1) != 0)) {
    local_res18 = *(longlong *)(p_Var10 + 8);
    *(longlong *)(p_Var10 + 8) = 0;
    if (param_1 == 8) {
      p_Var3 = FUN_1400065a4();
      local_res10 = *(undefined4 *)(p_Var3 + 0x10);
      p_Var3 = FUN_1400065a4();
      *(undefined4 *)(p_Var3 + 0x10) = 0x8c;
      goto LAB_140009b36;
    }
  }
  else {
LAB_140009b36:
    if (param_1 == 8) {
      lVar4 = DAT_14000f438 * 0x10 + *(longlong *)p_Var10;
      lVar7 = DAT_14000f440 * 0x10 + lVar4;
      for (; lVar4 != lVar7; lVar4 = lVar4 + 0x10) {
        *(undefined8 *)(lVar4 + 8) = 0;
      }
      goto LAB_140009b7f;
    }
  }
  *puVar9 = DAT_140018038;
LAB_140009b7f:
  if (bVar2) {
    __acrt_unlock(3);
  }
  if (uVar8 != 1) {
    if (param_1 == 8) {
      p_Var3 = FUN_1400065a4();
      (*(code *)PTR__guard_dispatch_icall_14000e268)(8,*(undefined4 *)(p_Var3 + 0x10));
    }
    else {
      (*(code *)PTR__guard_dispatch_icall_14000e268)(param_1);
    }
    if (((param_1 < 0xc) && ((0x910U >> (param_1 & 0x1f) & 1) != 0)) &&
       (*(longlong *)(p_Var10 + 8) = local_res18, param_1 == 8)) {
      p_Var10 = FUN_1400065a4();
      *(undefined4 *)(p_Var10 + 0x10) = local_res10;
    }
  }
  return 0;
}



/*****************************************************************************
 * Function: FUN_140009c20
 * Address: 140009c20
 * Size: 154 bytes
 *****************************************************************************/


void FUN_140009c20(undefined8 param_1,longlong *param_2,undefined8 *param_3,longlong *param_4)

{
  uint uVar1;
  int iVar2;
  
  FUN_14000a0e0(*param_2);
  if ((*(longlong *)*param_3 != 0) &&
     (uVar1 = *(uint *)(*(longlong *)*param_3 + 0x14), (uVar1 >> 0xd & 1) != 0)) {
    if (((((byte)uVar1 & 3) == 2) && ((uVar1 & 0xc0) != 0)) || ((uVar1 >> 0xb & 1) != 0)) {
      if ((*(char *)param_3[2] != '\0') || ((*(uint *)(*(longlong *)*param_3 + 0x14) >> 1 & 1) != 0)
         ) {
        iVar2 = FUN_140009e88(*(int **)*param_3);
        if (iVar2 == -1) {
          *(undefined4 *)param_3[3] = 0xffffffff;
        }
        else {
          *(int *)param_3[1] = *(int *)param_3[1] + 1;
        }
      }
    }
    else {
      *(int *)param_3[1] = *(int *)param_3[1] + 1;
    }
  }
  FUN_14000a0ec(*param_4);
  return;
}



/*****************************************************************************
 * Function: FUN_140009cbc
 * Address: 140009cbc
 * Size: 224 bytes
 *****************************************************************************/


void FUN_140009cbc(undefined8 param_1,int *param_2,undefined8 *param_3,int *param_4)

{
  longlong *plVar1;
  uint uVar2;
  longlong *plVar3;
  undefined1 local_res10 [16];
  int *local_res20;
  longlong local_58;
  longlong local_50;
  longlong local_48;
  longlong *local_40;
  longlong *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_res20 = param_4;
  __acrt_lock(*param_2);
  plVar1 = DAT_140019770 + DAT_140019768;
  for (plVar3 = DAT_140019770; local_40 = plVar3, plVar3 != plVar1; plVar3 = plVar3 + 1) {
    local_58 = *plVar3;
    if ((local_58 != 0) && (uVar2 = *(uint *)(local_58 + 0x14), (uVar2 >> 0xd & 1) != 0)) {
      if (((((byte)uVar2 & 3) == 2) && ((uVar2 & 0xc0) != 0)) || ((uVar2 >> 0xb & 1) != 0)) {
        local_20 = param_3[2];
        local_28 = param_3[1];
        local_30 = *param_3;
        local_38 = &local_58;
        local_50 = local_58;
        local_48 = local_58;
        FUN_140009c20(local_res10,&local_48,&local_38,&local_50);
      }
      else {
        *(int *)*param_3 = *(int *)*param_3 + 1;
      }
    }
  }
  __acrt_unlock(*param_4);
  return;
}



/*****************************************************************************
 * Function: common_flush_all
 * Address: 140009d9c
 * Size: 93 bytes
 *****************************************************************************/


/* Library Function - Single Match
    int __cdecl common_flush_all(bool)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl common_flush_all(bool param_1)

{
  char local_res8 [8];
  undefined1 local_res10 [8];
  int local_res18 [2];
  int local_res20 [2];
  int local_28 [2];
  int *local_20;
  char *local_18;
  int *local_10;
  
  local_res20[0] = 0;
  local_20 = local_res20;
  local_res18[0] = 0;
  local_18 = local_res8;
  local_10 = local_res18;
  local_28[0] = 8;
  local_28[1] = 8;
  local_res8[0] = param_1;
  FUN_140009cbc(local_res10,local_28 + 1,&local_20,local_28);
  if (local_res8[0] != '\0') {
    local_res18[0] = local_res20[0];
  }
  return local_res18[0];
}



/*****************************************************************************
 * Function: FUN_140009dfc
 * Address: 140009dfc
 * Size: 138 bytes
 *****************************************************************************/


undefined8 FUN_140009dfc(int *param_1,longlong *param_2)

{
  wchar_t *pwVar1;
  uint uVar2;
  uint uVar3;
  
  if ((((byte)param_1[5] & 3) == 2) && ((param_1[5] & 0xc0U) != 0)) {
    uVar3 = *param_1 - param_1[2];
    param_1[4] = 0;
    pwVar1 = *(wchar_t **)(param_1 + 2);
    *(wchar_t **)param_1 = pwVar1;
    if (0 < (int)uVar3) {
      uVar2 = FUN_14000a348((longlong)param_1);
      uVar2 = FUN_14000b638(uVar2,pwVar1,uVar3,param_2);
      if (uVar3 != uVar2) {
        LOCK();
        param_1[5] = param_1[5] | 0x10;
        UNLOCK();
        return 0xffffffff;
      }
      if (((uint)param_1[5] >> 2 & 1) != 0) {
        LOCK();
        param_1[5] = param_1[5] & 0xfffffffd;
        UNLOCK();
      }
    }
  }
  return 0;
}



/*****************************************************************************
 * Function: FUN_140009e88
 * Address: 140009e88
 * Size: 209 bytes
 *****************************************************************************/


int FUN_140009e88(int *param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong local_48 [2];
  undefined1 local_38;
  undefined *local_30;
  undefined *puStack_28;
  char local_20;
  undefined4 local_1c;
  char local_18;
  undefined4 local_14;
  char local_10;
  
  local_48[0] = 0;
  local_20 = DAT_140018eb4 == 0;
  local_38 = 0;
  local_18 = '\0';
  local_10 = '\0';
  if ((bool)local_20) {
    local_30 = PTR_PTR_140018708;
    puStack_28 = PTR_DAT_140018710;
  }
  if (param_1 == (int *)0x0) {
    iVar1 = common_flush_all(false);
    goto LAB_140009f0c;
  }
  uVar2 = FUN_140009dfc(param_1,local_48);
  if ((int)uVar2 == 0) {
    if (((uint)param_1[5] >> 0xb & 1) != 0) {
      iVar1 = FUN_14000a348((longlong)param_1);
      iVar1 = _commit(iVar1);
      if (iVar1 != 0) goto LAB_140009ee8;
    }
    iVar1 = 0;
  }
  else {
LAB_140009ee8:
    iVar1 = -1;
  }
LAB_140009f0c:
  if (local_20 == '\x02') {
    *(uint *)(local_48[0] + 0x3a8) = *(uint *)(local_48[0] + 0x3a8) & 0xfffffffd;
  }
  if (local_18 != '\0') {
    lVar3 = FUN_140006080(local_48);
    *(undefined4 *)(lVar3 + 0x20) = local_1c;
  }
  if (local_10 != '\0') {
    lVar3 = FUN_140006080(local_48);
    *(undefined4 *)(lVar3 + 0x24) = local_14;
  }
  return iVar1;
}



/*****************************************************************************
 * Function: common_flush_all
 * Address: 140009f5c
 * Size: 7 bytes
 *****************************************************************************/


int __cdecl common_flush_all(bool param_1)

{
  int iVar1;
  
  iVar1 = common_flush_all(true);
  return iVar1;
}



/*****************************************************************************
 * Function: FUN_14000a0e0
 * Address: 14000a0e0
 * Size: 11 bytes
 *****************************************************************************/


void FUN_14000a0e0(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00014000a0e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EnterCriticalSection(param_1 + 0x30);
  return;
}



/*****************************************************************************
 * Function: FUN_14000a0ec
 * Address: 14000a0ec
 * Size: 11 bytes
 *****************************************************************************/


void FUN_14000a0ec(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00014000a0f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LeaveCriticalSection(param_1 + 0x30);
  return;
}



/*****************************************************************************
 * Function: FUN_14000a0f8
 * Address: 14000a0f8
 * Size: 49 bytes
 *****************************************************************************/


void FUN_14000a0f8(longlong param_1,longlong *param_2)

{
  undefined **ppuVar1;
  
  if ((*param_2 != DAT_140019598) && ((DAT_1400187c0 & *(uint *)(param_1 + 0x3a8)) == 0)) {
    ppuVar1 = FUN_1400091b0();
    *param_2 = (longlong)ppuVar1;
  }
  return;
}



/*****************************************************************************
 * Function: FUN_14000a12c
 * Address: 14000a12c
 * Size: 53 bytes
 *****************************************************************************/


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



/*****************************************************************************
 * Function: FUN_14000a164
 * Address: 14000a164
 * Size: 49 bytes
 *****************************************************************************/


void FUN_14000a164(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  
  if ((*param_2 != DAT_140018f08) && ((DAT_1400187c0 & *(uint *)(param_1 + 0x3a8)) == 0)) {
    lVar1 = FUN_140007e44();
    *param_2 = lVar1;
  }
  return;
}



/*****************************************************************************
 * Function: FUN_14000a198
 * Address: 14000a198
 * Size: 53 bytes
 *****************************************************************************/


void FUN_14000a198(longlong param_1,longlong *param_2,longlong param_3)

{
  longlong lVar1;
  
  if ((*param_2 != (&DAT_140018f08)[param_3]) && ((DAT_1400187c0 & *(uint *)(param_1 + 0x3a8)) == 0)
     ) {
    lVar1 = FUN_140007e44();
    *param_2 = lVar1;
  }
  return;
}



/*****************************************************************************
 * Function: FUN_14000a1d0
 * Address: 14000a1d0
 * Size: 376 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_14000a1d0(ushort *param_1,byte *param_2,ulonglong param_3,longlong *param_4)

{
  uint uVar1;
  longlong *plVar2;
  int iVar3;
  
  if ((param_2 == (byte *)0x0) || (param_3 == 0)) {
    _DAT_140019788 = 0;
  }
  else {
    if (*param_2 != 0) {
      if ((char)param_4[5] == '\0') {
        FUN_1400060f0(param_4);
      }
      plVar2 = (longlong *)param_4[3];
      uVar1 = *(uint *)((longlong)plVar2 + 0xc);
      if (uVar1 != 0xfde9) {
        if (plVar2[0x27] == 0) {
          if (param_1 != (ushort *)0x0) {
            *param_1 = (ushort)*param_2;
          }
          return 1;
        }
        if (*(short *)(*plVar2 + (ulonglong)*param_2 * 2) < 0) {
          if ((((1 < (int)plVar2[1]) && ((int)plVar2[1] <= (int)param_3)) &&
              (iVar3 = __acrt_MultiByteToWideChar(uVar1,9), iVar3 != 0)) ||
             (((ulonglong)(longlong)*(int *)(param_4[3] + 8) <= param_3 && (param_2[1] != 0)))) {
            return *(int *)(param_4[3] + 8);
          }
        }
        else {
          iVar3 = __acrt_MultiByteToWideChar(uVar1,9);
          if (iVar3 != 0) {
            return 1;
          }
        }
        *(undefined1 *)(param_4 + 6) = 1;
        *(undefined4 *)((longlong)param_4 + 0x2c) = 0x2a;
        return -1;
      }
      iVar3 = FUN_14000bbc4(param_1,param_2,param_3,(uint *)&DAT_140019788,(longlong)param_4);
      if (iVar3 < 0) {
        return -1;
      }
      return iVar3;
    }
    if (param_1 != (ushort *)0x0) {
      *param_1 = 0;
    }
  }
  return 0;
}



/*****************************************************************************
 * Function: FUN_14000a348
 * Address: 14000a348
 * Size: 38 bytes
 *****************************************************************************/


undefined4 FUN_14000a348(longlong param_1)

{
  undefined4 uVar1;
  __acrt_ptd *p_Var2;
  
  if (param_1 == 0) {
    p_Var2 = FUN_140006ee4();
    *(undefined4 *)p_Var2 = 0x16;
    FUN_140006c8c();
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x18);
  }
  return uVar1;
}



/*****************************************************************************
 * Function: FUN_14000a370
 * Address: 14000a370
 * Size: 1034 bytes
 *****************************************************************************/


void FUN_14000a370(undefined1 *param_1,ulonglong param_2,ulonglong param_3,undefined *param_4)

{
  undefined1 uVar1;
  int iVar2;
  __acrt_ptd *p_Var3;
  undefined1 *puVar4;
  longlong lVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  ulonglong uVar9;
  undefined1 *puVar10;
  undefined1 auStack_468 [32];
  longlong local_448;
  undefined8 auStack_438 [62];
  undefined8 auStack_248 [62];
  ulonglong local_58;
  
  local_58 = DAT_140018038 ^ (ulonglong)auStack_468;
  if ((((param_1 == (undefined1 *)0x0) && (param_2 != 0)) || (param_3 == 0)) ||
     (param_4 == (undefined *)0x0)) {
    p_Var3 = FUN_140006ee4();
    *(undefined4 *)p_Var3 = 0x16;
    FUN_140006c8c();
  }
  else if (1 < param_2) {
    local_448 = 0;
    puVar10 = param_1 + (param_2 - 1) * param_3;
LAB_14000a410:
    while (uVar9 = (ulonglong)((longlong)puVar10 - (longlong)param_1) / param_3 + 1, 8 < uVar9) {
      lVar5 = (uVar9 >> 1) * param_3;
      puVar7 = param_1 + lVar5;
      iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(param_1,puVar7);
      if ((0 < iVar2) && (puVar6 = puVar7, uVar9 = param_3, param_1 != puVar7)) {
        do {
          uVar1 = puVar6[-lVar5];
          puVar6[-lVar5] = *puVar6;
          *puVar6 = uVar1;
          uVar9 = uVar9 - 1;
          puVar6 = puVar6 + 1;
        } while (uVar9 != 0);
      }
      iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(param_1,puVar10);
      if ((0 < iVar2) && (param_1 != puVar10)) {
        puVar6 = puVar10;
        uVar9 = param_3;
        do {
          uVar1 = puVar6[(longlong)param_1 - (longlong)puVar10];
          puVar6[(longlong)param_1 - (longlong)puVar10] = *puVar6;
          *puVar6 = uVar1;
          puVar6 = puVar6 + 1;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
      iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(puVar7);
      puVar6 = param_1;
      puVar8 = puVar10;
      if ((0 < iVar2) && (puVar7 != puVar10)) {
        puVar4 = puVar10;
        uVar9 = param_3;
        do {
          uVar1 = puVar4[(longlong)puVar7 - (longlong)puVar10];
          puVar4[(longlong)puVar7 - (longlong)puVar10] = *puVar4;
          *puVar4 = uVar1;
          puVar4 = puVar4 + 1;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
LAB_14000a5c0:
      puVar4 = puVar7;
      if (puVar6 < puVar4) {
        do {
          puVar6 = puVar6 + param_3;
          if (puVar4 <= puVar6) goto LAB_14000a5f0;
          iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(puVar6);
        } while (iVar2 < 1);
      }
      else {
LAB_14000a5f0:
        do {
          puVar6 = puVar6 + param_3;
          if (puVar10 < puVar6) break;
          iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(puVar6);
        } while (iVar2 < 1);
      }
      do {
        puVar7 = puVar8;
        puVar8 = puVar7 + -param_3;
        if (puVar8 <= puVar4) break;
        iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(puVar8);
      } while (0 < iVar2);
      if (puVar6 <= puVar8) {
        if (puVar8 != puVar6) {
          puVar7 = puVar8;
          uVar9 = param_3;
          do {
            uVar1 = puVar7[(longlong)puVar6 - (longlong)puVar8];
            puVar7[(longlong)puVar6 - (longlong)puVar8] = *puVar7;
            *puVar7 = uVar1;
            puVar7 = puVar7 + 1;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        puVar7 = puVar6;
        if (puVar4 != puVar8) {
          puVar7 = puVar4;
        }
        goto LAB_14000a5c0;
      }
      if (puVar4 < puVar7) {
        do {
          puVar7 = puVar7 + -param_3;
          if (puVar7 <= puVar4) goto LAB_14000a6a7;
          iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(puVar7);
        } while (iVar2 == 0);
      }
      else {
LAB_14000a6a7:
        do {
          puVar7 = puVar7 + -param_3;
          if (puVar7 <= param_1) break;
          iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(puVar7);
        } while (iVar2 == 0);
      }
      if ((longlong)puVar7 - (longlong)param_1 < (longlong)puVar10 - (longlong)puVar6)
      goto LAB_14000a70d;
      if (param_1 < puVar7) {
        auStack_438[local_448] = param_1;
        auStack_248[local_448] = puVar7;
        local_448 = local_448 + 1;
      }
      param_1 = puVar6;
      if (puVar10 <= puVar6) goto LAB_14000a4a3;
    }
    for (; puVar6 = param_1, puVar7 = param_1, param_1 < puVar10; puVar10 = puVar10 + -param_3) {
      while (puVar7 = puVar7 + param_3, puVar7 <= puVar10) {
        iVar2 = (*(code *)PTR__guard_dispatch_icall_14000e268)(puVar7,puVar6);
        if (0 < iVar2) {
          puVar6 = puVar7;
        }
      }
      if (puVar6 != puVar10) {
        puVar7 = puVar10;
        uVar9 = param_3;
        do {
          uVar1 = puVar7[(longlong)puVar6 - (longlong)puVar10];
          puVar7[(longlong)puVar6 - (longlong)puVar10] = *puVar7;
          *puVar7 = uVar1;
          puVar7 = puVar7 + 1;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
    }
    goto LAB_14000a4a3;
  }
LAB_14000a760:
  FUN_14000d520(local_58 ^ (ulonglong)auStack_468);
  return;
LAB_14000a70d:
  if (puVar6 < puVar10) {
    auStack_438[local_448] = puVar6;
    auStack_248[local_448] = puVar10;
    local_448 = local_448 + 1;
  }
  puVar10 = puVar7;
  if (puVar7 <= param_1) {
LAB_14000a4a3:
    local_448 = local_448 + -1;
    if (-1 < local_448) {
      param_1 = (undefined1 *)auStack_438[local_448];
      puVar10 = (undefined1 *)auStack_248[local_448];
      goto LAB_14000a410;
    }
    goto LAB_14000a760;
  }
  goto LAB_14000a410;
}



/*****************************************************************************
 * Function: FUN_14000a780
 * Address: 14000a780
 * Size: 799 bytes
 *****************************************************************************/


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_14000a780(longlong *param_1,ushort *param_2,uint param_3,char *param_4,int param_5,
                  undefined8 param_6,int param_7,uint param_8,int param_9)

{
  longlong lVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  ulonglong uVar5;
  LPCWSTR pWVar6;
  undefined4 *puVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined4 local_60;
  ushort *local_38;
  ulonglong local_30;
  
  puVar9 = auStack_88;
  puVar11 = auStack_88;
  local_30 = DAT_140018038 ^ (ulonglong)&local_38;
  local_38 = param_2;
  if (0 < param_5) {
    __strncnt(param_4,(longlong)param_5);
  }
  if (param_8 == 0) {
    param_8 = *(uint *)(*param_1 + 0xc);
  }
  local_60 = 0;
  local_68 = 0;
  iVar3 = __acrt_MultiByteToWideChar(param_8,(ulonglong)((-(uint)(param_9 != 0) & 8) + 1));
  puVar12 = auStack_88;
  if (iVar3 == 0) goto LAB_14000aa79;
  uVar5 = (longlong)iVar3 * 2 + 0x10;
  uVar5 = -(ulonglong)((ulonglong)((longlong)iVar3 * 2) < uVar5) & uVar5;
  if (uVar5 == 0) {
    pWVar6 = (LPCWSTR)0x0;
LAB_14000aa5f:
    puVar12 = puVar11;
    if (pWVar6 == (LPCWSTR)0x0) goto LAB_14000aa79;
  }
  else {
    if (uVar5 < 0x401) {
      uVar8 = uVar5 + 0xf;
      if (uVar8 <= uVar5) {
        uVar8 = 0xffffffffffffff0;
      }
      lVar1 = -(uVar8 & 0xfffffffffffffff0);
      puVar9 = auStack_88 + lVar1;
      pWVar6 = (LPCWSTR)((longlong)&local_38 + lVar1);
      puVar11 = auStack_88 + lVar1;
      if (pWVar6 != (LPCWSTR)0x0) {
        pWVar6[0] = L'쳌';
        pWVar6[1] = L'\0';
LAB_14000a885:
        pWVar6 = pWVar6 + 8;
        puVar11 = puVar9;
      }
    }
    else {
      pWVar6 = (LPCWSTR)_malloc_base(uVar5);
      puVar11 = auStack_88;
      if (pWVar6 != (LPCWSTR)0x0) {
        pWVar6[0] = L'\xdddd';
        pWVar6[1] = L'\0';
        goto LAB_14000a885;
      }
    }
    if (pWVar6 == (LPCWSTR)0x0) goto LAB_14000aa5f;
    *(int *)(puVar11 + 0x28) = iVar3;
    *(LPCWSTR *)(puVar11 + 0x20) = pWVar6;
    *(undefined8 *)(puVar11 + -8) = 0x14000a8b2;
    iVar4 = __acrt_MultiByteToWideChar(param_8,1);
    if (iVar4 == 0) goto LAB_14000aa5f;
    *(undefined8 *)(puVar11 + 0x40) = 0;
    *(undefined8 *)(puVar11 + 0x38) = 0;
    *(undefined8 *)(puVar11 + 0x30) = 0;
    puVar2 = local_38;
    *(undefined4 *)(puVar11 + 0x28) = 0;
    *(undefined8 *)(puVar11 + 0x20) = 0;
    *(undefined8 *)(puVar11 + -8) = 0x14000a8ec;
    iVar4 = FUN_140009530(puVar2,param_3,pWVar6,iVar3,*(LPWSTR *)(puVar11 + 0x20),
                          *(int *)(puVar11 + 0x28),*(undefined8 *)(puVar11 + 0x30),
                          *(undefined8 *)(puVar11 + 0x38),*(undefined8 *)(puVar11 + 0x40));
    if (iVar4 == 0) goto LAB_14000aa5f;
    if ((param_3 & 0x400) == 0) {
      uVar5 = (longlong)iVar4 * 2 + 0x10;
      uVar5 = -(ulonglong)((ulonglong)((longlong)iVar4 * 2) < uVar5) & uVar5;
      if (uVar5 != 0) {
        if (uVar5 < 0x401) {
          uVar8 = uVar5 + 0xf;
          if (uVar8 <= uVar5) {
            uVar8 = 0xffffffffffffff0;
          }
          *(undefined8 *)(puVar11 + -8) = 0x14000a98d;
          lVar1 = -(uVar8 & 0xfffffffffffffff0);
          puVar10 = puVar11 + lVar1;
          puVar7 = (undefined4 *)(puVar11 + lVar1 + 0x50);
          puVar11 = puVar11 + lVar1;
          if (puVar7 == (undefined4 *)0x0) goto LAB_14000aa66;
          *puVar7 = 0xcccc;
          puVar11 = puVar10;
LAB_14000a9b9:
          puVar7 = puVar7 + 4;
        }
        else {
          *(undefined8 *)(puVar11 + -8) = 0x14000a9ab;
          puVar7 = (undefined4 *)_malloc_base(uVar5);
          if (puVar7 != (undefined4 *)0x0) {
            *puVar7 = 0xdddd;
            goto LAB_14000a9b9;
          }
        }
        if (puVar7 != (undefined4 *)0x0) {
          *(undefined8 *)(puVar11 + 0x40) = 0;
          *(undefined8 *)(puVar11 + 0x38) = 0;
          *(undefined8 *)(puVar11 + 0x30) = 0;
          *(int *)(puVar11 + 0x28) = iVar4;
          *(undefined4 **)(puVar11 + 0x20) = puVar7;
          *(undefined8 *)(puVar11 + -8) = 0x14000a9ee;
          iVar3 = FUN_140009530(puVar2,param_3,pWVar6,iVar3,*(LPWSTR *)(puVar11 + 0x20),
                                *(int *)(puVar11 + 0x28),*(undefined8 *)(puVar11 + 0x30),
                                *(undefined8 *)(puVar11 + 0x38),*(undefined8 *)(puVar11 + 0x40));
          if (iVar3 != 0) {
            *(undefined8 *)(puVar11 + 0x38) = 0;
            *(undefined8 *)(puVar11 + 0x30) = 0;
            if (param_7 == 0) {
              *(undefined4 *)(puVar11 + 0x28) = 0;
              *(undefined8 *)(puVar11 + 0x20) = 0;
            }
            else {
              *(int *)(puVar11 + 0x28) = param_7;
              *(undefined8 *)(puVar11 + 0x20) = param_6;
            }
            *(undefined8 *)(puVar11 + -8) = 0x14000aa1d;
            iVar3 = __acrt_WideCharToMultiByte(param_8,0,puVar7,iVar4);
            if (iVar3 != 0) {
              if (puVar7[-4] == 0xdddd) {
                *(undefined8 *)(puVar11 + -8) = 0x14000aa5b;
                FUN_140006f7c(puVar7 + -4);
              }
              goto LAB_14000aa66;
            }
          }
          if (puVar7[-4] == 0xdddd) {
            *(undefined8 *)(puVar11 + -8) = 0x14000aa34;
            FUN_140006f7c(puVar7 + -4);
          }
        }
      }
    }
    else if (param_7 != 0) {
      if (iVar4 <= param_7) {
        *(undefined8 *)(puVar11 + 0x40) = 0;
        *(undefined8 *)(puVar11 + 0x38) = 0;
        *(undefined8 *)(puVar11 + 0x30) = 0;
        *(int *)(puVar11 + 0x28) = param_7;
        *(undefined8 *)(puVar11 + 0x20) = param_6;
        *(undefined8 *)(puVar11 + -8) = 0x14000a944;
        iVar3 = FUN_140009530(puVar2,param_3,pWVar6,iVar3,*(LPWSTR *)(puVar11 + 0x20),
                              *(int *)(puVar11 + 0x28),*(undefined8 *)(puVar11 + 0x30),
                              *(undefined8 *)(puVar11 + 0x38),*(undefined8 *)(puVar11 + 0x40));
        if (iVar3 != 0) goto LAB_14000aa66;
      }
      goto LAB_14000aa5f;
    }
  }
LAB_14000aa66:
  puVar12 = puVar11;
  if (*(int *)(pWVar6 + -8) == 0xdddd) {
    *(undefined8 *)(puVar11 + -8) = 0x14000aa77;
    FUN_140006f7c(pWVar6 + -8);
  }
LAB_14000aa79:
  uVar5 = local_30 ^ (ulonglong)&local_38;
  *(undefined8 *)(puVar12 + -8) = 0x14000aa85;
  FUN_14000d520(uVar5);
  return;
}



/*****************************************************************************
 * Function: FUN_14000ab38
 * Address: 14000ab38
 * Size: 23 bytes
 *****************************************************************************/


bool FUN_14000ab38(void)

{
  undefined8 uVar1;
  
  uVar1 = __acrt_initialize_multibyte();
  return (char)uVar1 == '\0';
}



/*****************************************************************************
 * Function: FUN_14000ab9c
 * Address: 14000ab9c
 * Size: 168 bytes
 *****************************************************************************/


undefined4 FUN_14000ab9c(ushort *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 != (ushort *)0x0) {
    iVar4 = 0;
    iVar5 = 0xe3;
    do {
      iVar2 = (iVar5 + iVar4) / 2;
      iVar3 = __ascii_wcsnicmp(param_1,(ushort *)(&PTR_DAT_140012440)[(longlong)iVar2 * 2],0x55);
      if (iVar3 == 0) {
        uVar1 = *(uint *)(&DAT_140012448 + (longlong)iVar2 * 0x10);
        if ((int)uVar1 < 0) {
          return 0;
        }
        if (0xe3 < uVar1) {
          return 0;
        }
        return *(undefined4 *)(&DAT_1400109e0 + (longlong)(int)uVar1 * 0x10);
      }
      if (iVar3 < 0) {
        iVar5 = iVar2 + -1;
      }
      else {
        iVar4 = iVar2 + 1;
      }
    } while (iVar4 <= iVar5);
  }
  return 0;
}



/*****************************************************************************
 * Function: _msize_base
 * Address: 14000ac44
 * Size: 57 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _msize_base
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined8 _msize_base(longlong param_1)

{
  __acrt_ptd *p_Var1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    p_Var1 = FUN_140006ee4();
    *(undefined4 *)p_Var1 = 0x16;
    FUN_140006c8c();
    return 0xffffffffffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x00014000ac76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = HeapSize(DAT_140019738,0,param_1);
  return uVar2;
}



/*****************************************************************************
 * Function: _realloc_base
 * Address: 14000ac80
 * Size: 122 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _realloc_base
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

LPVOID _realloc_base(LPVOID param_1,ulonglong param_2)

{
  int iVar1;
  LPVOID pvVar2;
  __acrt_ptd *p_Var3;
  undefined8 uVar4;
  
  if (param_1 == (LPVOID)0x0) {
    pvVar2 = _malloc_base(param_2);
  }
  else {
    if (param_2 == 0) {
      FUN_140006f7c(param_1);
    }
    else {
      if (param_2 < 0xffffffffffffffe1) {
        do {
          pvVar2 = HeapReAlloc(DAT_140019738,0,param_1,param_2);
          if (pvVar2 != (LPVOID)0x0) {
            return pvVar2;
          }
          iVar1 = FUN_1400059b0();
        } while ((iVar1 != 0) && (uVar4 = FUN_140009898(param_2), (int)uVar4 != 0));
      }
      p_Var3 = FUN_140006ee4();
      *(undefined4 *)p_Var3 = 0xc;
    }
    pvVar2 = (LPVOID)0x0;
  }
  return pvVar2;
}



/*****************************************************************************
 * Function: FUN_14000acfc
 * Address: 14000acfc
 * Size: 139 bytes
 *****************************************************************************/


undefined8 FUN_14000acfc(undefined8 param_1,uint *param_2,undefined8 *param_3,uint *param_4)

{
  uint uVar1;
  BOOL BVar2;
  DWORD DVar3;
  HANDLE hFile;
  __acrt_ptd *p_Var4;
  undefined8 uVar5;
  
  FUN_140008584(*param_2);
  uVar1 = *(uint *)*param_3;
  if ((*(byte *)((&DAT_140019190)[(longlong)(int)uVar1 >> 6] + 0x38 +
                (ulonglong)(uVar1 & 0x3f) * 0x48) & 1) != 0) {
    hFile = (HANDLE)FUN_140008690(uVar1);
    BVar2 = FlushFileBuffers(hFile);
    uVar5 = 0;
    if (BVar2 != 0) goto LAB_14000ad73;
    DVar3 = GetLastError();
    p_Var4 = FUN_140006ec4();
    *(DWORD *)p_Var4 = DVar3;
  }
  p_Var4 = FUN_140006ee4();
  *(undefined4 *)p_Var4 = 9;
  uVar5 = 0xffffffff;
LAB_14000ad73:
  FUN_1400085ac(*param_4);
  return uVar5;
}



/*****************************************************************************
 * Function: _commit
 * Address: 14000ad88
 * Size: 145 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _commit
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl _commit(int _FileHandle)

{
  __acrt_ptd *p_Var1;
  undefined8 uVar2;
  int local_res8 [2];
  undefined1 local_res10 [8];
  uint local_res18 [2];
  uint local_res20 [2];
  int *local_18 [3];
  
  local_res8[0] = _FileHandle;
  if (_FileHandle == -2) {
    p_Var1 = FUN_140006ee4();
    *(undefined4 *)p_Var1 = 9;
  }
  else {
    if (((-1 < _FileHandle) && ((uint)_FileHandle < DAT_140019590)) &&
       ((*(byte *)((&DAT_140019190)[(longlong)_FileHandle >> 6] + 0x38 +
                  (ulonglong)(_FileHandle & 0x3f) * 0x48) & 1) != 0)) {
      local_18[0] = local_res8;
      local_res18[0] = _FileHandle;
      local_res20[0] = _FileHandle;
      uVar2 = FUN_14000acfc(local_res10,local_res20,local_18,local_res18);
      return (int)uVar2;
    }
    p_Var1 = FUN_140006ee4();
    *(undefined4 *)p_Var1 = 9;
    FUN_140006c8c();
  }
  return -1;
}



/*****************************************************************************
 * Function: FUN_14000ae1c
 * Address: 14000ae1c
 * Size: 1162 bytes
 *****************************************************************************/


void FUN_14000ae1c(DWORD *param_1,uint param_2,byte *param_3,ulonglong param_4,longlong *param_5)

{
  char cVar1;
  byte bVar2;
  HANDLE hFile;
  int iVar3;
  BOOL BVar4;
  DWORD DVar5;
  longlong lVar6;
  char *pcVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  char *pcVar15;
  ulonglong uVar16;
  undefined1 auStackY_118 [32];
  undefined2 local_d8 [2];
  ushort local_d4 [2];
  uint local_d0 [2];
  byte *local_c8;
  uint local_c0 [2];
  UINT local_b8;
  int local_b4;
  longlong local_b0;
  longlong *local_a8;
  byte *local_a0;
  uint local_98 [2];
  char *local_90;
  byte *local_88;
  HANDLE local_80;
  longlong local_78;
  longlong local_70;
  ulonglong local_68;
  undefined8 local_60;
  char local_58 [8];
  byte local_50;
  byte local_4f;
  undefined1 local_48 [8];
  ulonglong local_40;
  
  local_60 = 0xfffffffffffffffe;
  local_40 = DAT_140018038 ^ (ulonglong)auStackY_118;
  local_70 = (longlong)(int)param_2;
  local_a8 = param_5;
  lVar6 = local_70 >> 6;
  uVar8 = (ulonglong)(param_2 & 0x3f);
  local_80 = *(HANDLE *)((&DAT_140019190)[lVar6] + 0x28 + uVar8 * 0x48);
  local_c8 = param_3 + (param_4 & 0xffffffff);
  local_b0 = lVar6;
  local_a0 = param_3;
  local_68 = uVar8;
  local_b8 = GetConsoleOutputCP();
  uVar13 = 0;
  if ((char)param_5[5] == '\0') {
    FUN_1400060f0(param_5);
  }
  local_b4 = *(int *)(param_5[3] + 0xc);
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  uVar9 = uVar13;
  if (local_a0 < param_3 + (param_4 & 0xffffffff)) {
    do {
      local_78 = lVar6;
      local_d8[0] = CONCAT11(local_d8[0]._1_1_,*param_3);
      local_d4[0] = 0;
      local_d4[1] = 0;
      uVar10 = 1;
      if (local_b4 == 0xfde9) {
        pcVar15 = (char *)(uVar8 * 0x48 + 0x3e + (&DAT_140019190)[local_78]);
        pcVar7 = pcVar15;
        uVar9 = uVar13;
        uVar16 = uVar13;
        do {
          uVar10 = (uint)uVar9;
          if (*pcVar7 == '\0') break;
          uVar10 = uVar10 + 1;
          uVar9 = (ulonglong)uVar10;
          uVar16 = uVar16 + 1;
          pcVar7 = pcVar7 + 1;
        } while ((longlong)uVar16 < 5);
        if (uVar16 == 0) {
          cVar1 = (&DAT_1400188e0)[*param_3];
          iVar3 = cVar1 + 1;
          lVar6 = (longlong)local_c8 - (longlong)param_3;
          if (lVar6 < iVar3) {
            if (0 < lVar6) {
              uVar8 = uVar13;
              do {
                *(byte *)((&DAT_140019190)[local_70 >> 6] + local_68 * 0x48 + 0x3e + uVar13) =
                     param_3[uVar13];
                uVar10 = (int)uVar8 + 1;
                uVar8 = (ulonglong)uVar10;
                uVar13 = uVar13 + 1;
              } while ((int)uVar10 < lVar6);
            }
            param_1[1] = param_1[1] + (int)lVar6;
            break;
          }
          local_c0[0] = 0;
          local_c0[1] = 0;
          uVar10 = (iVar3 == 4) + 1;
          local_88 = param_3;
          lVar6 = FUN_14000bc08(local_d4,&local_88,(ulonglong)uVar10,local_c0,(longlong)local_a8);
          if (lVar6 == -1) break;
          pbVar12 = param_3 + cVar1;
          param_5 = local_a8;
        }
        else {
          cVar1 = (&DAT_1400188e0)[*(byte *)((&DAT_140019190)[local_b0] + 0x3e + uVar8 * 0x48)];
          iVar3 = (cVar1 + 1) - uVar10;
          local_c0[0] = iVar3;
          lVar6 = (longlong)local_c8 - (longlong)param_3;
          uVar14 = (ulonglong)iVar3;
          uVar9 = uVar13;
          if (lVar6 < (longlong)uVar14) {
            if (0 < lVar6) {
              uVar9 = uVar16;
              do {
                *(byte *)((&DAT_140019190)[local_b0] + uVar9 + 0x3e + uVar8 * 0x48) =
                     param_3[uVar9 - uVar16];
                uVar10 = (int)uVar13 + 1;
                uVar13 = (ulonglong)uVar10;
                uVar9 = uVar9 + 1;
              } while ((int)uVar10 < lVar6);
            }
            param_1[1] = param_1[1] + (int)lVar6;
            break;
          }
          do {
            local_58[uVar9] = *pcVar15;
            uVar9 = uVar9 + 1;
            pcVar15 = pcVar15 + 1;
          } while ((longlong)uVar9 < (longlong)uVar16);
          uVar9 = uVar13;
          if (0 < (longlong)uVar14) {
            FUN_140002d40((undefined8 *)(local_58 + uVar16),(undefined8 *)param_3,uVar14);
          }
          do {
            *(undefined1 *)((&DAT_140019190)[local_b0] + uVar9 + 0x3e + uVar8 * 0x48) = 0;
            uVar9 = uVar9 + 1;
          } while ((longlong)uVar9 < (longlong)uVar16);
          local_98[0] = 0;
          local_98[1] = 0;
          local_90 = local_58;
          uVar10 = (cVar1 + 1 == 4) + 1;
          lVar6 = FUN_14000bc08(local_d4,&local_90,(ulonglong)uVar10,local_98,(longlong)param_5);
          if (lVar6 == -1) break;
          pbVar12 = param_3 + (int)(local_c0[0] - 1);
        }
      }
      else {
        lVar6 = (&DAT_140019190)[local_b0];
        bVar2 = *(byte *)(lVar6 + 0x3d + uVar8 * 0x48);
        if ((bVar2 & 4) == 0) {
          if (*(short *)(*(longlong *)param_5[3] + (ulonglong)*param_3 * 2) < 0) {
            pbVar12 = param_3 + 1;
            if (pbVar12 < local_c8) {
              iVar3 = FUN_14000a1d0(local_d4,param_3,2,param_5);
              if (iVar3 != -1) goto LAB_14000b119;
            }
            else {
              *(byte *)(lVar6 + 0x3e + uVar8 * 0x48) = *param_3;
              pbVar12 = (byte *)((&DAT_140019190)[local_b0] + 0x3d + uVar8 * 0x48);
              *pbVar12 = *pbVar12 | 4;
              param_1[1] = (int)uVar9 + 1;
            }
            break;
          }
          uVar9 = 1;
          pbVar12 = param_3;
        }
        else {
          local_50 = *(byte *)(lVar6 + 0x3e + uVar8 * 0x48);
          local_4f = *param_3;
          *(byte *)(lVar6 + 0x3d + uVar8 * 0x48) = bVar2 & 0xfb;
          uVar9 = 2;
          pbVar12 = &local_50;
        }
        iVar3 = FUN_14000a1d0(local_d4,pbVar12,uVar9,param_5);
        pbVar12 = param_3;
        if (iVar3 == -1) break;
      }
LAB_14000b119:
      param_3 = pbVar12 + 1;
      uVar10 = __acrt_WideCharToMultiByte(local_b8,0,local_d4,uVar10);
      hFile = local_80;
      if (uVar10 == 0) break;
      BVar4 = WriteFile(local_80,local_48,uVar10,local_d0,(LPOVERLAPPED)0x0);
      if (BVar4 == 0) {
LAB_14000b274:
        DVar5 = GetLastError();
        *param_1 = DVar5;
        break;
      }
      uVar11 = ((int)param_3 - (int)local_a0) + param_1[2];
      param_1[1] = uVar11;
      if (local_d0[0] < uVar10) break;
      if ((char)local_d8[0] == '\n') {
        local_d8[0] = 0xd;
        BVar4 = WriteFile(hFile,local_d8,1,local_d0,(LPOVERLAPPED)0x0);
        if (BVar4 == 0) goto LAB_14000b274;
        if (local_d0[0] == 0) break;
        param_1[2] = param_1[2] + 1;
        param_1[1] = param_1[1] + 1;
        uVar11 = param_1[1];
      }
      uVar9 = (ulonglong)uVar11;
      lVar6 = local_78;
    } while (param_3 < local_c8);
  }
  FUN_14000d520(local_40 ^ (ulonglong)auStackY_118);
  return;
}



/*****************************************************************************
 * Function: write_text_ansi_nolock
 * Address: 14000b2a8
 * Size: 258 bytes
 *****************************************************************************/


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* Library Function - Single Match
    struct `anonymous namespace'::write_result __cdecl write_text_ansi_nolock(int,char const *
   __ptr64 const,unsigned int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl write_text_ansi_nolock(int param_1,char *param_2,uint param_3)

{
  char cVar1;
  HANDLE hFile;
  BOOL BVar2;
  DWORD DVar3;
  undefined4 in_register_0000000c;
  DWORD *pDVar4;
  uint nNumberOfBytesToWrite;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 in_register_00000084;
  ulonglong in_R9;
  undefined1 auStackY_1468 [32];
  uint local_1438 [4];
  char local_1428 [5120];
  ulonglong local_28;
  undefined8 uStack_20;
  
  pcVar7 = (char *)CONCAT44(in_register_00000084,param_3);
  pDVar4 = (DWORD *)CONCAT44(in_register_0000000c,param_1);
  uStack_20 = 0x14000b2c0;
  local_28 = DAT_140018038 ^ (ulonglong)auStackY_1468;
  pcVar6 = pcVar7 + (in_R9 & 0xffffffff);
  hFile = *(HANDLE *)
           ((&DAT_140019190)[(longlong)(int)(uint)param_2 >> 6] + 0x28 +
           (ulonglong)((uint)param_2 & 0x3f) * 0x48);
  pDVar4[0] = 0;
  pDVar4[1] = 0;
  pDVar4[2] = 0;
  do {
    if (pcVar6 <= pcVar7) break;
    pcVar5 = local_1428;
    do {
      if (pcVar6 <= pcVar7) break;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      if (cVar1 == '\n') {
        pDVar4[2] = pDVar4[2] + 1;
        *pcVar5 = '\r';
        pcVar5 = pcVar5 + 1;
      }
      *pcVar5 = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (pcVar5 < local_1428 + 0x13ff);
    nNumberOfBytesToWrite = (int)pcVar5 - (int)local_1428;
    BVar2 = WriteFile(hFile,local_1428,nNumberOfBytesToWrite,local_1438,(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      *pDVar4 = DVar3;
      break;
    }
    pDVar4[1] = pDVar4[1] + local_1438[0];
  } while (nNumberOfBytesToWrite <= local_1438[0]);
  FUN_14000d520(local_28 ^ (ulonglong)auStackY_1468);
  return;
}



/*****************************************************************************
 * Function: write_text_utf16le_nolock
 * Address: 14000b3ac
 * Size: 281 bytes
 *****************************************************************************/


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* Library Function - Single Match
    struct `anonymous namespace'::write_result __cdecl write_text_utf16le_nolock(int,char const *
   __ptr64 const,unsigned int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl write_text_utf16le_nolock(int param_1,char *param_2,uint param_3)

{
  short sVar1;
  HANDLE hFile;
  uint nNumberOfBytesToWrite;
  BOOL BVar2;
  DWORD DVar3;
  undefined4 in_register_0000000c;
  DWORD *pDVar4;
  short *psVar5;
  short *psVar6;
  short *psVar7;
  undefined4 in_register_00000084;
  ulonglong in_R9;
  undefined1 auStackY_1468 [32];
  uint local_1438 [4];
  short local_1428 [2560];
  ulonglong local_28;
  undefined8 uStack_20;
  
  psVar7 = (short *)CONCAT44(in_register_00000084,param_3);
  pDVar4 = (DWORD *)CONCAT44(in_register_0000000c,param_1);
  uStack_20 = 0x14000b3c4;
  local_28 = DAT_140018038 ^ (ulonglong)auStackY_1468;
  psVar6 = (short *)((in_R9 & 0xffffffff) + (longlong)psVar7);
  hFile = *(HANDLE *)
           ((&DAT_140019190)[(longlong)(int)(uint)param_2 >> 6] + 0x28 +
           (ulonglong)((uint)param_2 & 0x3f) * 0x48);
  pDVar4[0] = 0;
  pDVar4[1] = 0;
  pDVar4[2] = 0;
  do {
    if (psVar6 <= psVar7) break;
    psVar5 = local_1428;
    do {
      if (psVar6 <= psVar7) break;
      sVar1 = *psVar7;
      psVar7 = psVar7 + 1;
      if (sVar1 == 10) {
        pDVar4[2] = pDVar4[2] + 2;
        *psVar5 = 0xd;
        psVar5 = psVar5 + 1;
      }
      *psVar5 = sVar1;
      psVar5 = psVar5 + 1;
    } while (psVar5 < local_1428 + 0x9ff);
    nNumberOfBytesToWrite = (int)((longlong)psVar5 - (longlong)local_1428 >> 1) * 2;
    BVar2 = WriteFile(hFile,local_1428,nNumberOfBytesToWrite,local_1438,(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      *pDVar4 = DVar3;
      break;
    }
    pDVar4[1] = pDVar4[1] + local_1438[0];
  } while (nNumberOfBytesToWrite <= local_1438[0]);
  FUN_14000d520(local_28 ^ (ulonglong)auStackY_1468);
  return;
}



/*****************************************************************************
 * Function: write_text_utf8_nolock
 * Address: 14000b4c8
 * Size: 368 bytes
 *****************************************************************************/


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* Library Function - Single Match
    struct `anonymous namespace'::write_result __cdecl write_text_utf8_nolock(int,char const *
   __ptr64 const,unsigned int)
   
   Library: Visual Studio 2019 Release */

void __cdecl write_text_utf8_nolock(int param_1,char *param_2,uint param_3)

{
  short sVar1;
  HANDLE hFile;
  uint uVar2;
  BOOL BVar3;
  DWORD DVar4;
  short *psVar5;
  undefined4 in_register_0000000c;
  DWORD *pDVar6;
  uint uVar7;
  ulonglong uVar8;
  short *psVar9;
  undefined4 in_register_00000084;
  uint in_R9D;
  short *psVar10;
  undefined1 auStackY_1498 [32];
  DWORD local_1458 [4];
  short local_1448 [856];
  undefined1 local_d98 [3424];
  ulonglong local_38;
  undefined8 uStack_30;
  
  psVar9 = (short *)CONCAT44(in_register_00000084,param_3);
  pDVar6 = (DWORD *)CONCAT44(in_register_0000000c,param_1);
  uStack_30 = 0x14000b4e4;
  local_38 = DAT_140018038 ^ (ulonglong)auStackY_1498;
  psVar10 = (short *)((ulonglong)in_R9D + (longlong)psVar9);
  hFile = *(HANDLE *)
           ((&DAT_140019190)[(longlong)(int)(uint)param_2 >> 6] + 0x28 +
           (ulonglong)((uint)param_2 & 0x3f) * 0x48);
  pDVar6[0] = 0;
  pDVar6[1] = 0;
  pDVar6[2] = 0;
  do {
    if (psVar10 <= psVar9) {
LAB_14000b609:
      FUN_14000d520(local_38 ^ (ulonglong)auStackY_1498);
      return;
    }
    psVar5 = local_1448;
    do {
      if (psVar10 <= psVar9) break;
      sVar1 = *psVar9;
      psVar9 = psVar9 + 1;
      if (sVar1 == 10) {
        *psVar5 = 0xd;
        psVar5 = psVar5 + 1;
      }
      *psVar5 = sVar1;
      psVar5 = psVar5 + 1;
    } while (psVar5 < local_1448 + 0x354);
    uVar2 = __acrt_WideCharToMultiByte
                      (0xfde9,0,local_1448,(int)((longlong)psVar5 - (longlong)local_1448 >> 1));
    if (uVar2 == 0) {
LAB_14000b601:
      DVar4 = GetLastError();
      *pDVar6 = DVar4;
      goto LAB_14000b609;
    }
    uVar8 = 0;
    if (uVar2 != 0) {
      do {
        BVar3 = WriteFile(hFile,local_d98 + uVar8,uVar2 - (int)uVar8,local_1458,(LPOVERLAPPED)0x0);
        if (BVar3 == 0) goto LAB_14000b601;
        uVar7 = (int)uVar8 + local_1458[0];
        uVar8 = (ulonglong)uVar7;
      } while (uVar7 < uVar2);
    }
    pDVar6[1] = (int)psVar9 - param_3;
  } while( true );
}



/*****************************************************************************
 * Function: FUN_14000b638
 * Address: 14000b638
 * Size: 293 bytes
 *****************************************************************************/


int FUN_14000b638(uint param_1,wchar_t *param_2,uint param_3,longlong *param_4)

{
  int iVar1;
  
  if (param_1 == 0xfffffffe) {
    *(undefined1 *)(param_4 + 7) = 1;
    *(undefined4 *)((longlong)param_4 + 0x34) = 0;
    *(undefined1 *)(param_4 + 6) = 1;
    *(undefined4 *)((longlong)param_4 + 0x2c) = 9;
  }
  else {
    if ((-1 < (int)param_1) && (param_1 < DAT_140019590)) {
      if ((*(byte *)((&DAT_140019190)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x38 +
                    (ulonglong)(param_1 & 0x3f) * 0x48) & 1) != 0) {
        FUN_140008584(param_1);
        iVar1 = -1;
        if ((*(byte *)((&DAT_140019190)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x38 +
                      (ulonglong)(param_1 & 0x3f) * 0x48) & 1) == 0) {
          *(undefined1 *)(param_4 + 6) = 1;
          *(undefined4 *)((longlong)param_4 + 0x2c) = 9;
          *(undefined1 *)(param_4 + 7) = 1;
          *(undefined4 *)((longlong)param_4 + 0x34) = 0;
        }
        else {
          iVar1 = FUN_14000b760(param_1,param_2,param_3,param_4);
        }
        FUN_1400085ac(param_1);
        return iVar1;
      }
    }
    *(undefined1 *)(param_4 + 7) = 1;
    *(undefined4 *)((longlong)param_4 + 0x34) = 0;
    *(undefined1 *)(param_4 + 6) = 1;
    *(undefined4 *)((longlong)param_4 + 0x2c) = 9;
    FUN_140006bbc((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0,param_4);
  }
  return -1;
}



/*****************************************************************************
 * Function: FUN_14000b760
 * Address: 14000b760
 * Size: 784 bytes
 *****************************************************************************/


int FUN_14000b760(uint param_1,wchar_t *param_2,uint param_3,longlong *param_4)

{
  wchar_t *pwVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  byte bVar5;
  wchar_t wVar6;
  wint_t wVar7;
  BOOL BVar8;
  DWORD DVar9;
  int iVar10;
  ulonglong uVar11;
  undefined7 extraout_var;
  undefined8 *puVar12;
  longlong lVar13;
  int iVar14;
  uint uVar15;
  wchar_t *pwVar16;
  undefined8 local_70;
  int local_68;
  undefined8 local_60;
  wchar_t local_50 [8];
  
  iVar14 = 0;
  if (param_3 == 0) {
    return 0;
  }
  if (param_2 == (wchar_t *)0x0) {
LAB_14000b790:
    *(undefined1 *)(param_4 + 7) = 1;
    *(undefined4 *)((longlong)param_4 + 0x34) = 0;
    *(undefined1 *)(param_4 + 6) = 1;
    *(undefined4 *)((longlong)param_4 + 0x2c) = 0x16;
    FUN_140006bbc((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0,param_4);
    return -1;
  }
  uVar11 = (ulonglong)(param_1 & 0x3f);
  lVar13 = (longlong)(int)param_1 >> 6;
  cVar2 = *(char *)((&DAT_140019190)[lVar13] + 0x39 + uVar11 * 0x48);
  if (((byte)(cVar2 - 1U) < 2) && ((~param_3 & 1) == 0)) goto LAB_14000b790;
  if ((*(byte *)((&DAT_140019190)[lVar13] + 0x38 + uVar11 * 0x48) & 0x20) != 0) {
    thunk_FUN_14000bdc4(param_1,(LARGE_INTEGER)0x0,2,(longlong)param_4);
  }
  local_60 = 0;
  bVar5 = FUN_14000bb64(param_1);
  if (((int)CONCAT71(extraout_var,bVar5) == 0) ||
     (-1 < *(char *)((&DAT_140019190)[lVar13] + 0x38 + uVar11 * 0x48))) {
LAB_14000b949:
    if (-1 < *(char *)((&DAT_140019190)[lVar13] + 0x38 + uVar11 * 0x48)) {
      local_70 = 0;
      local_68 = 0;
      BVar8 = WriteFile(*(HANDLE *)((&DAT_140019190)[lVar13] + 0x28 + uVar11 * 0x48),param_2,param_3
                        ,(LPDWORD)((longlong)&local_70 + 4),(LPOVERLAPPED)0x0);
      iVar14 = local_68;
      uVar4 = local_70;
      if (BVar8 == 0) {
        DVar9 = GetLastError();
        local_70 = CONCAT44(local_70._4_4_,DVar9);
        iVar14 = local_68;
        uVar4 = local_70;
      }
      goto LAB_14000b9ed;
    }
    uVar15 = (uint)param_2;
    if (cVar2 == '\0') {
      puVar12 = (undefined8 *)
                write_text_ansi_nolock((int)&local_70,(char *)(ulonglong)param_1,uVar15);
    }
    else if (cVar2 == '\x01') {
      puVar12 = (undefined8 *)
                write_text_utf8_nolock((int)&local_70,(char *)(ulonglong)param_1,uVar15);
    }
    else {
      iVar14 = 0;
      uVar4 = local_60;
      if (cVar2 != '\x02') goto LAB_14000b9ed;
      puVar12 = (undefined8 *)
                write_text_utf16le_nolock((int)&local_70,(char *)(ulonglong)param_1,uVar15);
    }
  }
  else {
    if ((char)param_4[5] == '\0') {
      FUN_1400060f0(param_4);
    }
    if (((*(longlong *)(param_4[3] + 0x138) == 0) &&
        (*(char *)((&DAT_140019190)[lVar13] + 0x39 + uVar11 * 0x48) == '\0')) ||
       (BVar8 = GetConsoleMode(*(HANDLE *)((&DAT_140019190)[lVar13] + 0x28 + uVar11 * 0x48),
                               (LPDWORD)local_50), BVar8 == 0)) goto LAB_14000b949;
    if (cVar2 != '\0') {
      uVar4 = local_60;
      if ((byte)(cVar2 - 1U) < 2) {
        pwVar1 = (wchar_t *)((longlong)param_2 + (ulonglong)param_3);
        local_70 = 0;
        uVar4 = local_70;
        if (param_2 < pwVar1) {
          local_70._4_4_ = 0;
          pwVar16 = param_2;
          iVar10 = local_70._4_4_;
          do {
            local_50[0] = *pwVar16;
            wVar6 = _putwch_nolock(local_50[0]);
            if (wVar6 != local_50[0]) {
LAB_14000b90d:
              DVar9 = GetLastError();
              local_70 = CONCAT44(local_70._4_4_,DVar9);
              uVar4 = local_70;
              break;
            }
            local_70 = CONCAT44(iVar10 + 2,(DWORD)local_70);
            iVar3 = iVar10 + 2;
            if (local_50[0] == L'\n') {
              wVar7 = _putwch_nolock(L'\r');
              if (wVar7 != 0xd) goto LAB_14000b90d;
              local_70 = CONCAT44(iVar10 + 3,(DWORD)local_70);
              iVar14 = iVar14 + 1;
              iVar3 = iVar10 + 3;
            }
            iVar10 = iVar3;
            pwVar16 = pwVar16 + 1;
            uVar4 = local_70;
          } while (pwVar16 < pwVar1);
        }
      }
      goto LAB_14000b9ed;
    }
    puVar12 = (undefined8 *)
              FUN_14000ae1c((DWORD *)&local_70,param_1,(byte *)param_2,(ulonglong)param_3,param_4);
  }
  iVar14 = *(int *)(puVar12 + 1);
  uVar4 = *puVar12;
LAB_14000b9ed:
  local_60 = uVar4;
  iVar10 = (int)((ulonglong)local_60 >> 0x20);
  if (iVar10 != 0) {
    return iVar10 - iVar14;
  }
  if ((int)local_60 != 0) {
    if ((int)local_60 == 5) {
      *(undefined1 *)(param_4 + 6) = 1;
      *(undefined4 *)((longlong)param_4 + 0x2c) = 9;
      *(undefined1 *)(param_4 + 7) = 1;
      *(undefined4 *)((longlong)param_4 + 0x34) = 5;
      return -1;
    }
    FUN_140006ea0((int)local_60,(longlong)param_4);
    return -1;
  }
  if (((*(byte *)((&DAT_140019190)[lVar13] + 0x38 + uVar11 * 0x48) & 0x40) != 0) &&
     ((char)*param_2 == '\x1a')) {
    return 0;
  }
  *(undefined4 *)((longlong)param_4 + 0x34) = 0;
  *(undefined1 *)(param_4 + 6) = 1;
  *(undefined4 *)((longlong)param_4 + 0x2c) = 0x1c;
  *(undefined1 *)(param_4 + 7) = 1;
  return -1;
}



/*****************************************************************************
 * Function: FUN_14000ba70
 * Address: 14000ba70
 * Size: 177 bytes
 *****************************************************************************/


int FUN_14000ba70(void)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  longlong lVar4;
  int local_18;
  
  local_18 = 0;
  __acrt_lock(8);
  for (iVar3 = 3; iVar3 != DAT_140019768; iVar3 = iVar3 + 1) {
    lVar4 = (longlong)iVar3;
    lVar1 = *(longlong *)(DAT_140019770 + lVar4 * 8);
    if (lVar1 != 0) {
      if (((*(uint *)(lVar1 + 0x14) >> 0xd & 1) != 0) &&
         (uVar2 = FUN_14000bfd4(*(int **)(DAT_140019770 + lVar4 * 8)), (int)uVar2 != -1)) {
        local_18 = local_18 + 1;
      }
      DeleteCriticalSection((LPCRITICAL_SECTION)(*(longlong *)(DAT_140019770 + lVar4 * 8) + 0x30));
      FUN_140006f7c(*(LPVOID *)(DAT_140019770 + lVar4 * 8));
      *(undefined8 *)(DAT_140019770 + lVar4 * 8) = 0;
    }
  }
  __acrt_unlock(8);
  return local_18;
}



/*****************************************************************************
 * Function: FUN_14000bb64
 * Address: 14000bb64
 * Size: 95 bytes
 *****************************************************************************/


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



/*****************************************************************************
 * Function: FUN_14000bbc4
 * Address: 14000bbc4
 * Size: 67 bytes
 *****************************************************************************/


void FUN_14000bbc4(undefined2 *param_1,byte *param_2,ulonglong param_3,uint *param_4,
                  longlong param_5)

{
  ulonglong uVar1;
  uint local_18 [4];
  
  uVar1 = FUN_14000c638((ulonglong)local_18,param_2,param_3,param_4,param_5);
  if (uVar1 < 5) {
    if (0xffff < local_18[0]) {
      local_18[0] = 0xfffd;
    }
    if (param_1 != (undefined2 *)0x0) {
      *param_1 = (short)local_18[0];
    }
  }
  return;
}



/*****************************************************************************
 * Function: FUN_14000bc08
 * Address: 14000bc08
 * Size: 418 bytes
 *****************************************************************************/


longlong FUN_14000bc08(ushort *param_1,undefined8 *param_2,ulonglong param_3,uint *param_4,
                      longlong param_5)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ushort *puVar4;
  byte *pbVar5;
  byte *pbVar6;
  ulonglong uVar7;
  uint local_res8 [2];
  
  pbVar6 = (byte *)*param_2;
  lVar1 = 0;
  if (param_1 == (ushort *)0x0) {
    while( true ) {
      if (*pbVar6 == 0) {
        uVar7 = 1;
      }
      else if (pbVar6[1] == 0) {
        uVar7 = 2;
      }
      else {
        uVar7 = (ulonglong)(pbVar6[2] != 0) + 3;
      }
      lVar2 = FUN_14000c638(0,pbVar6,uVar7,param_4,param_5);
      if (lVar2 == -1) {
        *(undefined1 *)(param_5 + 0x30) = 1;
        *(undefined4 *)(param_5 + 0x2c) = 0x2a;
        return -1;
      }
      if (lVar2 == 0) break;
      if (lVar2 == 4) {
        lVar1 = lVar1 + 1;
      }
      pbVar6 = pbVar6 + lVar2;
      lVar1 = lVar1 + 1;
    }
  }
  else {
    puVar4 = param_1;
    pbVar5 = pbVar6;
    if (param_3 != 0) {
      do {
        if (*pbVar6 == 0) {
          uVar7 = 1;
        }
        else if (pbVar6[1] == 0) {
          uVar7 = 2;
        }
        else {
          uVar7 = (ulonglong)(pbVar6[2] != 0) + 3;
        }
        lVar1 = FUN_14000c638((ulonglong)local_res8,pbVar6,uVar7,param_4,param_5);
        if (lVar1 == -1) {
          *param_2 = pbVar6;
          *(undefined1 *)(param_5 + 0x30) = 1;
          *(undefined4 *)(param_5 + 0x2c) = 0x2a;
          return -1;
        }
        pbVar5 = (byte *)0x0;
        if (lVar1 == 0) {
          *puVar4 = 0;
          break;
        }
        uVar3 = local_res8[0];
        if (0xffff < local_res8[0]) {
          pbVar5 = pbVar6;
          if (param_3 < 2) break;
          local_res8[0] = local_res8[0] - 0x10000;
          param_3 = param_3 - 1;
          *puVar4 = (ushort)(local_res8[0] >> 10) | 0xd800;
          puVar4 = puVar4 + 1;
          uVar3 = (uint)((ushort)local_res8[0] & 0x3ff | 0xdc00);
        }
        *puVar4 = (ushort)uVar3;
        pbVar5 = pbVar6 + lVar1;
        puVar4 = puVar4 + 1;
        param_3 = param_3 - 1;
        pbVar6 = pbVar5;
      } while (param_3 != 0);
    }
    *param_2 = pbVar5;
    lVar1 = (longlong)puVar4 - (longlong)param_1 >> 1;
  }
  return lVar1;
}



/*****************************************************************************
 * Function: FUN_14000bdc4
 * Address: 14000bdc4
 * Size: 169 bytes
 *****************************************************************************/


longlong FUN_14000bdc4(uint param_1,LARGE_INTEGER param_2,DWORD param_3,longlong param_4)

{
  byte *pbVar1;
  BOOL BVar2;
  DWORD DVar3;
  HANDLE hFile;
  LARGE_INTEGER local_18 [2];
  
  hFile = (HANDLE)FUN_140008690(param_1);
  if (hFile == (HANDLE)0xffffffffffffffff) {
    *(undefined1 *)(param_4 + 0x30) = 1;
    *(undefined4 *)(param_4 + 0x2c) = 9;
  }
  else {
    BVar2 = SetFilePointerEx(hFile,param_2,local_18,param_3);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      FUN_140006ea0(DVar3,param_4);
    }
    else if (local_18[0].QuadPart != -1) {
      pbVar1 = (byte *)((&DAT_140019190)[(longlong)(int)param_1 >> 6] + 0x38 +
                       (ulonglong)(param_1 & 0x3f) * 0x48);
      *pbVar1 = *pbVar1 & 0xfd;
      return (longlong)local_18[0].s;
    }
  }
  return -1;
}



/*****************************************************************************
 * Function: thunk_FUN_14000bdc4
 * Address: 14000be70
 * Size: 5 bytes
 *****************************************************************************/


longlong thunk_FUN_14000bdc4(uint param_1,LARGE_INTEGER param_2,DWORD param_3,longlong param_4)

{
  byte *pbVar1;
  BOOL BVar2;
  DWORD DVar3;
  HANDLE hFile;
  LARGE_INTEGER aLStack_18 [2];
  
  hFile = (HANDLE)FUN_140008690(param_1);
  if (hFile == (HANDLE)0xffffffffffffffff) {
    *(undefined1 *)(param_4 + 0x30) = 1;
    *(undefined4 *)(param_4 + 0x2c) = 9;
  }
  else {
    BVar2 = SetFilePointerEx(hFile,param_2,aLStack_18,param_3);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      FUN_140006ea0(DVar3,param_4);
    }
    else if (aLStack_18[0].QuadPart != -1) {
      pbVar1 = (byte *)((&DAT_140019190)[(longlong)(int)param_1 >> 6] + 0x38 +
                       (ulonglong)(param_1 & 0x3f) * 0x48);
      *pbVar1 = *pbVar1 & 0xfd;
      return (longlong)aLStack_18[0].s;
    }
  }
  return -1;
}



/*****************************************************************************
 * Function: _putwch_nolock
 * Address: 14000be78
 * Size: 59 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _putwch_nolock
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

wint_t __cdecl _putwch_nolock(wchar_t _WCh)

{
  bool bVar1;
  BOOL BVar2;
  undefined7 extraout_var;
  wchar_t local_res8 [4];
  DWORD local_res10 [6];
  
  local_res8[0] = _WCh;
  bVar1 = __dcrt_lowio_ensure_console_output_initialized();
  if (((int)CONCAT71(extraout_var,bVar1) == 0) ||
     (BVar2 = __dcrt_write_console(local_res8,1,local_res10), BVar2 == 0)) {
    local_res8[0] = L'\xffff';
  }
  return local_res8[0];
}



/*****************************************************************************
 * Function: FUN_14000beb4
 * Address: 14000beb4
 * Size: 121 bytes
 *****************************************************************************/


ulonglong FUN_14000beb4(int *param_1,longlong *param_2)

{
  ulonglong uVar1;
  
  if (param_1 == (int *)0x0) {
    *(undefined1 *)(param_2 + 6) = 1;
    *(undefined4 *)((longlong)param_2 + 0x2c) = 0x16;
    FUN_140006bbc((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0,param_2);
  }
  else {
    if (((uint)param_1[5] >> 0xc & 1) == 0) {
      FUN_14000a0e0((longlong)param_1);
      uVar1 = FUN_14000bf30(param_1,param_2);
      FUN_14000a0ec((longlong)param_1);
      return uVar1 & 0xffffffff;
    }
    FUN_14000cb50((undefined8 *)param_1);
  }
  return 0xffffffff;
}



/*****************************************************************************
 * Function: FUN_14000bf30
 * Address: 14000bf30
 * Size: 164 bytes
 *****************************************************************************/


ulonglong FUN_14000bf30(int *param_1,longlong *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  if (param_1 == (int *)0x0) {
    *(undefined1 *)(param_2 + 6) = 1;
    *(undefined4 *)((longlong)param_2 + 0x2c) = 0x16;
    FUN_140006bbc((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0,param_2);
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0xffffffff;
    if (((uint)param_1[5] >> 0xd & 1) != 0) {
      uVar2 = FUN_140009dfc(param_1,param_2);
      uVar2 = uVar2 & 0xffffffff;
      __acrt_stdio_free_buffer_nolock((undefined8 *)param_1);
      uVar1 = FUN_14000a348((longlong)param_1);
      uVar3 = FUN_14000c9bc(uVar1,param_2);
      if ((int)uVar3 < 0) {
        uVar2 = 0xffffffff;
      }
      else if (*(LPVOID *)(param_1 + 10) != (LPVOID)0x0) {
        FUN_140006f7c(*(LPVOID *)(param_1 + 10));
        param_1[10] = 0;
        param_1[0xb] = 0;
      }
    }
    FUN_14000cb50((undefined8 *)param_1);
  }
  return uVar2;
}



/*****************************************************************************
 * Function: FUN_14000bfd4
 * Address: 14000bfd4
 * Size: 152 bytes
 *****************************************************************************/


ulonglong FUN_14000bfd4(int *param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong local_48 [2];
  undefined1 local_38;
  undefined *local_30;
  undefined *puStack_28;
  char local_20;
  undefined4 local_1c;
  char local_18;
  undefined4 local_14;
  char local_10;
  
  local_48[0] = 0;
  local_20 = DAT_140018eb4 == 0;
  local_38 = 0;
  local_18 = '\0';
  local_10 = '\0';
  if ((bool)local_20) {
    local_30 = PTR_PTR_140018708;
    puStack_28 = PTR_DAT_140018710;
  }
  uVar1 = FUN_14000beb4(param_1,local_48);
  if (local_20 == '\x02') {
    *(uint *)(local_48[0] + 0x3a8) = *(uint *)(local_48[0] + 0x3a8) & 0xfffffffd;
  }
  if (local_18 != '\0') {
    lVar2 = FUN_140006080(local_48);
    *(undefined4 *)(lVar2 + 0x20) = local_1c;
  }
  if (local_10 != '\0') {
    lVar2 = FUN_140006080(local_48);
    *(undefined4 *)(lVar2 + 0x24) = local_14;
  }
  return uVar1 & 0xffffffff;
}



/*****************************************************************************
 * Function: FUN_14000c070
 * Address: 14000c070
 * Size: 1386 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_14000c070(void)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  ulonglong uVar13;
  ulonglong uVar14;
  double dVar15;
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 in_ZMM0 [64];
  double dVar20;
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  double dVar23;
  double dVar24;
  undefined1 auVar25 [16];
  double dVar26;
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  double dVar37;
  
  dVar15 = in_ZMM0._0_8_;
  auVar16 = in_ZMM0._0_16_;
  if (DAT_14001979c == 0) {
    if ((double)((ulonglong)dVar15 & (ulonglong)DAT_140013d10) == DAT_140013d10) {
      if (dVar15 == DAT_140013d10) {
        return dVar15;
      }
      if (dVar15 != DAT_140013d00) {
        return (double)((ulonglong)dVar15 | _DAT_140013d30);
      }
    }
    else {
      dVar37 = (double)(int)(((ulonglong)dVar15 >> 0x34) - _DAT_140013d40);
      if (0.0 < dVar15) {
        dVar23 = (double)((ulonglong)dVar15 & (ulonglong)DAT_140013d60);
        dVar20 = dVar15;
        if (dVar37 == DAT_140013e80) {
          dVar37 = (double)((ulonglong)dVar23 | (ulonglong)DAT_140013df0) - DAT_140013df0;
          dVar20 = (double)((ulonglong)dVar37 & (ulonglong)DAT_140013d60);
          dVar37 = (double)(int)((uint)((ulonglong)dVar37 >> 0x34) - _DAT_140013e90);
          dVar23 = dVar20;
        }
        uVar13 = ((ulonglong)dVar20 & _DAT_140013d70) + ((ulonglong)dVar20 & _DAT_140013d80) * 2;
        if ((double)((ulonglong)(dVar15 - DAT_140013df0) & _DAT_140013ee0) < DAT_140013ea0) {
          dVar15 = dVar15 - DAT_140013df0;
          dVar37 = dVar15 / (DAT_140013de0 + dVar15);
          dVar20 = dVar37 + dVar37;
          dVar23 = dVar20 * dVar20;
          dVar24 = dVar23 * dVar20;
          dVar26 = (double)((ulonglong)dVar15 & (ulonglong)DAT_140013f30);
          dVar15 = (((DAT_140013f00 * dVar23 + DAT_140013ef0) * dVar24 +
                    (DAT_140013f20 * dVar23 + DAT_140013f10) * dVar24 * dVar24 * dVar20) -
                   dVar15 * dVar37) + (dVar15 - dVar26);
          return dVar26 * DAT_140013db0 + dVar15 * DAT_140013db0 + dVar15 * DAT_140013da0 +
                 dVar26 * DAT_140013da0;
        }
        uVar14 = uVar13 >> 0x2c;
        dVar20 = ((double)(uVar13 | DAT_140013e00) - (double)((ulonglong)dVar23 | DAT_140013e00)) *
                 *(double *)(&DAT_140014f80 + uVar14 * 8);
        dVar15 = dVar20 * dVar20;
        return *(double *)(&DAT_140013f60 + uVar14 * 8) + DAT_140013dc0 * dVar37 +
               *(double *)(&DAT_140014770 + uVar14 * 8) +
               (DAT_140013dd0 * dVar37 -
               ((DAT_140013e40 * dVar20 + _DAT_140013e30) * dVar15 + dVar20 +
               ((DAT_140013e70 * dVar20 + DAT_140013e60) * dVar20 + DAT_140013e50) * dVar15 * dVar15
               ) * DAT_140013d90);
      }
      if (dVar15 == 0.0) {
        dVar15 = (double)FUN_14000ce30(dVar15,DAT_140013d00,DAT_140013f40);
        return dVar15;
      }
    }
    dVar15 = (double)FUN_14000ce30(dVar15,DAT_140013d20,DAT_140013f44);
    return dVar15;
  }
  auVar27 = vpsrlq_avx(auVar16,0x34);
  auVar36._8_8_ = _UNK_140013d48;
  auVar36._0_8_ = _DAT_140013d40;
  auVar36 = vpsubq_avx(auVar27,auVar36);
  auVar36 = vcvtdq2pd_avx(auVar36);
  auVar27._8_8_ = _UNK_140013d18;
  auVar27._0_8_ = DAT_140013d10;
  auVar27 = vpand_avx(auVar16,auVar27);
  if (auVar27._0_8_ == DAT_140013d10) {
    if (dVar15 != DAT_140013d10) {
      if (dVar15 == DAT_140013d00) goto LAB_14000c5c0;
      dVar15 = (double)FUN_14000ce30(dVar15,(ulonglong)dVar15 | _DAT_140013d30,DAT_140013f48);
    }
    return dVar15;
  }
  if (0.0 < dVar15) {
    auVar27 = vpand_avx(auVar16,_DAT_140013d60);
    if (auVar36._0_8_ == DAT_140013e80) {
      auVar16._8_8_ = _UNK_140013df8;
      auVar16._0_8_ = DAT_140013df0;
      auVar16 = vpor_avx(auVar27,auVar16);
      auVar28._8_8_ = 0;
      auVar28._0_8_ = auVar16._0_8_ - DAT_140013df0;
      auVar36 = vpsrlq_avx(auVar28,0x34);
      auVar16 = vpand_avx(auVar28,_DAT_140013d60);
      auVar7._4_12_ = _UNK_140013e94;
      auVar7._0_4_ = _DAT_140013e90;
      auVar36 = vpsubd_avx(auVar36,auVar7);
      auVar36 = vcvtdq2pd_avx(auVar36);
      auVar27 = auVar16;
    }
    auVar8._8_8_ = _UNK_140013d78;
    auVar8._0_8_ = _DAT_140013d70;
    auVar7 = vpand_avx(auVar16,auVar8);
    auVar9._8_8_ = _UNK_140013d88;
    auVar9._0_8_ = _DAT_140013d80;
    auVar28 = vpand_avx(auVar16,auVar9);
    auVar28 = vpsllq_avx(auVar28,1);
    auVar7 = vpaddq_avx(auVar28,auVar7);
    auVar30._8_8_ = 0;
    auVar30._0_8_ = dVar15 - DAT_140013df0;
    auVar12._8_8_ = _UNK_140013ee8;
    auVar12._0_8_ = _DAT_140013ee0;
    auVar28 = vpand_avx(auVar30,auVar12);
    if (auVar28._0_8_ < DAT_140013ea0) {
      dVar20 = auVar16._0_8_ - DAT_140013df0;
      dVar23 = dVar20 / (DAT_140013de0 + dVar20);
      auVar32._8_8_ = 0;
      auVar32._0_8_ = DAT_140013f00;
      auVar35._8_8_ = 0;
      auVar35._0_8_ = DAT_140013f20;
      dVar15 = dVar23 + dVar23;
      auVar5._8_8_ = 0;
      auVar5._0_8_ = DAT_140013ef0;
      auVar25._8_8_ = 0;
      auVar25._0_8_ = dVar15 * dVar15;
      auVar36 = vfmadd213sd_fma(auVar32,auVar25,auVar5);
      auVar6._8_8_ = 0;
      auVar6._0_8_ = DAT_140013f10;
      auVar27 = vfmadd213sd_fma(auVar35,auVar25,auVar6);
      dVar37 = dVar15 * dVar15 * dVar15;
      auVar19._8_8_ = 0;
      auVar19._0_8_ = dVar20;
      auVar16 = vpand_avx(auVar19,_DAT_140013f30);
      dVar24 = auVar16._0_8_;
      dVar15 = ((auVar36._0_8_ * dVar37 + auVar27._0_8_ * dVar37 * dVar37 * dVar15) -
               dVar20 * dVar23) + (dVar20 - dVar24);
      return dVar24 * DAT_140013db0 + dVar15 * DAT_140013db0 + dVar15 * DAT_140013da0 +
             dVar24 * DAT_140013da0;
    }
    uVar13 = auVar7._0_8_ >> 0x2c;
    auVar10._8_8_ = _UNK_140013e08;
    auVar10._0_8_ = DAT_140013e00;
    auVar16 = vpor_avx(auVar27,auVar10);
    auVar11._8_8_ = _UNK_140013e08;
    auVar11._0_8_ = DAT_140013e00;
    auVar27 = vpor_avx(auVar7,auVar11);
    dVar15 = (auVar27._0_8_ - auVar16._0_8_) * *(double *)(&DAT_140014f80 + uVar13 * 8);
    dVar37 = dVar15 * dVar15;
    auVar29._8_8_ = 0;
    auVar29._0_8_ = DAT_140013e70;
    auVar33._8_8_ = 0;
    auVar33._0_8_ = DAT_140013e40;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = DAT_140013e60;
    auVar21._8_8_ = 0;
    auVar21._0_8_ = dVar15;
    auVar16 = vfmadd213sd_fma(auVar29,auVar21,auVar1);
    auVar2._8_8_ = 0;
    auVar2._0_8_ = DAT_140013e00;
    auVar27 = vfmadd213sd_fma(auVar33,auVar21,auVar2);
    auVar3._8_8_ = 0;
    auVar3._0_8_ = DAT_140013e50;
    auVar16 = vfmadd213sd_fma(auVar16,auVar21,auVar3);
    auVar17._8_8_ = 0;
    auVar17._0_8_ = dVar37;
    auVar27 = vfmadd231sd_fma(auVar21,auVar27,auVar17);
    auVar31._8_8_ = 0;
    auVar31._0_8_ = dVar37 * dVar37;
    auVar16 = vfmadd231sd_fma(auVar27,auVar16,auVar31);
    auVar34._8_8_ = 0;
    auVar34._0_8_ = DAT_140013dd0;
    auVar22._8_8_ = 0;
    auVar22._0_8_ = auVar16._0_8_ * DAT_140013d90;
    auVar27 = vfmsub213sd_fma(auVar34,auVar36,auVar22);
    auVar4._8_8_ = 0;
    auVar4._0_8_ = DAT_140013dc0;
    auVar18._8_8_ = 0;
    auVar18._0_8_ = *(ulonglong *)(&DAT_140013f60 + uVar13 * 8);
    auVar16 = vfmadd231sd_fma(auVar18,auVar36,auVar4);
    return auVar16._0_8_ + *(double *)(&DAT_140014770 + uVar13 * 8) + auVar27._0_8_;
  }
  if (dVar15 == 0.0) {
    dVar15 = (double)FUN_14000ce30(dVar15,DAT_140013d00,DAT_140013f40);
    return dVar15;
  }
LAB_14000c5c0:
  dVar15 = (double)FUN_14000ce30(dVar15,DAT_140013d20,DAT_140013f44);
  return dVar15;
}



/*****************************************************************************
 * Function: FUN_14000c61c
 * Address: 14000c61c
 * Size: 8 bytes
 *****************************************************************************/


undefined8 FUN_14000c61c(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = 0;
  return param_1;
}



/*****************************************************************************
 * Function: FUN_14000c624
 * Address: 14000c624
 * Size: 20 bytes
 *****************************************************************************/


undefined8 FUN_14000c624(undefined8 *param_1,longlong param_2)

{
  *param_1 = 0;
  *(undefined1 *)(param_2 + 0x30) = 1;
  *(undefined4 *)(param_2 + 0x2c) = 0x2a;
  return 0xffffffffffffffff;
}



/*****************************************************************************
 * Function: FUN_14000c638
 * Address: 14000c638
 * Size: 473 bytes
 *****************************************************************************/


void FUN_14000c638(ulonglong param_1,byte *param_2,ulonglong param_3,uint *param_4,longlong param_5)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  ulonglong uVar4;
  byte *pbVar5;
  byte bVar6;
  ulonglong uVar7;
  uint *puVar8;
  uint *puVar9;
  ulonglong uVar10;
  undefined1 auStack_78 [24];
  uint auStack_60 [6];
  ulonglong local_48;
  
  local_48 = DAT_140018038 ^ (ulonglong)auStack_78;
  puVar8 = (uint *)&DAT_140019790;
  if (param_4 != (uint *)0x0) {
    puVar8 = param_4;
  }
  pbVar5 = (byte *)0x14000eb52;
  if (param_2 != (byte *)0x0) {
    pbVar5 = param_2;
  }
  uVar10 = 1;
  if (param_2 != (byte *)0x0) {
    uVar10 = param_3;
  }
  puVar9 = (uint *)(-(ulonglong)(param_2 != (byte *)0x0) & param_1);
  if (uVar10 == 0) goto LAB_14000c7f5;
  if (*(short *)((longlong)puVar8 + 6) == 0) {
    bVar3 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    if (-1 < (char)bVar3) {
      if (puVar9 != (uint *)0x0) {
        *puVar9 = (uint)bVar3;
      }
      goto LAB_14000c7f5;
    }
    if ((bVar3 & 0xe0) == 0xc0) {
      bVar6 = 2;
    }
    else if ((bVar3 & 0xf0) == 0xe0) {
      bVar6 = 3;
    }
    else {
      if ((bVar3 & 0xf8) != 0xf0) goto LAB_14000c7ea;
      bVar6 = 4;
    }
    uVar2 = (1 << (7 - bVar6 & 0x1f)) - 1U & (uint)bVar3;
    bVar3 = bVar6;
LAB_14000c740:
    uVar4 = (ulonglong)bVar3;
    uVar7 = (ulonglong)bVar3;
    if (uVar10 <= uVar4) {
      uVar7 = uVar10;
    }
    while ((ulonglong)((longlong)pbVar5 - (longlong)param_2) < uVar7) {
      bVar1 = *pbVar5;
      pbVar5 = pbVar5 + 1;
      if ((bVar1 & 0xc0) != 0x80) goto LAB_14000c7ea;
      uVar2 = bVar1 & 0x3f | uVar2 << 6;
    }
    if (uVar7 < uVar4) {
      *(ushort *)(puVar8 + 1) = (ushort)bVar6;
      *(ushort *)((longlong)puVar8 + 6) = (ushort)(byte)(bVar3 - (char)uVar7);
      *puVar8 = uVar2;
      goto LAB_14000c7f5;
    }
    if ((0x7ff < uVar2 - 0xd800) && (uVar2 < 0x110000)) {
      auStack_60[2] = 0x80;
      auStack_60[3] = 0x800;
      auStack_60[4] = 0x10000;
      if (auStack_60[bVar6] <= uVar2) {
        if (puVar9 != (uint *)0x0) {
          *puVar9 = uVar2;
        }
        FUN_14000c61c(-(ulonglong)(uVar2 != 0) & uVar4,(undefined8 *)puVar8);
        goto LAB_14000c7f5;
      }
    }
  }
  else {
    bVar6 = (byte)puVar8[1];
    uVar2 = *puVar8;
    bVar3 = *(byte *)((longlong)puVar8 + 6);
    if ((((byte)(bVar6 - 2) < 3) && (bVar3 != 0)) && (bVar3 < bVar6)) goto LAB_14000c740;
  }
LAB_14000c7ea:
  FUN_14000c624((undefined8 *)puVar8,param_5);
LAB_14000c7f5:
  FUN_14000d520(local_48 ^ (ulonglong)auStack_78);
  return;
}



/*****************************************************************************
 * Function: FUN_14000c868
 * Address: 14000c868
 * Size: 28 bytes
 *****************************************************************************/


void FUN_14000c868(void)

{
  if (DAT_1400189e0 < (HANDLE)0xfffffffffffffffe) {
    CloseHandle(DAT_1400189e0);
  }
  return;
}



/*****************************************************************************
 * Function: FUN_14000c944
 * Address: 14000c944
 * Size: 119 bytes
 *****************************************************************************/


ulonglong FUN_14000c944(undefined8 param_1,uint *param_2,undefined8 *param_3,uint *param_4)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  FUN_140008584(*param_2);
  uVar1 = *(uint *)*param_3;
  lVar2 = param_3[1];
  if ((*(byte *)((&DAT_140019190)[(longlong)(int)uVar1 >> 6] + 0x38 +
                (ulonglong)(uVar1 & 0x3f) * 0x48) & 1) == 0) {
    *(undefined1 *)(lVar2 + 0x30) = 1;
    *(undefined4 *)(lVar2 + 0x2c) = 9;
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = FUN_14000ca80(uVar1,lVar2);
    uVar3 = uVar3 & 0xffffffff;
  }
  FUN_1400085ac(*param_4);
  return uVar3;
}



/*****************************************************************************
 * Function: FUN_14000c9bc
 * Address: 14000c9bc
 * Size: 193 bytes
 *****************************************************************************/


ulonglong FUN_14000c9bc(uint param_1,longlong *param_2)

{
  ulonglong uVar1;
  uint local_res8 [4];
  undefined1 local_res18 [8];
  uint local_res20 [2];
  uint local_28 [2];
  uint *local_20;
  longlong *local_18;
  
  if (param_1 == 0xfffffffe) {
    *(undefined1 *)(param_2 + 7) = 1;
    *(undefined4 *)((longlong)param_2 + 0x34) = 0;
    *(undefined1 *)(param_2 + 6) = 1;
    *(undefined4 *)((longlong)param_2 + 0x2c) = 9;
  }
  else {
    local_res8[0] = param_1;
    if (((-1 < (int)param_1) && (param_1 < DAT_140019590)) &&
       ((*(byte *)((&DAT_140019190)[(longlong)(int)param_1 >> 6] + 0x38 +
                  (ulonglong)(param_1 & 0x3f) * 0x48) & 1) != 0)) {
      local_20 = local_res8;
      local_res20[0] = param_1;
      local_28[0] = param_1;
      local_18 = param_2;
      uVar1 = FUN_14000c944(local_res18,local_28,&local_20,local_res20);
      return uVar1;
    }
    *(undefined1 *)(param_2 + 7) = 1;
    *(undefined4 *)((longlong)param_2 + 0x34) = 0;
    *(undefined1 *)(param_2 + 6) = 1;
    *(undefined4 *)((longlong)param_2 + 0x2c) = 9;
    FUN_140006bbc((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0,param_2);
  }
  return 0xffffffff;
}



/*****************************************************************************
 * Function: FUN_14000ca80
 * Address: 14000ca80
 * Size: 205 bytes
 *****************************************************************************/


undefined8 FUN_14000ca80(uint param_1,longlong param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  longlong lVar3;
  longlong lVar4;
  HANDLE hObject;
  undefined8 uVar5;
  
  lVar3 = FUN_140008690(param_1);
  if (lVar3 != -1) {
    if (((param_1 == 1) && ((*(byte *)(DAT_140019190 + 200) & 1) != 0)) ||
       ((param_1 == 2 && ((*(byte *)(DAT_140019190 + 0x80) & 1) != 0)))) {
      lVar3 = FUN_140008690(2);
      lVar4 = FUN_140008690(1);
      if (lVar4 == lVar3) goto LAB_14000caa2;
    }
    hObject = (HANDLE)FUN_140008690(param_1);
    BVar1 = CloseHandle(hObject);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      goto LAB_14000cb00;
    }
  }
LAB_14000caa2:
  DVar2 = 0;
LAB_14000cb00:
  FUN_1400085d4(param_1);
  *(undefined1 *)
   ((&DAT_140019190)[(longlong)(int)param_1 >> 6] + 0x38 + (ulonglong)(param_1 & 0x3f) * 0x48) = 0;
  if (DVar2 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_140006ea0(DVar2,param_2);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}



/*****************************************************************************
 * Function: FUN_14000cb50
 * Address: 14000cb50
 * Size: 28 bytes
 *****************************************************************************/


undefined4 FUN_14000cb50(undefined8 *param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 3) = 0xffffffff;
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  *(undefined8 *)((longlong)param_1 + 0x1c) = 0;
  param_1[5] = 0;
  LOCK();
  uVar1 = *(undefined4 *)((longlong)param_1 + 0x14);
  *(undefined4 *)((longlong)param_1 + 0x14) = 0;
  UNLOCK();
  return uVar1;
}



/*****************************************************************************
 * Function: FUN_14000cb6c
 * Address: 14000cb6c
 * Size: 101 bytes
 *****************************************************************************/


undefined8
FUN_14000cb6c(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
             undefined8 param_5,undefined8 param_6,uint param_7)

{
  undefined8 uVar1;
  int local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_20 = param_5;
  local_18 = param_6;
  local_38[0] = param_1;
  local_30 = param_3;
  local_28 = param_4;
  _ctrlfp(param_7,0xffc0);
  uVar1 = FUN_140004e1c(local_38);
  if ((int)uVar1 == 0) {
    _set_errno_from_matherr(param_1);
  }
  return local_18;
}



/*****************************************************************************
 * Function: _exception_enabled
 * Address: 14000cbd4
 * Size: 186 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _exception_enabled
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool _exception_enabled(uint param_1,ulonglong param_2)

{
  uint uVar1;
  
  uVar1 = param_1 & 0x1f;
  if (((param_1 & 8) == 0) || (-1 < (char)param_2)) {
    if (((param_1 & 4) == 0) || ((param_2 >> 9 & 1) == 0)) {
      if (((param_1 & 1) == 0) || ((param_2 >> 10 & 1) == 0)) {
        if (((param_1 & 2) != 0) && ((param_2 >> 0xb & 1) != 0)) {
          if ((param_1 & 0x10) != 0) {
            _set_statfp(0x10);
          }
          uVar1 = param_1 & 0x1d;
        }
      }
      else {
        _set_statfp(8);
        uVar1 = param_1 & 0x1e;
      }
    }
    else {
      _set_statfp(4);
      uVar1 = param_1 & 0x1b;
    }
  }
  else {
    _set_statfp(1);
    uVar1 = param_1 & 0x17;
  }
  if (((param_1 & 0x10) != 0) && ((param_2 >> 0xc & 1) != 0)) {
    _set_statfp(0x20);
    uVar1 = uVar1 & 0xffffffef;
  }
  return uVar1 == 0;
}



/*****************************************************************************
 * Function: FUN_14000cc90
 * Address: 14000cc90
 * Size: 295 bytes
 *****************************************************************************/


void FUN_14000cc90(undefined8 param_1,uint param_2,undefined8 param_3,int param_4,uint param_5,
                  uint param_6,undefined8 param_7,undefined8 param_8,int param_9)

{
  undefined8 uVar1;
  bool bVar2;
  uint uVar3;
  undefined4 extraout_var_00;
  undefined7 extraout_var;
  undefined1 auStackY_108 [32];
  undefined8 local_c8;
  ulonglong local_c0;
  uint local_b8 [12];
  undefined8 local_88;
  uint local_78;
  ulonglong local_48;
  
  local_48 = DAT_140018038 ^ (ulonglong)auStackY_108;
  uVar3 = _ctrlfp(0x1f80,0xffc0);
  local_c0 = CONCAT44(extraout_var_00,uVar3);
  local_c8 = param_3;
  bVar2 = _exception_enabled(param_5,local_c0);
  uVar1 = param_8;
  if ((int)CONCAT71(extraout_var,bVar2) == 0) {
    if (param_9 == 2) {
      local_88 = param_8;
      local_78 = local_78 & 0xffffffe3 | 3;
    }
    _raise_exc(local_b8,&local_c0,(ulonglong)param_5,param_2,(uint *)&param_7,(uint *)&local_c8);
  }
  bVar2 = FUN_140004df4();
  if ((bVar2) && (param_4 != 0)) {
    FUN_14000cb6c(param_4,(ulonglong)param_6,param_1,param_7,uVar1,local_c8,(uint)local_c0);
  }
  else {
    _set_errno_from_matherr(param_4);
    _ctrlfp((uint)local_c0,0xffc0);
  }
  FUN_14000d520(local_48 ^ (ulonglong)auStackY_108);
  return;
}



/*****************************************************************************
 * Function: FUN_14000ce30
 * Address: 14000ce30
 * Size: 32 bytes
 *****************************************************************************/


void FUN_14000ce30(undefined8 param_1,undefined8 param_2,int param_3)

{
  FUN_14000ce50(param_1,param_2,param_3,0x1b,"log10");
  return;
}



/*****************************************************************************
 * Function: FUN_14000ce50
 * Address: 14000ce50
 * Size: 150 bytes
 *****************************************************************************/


undefined4
FUN_14000ce50(undefined8 param_1,undefined8 param_2,int param_3,uint param_4,undefined8 param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_3 == 1) {
    iVar1 = 2;
    uVar3 = 0x22;
    uVar2 = 4;
  }
  else {
    if (param_3 != 2) {
      return (int)param_2;
    }
    uVar3 = 0x21;
    uVar2 = 8;
    iVar1 = 1;
  }
  FUN_14000cc90(param_5,param_4,param_2,iVar1,uVar2,uVar3,param_1,0,1);
  return (int)param_2;
}



/*****************************************************************************
 * Function: _get_fpsr
 * Address: 14000cf00
 * Size: 16 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _get_fpsr
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 _get_fpsr(void)

{
  return MXCSR;
}



/*****************************************************************************
 * Function: FUN_14000cf10
 * Address: 14000cf10
 * Size: 10 bytes
 *****************************************************************************/


void FUN_14000cf10(undefined4 param_1)

{
  MXCSR = param_1;
  return;
}



/*****************************************************************************
 * Function: _fclrf
 * Address: 14000cf1a
 * Size: 20 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _fclrf
   
   Library: Visual Studio */

void _fclrf(void)

{
  MXCSR = MXCSR & 0xffffffc0;
  return;
}



/*****************************************************************************
 * Function: _raise_exc
 * Address: 14000cf50
 * Size: 39 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _raise_exc
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void _raise_exc(uint *param_1,ulonglong *param_2,ulonglong param_3,uint param_4,uint *param_5,
               uint *param_6)

{
  _raise_exc_ex(param_1,param_2,param_3,param_4,param_5,param_6,0);
  return;
}



/*****************************************************************************
 * Function: _raise_exc_ex
 * Address: 14000cf78
 * Size: 781 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _raise_exc_ex
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void _raise_exc_ex(uint *param_1,ulonglong *param_2,ulonglong param_3,uint param_4,uint *param_5,
                  uint *param_6,int param_7)

{
  uint uVar1;
  DWORD dwExceptionCode;
  uint *local_res8;
  
  dwExceptionCode = 0xc000000d;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((param_3 & 0x10) != 0) {
    dwExceptionCode = 0xc000008f;
    param_1[1] = param_1[1] | 1;
  }
  if ((param_3 & 2) != 0) {
    dwExceptionCode = 0xc0000093;
    param_1[1] = param_1[1] | 2;
  }
  if ((param_3 & 1) != 0) {
    dwExceptionCode = 0xc0000091;
    param_1[1] = param_1[1] | 4;
  }
  if ((param_3 & 4) != 0) {
    dwExceptionCode = 0xc000008e;
    param_1[1] = param_1[1] | 8;
  }
  if ((param_3 & 8) != 0) {
    dwExceptionCode = 0xc0000090;
    param_1[1] = param_1[1] | 0x10;
  }
  param_1[2] = param_1[2] ^ (~((int)(*param_2 >> 7) << 4) ^ param_1[2]) & 0x10;
  param_1[2] = param_1[2] ^ (~((int)(*param_2 >> 9) << 3) ^ param_1[2]) & 8;
  param_1[2] = param_1[2] ^ (~((int)(*param_2 >> 10) << 2) ^ param_1[2]) & 4;
  param_1[2] = param_1[2] ^ (~((int)(*param_2 >> 0xb) * 2) ^ param_1[2]) & 2;
  param_1[2] = param_1[2] ^ (~((uint)*param_2 >> 0xc) ^ param_1[2]) & 1;
  local_res8 = param_1;
  uVar1 = _statfp();
  if ((uVar1 & 1) != 0) {
    local_res8[3] = local_res8[3] | 0x10;
  }
  if ((uVar1 & 4) != 0) {
    local_res8[3] = local_res8[3] | 8;
  }
  if ((uVar1 & 8) != 0) {
    local_res8[3] = local_res8[3] | 4;
  }
  if ((uVar1 & 0x10) != 0) {
    local_res8[3] = local_res8[3] | 2;
  }
  if ((uVar1 & 0x20) != 0) {
    local_res8[3] = local_res8[3] | 1;
  }
  uVar1 = (uint)*param_2 & 0x6000;
  if (((uint)*param_2 & 0x6000) == 0) {
    *local_res8 = *local_res8 & 0xfffffffc;
  }
  else if (uVar1 == 0x2000) {
    *local_res8 = *local_res8 & 0xfffffffd;
    *local_res8 = *local_res8 | 1;
  }
  else if (uVar1 == 0x4000) {
    *local_res8 = *local_res8 & 0xfffffffe;
    *local_res8 = *local_res8 | 2;
  }
  else if (uVar1 == 0x6000) {
    *local_res8 = *local_res8 | 3;
  }
  *local_res8 = *local_res8 & 0xfffe001f;
  *local_res8 = *local_res8 | (param_4 & 0xfff) << 5;
  local_res8[8] = local_res8[8] | 1;
  if (param_7 == 0) {
    local_res8[8] = local_res8[8] & 0xffffffe3 | 2;
    *(undefined8 *)(local_res8 + 4) = *(undefined8 *)param_5;
    local_res8[0x18] = local_res8[0x18] | 1;
    local_res8[0x18] = local_res8[0x18] & 0xffffffe3 | 2;
    *(undefined8 *)(local_res8 + 0x14) = *(undefined8 *)param_6;
  }
  else {
    local_res8[8] = local_res8[8] & 0xffffffe1;
    local_res8[4] = *param_5;
    local_res8[0x18] = local_res8[0x18] | 1;
    local_res8[0x18] = local_res8[0x18] & 0xffffffe1;
    local_res8[0x14] = *param_6;
  }
  _clrfp();
  RaiseException(dwExceptionCode,0,1,(ULONG_PTR *)&local_res8);
  uVar1 = local_res8[2];
  if ((uVar1 & 0x10) != 0) {
    *param_2 = *param_2 & 0xffffffffffffff7f;
    uVar1 = local_res8[2];
  }
  if ((uVar1 & 8) != 0) {
    *param_2 = *param_2 & 0xfffffffffffffdff;
    uVar1 = local_res8[2];
  }
  if ((uVar1 & 4) != 0) {
    *param_2 = *param_2 & 0xfffffffffffffbff;
    uVar1 = local_res8[2];
  }
  if ((uVar1 & 2) != 0) {
    *param_2 = *param_2 & 0xfffffffffffff7ff;
    uVar1 = local_res8[2];
  }
  if ((uVar1 & 1) != 0) {
    *param_2 = *param_2 & 0xffffffffffffefff;
  }
  uVar1 = *local_res8 & 3;
  if (uVar1 == 0) {
    *param_2 = *param_2 & 0xffffffffffff9fff;
  }
  else if (uVar1 == 1) {
    *param_2 = *param_2 & 0xffffffffffffbfff;
    *param_2 = *param_2 | 0x2000;
  }
  else if (uVar1 == 2) {
    *param_2 = *param_2 & 0xffffffffffffdfff;
    *param_2 = *param_2 | 0x4000;
  }
  else if (uVar1 == 3) {
    *param_2 = *param_2 | 0x6000;
  }
  if (param_7 == 0) {
    *(undefined8 *)param_6 = *(undefined8 *)(local_res8 + 0x14);
  }
  else {
    *param_6 = local_res8[0x14];
  }
  return;
}



/*****************************************************************************
 * Function: _set_errno_from_matherr
 * Address: 14000d288
 * Size: 46 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _set_errno_from_matherr
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

void _set_errno_from_matherr(int param_1)

{
  __acrt_ptd *p_Var1;
  
  if (param_1 == 1) {
    p_Var1 = FUN_140006ee4();
    *(undefined4 *)p_Var1 = 0x21;
  }
  else if (param_1 - 2U < 2) {
    p_Var1 = FUN_140006ee4();
    *(undefined4 *)p_Var1 = 0x22;
  }
  return;
}



/*****************************************************************************
 * Function: _clrfp
 * Address: 14000d2b8
 * Size: 29 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _clrfp
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

uint _clrfp(void)

{
  uint uVar1;
  
  uVar1 = _get_fpsr();
  _fclrf();
  return uVar1 & 0x3f;
}



/*****************************************************************************
 * Function: _ctrlfp
 * Address: 14000d2d8
 * Size: 99 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _ctrlfp
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

uint _ctrlfp(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = _get_fpsr();
  uVar2 = (~param_2 | 0xffff807f) & uVar1 | param_1 & param_2;
  if ((DAT_1400189f0 == '\0') || ((uVar2 & 0x40) == 0)) {
    FUN_14000cf10(uVar2 & 0xffffffbf);
  }
  else {
    FUN_14000cf10(uVar2);
  }
  return uVar1;
}



/*****************************************************************************
 * Function: _set_statfp
 * Address: 14000d354
 * Size: 31 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _set_statfp
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void _set_statfp(uint param_1)

{
  uint uVar1;
  
  uVar1 = _get_fpsr();
  FUN_14000cf10(uVar1 | param_1 & 0x3f);
  return;
}



/*****************************************************************************
 * Function: _statfp
 * Address: 14000d374
 * Size: 17 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _statfp
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

uint _statfp(void)

{
  uint uVar1;
  
  uVar1 = _get_fpsr();
  return uVar1 & 0x3f;
}



/*****************************************************************************
 * Function: _FindPESection
 * Address: 14000d390
 * Size: 68 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _FindPESection
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

PIMAGE_SECTION_HEADER __cdecl _FindPESection(PBYTE pImageBase,DWORD_PTR rva)

{
  int iVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  uint uVar3;
  
  iVar1 = *(int *)(pImageBase + 0x3c);
  uVar3 = 0;
  p_Var2 = (PIMAGE_SECTION_HEADER)
           (pImageBase +
           (ulonglong)*(ushort *)(pImageBase + (longlong)iVar1 + 0x14) + 0x18 + (longlong)iVar1);
  if (*(ushort *)(pImageBase + (longlong)iVar1 + 6) != 0) {
    do {
      if ((p_Var2->VirtualAddress <= rva) &&
         (rva < (p_Var2->Misc).PhysicalAddress + p_Var2->VirtualAddress)) {
        return p_Var2;
      }
      uVar3 = uVar3 + 1;
      p_Var2 = p_Var2 + 1;
    } while (uVar3 < *(ushort *)(pImageBase + (longlong)iVar1 + 6));
  }
  return (PIMAGE_SECTION_HEADER)0x0;
}



/*****************************************************************************
 * Function: _IsNonwritableInCurrentImage
 * Address: 14000d3e0
 * Size: 75 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _IsNonwritableInCurrentImage
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

BOOL __cdecl _IsNonwritableInCurrentImage(PBYTE pTarget)

{
  bool bVar1;
  undefined7 extraout_var;
  PIMAGE_SECTION_HEADER p_Var2;
  
  bVar1 = FUN_14000d430((short *)&IMAGE_DOS_HEADER_140000000);
  p_Var2 = (PIMAGE_SECTION_HEADER)CONCAT71(extraout_var,bVar1);
  if ((int)p_Var2 != 0) {
    p_Var2 = _FindPESection((PBYTE)&IMAGE_DOS_HEADER_140000000,(DWORD_PTR)(pTarget + -0x140000000));
    if (p_Var2 != (PIMAGE_SECTION_HEADER)0x0) {
      p_Var2 = (PIMAGE_SECTION_HEADER)(ulonglong)(~(p_Var2->Characteristics >> 0x1f) & 1);
    }
  }
  return (BOOL)p_Var2;
}



/*****************************************************************************
 * Function: FUN_14000d430
 * Address: 14000d430
 * Size: 43 bytes
 *****************************************************************************/


bool FUN_14000d430(short *param_1)

{
  if ((*param_1 == 0x5a4d) &&
     (*(int *)((longlong)*(int *)(param_1 + 0x1e) + (longlong)param_1) == 0x4550)) {
    return (short)((int *)((longlong)*(int *)(param_1 + 0x1e) + (longlong)param_1))[6] == 0x20b;
  }
  return false;
}



/*****************************************************************************
 * Function: FUN_14000d45c
 * Address: 14000d45c
 * Size: 43 bytes
 *****************************************************************************/


undefined8 * FUN_14000d45c(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = type_info::vftable;
  if ((param_2 & 1) != 0) {
    thunk_FUN_140005f9c(param_1);
  }
  return param_1;
}



/*****************************************************************************
 * Function: FUN_14000d520
 * Address: 14000d520
 * Size: 30 bytes
 *****************************************************************************/


void FUN_14000d520(longlong param_1)

{
  if ((param_1 == DAT_140018038) && ((short)((ulonglong)param_1 >> 0x30) == 0)) {
    return;
  }
  FUN_14000d57c();
  return;
}



/*****************************************************************************
 * Function: thunk_FUN_140005f9c
 * Address: 14000d540
 * Size: 5 bytes
 *****************************************************************************/


void thunk_FUN_140005f9c(LPVOID param_1)

{
  FUN_140006f7c(param_1);
  return;
}



/*****************************************************************************
 * Function: FUN_14000d57c
 * Address: 14000d57c
 * Size: 210 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14000d57c(void)

{
  code *pcVar1;
  BOOL BVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
  puVar3 = auStack_38;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(2);
    puVar3 = auStack_30;
  }
  *(undefined8 *)(puVar3 + -8) = 0x14000d5a7;
  capture_previous_context((PCONTEXT)&DAT_140019840);
  _DAT_1400197b0 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_1400198d8 = puVar3 + 0x40;
  _DAT_1400198c0 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_1400197a0 = 0xc0000409;
  _DAT_1400197a4 = 1;
  _DAT_1400197b8 = 1;
  DAT_1400197c0 = 2;
  *(undefined8 *)(puVar3 + 0x20) = DAT_140018038;
  *(undefined8 *)(puVar3 + 0x28) = DAT_140018030;
  *(undefined8 *)(puVar3 + -8) = 0x14000d649;
  DAT_140019938 = _DAT_1400197b0;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_1400157c0);
  return;
}



/*****************************************************************************
 * Function: capture_previous_context
 * Address: 14000d650
 * Size: 113 bytes
 *****************************************************************************/


/* Library Function - Single Match
    capture_previous_context
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void capture_previous_context(PCONTEXT param_1)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  int iVar1;
  DWORD64 local_res8;
  ulonglong local_res10;
  PVOID local_res18 [2];
  
  RtlCaptureContext();
  ControlPc = param_1->Rip;
  iVar1 = 0;
  do {
    FunctionEntry = RtlLookupFunctionEntry(ControlPc,&local_res8,(PUNWIND_HISTORY_TABLE)0x0);
    if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
      return;
    }
    RtlVirtualUnwind(0,local_res8,ControlPc,FunctionEntry,param_1,local_res18,&local_res10,
                     (PKNONVOLATILE_CONTEXT_POINTERS)0x0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return;
}



/*****************************************************************************
 * Function: FID_conflict:__GSHandlerCheck_EH
 * Address: 14000d730
 * Size: 127 bytes
 *****************************************************************************/


/* Library Function - Multiple Matches With Different Base Names
    __GSHandlerCheck_EH
    __GSHandlerCheck_EH4
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void FID_conflict___GSHandlerCheck_EH
               (EHExceptionRecord *param_1,ulonglong param_2,_CONTEXT *param_3,
               _xDISPATCHER_CONTEXT *param_4)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_4 + 0x38);
  __GSHandlerCheckCommon(param_2,(longlong)param_4,(uint *)(lVar1 + 4));
  if ((*(uint *)(lVar1 + 4) & ((*(uint *)(param_1 + 4) & 0x66) != 0) + 1) != 0) {
    FUN_140002c84(param_1,param_2,param_3,param_4);
  }
  return;
}



/*****************************************************************************
 * Function: thunk_FUN_140005f9c
 * Address: 14000d7b0
 * Size: 5 bytes
 *****************************************************************************/


void thunk_FUN_140005f9c(LPVOID param_1)

{
  FUN_140006f7c(param_1);
  return;
}



/*****************************************************************************
 * Function: memcmp
 * Address: 14000d7d0
 * Size: 198 bytes
 *****************************************************************************/


/* Library Function - Single Match
    memcmp
   
   Library: Visual Studio */

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  bool bVar5;
  
  lVar3 = (longlong)_Buf2 - (longlong)_Buf1;
  if (7 < _Size) {
    uVar4 = (ulonglong)_Buf1 & 7;
    while (uVar4 != 0) {
                    /* WARNING: Load size is inaccurate */
      bVar5 = (byte)*_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
      if ((byte)*_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_14000d813;
      _Buf1 = (void *)((longlong)_Buf1 + 1);
      _Size = _Size - 1;
      uVar4 = (ulonglong)_Buf1 & 7;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
                    /* WARNING: Load size is inaccurate */
          uVar2 = *_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_14000d884;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_14000d880:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000d884;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14000d87c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000d880;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000d87c;
          }
          _Buf1 = (void *)((longlong)_Buf1 + 0x20);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 0x1f;
      }
      uVar4 = _Size >> 3;
      if (uVar4 != 0) {
        do {
                    /* WARNING: Load size is inaccurate */
          uVar2 = *_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) {
LAB_14000d884:
            uVar4 = *(ulonglong *)(lVar3 + (longlong)_Buf1);
            uVar1 = (uint)((uVar2 >> 0x38 | (uVar2 & 0xff000000000000) >> 0x28 |
                            (uVar2 & 0xff0000000000) >> 0x18 | (uVar2 & 0xff00000000) >> 8 |
                            (uVar2 & 0xff000000) << 8 | (uVar2 & 0xff0000) << 0x18 |
                            (uVar2 & 0xff00) << 0x28 | uVar2 << 0x38) <
                          (uVar4 >> 0x38 | (uVar4 & 0xff000000000000) >> 0x28 |
                           (uVar4 & 0xff0000000000) >> 0x18 | (uVar4 & 0xff00000000) >> 8 |
                           (uVar4 & 0xff000000) << 8 | (uVar4 & 0xff0000) << 0x18 |
                           (uVar4 & 0xff00) << 0x28 | uVar4 << 0x38));
            return (1 - uVar1) - (uint)(uVar1 != 0);
          }
          _Buf1 = (void *)((longlong)_Buf1 + 8);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 7;
      }
    }
  }
  while( true ) {
    if (_Size == 0) {
      return 0;
    }
                    /* WARNING: Load size is inaccurate */
    bVar5 = (byte)*_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
    if ((byte)*_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) break;
    _Buf1 = (void *)((longlong)_Buf1 + 1);
    _Size = _Size - 1;
  }
LAB_14000d813:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



/*****************************************************************************
 * Function: _guard_dispatch_icall
 * Address: 14000d900
 * Size: 2 bytes
 *****************************************************************************/


/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000d900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



/*****************************************************************************
 * Function: _guard_dispatch_icall
 * Address: 14000d920
 * Size: 6 bytes
 *****************************************************************************/


/* WARNING: This is an inlined function */
/* WARNING: Switch with 1 destination removed at 0x00014000d920 */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000d900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



/*****************************************************************************
 * Function: FUN_14000d930
 * Address: 14000d930
 * Size: 29 bytes
 *****************************************************************************/


void FUN_14000d930(undefined8 *param_1)

{
  FUN_140004c60(*(int *)*param_1,param_1);
  return;
}



/*****************************************************************************
 * Function: FUN_14000d94e
 * Address: 14000d94e
 * Size: 23 bytes
 *****************************************************************************/


bool FUN_14000d94e(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/*****************************************************************************
 * Function: FUN_14000d966
 * Address: 14000d966
 * Size: 149 bytes
 *****************************************************************************/


undefined4 FUN_14000d966(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  
  *(undefined8 *)(param_2 + 0x38) = param_1;
  *(undefined8 *)(param_2 + 0x30) = param_1;
  if ((((*(char *)(param_2 + 0x58) != '\0') &&
       (*(undefined8 *)(param_2 + 0x28) = **(undefined8 **)(param_2 + 0x30),
       **(int **)(param_2 + 0x28) == -0x1f928c9d)) &&
      (*(int *)(*(longlong *)(param_2 + 0x28) + 0x18) == 4)) &&
     (((*(int *)(*(longlong *)(param_2 + 0x28) + 0x20) == 0x19930520 ||
       (*(int *)(*(longlong *)(param_2 + 0x28) + 0x20) == 0x19930521)) ||
      (*(int *)(*(longlong *)(param_2 + 0x28) + 0x20) == 0x19930522)))) {
    lVar2 = __vcrt_getptd();
    *(undefined8 *)(lVar2 + 0x20) = *(undefined8 *)(param_2 + 0x28);
    uVar1 = *(undefined8 *)(*(longlong *)(param_2 + 0x30) + 8);
    lVar2 = __vcrt_getptd();
    *(undefined8 *)(lVar2 + 0x28) = uVar1;
    FUN_140005f70();
  }
  *(undefined4 *)(param_2 + 0x20) = 0;
  return *(undefined4 *)(param_2 + 0x20);
}



/*****************************************************************************
 * Function: FUN_14000d9fc
 * Address: 14000d9fc
 * Size: 162 bytes
 *****************************************************************************/


undefined8 FUN_14000d9fc(undefined8 param_1,longlong param_2)

{
  _xDISPATCHER_CONTEXT *p_Var1;
  undefined8 uVar2;
  longlong lVar3;
  
  *(undefined8 *)(param_2 + 0x50) = param_1;
  *(undefined8 *)(param_2 + 0x48) = param_1;
  lVar3 = __vcrt_getptd();
  *(undefined8 *)(lVar3 + 0x70) = *(undefined8 *)(param_2 + 0x80);
  p_Var1 = *(_xDISPATCHER_CONTEXT **)(param_2 + 0x98);
  uVar2 = *(undefined8 *)(p_Var1 + 8);
  lVar3 = __vcrt_getptd();
  *(undefined8 *)(lVar3 + 0x60) = uVar2;
  uVar2 = *(undefined8 *)(**(longlong **)(param_2 + 0x48) + 0x38);
  lVar3 = __vcrt_getptd();
  *(undefined8 *)(lVar3 + 0x68) = uVar2;
  thunk_FUN_14000408c((EHExceptionRecord *)**(undefined8 **)(param_2 + 0x48),
                      *(__uint64 **)(param_2 + 0x88),*(_CONTEXT **)(param_2 + 0x90),p_Var1,
                      *(_s_FuncInfo **)(param_2 + 0xa0),0,(__uint64 *)0x0,1);
  lVar3 = __vcrt_getptd();
  *(undefined8 *)(lVar3 + 0x70) = 0;
  *(undefined4 *)(param_2 + 0x40) = 1;
  return 1;
}



/*****************************************************************************
 * Function: FUN_14000da9f
 * Address: 14000da9f
 * Size: 36 bytes
 *****************************************************************************/


void FUN_14000da9f(_EXCEPTION_POINTERS *param_1,longlong param_2)

{
  *(_EXCEPTION_POINTERS **)(param_2 + 0x58) = param_1;
  ExFilterRethrow(param_1,*(EHExceptionRecord **)(param_2 + 0xb8),(int *)(param_2 + 0x20));
  return;
}



/*****************************************************************************
 * Function: FUN_14000dac4
 * Address: 14000dac4
 * Size: 133 bytes
 *****************************************************************************/


void FUN_14000dac4(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  
  _FindAndUnlinkFrame(*(longlong *)(param_2 + 0x38));
  if ((((*(int *)(param_2 + 0x20) == 0) &&
       (piVar1 = *(int **)(param_2 + 0xb8), *piVar1 == -0x1f928c9d)) && (piVar1[6] == 4)) &&
     (((piVar1[8] == 0x19930520 || (piVar1[8] == 0x19930521)) || (piVar1[8] == 0x19930522)))) {
    iVar3 = _IsExceptionObjectToBeDestroyed(*(longlong *)(piVar1 + 10));
    if (iVar3 != 0) {
      __DestructExceptionObject(piVar1);
    }
  }
  lVar2 = __vcrt_getptd();
  *(undefined8 *)(lVar2 + 0x20) = *(undefined8 *)(param_2 + 0xc0);
  lVar2 = __vcrt_getptd();
  *(undefined8 *)(lVar2 + 0x28) = *(undefined8 *)(param_2 + 0x40);
  return;
}



/*****************************************************************************
 * Function: FUN_14000db4a
 * Address: 14000db4a
 * Size: 21 bytes
 *****************************************************************************/


void FUN_14000db4a(undefined8 *param_1)

{
  __FrameUnwindFilter(param_1);
  return;
}



/*****************************************************************************
 * Function: FUN_14000db60
 * Address: 14000db60
 * Size: 34 bytes
 *****************************************************************************/


void FUN_14000db60(void)

{
  longlong lVar1;
  
  lVar1 = __vcrt_getptd();
  if (0 < *(int *)(lVar1 + 0x30)) {
    lVar1 = __vcrt_getptd();
    *(int *)(lVar1 + 0x30) = *(int *)(lVar1 + 0x30) + -1;
  }
  return;
}



/*****************************************************************************
 * Function: FUN_14000db83
 * Address: 14000db83
 * Size: 25 bytes
 *****************************************************************************/


void FUN_14000db83(undefined8 param_1,longlong param_2)

{
  __acrt_unlock(**(int **)(param_2 + 0x48));
  return;
}



/*****************************************************************************
 * Function: FUN_14000db9d
 * Address: 14000db9d
 * Size: 44 bytes
 *****************************************************************************/


undefined4 FUN_14000db9d(undefined8 *param_1,longlong param_2)

{
  int iVar1;
  
  *(undefined8 **)(param_2 + 0x28) = param_1;
  iVar1 = *(int *)*param_1;
  *(int *)(param_2 + 0x24) = iVar1;
  *(uint *)(param_2 + 0x20) = (uint)(iVar1 == -0x1f928c9d);
  return *(undefined4 *)(param_2 + 0x20);
}



/*****************************************************************************
 * Function: FUN_14000dbca
 * Address: 14000dbca
 * Size: 25 bytes
 *****************************************************************************/


void FUN_14000dbca(undefined8 param_1,longlong param_2)

{
  __acrt_unlock(**(int **)(param_2 + 0x58));
  return;
}



/*****************************************************************************
 * Function: FUN_14000dbe4
 * Address: 14000dbe4
 * Size: 25 bytes
 *****************************************************************************/


void FUN_14000dbe4(undefined8 param_1,longlong param_2)

{
  __acrt_unlock(**(int **)(param_2 + 0x68));
  return;
}



/*****************************************************************************
 * Function: FUN_14000dbfe
 * Address: 14000dbfe
 * Size: 24 bytes
 *****************************************************************************/


void FUN_14000dbfe(void)

{
  __acrt_unlock(5);
  return;
}



/*****************************************************************************
 * Function: FUN_14000dc17
 * Address: 14000dc17
 * Size: 24 bytes
 *****************************************************************************/


void FUN_14000dc17(void)

{
  __acrt_unlock(7);
  return;
}



/*****************************************************************************
 * Function: FUN_14000dc30
 * Address: 14000dc30
 * Size: 24 bytes
 *****************************************************************************/


void FUN_14000dc30(void)

{
  __acrt_unlock(4);
  return;
}



/*****************************************************************************
 * Function: FUN_14000dc49
 * Address: 14000dc49
 * Size: 21 bytes
 *****************************************************************************/


void FUN_14000dc49(void)

{
  __acrt_unlock(0);
  return;
}



/*****************************************************************************
 * Function: FUN_14000dc5f
 * Address: 14000dc5f
 * Size: 32 bytes
 *****************************************************************************/


void FUN_14000dc5f(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x70) != '\0') {
    __acrt_unlock(3);
  }
  return;
}



/*****************************************************************************
 * Function: FUN_14000dc80
 * Address: 14000dc80
 * Size: 26 bytes
 *****************************************************************************/


void FUN_14000dc80(undefined8 param_1,longlong param_2)

{
  FUN_14000a0ec(**(longlong **)(param_2 + 0x48));
  return;
}



/*****************************************************************************
 * Function: FUN_14000dc9b
 * Address: 14000dc9b
 * Size: 28 bytes
 *****************************************************************************/


void FUN_14000dc9b(undefined8 param_1,longlong param_2)

{
  __acrt_unlock(**(int **)(param_2 + 0x98));
  return;
}



/*****************************************************************************
 * Function: FUN_14000dcb8
 * Address: 14000dcb8
 * Size: 25 bytes
 *****************************************************************************/


void FUN_14000dcb8(undefined8 param_1,longlong param_2)

{
  FUN_1400085ac(**(uint **)(param_2 + 0x48));
  return;
}



/*****************************************************************************
 * Function: FUN_14000dcd2
 * Address: 14000dcd2
 * Size: 22 bytes
 *****************************************************************************/


void FUN_14000dcd2(undefined8 param_1,longlong param_2)

{
  FUN_1400085ac(*(uint *)(param_2 + 0x60));
  return;
}



/*****************************************************************************
 * Function: FUN_14000dce9
 * Address: 14000dce9
 * Size: 24 bytes
 *****************************************************************************/


void FUN_14000dce9(void)

{
  __acrt_unlock(8);
  return;
}



/*****************************************************************************
 * Function: FUN_14000dd02
 * Address: 14000dd02
 * Size: 23 bytes
 *****************************************************************************/


void FUN_14000dd02(undefined8 param_1,longlong param_2)

{
  FUN_14000a0ec(*(longlong *)(param_2 + 0x40));
  return;
}



/*****************************************************************************
 * Function: FUN_14000dd1a
 * Address: 14000dd1a
 * Size: 43 bytes
 *****************************************************************************/


undefined8 FUN_14000dd1a(undefined8 *param_1)

{
  undefined8 uVar1;
  
  if ((*(int *)*param_1 == -0x3ffffffb) || (*(int *)*param_1 == -0x3fffffe3)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/*****************************************************************************
 * Function: FUN_14000dd50
 * Address: 14000dd50
 * Size: 31 bytes
 *****************************************************************************/


bool FUN_14000dd50(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}




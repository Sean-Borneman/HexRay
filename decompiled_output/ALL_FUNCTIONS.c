/*==============================================================================
 * CONSOLIDATED DECOMPILED FUNCTIONS
 * Program: 897112063a58763673cf896cdcfccf1f
 * Generated: Sat Sep 13 10:46:35 CDT 2025
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************************
 * Function: FUN_140001010
 * Address: 140001010
 * Size: 129 bytes
 *****************************************************************************/


void FUN_140001010(undefined8 param_1,int param_2,byte param_3,undefined8 param_4,undefined8 param_5
                  ,undefined8 param_6,int *param_7)

{
  int iVar1;
  
  if (param_7 != (int *)0x0) {
    if (param_2 == 0) {
      *param_7 = 0;
    }
    else if (param_2 == 1) {
      if (param_3 == 0) {
        iVar1 = 0x100;
      }
      else {
        iVar1 = param_3 + 1;
      }
      *param_7 = iVar1;
      *(undefined8 *)(param_7 + 4) = param_4;
      *(undefined8 *)(param_7 + 6) = param_5;
    }
    if (*(longlong *)(param_7 + 10) != 0) {
      (*(code *)PTR__guard_dispatch_icall_1400022a8)(param_1);
    }
  }
  return;
}



/*****************************************************************************
 * Function: _tlgWriteTransfer_EtwWriteTransfer
 * Address: 140001098
 * Size: 148 bytes
 *****************************************************************************/


/* Library Function - Single Match
    _tlgWriteTransfer_EtwWriteTransfer
   
   Library: Visual Studio 2019 Release */

void _tlgWriteTransfer_EtwWriteTransfer
               (longlong param_1,byte *param_2,LPCGUID param_3,LPCGUID param_4,ULONG param_5,
               PEVENT_DATA_DESCRIPTOR param_6)

{
  EVENT_DESCRIPTOR local_18;
  
  local_18._0_4_ = (uint)*param_2 << 0x18;
  local_18._4_4_ = ZEXT24(*(ushort *)(param_2 + 1));
  local_18.Keyword = *(ULONGLONG *)(param_2 + 3);
  param_6->Ptr = *(ULONGLONG *)(param_1 + 8);
  param_6->Size = (uint)**(ushort **)(param_1 + 8);
  param_6->Reserved = 2;
  param_6[1].Ptr = (ULONGLONG)(param_2 + 0xb);
  param_6[1].Size = (uint)*(ushort *)(param_2 + 0xb);
  param_6[1].Reserved = 1;
  EventWriteTransfer(*(REGHANDLE *)(param_1 + 0x20),&local_18,param_3,param_4,param_5,param_6);
  return;
}



/*****************************************************************************
 * Function: FUN_140001390
 * Address: 140001390
 * Size: 211 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140001390(void)

{
  int iVar1;
  longlong lVar2;
  
  if ((IMAGE_DOS_HEADER_140000000.e_magic == (char  [2])0x5a4d) &&
     (lVar2 = (longlong)(int)IMAGE_DOS_HEADER_140000000.e_lfanew,
     *(int *)(IMAGE_DOS_HEADER_140000000.e_magic + lVar2) == 0x4550)) {
    if (*(short *)((longlong)IMAGE_DOS_HEADER_140000000.e_res_4_ + lVar2 + -4) == 0x10b) {
      DAT_1400035f0 = 0;
      if (*(uint *)(IMAGE_DOS_HEADER_140000000.e_program + lVar2 + 0x34) < 0xf) goto LAB_1400013f9;
      iVar1 = *(int *)(&UNK_1400000e8 + lVar2);
    }
    else {
      if (*(short *)((longlong)IMAGE_DOS_HEADER_140000000.e_res_4_ + lVar2 + -4) != 0x20b)
      goto LAB_1400013a2;
      DAT_1400035f0 = 0;
      if (*(uint *)(&UNK_140000080.field_0x4 + lVar2) < 0xf) goto LAB_1400013f9;
      iVar1 = *(int *)(IMAGE_NT_HEADERS64_1400000f8.Signature + lVar2);
    }
    DAT_1400035f0 = (uint)(iVar1 != 0);
  }
  else {
LAB_1400013a2:
    DAT_1400035f0 = 0;
  }
LAB_1400013f9:
  iVar1 = FUN_140001848(2);
  __set_app_type(iVar1);
  _DAT_140003610 = 0xffffffffffffffff;
  _DAT_140003618 = 0xffffffffffffffff;
  *(undefined4 *)_fmode_exref = DAT_140003604;
  *(undefined4 *)_commode_exref = DAT_1400035f8;
  FUN_1400018a0();
  if (DAT_140003050 == 0) {
    __setusermatherr(FUN_1400019a0);
  }
  return 0;
}



/*****************************************************************************
 * Function: FUN_140001470
 * Address: 140001470
 * Size: 73 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140001470(void)

{
  _DAT_1400035f4 = DAT_140003600;
  _DAT_1400035dc =
       __wgetmainargs(&DAT_1400035d8,&DAT_1400035e0,&DAT_1400035e8,DAT_1400035fc,&DAT_1400035f4);
  return;
}



/*****************************************************************************
 * Function: FUN_1400014c0
 * Address: 1400014c0
 * Size: 588 bytes
 *****************************************************************************/


ulonglong FUN_1400014c0(void)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  longlong lVar4;
  ushort uVar5;
  int iVar6;
  BOOL BVar7;
  longlong lVar8;
  ulonglong uVar9;
  ushort *puVar10;
  longlong *plVar11;
  bool bVar12;
  _STARTUPINFOW local_78;
  
  iVar6 = 0;
  bVar2 = false;
  bVar3 = false;
  GetStartupInfoW(&local_78);
  lVar1 = *(longlong *)((longlong)Self + 8);
  while( true ) {
    lVar8 = 0;
    LOCK();
    bVar12 = DAT_140003620 == 0;
    lVar4 = lVar1;
    if (!bVar12) {
      lVar8 = DAT_140003620;
      lVar4 = DAT_140003620;
    }
    DAT_140003620 = lVar4;
    UNLOCK();
    if (bVar12) goto LAB_14000152c;
    if (lVar8 == lVar1) break;
    Sleep(1000);
  }
  bVar2 = true;
LAB_14000152c:
  if (DAT_140003628 == 1) {
    _amsg_exit(0x1f);
  }
  else if (DAT_140003628 == 0) {
    DAT_140003628 = 1;
    for (plVar11 = &DAT_1400022d8; plVar11 < &DAT_1400022f0; plVar11 = plVar11 + 1) {
      if (iVar6 != 0) {
        return 0xff;
      }
      if (*plVar11 != 0) {
        iVar6 = (*(code *)PTR__guard_dispatch_icall_1400022a8)();
      }
    }
    if (iVar6 != 0) {
      return 0xff;
    }
  }
  else {
    DAT_1400035d4 = 1;
  }
  if (DAT_140003628 == 1) {
    _initterm(&DAT_1400022c0,&DAT_1400022d0);
    DAT_140003628 = 2;
  }
  if (!bVar2) {
    LOCK();
    DAT_140003620 = 0;
    UNLOCK();
  }
  if ((DAT_140003630 != 0) &&
     (BVar7 = _IsNonwritableInCurrentImage((PBYTE)&DAT_140003630), BVar7 != 0)) {
    (*(code *)PTR__guard_dispatch_icall_1400022a8)(0,2);
  }
  puVar10 = *(ushort **)_wcmdln_exref;
  if (puVar10 == (ushort *)0x0) {
    uVar9 = 0xff;
  }
  else {
    while ((uVar5 = *puVar10, 0x20 < uVar5 || ((uVar5 != 0 && (bVar3))))) {
      if (uVar5 == 0x22) {
        bVar3 = !bVar3;
      }
      puVar10 = puVar10 + 1;
    }
    while ((ushort)(uVar5 - 1) < 0x20) {
      puVar10 = puVar10 + 1;
      uVar5 = *puVar10;
    }
    uVar9 = FUN_1400019f4();
    DAT_1400035d0 = (uint)uVar9;
    if (DAT_1400035f0 == 0) {
                    /* WARNING: Subroutine does not return */
      exit(DAT_1400035d0);
    }
    if (DAT_1400035d4 == 0) {
      _cexit();
      uVar9 = (ulonglong)DAT_1400035d0;
    }
  }
  return uVar9;
}



/*****************************************************************************
 * Function: entry
 * Address: 140001750
 * Size: 18 bytes
 *****************************************************************************/


void entry(void)

{
  __security_init_cookie();
  FUN_1400014c0();
  return;
}



/*****************************************************************************
 * Function: FUN_140001770
 * Address: 140001770
 * Size: 57 bytes
 *****************************************************************************/


undefined8 FUN_140001770(undefined8 *param_1)

{
  int *piVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[6] == 4)) &&
     ((piVar1[8] + 0xe66cfae0U < 3 || (piVar1[8] == 0x1994000)))) {
    terminate();
    pcVar2 = (code *)swi(3);
    uVar3 = (*pcVar2)();
    return uVar3;
  }
  return 0;
}



/*****************************************************************************
 * Function: FUN_1400017c0
 * Address: 1400017c0
 * Size: 24 bytes
 *****************************************************************************/


undefined8 FUN_1400017c0(void)

{
  SetUnhandledExceptionFilter(FUN_140001770);
  return 0;
}



/*****************************************************************************
 * Function: _XcptFilter
 * Address: 1400017de
 * Size: 6 bytes
 *****************************************************************************/


int __cdecl _XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400017de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _XcptFilter(_ExceptionNum,_ExceptionPtr);
  return iVar1;
}



/*****************************************************************************
 * Function: FUN_1400017ec
 * Address: 1400017ec
 * Size: 78 bytes
 *****************************************************************************/


int * FUN_1400017ec(short *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)0x0;
  piVar2 = piVar1;
  if (((((longlong)param_1 - 1U < 0xfffffffffffffffe) && (*param_1 == 0x5a4d)) &&
      (-1 < *(int *)(param_1 + 0x1e))) &&
     ((*(uint *)(param_1 + 0x1e) < 0x10000000 &&
      (piVar2 = (int *)((longlong)*(int *)(param_1 + 0x1e) + (longlong)param_1),
      *(int *)((longlong)*(int *)(param_1 + 0x1e) + (longlong)param_1) != 0x4550)))) {
    piVar2 = piVar1;
  }
  return piVar2;
}



/*****************************************************************************
 * Function: FUN_140001848
 * Address: 140001848
 * Size: 70 bytes
 *****************************************************************************/


undefined4 FUN_140001848(undefined4 param_1)

{
  HMODULE pHVar1;
  int *piVar2;
  
  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  if ((pHVar1 != (HMODULE)0x0) && (piVar2 = FUN_1400017ec((short *)pHVar1), piVar2 != (int *)0x0)) {
    if ((short)piVar2[0x17] == 2) {
      param_1 = 2;
    }
    else if ((short)piVar2[0x17] == 3) {
      param_1 = 1;
    }
  }
  return param_1;
}



/*****************************************************************************
 * Function: _amsg_exit
 * Address: 140001894
 * Size: 6 bytes
 *****************************************************************************/


void __cdecl _amsg_exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000140001894. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _amsg_exit(param_1);
  return;
}



/*****************************************************************************
 * Function: FUN_1400018a0
 * Address: 1400018a0
 * Size: 3 bytes
 *****************************************************************************/


undefined8 FUN_1400018a0(void)

{
  return 0;
}



/*****************************************************************************
 * Function: _FindPESection
 * Address: 1400018b0
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
 * Address: 140001900
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
  
  bVar1 = FUN_140001960((short *)&IMAGE_DOS_HEADER_140000000);
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
 * Function: FUN_140001960
 * Address: 140001960
 * Size: 43 bytes
 *****************************************************************************/


bool FUN_140001960(short *param_1)

{
  if ((*param_1 == 0x5a4d) &&
     (*(int *)((longlong)*(int *)(param_1 + 0x1e) + (longlong)param_1) == 0x4550)) {
    return (short)((int *)((longlong)*(int *)(param_1 + 0x1e) + (longlong)param_1))[6] == 0x20b;
  }
  return false;
}



/*****************************************************************************
 * Function: FUN_1400019a0
 * Address: 1400019a0
 * Size: 3 bytes
 *****************************************************************************/


undefined8 FUN_1400019a0(void)

{
  return 0;
}



/*****************************************************************************
 * Function: _initterm
 * Address: 1400019a9
 * Size: 6 bytes
 *****************************************************************************/


void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400019a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}



/*****************************************************************************
 * Function: _guard_check_icall
 * Address: 1400019d0
 * Size: 3 bytes
 *****************************************************************************/


void _guard_check_icall(void)

{
  return;
}



/*****************************************************************************
 * Function: FUN_1400019f4
 * Address: 1400019f4
 * Size: 320 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400019f4(void)

{
  code *pcVar1;
  ULONG UVar2;
  undefined1 *puVar3;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [40];
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  ulonglong local_18;
  
  puVar3 = auStack_88;
  local_18 = DAT_140003040 ^ (ulonglong)auStack_88;
  local_58 = *(undefined4 *)(PTR_DAT_140003008 + -0x10);
  uStack_54 = *(undefined4 *)(PTR_DAT_140003008 + -0xc);
  uStack_50 = *(undefined4 *)(PTR_DAT_140003008 + -8);
  uStack_4c = *(undefined4 *)(PTR_DAT_140003008 + -4);
  if (DAT_140003020 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
    puVar3 = auStack_80;
  }
  _DAT_140003028 = 0;
  uRam0000000140003030 = 0;
  *(undefined8 *)(puVar3 + -8) = 0x140001a58;
  UVar2 = EventRegister((LPCGUID)(puVar3 + 0x30),FUN_140001010,&DAT_140003000,
                        (PREGHANDLE)&DAT_140003020);
  if (UVar2 == 0) {
    *(undefined8 *)(puVar3 + -8) = 0x140001a7d;
    EventSetInformation(DAT_140003020,2);
  }
  if (((5 < DAT_140003000) && ((_DAT_140003010 & 0x2000000000000) != 0)) &&
     ((DAT_140003018 & 0x2000000000000) == DAT_140003018)) {
    *(undefined4 *)(puVar3 + 0x6c) = 0;
    *(char **)(puVar3 + 0x60) = "CalculatorStarted";
    *(undefined4 *)(puVar3 + 0x68) = 0x12;
    *(undefined1 **)(puVar3 + 0x28) = puVar3 + 0x40;
    *(undefined4 *)(puVar3 + 0x20) = 3;
    *(undefined8 *)(puVar3 + -8) = 0x140001af5;
    _tlgWriteTransfer_EtwWriteTransfer
              (0x140003000,&DAT_140002489,(LPCGUID)0x0,(LPCGUID)0x0,*(ULONG *)(puVar3 + 0x20),
               *(PEVENT_DATA_DESCRIPTOR *)(puVar3 + 0x28));
  }
  *(undefined4 *)(puVar3 + 0x28) = 1;
  *(undefined8 *)(puVar3 + 0x20) = 0;
  *(undefined8 *)(puVar3 + -8) = 0x140001b18;
  ShellExecuteW((HWND)0x0,(LPCWSTR)0x0,L"ms-calculator:",(LPCWSTR)0x0,*(LPCWSTR *)(puVar3 + 0x20),
                *(INT *)(puVar3 + 0x28));
  *(undefined8 *)(puVar3 + -8) = 0x140001b2c;
  __security_check_cookie(*(ulonglong *)(puVar3 + 0x70) ^ (ulonglong)puVar3);
  return;
}



/*****************************************************************************
 * Function: _guard_dispatch_icall
 * Address: 140001bd0
 * Size: 2 bytes
 *****************************************************************************/


/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140001bd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



/*****************************************************************************
 * Function: _guard_dispatch_icall
 * Address: 140001bf0
 * Size: 6 bytes
 *****************************************************************************/


/* WARNING: This is an inlined function */
/* WARNING: Switch with 1 destination removed at 0x000140001bf0 */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140001bd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



/*****************************************************************************
 * Function: FUN_140001c00
 * Address: 140001c00
 * Size: 29 bytes
 *****************************************************************************/


void FUN_140001c00(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/*****************************************************************************
 * Function: FUN_140001c30
 * Address: 140001c30
 * Size: 31 bytes
 *****************************************************************************/


bool FUN_140001c30(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}




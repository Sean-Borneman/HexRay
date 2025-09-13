/*==============================================================================
 * CONSOLIDATED DECOMPILED FUNCTIONS
 * Program: 22b0596355c0eca90a15627353ae66af
 * Generated: Sat Sep 13 11:28:33 EDT 2025
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************************
 * Function: FUN_004015a0
 * Address: 004015a0
 * Size: 125 bytes
 *****************************************************************************/


void FUN_004015a0(undefined4 param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,
                 int param_7,undefined4 param_8,int *param_9)

{
  code *pcVar1;
  int iVar2;
  
  if (param_9 != (int *)0x0) {
    if (param_2 == 0) {
      *param_9 = 0;
    }
    else if (param_2 == 1) {
      param_9[5] = param_7;
      iVar2 = 0x100;
      if ((char)param_3 != '\0') {
        iVar2 = (param_3 & 0xff) + 1;
      }
      *param_9 = iVar2;
      param_9[2] = param_4;
      param_9[3] = param_5;
      param_9[4] = param_6;
    }
    pcVar1 = (code *)param_9[8];
    if (pcVar1 != (code *)0x0) {
      (*(code *)PTR_guard_check_icall_00404098)
                (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9[9]);
      (*pcVar1)();
    }
  }
  return;
}



/*****************************************************************************
 * Function: FUN_00401623
 * Address: 00401623
 * Size: 166 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401623(void)

{
  code *pcVar1;
  ULONG UVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar3;
  GUID local_1c;
  uint local_c;
  
  local_c = DAT_00403028 ^ (uint)&stack0xfffffffc;
  local_1c.Data1 = *(ulong *)(PTR_DAT_00403004 + -0x10);
  local_1c._4_4_ = *(undefined4 *)(PTR_DAT_00403004 + -0xc);
  local_1c.Data4._0_4_ = *(undefined4 *)(PTR_DAT_00403004 + -8);
  local_1c.Data4._4_4_ = *(undefined4 *)(PTR_DAT_00403004 + -4);
  if (DAT_00403018 != 0 || DAT_0040301c != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  _DAT_00403020 = 0;
  _DAT_00403024 = 0;
  UVar2 = EventRegister(&local_1c,FUN_004015a0,&DAT_00403000,(PREGHANDLE)&DAT_00403018);
  uVar3 = extraout_EDX;
  if (UVar2 == 0) {
    EventSetInformation(DAT_00403018,DAT_0040301c,2,PTR_DAT_00403004,*(undefined2 *)PTR_DAT_00403004
                       );
    uVar3 = extraout_EDX_00;
  }
  FUN_00401810(local_c ^ (uint)&stack0xfffffffc,uVar3);
  return;
}



/*****************************************************************************
 * Function: FUN_004016cf
 * Address: 004016cf
 * Size: 143 bytes
 *****************************************************************************/


void FUN_004016cf(int param_1,byte *param_2,LPCGUID param_3,LPCGUID param_4,ULONG param_5,
                 PEVENT_DATA_DESCRIPTOR param_6)

{
  ushort uVar1;
  undefined4 uVar2;
  EVENT_DESCRIPTOR local_18;
  undefined4 local_8;
  
  local_18.Keyword._4_4_ = *(undefined4 *)(param_2 + 7);
  local_18._0_4_ = (uint)*param_2 << 0x18;
  local_18._4_4_ = ZEXT24(*(ushort *)(param_2 + 1));
  local_18.Keyword._0_4_ = *(undefined4 *)(param_2 + 3);
  uVar2 = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)&param_6->Ptr + 4) = 0;
  *(undefined4 *)&param_6->Ptr = uVar2;
  uVar1 = **(ushort **)(param_1 + 4);
  *(undefined4 *)((int)&param_6[1].Ptr + 4) = 0;
  param_6->Size = (uint)uVar1;
  param_6->Reserved = 2;
  *(byte **)&param_6[1].Ptr = param_2 + 0xb;
  param_6[1].Size = (uint)*(ushort *)(param_2 + 0xb);
  param_6[1].Reserved = 1;
  local_8 = 0x80;
  EventWriteTransfer(*(REGHANDLE *)(param_1 + 0x18),&local_18,param_3,param_4,param_5,param_6);
  return;
}



/*****************************************************************************
 * Function: FUN_0040176d
 * Address: 0040176d
 * Size: 154 bytes
 *****************************************************************************/


void FUN_0040176d(void)

{
  undefined4 extraout_EDX;
  _EVENT_DATA_DESCRIPTOR local_3c [2];
  char *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_8;
  
  local_8 = DAT_00403028 ^ (uint)&stack0xfffffffc;
  FUN_00401623();
  if ((5 < DAT_00403000) && ((DAT_0040300c & 0x20000) != 0)) {
    if ((DAT_00403010 == 0) && ((DAT_00403014 & 0x20000) == DAT_00403014)) {
      local_1c = "CalculatorStarted";
      local_18 = 0;
      local_14 = 0x12;
      local_10 = 0;
      FUN_004016cf(0x403000,&DAT_00401259,(LPCGUID)0x0,(LPCGUID)0x0,3,local_3c);
    }
  }
  ShellExecuteW((HWND)0x0,(LPCWSTR)0x0,L"ms-calculator:",(LPCWSTR)0x0,(LPCWSTR)0x0,1);
  FUN_00401810(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX);
  return;
}



/*****************************************************************************
 * Function: FUN_00401810
 * Address: 00401810
 * Size: 279 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00401810(int param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  HANDLE hProcess;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined4 unaff_retaddr;
  UINT uExitCode;
  undefined4 auStack_328 [199];
  undefined4 local_c;
  int local_8;
  
  if (param_1 == DAT_00403028) {
    return;
  }
  _DAT_00403150 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x324) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)auStack_328 < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x328) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)auStack_328 & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x324) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_00403090 = 0x10001;
  _DAT_00403154 = &stack0x00000004;
  _DAT_00403040 = 0xc0000409;
  _DAT_00403044 = 1;
  _DAT_00403050 = 1;
  DAT_00403054 = 2;
  local_8 = DAT_00403028;
  local_c = DAT_0040302c;
  _DAT_0040304c = unaff_retaddr;
  _DAT_0040311c = in_GS;
  _DAT_00403120 = in_FS;
  _DAT_00403124 = in_ES;
  _DAT_00403128 = in_DS;
  _DAT_0040312c = unaff_EDI;
  _DAT_00403130 = unaff_ESI;
  _DAT_00403134 = unaff_EBX;
  _DAT_00403138 = param_2;
  _DAT_0040313c = param_1;
  _DAT_00403140 = in_EAX;
  _DAT_00403144 = unaff_EBP;
  DAT_00403148 = unaff_retaddr;
  _DAT_0040314c = in_CS;
  _DAT_00403158 = in_SS;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_00401000);
  auStack_328[0] = 1;
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



/*****************************************************************************
 * Function: FUN_00401933
 * Address: 00401933
 * Size: 131 bytes
 *****************************************************************************/


void FUN_00401933(void)

{
  DWORD DVar1;
  _FILETIME local_18;
  LARGE_INTEGER local_10;
  uint local_8;
  
  local_10.QuadPart = 0.0;
  if ((DAT_00403028 == 0) || (DAT_00403028 == 0xbb40e64e)) {
    GetSystemTimeAsFileTime(&local_18);
    local_8 = local_18.dwHighDateTime ^ local_18.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    local_8 = local_8 ^ DVar1;
    DVar1 = GetCurrentThreadId();
    local_8 = local_8 ^ DVar1;
    DVar1 = GetTickCount();
    local_8 = DVar1 ^ local_8 ^ (uint)&local_8;
    QueryPerformanceCounter(&local_10);
    local_8 = local_10.s.HighPart ^ local_10.s.LowPart ^ local_8;
    DAT_00403028 = 0xbb40e64e;
    if (local_8 != 0) {
      DAT_00403028 = local_8;
    }
  }
  DAT_0040302c = ~DAT_00403028;
  return;
}



/*****************************************************************************
 * Function: FUN_004019c0
 * Address: 004019c0
 * Size: 102 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004019c0(void)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 *puVar3;
  
  bVar1 = FUN_00401c80();
  DAT_00403374 = CONCAT31(extraout_var,bVar1);
  iVar2 = FUN_00401de4(2);
  __set_app_type(iVar2);
  _DAT_00403390 = 0xffffffff;
  _DAT_00403394 = 0xffffffff;
  puVar3 = (undefined4 *)__p__fmode();
  *puVar3 = DAT_00403388;
  puVar3 = (undefined4 *)__p__commode();
  *puVar3 = DAT_0040337c;
  FUN_00401e40();
  if (DAT_00403030 == 0) {
    __setusermatherr(FUN_00401e40);
  }
  FUN_00401fa9();
  return 0;
}



/*****************************************************************************
 * Function: FUN_00401a30
 * Address: 00401a30
 * Size: 51 bytes
 *****************************************************************************/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401a30(void)

{
  _DAT_00403378 = DAT_00403384;
  _DAT_00403370 =
       __wgetmainargs((int *)&DAT_00403364,(wchar_t ***)&DAT_00403368,(wchar_t ***)&DAT_0040336c,
                      DAT_00403380,(_startupinfo *)&DAT_00403378);
  return;
}



/*****************************************************************************
 * Function: FUN_00401a69
 * Address: 00401a69
 * Size: 427 bytes
 *****************************************************************************/


/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

int FUN_00401a69(void)

{
  bool bVar1;
  code *pcVar2;
  int iVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  BOOL BVar7;
  uint uVar8;
  _STARTUPINFOW local_6c;
  ushort *local_24;
  uint local_20;
  void *local_14;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00402078;
  uStack_c = 0x401a75;
  local_20 = 0;
  GetStartupInfoW(&local_6c);
  local_8 = (undefined *)0x0;
  iVar6 = *(int *)((int)Self + 4);
  bVar1 = false;
  while( true ) {
    iVar5 = 0;
    LOCK();
    iVar3 = iVar6;
    if (DAT_00403398 != 0) {
      iVar5 = DAT_00403398;
      iVar3 = DAT_00403398;
    }
    DAT_00403398 = iVar3;
    UNLOCK();
    if (iVar5 == 0) goto LAB_00401abe;
    if (iVar5 == iVar6) break;
    Sleep(1000);
  }
  bVar1 = true;
LAB_00401abe:
  if (DAT_0040339c == 1) {
    _amsg_exit(0x1f);
  }
  else if (DAT_0040339c == 0) {
    DAT_0040339c = 1;
    iVar6 = FUN_00401c49((undefined4 *)&DAT_004010d4,(undefined4 *)&DAT_004010e0);
    if (iVar6 != 0) {
      ExceptionList = local_14;
      return 0xff;
    }
  }
  else {
    DAT_00403360 = 1;
  }
  if (DAT_0040339c == 1) {
    initterm(&DAT_004010c8,&DAT_004010d0);
    DAT_0040339c = 2;
  }
  if (!bVar1) {
    LOCK();
    DAT_00403398 = 0;
    UNLOCK();
  }
  if ((DAT_004033a0 != (code *)0x0) &&
     (BVar7 = __IsNonwritableInCurrentImage((PBYTE)&DAT_004033a0), pcVar2 = DAT_004033a0, BVar7 != 0
     )) {
    (*(code *)PTR_guard_check_icall_00404098)(0,2,0);
    (*pcVar2)();
  }
  local_24 = *(ushort **)_wcmdln_exref;
  uVar8 = local_20;
  if (local_24 == (ushort *)0x0) {
    ExceptionList = local_14;
    return 0xff;
  }
  do {
    uVar4 = *local_24;
    if (uVar4 < 0x21) {
      if (uVar4 == 0) goto LAB_00401ba0;
      if (uVar8 == 0) {
        while ((uVar4 != 0 && (uVar4 < 0x21))) {
          local_24 = local_24 + 1;
          uVar4 = *local_24;
        }
LAB_00401ba0:
        DAT_0040335c = FUN_0040176d();
        if (DAT_00403374 == 0) {
                    /* WARNING: Subroutine does not return */
          exit(DAT_0040335c);
        }
        if (DAT_00403360 == 0) {
          _cexit();
          ExceptionList = local_14;
          return DAT_0040335c;
        }
        ExceptionList = local_14;
        return DAT_0040335c;
      }
    }
    if (uVar4 == 0x22) {
      uVar8 = (uint)(uVar8 == 0);
      local_20 = uVar8;
    }
    local_24 = local_24 + 1;
  } while( true );
}



/*****************************************************************************
 * Function: FUN_00401c49
 * Address: 00401c49
 * Size: 49 bytes
 *****************************************************************************/


void __cdecl FUN_00401c49(undefined4 *param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 < param_2) {
    do {
      if (iVar2 != 0) {
        return;
      }
      pcVar1 = (code *)*param_1;
      if (pcVar1 != (code *)0x0) {
        (*(code *)PTR_guard_check_icall_00404098)();
        iVar2 = (*pcVar1)();
      }
      param_1 = param_1 + 1;
    } while (param_1 < param_2);
  }
  return;
}



/*****************************************************************************
 * Function: FUN_00401c80
 * Address: 00401c80
 * Size: 102 bytes
 *****************************************************************************/


bool FUN_00401c80(void)

{
  short sVar1;
  int iVar2;
  
  if ((IMAGE_DOS_HEADER_00400000.e_magic != (char  [2])0x5a4d) ||
     (*(int *)(IMAGE_DOS_HEADER_00400000.e_lfanew + 0x400000) != 0x4550)) {
    return false;
  }
  sVar1 = *(short *)((int)IMAGE_DOS_HEADER_00400000.e_res_4_ +
                    (IMAGE_DOS_HEADER_00400000.e_lfanew - 4));
  if (sVar1 == 0x10b) {
    if (*(uint *)(IMAGE_DOS_HEADER_00400000.e_program + IMAGE_DOS_HEADER_00400000.e_lfanew + 0x34) <
        0xf) {
      return false;
    }
    iVar2 = *(int *)(&UNK_004000e8 + IMAGE_DOS_HEADER_00400000.e_lfanew);
  }
  else {
    if (sVar1 != 0x20b) {
      return false;
    }
    if (*(uint *)(&UNK_00400080.field_0x4 + IMAGE_DOS_HEADER_00400000.e_lfanew) < 0xf) {
      return false;
    }
    iVar2 = *(int *)(IMAGE_NT_HEADERS32_004000f8.Signature + IMAGE_DOS_HEADER_00400000.e_lfanew);
  }
  return iVar2 != 0;
}



/*****************************************************************************
 * Function: entry
 * Address: 00401cf0
 * Size: 10 bytes
 *****************************************************************************/


void entry(void)

{
  FUN_00401933();
  FUN_00401a69();
  return;
}



/*****************************************************************************
 * Function: FUN_00401d00
 * Address: 00401d00
 * Size: 67 bytes
 *****************************************************************************/


undefined4 FUN_00401d00(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) &&
     ((iVar2 = piVar1[5], iVar2 == 0x19930520 ||
      (((iVar2 == 0x19930521 || (iVar2 == 0x19930522)) || (iVar2 == 0x1994000)))))) {
    terminate();
  }
  return 0;
}



/*****************************************************************************
 * Function: FUN_00401d50
 * Address: 00401d50
 * Size: 14 bytes
 *****************************************************************************/


undefined4 FUN_00401d50(void)

{
  SetUnhandledExceptionFilter(FUN_00401d00);
  return 0;
}



/*****************************************************************************
 * Function: _XcptFilter
 * Address: 00401d64
 * Size: 6 bytes
 *****************************************************************************/


int __cdecl _XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00401d64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _XcptFilter(_ExceptionNum,_ExceptionPtr);
  return iVar1;
}



/*****************************************************************************
 * Function: FUN_00401d70
 * Address: 00401d70
 * Size: 101 bytes
 *****************************************************************************/


/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

void FUN_00401d70(void)

{
  void *local_14;
  
  ExceptionList = local_14;
  return;
}



/*****************************************************************************
 * Function: FUN_00401de4
 * Address: 00401de4
 * Size: 60 bytes
 *****************************************************************************/


undefined4 __cdecl FUN_00401de4(undefined4 param_1)

{
  HMODULE pHVar1;
  int iVar2;
  undefined4 uVar3;
  
  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  uVar3 = param_1;
  if ((pHVar1 != (HMODULE)0x0) && (iVar2 = FUN_00401d70(), iVar2 != 0)) {
    uVar3 = 2;
    if (*(short *)(iVar2 + 0x5c) != 2) {
      if (*(short *)(iVar2 + 0x5c) == 3) {
        param_1 = 1;
      }
      return param_1;
    }
  }
  return uVar3;
}



/*****************************************************************************
 * Function: _amsg_exit
 * Address: 00401e26
 * Size: 6 bytes
 *****************************************************************************/


void __cdecl _amsg_exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00401e26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _amsg_exit(param_1);
  return;
}



/*****************************************************************************
 * Function: FUN_00401e40
 * Address: 00401e40
 * Size: 3 bytes
 *****************************************************************************/


undefined4 FUN_00401e40(void)

{
  return 0;
}



/*****************************************************************************
 * Function: FUN_00401f70
 * Address: 00401f70
 * Size: 51 bytes
 *****************************************************************************/


bool __cdecl FUN_00401f70(short *param_1)

{
  if ((*param_1 == 0x5a4d) && (*(int *)(*(int *)(param_1 + 0x1e) + (int)param_1) == 0x4550)) {
    return (short)((int *)(*(int *)(param_1 + 0x1e) + (int)param_1))[6] == 0x10b;
  }
  return false;
}



/*****************************************************************************
 * Function: FUN_00401fa9
 * Address: 00401fa9
 * Size: 19 bytes
 *****************************************************************************/


void FUN_00401fa9(void)

{
  _controlfp(0x10000,0x30000);
  return;
}



/*****************************************************************************
 * Function: initterm
 * Address: 00401fc2
 * Size: 6 bytes
 *****************************************************************************/


void __cdecl initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00401fc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  initterm();
  return;
}



/*****************************************************************************
 * Function: FUN_00402030
 * Address: 00402030
 * Size: 37 bytes
 *****************************************************************************/


void __cdecl
FUN_00402030(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_00403028,FUN_00401810,param_1,param_2,param_3,param_4);
  return;
}



/*****************************************************************************
 * Function: except_handler4_common
 * Address: 0040205b
 * Size: 6 bytes
 *****************************************************************************/


void __cdecl except_handler4_common(void)

{
                    /* WARNING: Could not recover jumptable at 0x0040205b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  except_handler4_common();
  return;
}



/*****************************************************************************
 * Function: guard_check_icall
 * Address: 00402070
 * Size: 3 bytes
 *****************************************************************************/


/* guard_check_icall */

void __cdecl guard_check_icall(void)

{
  return;
}




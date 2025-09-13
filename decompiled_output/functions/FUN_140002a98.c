// Function: FUN_140002a98
// Address: 140002a98
// Size: 259 bytes
============================================================


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


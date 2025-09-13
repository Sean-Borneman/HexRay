// Function: FUN_1400094c0
// Address: 1400094c0
// Size: 112 bytes
============================================================


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


// Function: FUN_140009530
// Address: 140009530
// Size: 236 bytes
============================================================


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


// Function: FUN_14000961c
// Address: 14000961c
// Size: 93 bytes
============================================================


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


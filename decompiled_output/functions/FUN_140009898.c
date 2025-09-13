// Function: FUN_140009898
// Address: 140009898
// Size: 57 bytes
============================================================


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


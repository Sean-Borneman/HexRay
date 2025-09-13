// Function: FUN_140001878
// Address: 140001878
// Size: 60 bytes
============================================================


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


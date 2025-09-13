// Function: FUN_14000183c
// Address: 14000183c
// Size: 60 bytes
============================================================


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


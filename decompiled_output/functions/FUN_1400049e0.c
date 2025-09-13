// Function: FUN_1400049e0
// Address: 1400049e0
// Size: 18 bytes
============================================================


char * FUN_1400049e0(longlong param_1)

{
  char *pcVar1;
  
  pcVar1 = "Unknown exception";
  if (*(longlong *)(param_1 + 8) != 0) {
    pcVar1 = *(char **)(param_1 + 8);
  }
  return pcVar1;
}


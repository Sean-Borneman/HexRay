// Function: Unwind@140001e2c
// Address: 140001e2c
// Size: 10 bytes
============================================================


void Unwind_140001e2c(void)

{
  code *pcVar1;
  
  FUN_140005f70();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


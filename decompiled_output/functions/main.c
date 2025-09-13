// Function: main
// Address: 001011c9
// Size: 588 bytes
============================================================


undefined8 main(void)

{
  int iVar1;
  size_t sVar2;
  long in_FS_OFFSET;
  int local_290;
  int local_28c;
  int local_288;
  int local_284;
  uint local_280;
  char local_278 [80];
  char acStack_228 [520];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  printf("Enter flag: ");
  __isoc99_scanf(&DAT_001021ee,local_278);
  sVar2 = strlen(local_278);
  if (sVar2 < 0x47) {
    local_290 = 0;
    local_28c = 0;
    while( true ) {
      sVar2 = strlen(local_278);
      if (sVar2 <= (ulong)(long)local_28c) break;
      local_288 = 0;
      local_284 = 0xff;
      while (iVar1 = (local_284 + local_288) / 2, iVar1 != local_278[local_28c]) {
        if (iVar1 < local_278[local_28c]) {
          acStack_228[local_290] = '>';
          local_288 = iVar1 + 1;
          local_290 = local_290 + 1;
        }
        else {
          acStack_228[local_290] = '<';
          local_284 = iVar1 + -1;
          local_290 = local_290 + 1;
        }
      }
      acStack_228[local_290] = '=';
      local_28c = local_28c + 1;
      local_290 = local_290 + 1;
    }
    if (local_290 == 0x1c0) {
      for (local_280 = 0; local_280 < 0x1c0; local_280 = local_280 + 1) {
        if (acStack_228[(int)local_280] != target[(int)local_280]) {
          puts("Nope");
          goto LAB_001013fb;
        }
      }
      puts("Correct!");
    }
    else {
      puts("Nope");
    }
  }
  else {
    puts("Nope");
  }
LAB_001013fb:
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}


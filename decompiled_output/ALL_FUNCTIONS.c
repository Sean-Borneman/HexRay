/*==============================================================================
 * CONSOLIDATED DECOMPILED FUNCTIONS
 * Program: 0033cebc0dd0e505a7b27913d015dee7
 * Generated: Sat Sep 13 01:33:39 EDT 2025
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************************
 * Function: _init
 * Address: 00101000
 * Size: 27 bytes
 *****************************************************************************/


int _init(EVP_PKEY_CTX *ctx)

{
  undefined *puVar1;
  
  puVar1 = PTR___gmon_start___00103fe8;
  if (PTR___gmon_start___00103fe8 != (undefined *)0x0) {
    puVar1 = (undefined *)(*(code *)PTR___gmon_start___00103fe8)();
  }
  return (int)puVar1;
}



/*****************************************************************************
 * Function: FUN_00101020
 * Address: 00101020
 * Size: 12 bytes
 *****************************************************************************/


void FUN_00101020(void)

{
  (*(code *)PTR_00103fa8)();
  return;
}



/*****************************************************************************
 * Function: FUN_00101080
 * Address: 00101080
 * Size: 10 bytes
 *****************************************************************************/


void FUN_00101080(void)

{
  (*(code *)PTR___cxa_finalize_00103ff8)();
  return;
}



/*****************************************************************************
 * Function: puts
 * Address: 00101090
 * Size: 10 bytes
 *****************************************************************************/


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_puts_00103fb0)();
  return iVar1;
}



/*****************************************************************************
 * Function: strlen
 * Address: 001010a0
 * Size: 10 bytes
 *****************************************************************************/


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_00103fb8)();
  return sVar1;
}



/*****************************************************************************
 * Function: printf
 * Address: 001010c0
 * Size: 10 bytes
 *****************************************************************************/


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_00103fc8)();
  return iVar1;
}



/*****************************************************************************
 * Function: _start
 * Address: 001010e0
 * Size: 38 bytes
 *****************************************************************************/


void processEntry _start(undefined8 param_1,undefined8 param_2)

{
  undefined1 auStack_8 [8];
  
  (*(code *)PTR___libc_start_main_00103fd8)(main,param_2,&stack0x00000008,0,0,param_1,auStack_8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/*****************************************************************************
 * Function: deregister_tm_clones
 * Address: 00101110
 * Size: 34 bytes
 *****************************************************************************/


/* WARNING: Removing unreachable block (ram,0x00101123) */
/* WARNING: Removing unreachable block (ram,0x0010112f) */

void deregister_tm_clones(void)

{
  return;
}



/*****************************************************************************
 * Function: register_tm_clones
 * Address: 00101140
 * Size: 51 bytes
 *****************************************************************************/


/* WARNING: Removing unreachable block (ram,0x00101164) */
/* WARNING: Removing unreachable block (ram,0x00101170) */

void register_tm_clones(void)

{
  return;
}



/*****************************************************************************
 * Function: frame_dummy
 * Address: 001011c0
 * Size: 9 bytes
 *****************************************************************************/


void frame_dummy(void)

{
  register_tm_clones();
  return;
}



/*****************************************************************************
 * Function: main
 * Address: 001011c9
 * Size: 588 bytes
 *****************************************************************************/


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



/*****************************************************************************
 * Function: _fini
 * Address: 00101418
 * Size: 13 bytes
 *****************************************************************************/


void _fini(void)

{
  return;
}



/*****************************************************************************
 * Function: _ITM_deregisterTMCloneTable
 * Address: 00105008
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */

void _ITM_deregisterTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/*****************************************************************************
 * Function: puts
 * Address: 00105010
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* puts@GLIBC_2.2.5 */
  halt_baddata();
}



/*****************************************************************************
 * Function: strlen
 * Address: 00105018
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* strlen@GLIBC_2.2.5 */
  halt_baddata();
}



/*****************************************************************************
 * Function: printf
 * Address: 00105028
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* printf@GLIBC_2.2.5 */
  halt_baddata();
}



/*****************************************************************************
 * Function: _ITM_registerTMCloneTable
 * Address: 00105040
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




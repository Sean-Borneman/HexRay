/*==============================================================================
 * CONSOLIDATED DECOMPILED FUNCTIONS
 * Program: b725ef767b4150d81d3072d2f6cf5d07
 * Generated: Sat Sep 13 11:39:54 EDT 2025
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************************
 * Function: _DT_INIT
 * Address: 00101000
 * Size: 27 bytes
 *****************************************************************************/


void _DT_INIT(void)

{
  if (PTR___gmon_start___00103fe8 != (undefined *)0x0) {
    (*(code *)PTR___gmon_start___00103fe8)();
  }
  return;
}



/*****************************************************************************
 * Function: FUN_00101020
 * Address: 00101020
 * Size: 13 bytes
 *****************************************************************************/


void FUN_00101020(void)

{
  (*(code *)PTR_00103f70)();
  return;
}



/*****************************************************************************
 * Function: FUN_001010f0
 * Address: 001010f0
 * Size: 11 bytes
 *****************************************************************************/


void FUN_001010f0(void)

{
  (*(code *)PTR___cxa_finalize_00103ff8)();
  return;
}



/*****************************************************************************
 * Function: getenv
 * Address: 00101100
 * Size: 11 bytes
 *****************************************************************************/


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * getenv(char *__name)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_getenv_00103f78)();
  return pcVar1;
}



/*****************************************************************************
 * Function: putchar
 * Address: 00101110
 * Size: 11 bytes
 *****************************************************************************/


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int putchar(int __c)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_putchar_00103f80)();
  return iVar1;
}



/*****************************************************************************
 * Function: puts
 * Address: 00101120
 * Size: 11 bytes
 *****************************************************************************/


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_puts_00103f88)();
  return iVar1;
}



/*****************************************************************************
 * Function: printf
 * Address: 00101140
 * Size: 11 bytes
 *****************************************************************************/


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_00103f98)();
  return iVar1;
}



/*****************************************************************************
 * Function: srand
 * Address: 00101150
 * Size: 11 bytes
 *****************************************************************************/


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void srand(uint __seed)

{
  (*(code *)PTR_srand_00103fa0)();
  return;
}



/*****************************************************************************
 * Function: getchar
 * Address: 00101160
 * Size: 11 bytes
 *****************************************************************************/


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getchar(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_getchar_00103fa8)();
  return iVar1;
}



/*****************************************************************************
 * Function: time
 * Address: 00101170
 * Size: 11 bytes
 *****************************************************************************/


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t time(time_t *__timer)

{
  time_t tVar1;
  
  tVar1 = (*(code *)PTR_time_00103fb0)();
  return tVar1;
}



/*****************************************************************************
 * Function: random
 * Address: 00101180
 * Size: 11 bytes
 *****************************************************************************/


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long random(void)

{
  long lVar1;
  
  lVar1 = (*(code *)PTR_random_00103fb8)();
  return lVar1;
}



/*****************************************************************************
 * Function: fflush
 * Address: 00101190
 * Size: 11 bytes
 *****************************************************************************/


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fflush(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fflush_00103fc0)();
  return iVar1;
}



/*****************************************************************************
 * Function: exit
 * Address: 001011a0
 * Size: 11 bytes
 *****************************************************************************/


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
  (*(code *)PTR_exit_00103fc8)();
  return;
}



/*****************************************************************************
 * Function: rand
 * Address: 001011b0
 * Size: 11 bytes
 *****************************************************************************/


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int rand(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_rand_00103fd0)();
  return iVar1;
}



/*****************************************************************************
 * Function: entry
 * Address: 001011c0
 * Size: 47 bytes
 *****************************************************************************/


void processEntry entry(undefined8 param_1,undefined8 param_2)

{
  undefined1 auStack_8 [8];
  
  (*(code *)PTR___libc_start_main_00103fe0)
            (FUN_001012a9,param_2,&stack0x00000008,FUN_001016b0,FUN_00101720,param_1,auStack_8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/*****************************************************************************
 * Function: FUN_001011f0
 * Address: 001011f0
 * Size: 34 bytes
 *****************************************************************************/


/* WARNING: Removing unreachable block (ram,0x00101203) */
/* WARNING: Removing unreachable block (ram,0x0010120f) */

void FUN_001011f0(void)

{
  return;
}



/*****************************************************************************
 * Function: FUN_00101220
 * Address: 00101220
 * Size: 51 bytes
 *****************************************************************************/


/* WARNING: Removing unreachable block (ram,0x00101244) */
/* WARNING: Removing unreachable block (ram,0x00101250) */

void FUN_00101220(void)

{
  return;
}



/*****************************************************************************
 * Function: _FINI_0
 * Address: 00101260
 * Size: 54 bytes
 *****************************************************************************/


void _FINI_0(void)

{
  if (DAT_00104018 == '\0') {
    if (PTR___cxa_finalize_00103ff8 != (undefined *)0x0) {
      FUN_001010f0(PTR_LOOP_00104008);
    }
    FUN_001011f0();
    DAT_00104018 = 1;
    return;
  }
  return;
}



/*****************************************************************************
 * Function: _INIT_0
 * Address: 001012a0
 * Size: 9 bytes
 *****************************************************************************/


void _INIT_0(void)

{
  FUN_00101220();
  return;
}



/*****************************************************************************
 * Function: FUN_001012a9
 * Address: 001012a9
 * Size: 92 bytes
 *****************************************************************************/


undefined8 FUN_001012a9(void)

{
  time_t tVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  tVar1 = time((time_t *)0x0);
  srand((uint)tVar1);
  local_10 = 0;
  while (local_10 == 0) {
    local_10 = FUN_00101305();
  }
  local_c = 1;
  while (local_c != 0) {
    local_c = FUN_001014b0(local_10);
  }
  return 0;
}



/*****************************************************************************
 * Function: FUN_00101305
 * Address: 00101305
 * Size: 427 bytes
 *****************************************************************************/


int FUN_00101305(void)

{
  int iVar1;
  long in_FS_OFFSET;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int aiStack_28 [6];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_3c = 0;
  while (local_3c == 0) {
    for (local_38 = 0; local_38 < 5; local_38 = local_38 + 1) {
      iVar1 = rand();
      aiStack_28[local_38] = iVar1 % 9;
      local_3c = local_3c + aiStack_28[local_38];
    }
  }
  local_34 = 0;
  do {
    if (4 < local_34) {
      puts(":Calibration success");
      puts("!");
      fflush(stdout);
      local_3c = local_3c + 0xc;
LAB_0010149a:
      if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return local_3c;
    }
    printf(":Calibrating (%d/5)...\n",(ulong)(local_34 + 1));
    putchar(0x3e);
    for (local_30 = 0; local_30 <= local_34; local_30 = local_30 + 1) {
      putchar(aiStack_28[local_30] + 0x31);
    }
    putchar(10);
    fflush(stdout);
    for (local_2c = 0; local_2c <= local_34; local_2c = local_2c + 1) {
      iVar1 = getchar();
      if ((char)iVar1 == -1) {
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
      if ((int)(char)((char)iVar1 + -0x31) != aiStack_28[local_2c]) {
        puts(":Calibration failure");
        fflush(stdout);
        local_3c = 0;
        goto LAB_0010149a;
      }
    }
    local_34 = local_34 + 1;
  } while( true );
}



/*****************************************************************************
 * Function: FUN_001014b0
 * Address: 001014b0
 * Size: 500 bytes
 *****************************************************************************/


undefined8 FUN_001014b0(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  char *pcVar5;
  long in_FS_OFFSET;
  int local_28;
  int local_24;
  uint local_20;
  char local_17 [7];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  for (local_28 = 0; local_28 < 7; local_28 = local_28 + 1) {
    local_17[local_28] = '\0';
  }
  do {
    for (local_24 = 0; local_24 < 6; local_24 = local_24 + 1) {
      local_17[local_24] = local_17[local_24 + 1];
    }
    iVar1 = getchar();
    if ((char)iVar1 == -1) {
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    local_17[6] = (char)iVar1 + -0x31;
  } while (((((local_17[0] != '\x05') || (local_17[1] != '\b')) || (local_17[2] != '\b')) ||
           ((local_17[3] != '\x02' || (local_17[4] != '\x03')))) ||
          ((local_17[5] != '\0' || (local_20 = param_1, local_17[6] != '\0'))));
  do {
    if ((int)local_20 < 10) {
      printf(">%d\n",(ulong)local_20);
      fflush(stdout);
      uVar3 = 1;
      goto LAB_0010168e;
    }
    lVar4 = random();
    uVar2 = (int)lVar4 + (int)(lVar4 / 9) * -9 + 1;
    printf(">%d\n",(ulong)uVar2);
    fflush(stdout);
    local_20 = local_20 - uVar2;
    iVar1 = getchar();
    if ((char)iVar1 == -1) {
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    iVar1 = (char)iVar1 + -0x30;
  } while (((iVar1 < 1) || (9 < iVar1)) || (local_20 = local_20 - iVar1, local_20 != 0));
  pcVar5 = getenv("FLAG");
  printf(":%s\n",pcVar5);
  fflush(stdout);
  uVar3 = 0;
LAB_0010168e:
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/*****************************************************************************
 * Function: FUN_001016b0
 * Address: 001016b0
 * Size: 101 bytes
 *****************************************************************************/


void FUN_001016b0(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  _DT_INIT();
  lVar1 = 0;
  do {
    (*(code *)(&__DT_INIT_ARRAY)[lVar1])(param_1,param_2,param_3);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 1);
  return;
}



/*****************************************************************************
 * Function: FUN_00101720
 * Address: 00101720
 * Size: 5 bytes
 *****************************************************************************/


void FUN_00101720(void)

{
  return;
}



/*****************************************************************************
 * Function: _DT_FINI
 * Address: 00101728
 * Size: 13 bytes
 *****************************************************************************/


void _DT_FINI(void)

{
  return;
}



/*****************************************************************************
 * Function: getenv
 * Address: 00105000
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * getenv(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/*****************************************************************************
 * Function: putchar
 * Address: 00105008
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int putchar(int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/*****************************************************************************
 * Function: _ITM_deregisterTMCloneTable
 * Address: 00105010
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
 * Address: 00105018
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
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
  halt_baddata();
}



/*****************************************************************************
 * Function: srand
 * Address: 00105038
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void srand(uint __seed)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/*****************************************************************************
 * Function: getchar
 * Address: 00105040
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getchar(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/*****************************************************************************
 * Function: time
 * Address: 00105050
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t time(time_t *__timer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/*****************************************************************************
 * Function: random
 * Address: 00105058
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long random(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/*****************************************************************************
 * Function: fflush
 * Address: 00105060
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fflush(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/*****************************************************************************
 * Function: exit
 * Address: 00105068
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/*****************************************************************************
 * Function: _ITM_registerTMCloneTable
 * Address: 00105070
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/*****************************************************************************
 * Function: rand
 * Address: 00105078
 * Size: 1 bytes
 *****************************************************************************/


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int rand(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




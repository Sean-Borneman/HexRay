#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// External declarations
extern char target[];
extern int __isoc99_scanf(const char *format, ...);
extern void __stack_chk_fail(void);

// Function pointer declarations
extern void *PTR___gmon_start___00103fe8;
extern void *PTR_00103fa8;
extern void *PTR___cxa_finalize_00103ff8;
extern void *PTR_puts_00103fb0;
extern void *PTR_strlen_00103fb8;
extern void *PTR_printf_00103fc8;
extern void *PTR___libc_start_main_00103fd8;
extern char DAT_001021ee[];

int _init(void *ctx)
{
    void *puVar1;
    
    puVar1 = PTR___gmon_start___00103fe8;
    if (PTR___gmon_start___00103fe8 != (void *)0x0) {
        puVar1 = (void *)(*(void (*)(void))PTR___gmon_start___00103fe8)();
    }
    return (int)(long)puVar1;
}

void FUN_00101020(void)
{
    (*(void (*)(void))PTR_00103fa8)();
    return;
}

void FUN_00101080(void)
{
    (*(void (*)(void))PTR___cxa_finalize_00103ff8)();
    return;
}

int puts(const char *__s)
{
    int iVar1;
    
    iVar1 = (*(int (*)(const char *))PTR_puts_00103fb0)(__s);
    return iVar1;
}

size_t strlen(const char *__s)
{
    size_t sVar1;
    
    sVar1 = (*(size_t (*)(const char *))PTR_strlen_00103fb8)(__s);
    return sVar1;
}

int printf(const char *__format, ...)
{
    int iVar1;
    
    iVar1 = (*(int (*)(const char *, ...))PTR_printf_00103fc8)(__format);
    return iVar1;
}

void _start(long param_1, char **param_2)
{
    char auStack_8[8];
    
    (*(int (*)(int (*)(void), char **, char **, void *, void *, long, char *))PTR___libc_start_main_00103fd8)(main, param_2, &auStack_8[8], 0, 0, param_1, auStack_8);
    do {
        /* WARNING: Do nothing block with infinite loop */
    } while(true);
}

void deregister_tm_clones(void)
{
    return;
}

void register_tm_clones(void)
{
    return;
}

void frame_dummy(void)
{
    register_tm_clones();
    return;
}

int main(void)
{
    int iVar1;
    size_t sVar2;
    long in_FS_OFFSET;
    int local_290;
    int local_28c;
    int local_288;
    int local_284;
    unsigned int local_280;
    char local_278[80];
    char acStack_228[520];
    long local_20;
    
    local_20 = *(long *)(in_FS_OFFSET + 0x28);
    printf("Enter flag: ");
    __isoc99_scanf(DAT_001021ee, local_278);
    sVar2 = strlen(local_278);
    if (sVar2 < 0x47) {
        local_290 = 0;
        local_28c = 0;
        while(true) {
            sVar2 = strlen(local_278);
            if (sVar2 <= (unsigned long)(long)local_28c) break;
            local_288 = 0;
            local_284 = 0xff;
            while (iVar1 = (local_284 + local_288) / 2, iVar1 != (int)local_278[local_28c]) {
                if (iVar1 < (int)local_278[local_28c]) {
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

void _fini(void)
{
    return;
}

void _ITM_deregisterTMCloneTable(void)
{
    /* WARNING: Bad instruction - Truncating control flow here */
    while(1);
}

int puts_external(const char *__s)
{
    /* WARNING: Bad instruction - Truncating control flow here */
    /* puts@GLIBC_2.2.5 */
    while(1);
}

size_t strlen_external(const char *__s)
{
    /* WARNING: Bad instruction - Truncating control flow here */
    /* strlen@GLIBC_2.2.5 */
    while(1);
}

int printf_external(const char *__format, ...)
{
    /* WARNING: Bad instruction - Truncating control flow here */
    /* printf@GLIBC_2.2.5 */
    while(1);
}

void _ITM_registerTMCloneTable(void)
{
    /* WARNING: Bad instruction - Truncating control flow here */
    while(1);
}

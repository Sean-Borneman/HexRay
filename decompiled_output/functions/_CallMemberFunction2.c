// Function: _CallMemberFunction2
// Address: 1400049d0
// Size: 15 bytes
============================================================


/* Library Function - Single Match
    void __cdecl _CallMemberFunction2(void * __ptr64 const,void * __ptr64 const,void * __ptr64
   const,int)
   
   Library: Visual Studio 2019 Release */

void __cdecl _CallMemberFunction2(void *param_1,void *param_2,void *param_3,int param_4)

{
                    /* WARNING: Could not recover jumptable at 0x0001400049dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_2)(param_1,param_3,param_4);
  return;
}


// Function: SetUnwindTryBlock
// Address: 140003418
// Size: 59 bytes
============================================================


/* Library Function - Single Match
    public: static void __cdecl __FrameHandler3::SetUnwindTryBlock(unsigned __int64 * __ptr64,struct
   _xDISPATCHER_CONTEXT * __ptr64,struct _s_FuncInfo const * __ptr64,int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl
__FrameHandler3::SetUnwindTryBlock
          (__uint64 *param_1,_xDISPATCHER_CONTEXT *param_2,_s_FuncInfo *param_3,int param_4)

{
  longlong *plVar1;
  longlong local_res18 [2];
  
  plVar1 = FUN_14000288c((longlong *)param_1,(ulonglong *)param_2,(longlong)param_3,local_res18);
  if (*(int *)((longlong)param_3->dispUnwindHelp + 4 + *plVar1) < param_4) {
    *(int *)((longlong)param_3->dispUnwindHelp + 4 + *plVar1) = param_4;
  }
  return;
}


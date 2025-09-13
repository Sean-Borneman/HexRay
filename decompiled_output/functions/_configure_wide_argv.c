// Function: _configure_wide_argv
// Address: 140005080
// Size: 386 bytes
============================================================


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _configure_wide_argv
   
   Library: Visual Studio 2019 Release */

int _configure_wide_argv(int param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  __acrt_ptd *p_Var4;
  longlong *plVar5;
  longlong *plVar6;
  int iVar7;
  short *psVar8;
  longlong *local_res10;
  ulonglong local_res18;
  ulonglong local_res20;
  
  iVar7 = 0;
  if (param_1 != 0) {
    if (param_1 - 1U < 2) {
      GetModuleFileNameW((HMODULE)0x0,(LPWSTR)&DAT_140018c70,0x104);
      _DAT_140018f18 = &DAT_140018c70;
      if ((DAT_140018f40 == (short *)0x0) || (psVar8 = DAT_140018f40, *DAT_140018f40 == 0)) {
        psVar8 = (short *)&DAT_140018c70;
      }
      local_res18 = 0;
      local_res20 = 0;
      FUN_140004e7c(psVar8,(undefined8 *)0x0,(short *)0x0,(longlong *)&local_res18,
                    (longlong *)&local_res20);
      uVar2 = local_res18;
      plVar5 = (longlong *)__acrt_allocate_buffer_for_argv(local_res18,local_res20,2);
      if (plVar5 == (longlong *)0x0) {
        p_Var4 = FUN_140006ee4();
        iVar7 = 0xc;
        *(undefined4 *)p_Var4 = 0xc;
        FUN_140006f7c((LPVOID)0x0);
      }
      else {
        FUN_140004e7c(psVar8,plVar5,(short *)(plVar5 + uVar2),(longlong *)&local_res18,
                      (longlong *)&local_res20);
        if (param_1 == 1) {
          _DAT_140018f20 = (int)local_res18 + -1;
          plVar6 = (longlong *)0x0;
          DAT_140018f30 = plVar5;
        }
        else {
          local_res10 = (longlong *)0x0;
          iVar3 = thunk_FUN_140006fcc(plVar5,&local_res10);
          plVar6 = local_res10;
          if (iVar3 != 0) {
            FUN_140006f7c(local_res10);
            local_res10 = (longlong *)0x0;
            FUN_140006f7c(plVar5);
            return iVar3;
          }
          _DAT_140018f20 = 0;
          lVar1 = *local_res10;
          while (lVar1 != 0) {
            local_res10 = local_res10 + 1;
            _DAT_140018f20 = _DAT_140018f20 + 1;
            lVar1 = *local_res10;
          }
          local_res10 = (longlong *)0x0;
          DAT_140018f30 = plVar6;
          FUN_140006f7c((LPVOID)0x0);
          local_res10 = (longlong *)0x0;
          plVar6 = plVar5;
        }
        FUN_140006f7c(plVar6);
      }
    }
    else {
      p_Var4 = FUN_140006ee4();
      iVar7 = 0x16;
      *(undefined4 *)p_Var4 = 0x16;
      FUN_140006c8c();
    }
  }
  return iVar7;
}


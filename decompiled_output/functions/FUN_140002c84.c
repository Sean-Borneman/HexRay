// Function: FUN_140002c84
// Address: 140002c84
// Size: 134 bytes
============================================================


void FUN_140002c84(EHExceptionRecord *param_1,__uint64 param_2,_CONTEXT *param_3,
                  _xDISPATCHER_CONTEXT *param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  __uint64 local_res8;
  
  uVar1 = *(undefined8 *)(param_4 + 8);
  local_res8 = param_2;
  lVar2 = __vcrt_getptd();
  *(undefined8 *)(lVar2 + 0x60) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x38);
  lVar2 = __vcrt_getptd();
  *(undefined8 *)(lVar2 + 0x68) = uVar1;
  lVar2 = __vcrt_getptd();
  thunk_FUN_14000408c(param_1,&local_res8,param_3,param_4,
                      (_s_FuncInfo *)
                      ((ulonglong)**(uint **)(param_4 + 0x38) + *(longlong *)(lVar2 + 0x60)),0,
                      (__uint64 *)0x0,0);
  return;
}


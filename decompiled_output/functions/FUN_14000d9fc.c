// Function: FUN_14000d9fc
// Address: 14000d9fc
// Size: 162 bytes
============================================================


undefined8 FUN_14000d9fc(undefined8 param_1,longlong param_2)

{
  _xDISPATCHER_CONTEXT *p_Var1;
  undefined8 uVar2;
  longlong lVar3;
  
  *(undefined8 *)(param_2 + 0x50) = param_1;
  *(undefined8 *)(param_2 + 0x48) = param_1;
  lVar3 = __vcrt_getptd();
  *(undefined8 *)(lVar3 + 0x70) = *(undefined8 *)(param_2 + 0x80);
  p_Var1 = *(_xDISPATCHER_CONTEXT **)(param_2 + 0x98);
  uVar2 = *(undefined8 *)(p_Var1 + 8);
  lVar3 = __vcrt_getptd();
  *(undefined8 *)(lVar3 + 0x60) = uVar2;
  uVar2 = *(undefined8 *)(**(longlong **)(param_2 + 0x48) + 0x38);
  lVar3 = __vcrt_getptd();
  *(undefined8 *)(lVar3 + 0x68) = uVar2;
  thunk_FUN_14000408c((EHExceptionRecord *)**(undefined8 **)(param_2 + 0x48),
                      *(__uint64 **)(param_2 + 0x88),*(_CONTEXT **)(param_2 + 0x90),p_Var1,
                      *(_s_FuncInfo **)(param_2 + 0xa0),0,(__uint64 *)0x0,1);
  lVar3 = __vcrt_getptd();
  *(undefined8 *)(lVar3 + 0x70) = 0;
  *(undefined4 *)(param_2 + 0x40) = 1;
  return 1;
}


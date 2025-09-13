// Function: thunk_FUN_14000408c
// Address: 1400042c4
// Size: 5 bytes
============================================================


undefined8
thunk_FUN_14000408c(EHExceptionRecord *param_1,__uint64 *param_2,_CONTEXT *param_3,
                   _xDISPATCHER_CONTEXT *param_4,_s_FuncInfo *param_5,int param_6,__uint64 *param_7,
                   byte param_8)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined8 in_stack_ffffffffffffffe0;
  
  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  __except_validate_context_record((longlong)param_3);
  lVar2 = __vcrt_getptd();
  if ((*(int *)(lVar2 + 0x40) == 0) && (*(int *)param_1 != -0x1f928c9d)) {
    if (*(int *)param_1 == -0x7fffffd7) {
      if (*(int *)(param_1 + 0x18) == 0xf) {
        if (*(longlong *)(param_1 + 0x60) == 0x19930520) goto LAB_14000410e;
        goto LAB_1400040f2;
      }
    }
    else {
LAB_1400040f2:
      if (*(int *)param_1 == -0x7fffffda) goto LAB_14000410e;
    }
    if ((0x19930521 < (param_5->magicNumber_and_bbtFlags & 0x1fffffff)) &&
       ((param_5->EHFlags & 1) != 0)) {
      return 1;
    }
  }
LAB_14000410e:
  if (((byte)param_1[4] & 0x66) == 0) {
    if ((param_5->nTryBlocks == 0) &&
       ((((param_5->magicNumber_and_bbtFlags & 0x1fffffff) < 0x19930521 ||
         (param_5->dispESTypeList == 0)) ||
        (lVar2 = _GetImageBase(), lVar2 + (int)param_5->dispESTypeList == 0)))) {
      if ((param_5->magicNumber_and_bbtFlags & 0x1fffffff) < 0x19930522) {
        return 1;
      }
      if (((uint)param_5->EHFlags >> 2 & 1) == 0) {
        return 1;
      }
    }
    if (((*(int *)param_1 == -0x1f928c9d) && (2 < *(uint *)(param_1 + 0x18))) &&
       ((0x19930522 < *(uint *)(param_1 + 0x20) &&
        ((*(int *)(*(longlong *)(param_1 + 0x30) + 8) != 0 &&
         (lVar2 = _GetThrowImageBase(), lVar2 + *(int *)(*(longlong *)(param_1 + 0x30) + 8) != 0))))
       )) {
      uVar3 = (*(code *)PTR__guard_dispatch_icall_14000e260)
                        (param_1,param_2,param_3,param_4,param_5,param_6,param_7,
                         CONCAT44(uVar4,(uint)param_8));
      return uVar3;
    }
    FUN_140003858(param_1,param_2,param_3,param_4,param_5,param_8,param_6,param_7);
    return 1;
  }
  if (param_5->maxState == 0) {
    return 1;
  }
  if (param_6 != 0) {
    return 1;
  }
  if (((byte)param_1[4] & 0x20) == 0) {
LAB_140004193:
    __FrameHandler3::FrameUnwindToEmptyState(param_2,param_4,param_5);
  }
  else {
    if (*(int *)param_1 == -0x7fffffda) {
      iVar1 = FUN_14000345c((longlong)param_5,(longlong)param_4,*(ulonglong *)(param_4 + 0x20));
      if ((iVar1 < -1) || (param_5->maxState <= iVar1)) {
LAB_1400042bd:
                    /* WARNING: Subroutine does not return */
        abort();
      }
    }
    else {
      if (*(int *)param_1 != -0x7fffffd7) goto LAB_140004193;
      iVar1 = *(int *)(param_1 + 0x38);
      if ((iVar1 < -1) || (param_5->maxState <= iVar1)) goto LAB_1400042bd;
      param_2 = *(__uint64 **)(param_1 + 0x28);
    }
    FUN_140004628(param_2,(ulonglong *)param_4,param_5,iVar1);
  }
  return 1;
}


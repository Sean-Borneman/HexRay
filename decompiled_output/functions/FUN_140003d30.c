// Function: FUN_140003d30
// Address: 140003d30
// Size: 536 bytes
============================================================


void FUN_140003d30(EHExceptionRecord *param_1,__uint64 *param_2,_CONTEXT *param_3,
                  _xDISPATCHER_CONTEXT *param_4,_s_FuncInfo *param_5,int param_6,int param_7,
                  __uint64 *param_8)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  PVOID pvVar5;
  _s_HandlerType *p_Var6;
  uint uVar7;
  _s_FuncInfo *local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 uStack_84;
  uint uStack_80;
  undefined4 uStack_7c;
  int local_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  int local_68;
  undefined4 local_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  uint local_48;
  
  if (*(int *)param_1 != -0x7ffffffd) {
    lVar4 = __vcrt_getptd();
    if (*(longlong *)(lVar4 + 0x10) != 0) {
      pvVar5 = EncodePointer((PVOID)0x0);
      lVar4 = __vcrt_getptd();
      if ((((*(PVOID *)(lVar4 + 0x10) != pvVar5) && (*(int *)param_1 != -0x1fbcb0b3)) &&
          (*(int *)param_1 != -0x1fbcbcae)) &&
         (iVar3 = _CallSETranslator<>((undefined4 *)param_1,param_2,param_3), iVar3 != 0)) {
        return;
      }
    }
    local_90 = *(undefined8 *)(param_4 + 8);
    local_98 = param_5;
    if (param_5->nTryBlocks == 0) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
    FUN_140002958((undefined8 *)&local_60,&local_98,param_6,(ulonglong *)param_4,(longlong)param_5);
    local_88 = local_60;
    uStack_84 = uStack_5c;
    uStack_80 = uStack_58;
    uStack_7c = uStack_54;
    if (uStack_58 < local_48) {
      uVar7 = uStack_58;
      do {
        lVar2 = *(longlong *)(CONCAT44(uStack_5c,local_60) + 8);
        lVar4 = (longlong)*(int *)(*(longlong *)CONCAT44(uStack_84,local_88) + 0x10) +
                (ulonglong)uVar7 * 0x14;
        piVar1 = (int *)(lVar4 + lVar2);
        local_78 = *piVar1;
        iStack_74 = piVar1[1];
        iStack_70 = (int)*(ulonglong *)(piVar1 + 2);
        iStack_6c = piVar1[3];
        local_68 = *(int *)(lVar4 + 0x10 + lVar2);
        if ((local_78 <= param_6) && (param_6 <= iStack_74)) {
          p_Var6 = (_s_HandlerType *)
                   (*(longlong *)(param_4 + 8) + -0x14 +
                   (longlong)local_68 + (*(ulonglong *)(piVar1 + 2) >> 0x20) * 0x14);
          if (*(int *)(p_Var6 + 4) != 0) {
            iVar3 = *(int *)(p_Var6 + 4);
            lVar4 = _GetImageBase();
            if (lVar4 + iVar3 != 0) {
              if (iVar3 == 0) {
                lVar4 = 0;
              }
              else {
                lVar4 = _GetImageBase();
                lVar4 = lVar4 + *(int *)(p_Var6 + 4);
              }
              if (*(char *)(lVar4 + 0x10) != '\0') goto LAB_140003f29;
            }
          }
          if (((byte)*p_Var6 & 0x40) == 0) {
            CatchIt<class___FrameHandler3>
                      (param_1,param_2,param_3,param_4,param_5,p_Var6,(_s_CatchableType *)0x0,
                       (_s_TryBlockMapEntry *)&local_78,param_7,param_8,'\x01','\0');
          }
        }
LAB_140003f29:
        uVar7 = uVar7 + 1;
      } while (uVar7 < local_48);
    }
  }
  return;
}


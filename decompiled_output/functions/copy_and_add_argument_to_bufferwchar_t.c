// Function: copy_and_add_argument_to_buffer<wchar_t>
// Address: 1400073bc
// Size: 392 bytes
============================================================


/* Library Function - Single Match
    int __cdecl copy_and_add_argument_to_buffer<wchar_t>(wchar_t const * __ptr64 const,wchar_t const
   * __ptr64 const,unsigned __int64,class `anonymous namespace'::argument_list<wchar_t> & __ptr64)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl
copy_and_add_argument_to_buffer<wchar_t>
          (wchar_t *param_1,wchar_t *param_2,__uint64 param_3,argument_list<wchar_t> *param_4)

{
  int iVar1;
  short *psVar2;
  LPVOID pvVar3;
  undefined8 *puVar4;
  longlong lVar5;
  ulonglong uVar7;
  int iVar8;
  ulonglong uVar9;
  longlong lVar6;
  
  iVar8 = 0;
  lVar5 = -1;
  do {
    lVar6 = lVar5;
    lVar5 = lVar6 + 1;
  } while (param_1[lVar5] != L'\0');
  uVar7 = lVar6 + 2;
  if (~param_3 < uVar7) {
    return 0xc;
  }
  uVar9 = param_3 + 1 + uVar7;
  psVar2 = (short *)_calloc_base(uVar9,2);
  if (((param_3 != 0) && (iVar1 = FUN_140006d5c(psVar2,uVar9,(longlong)param_2,param_3), iVar1 != 0)
      ) || (iVar1 = FUN_140006d5c(psVar2 + param_3,uVar9 - param_3,(longlong)param_1,uVar7),
           iVar1 != 0)) {
                    /* WARNING: Subroutine does not return */
    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  puVar4 = *(undefined8 **)(param_4 + 8);
  if (puVar4 == *(undefined8 **)(param_4 + 0x10)) {
    if (*(longlong *)param_4 == 0) {
      pvVar3 = _calloc_base(4,8);
      *(LPVOID *)param_4 = pvVar3;
      FUN_140006f7c((LPVOID)0x0);
      puVar4 = *(undefined8 **)param_4;
      if (puVar4 != (undefined8 *)0x0) {
        *(undefined8 **)(param_4 + 8) = puVar4;
        *(undefined8 **)(param_4 + 0x10) = puVar4 + 4;
        goto LAB_140007527;
      }
    }
    else {
      uVar7 = (longlong)*(undefined8 **)(param_4 + 0x10) - *(longlong *)param_4 >> 3;
      if (uVar7 < 0x8000000000000000) {
        pvVar3 = _recalloc_base(*(LPVOID *)param_4,uVar7 * 2,8);
        if (pvVar3 != (LPVOID)0x0) {
          *(LPVOID *)param_4 = pvVar3;
          *(LPVOID *)(param_4 + 8) = (LPVOID)((longlong)pvVar3 + uVar7 * 8);
          *(LPVOID *)(param_4 + 0x10) = (LPVOID)((longlong)pvVar3 + uVar7 * 0x10);
          FUN_140006f7c((LPVOID)0x0);
          puVar4 = *(undefined8 **)(param_4 + 8);
          goto LAB_140007527;
        }
        FUN_140006f7c((LPVOID)0x0);
      }
    }
    FUN_140006f7c(psVar2);
    iVar8 = 0xc;
  }
  else {
LAB_140007527:
    *puVar4 = psVar2;
    *(longlong *)(param_4 + 8) = *(longlong *)(param_4 + 8) + 8;
  }
  FUN_140006f7c((LPVOID)0x0);
  return iVar8;
}


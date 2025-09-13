// Function: CxxCallCatchBlock
// Address: 1400043b4
// Size: 370 bytes
============================================================


/* Library Function - Single Match
    public: static void * __ptr64 __cdecl __FrameHandler3::CxxCallCatchBlock(struct
   _EXCEPTION_RECORD * __ptr64)
   
   Library: Visual Studio 2019 Release */

void * __cdecl __FrameHandler3::CxxCallCatchBlock(_EXCEPTION_RECORD *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int *piVar3;
  ULONG_PTR UVar4;
  ULONG_PTR UVar5;
  longlong *plVar6;
  int iVar7;
  longlong lVar8;
  undefined8 *puVar9;
  void *pvVar10;
  undefined8 local_48 [2];
  
  lVar8 = __vcrt_getptd();
  uVar1 = *(undefined8 *)(lVar8 + 0x28);
  lVar8 = __vcrt_getptd();
  uVar2 = *(undefined8 *)(lVar8 + 0x20);
  piVar3 = (int *)param_1->ExceptionInformation[6];
  UVar4 = param_1->ExceptionInformation[5];
  UVar5 = param_1->ExceptionInformation[4];
  plVar6 = (longlong *)param_1->ExceptionInformation[1];
  __except_validate_context_record(UVar5);
  lVar8 = __vcrt_getptd();
  *(int **)(lVar8 + 0x20) = piVar3;
  lVar8 = __vcrt_getptd();
  *(ULONG_PTR *)(lVar8 + 0x28) = UVar5;
  lVar8 = __vcrt_getptd();
  puVar9 = _CreateFrameInfo(local_48,*(undefined8 *)(*(longlong *)(lVar8 + 0x20) + 0x28));
  if (param_1->ExceptionInformation[7] != 0) {
    __vcrt_getptd();
  }
  pvVar10 = (void *)_CallSettingFrame();
  _FindAndUnlinkFrame((longlong)puVar9);
  if ((((*piVar3 == -0x1f928c9d) && (piVar3[6] == 4)) && (piVar3[8] + 0xe66cfae0U < 3)) &&
     (iVar7 = _IsExceptionObjectToBeDestroyed(*(longlong *)(piVar3 + 10)), iVar7 != 0)) {
    __DestructExceptionObject(piVar3);
  }
  lVar8 = __vcrt_getptd();
  *(undefined8 *)(lVar8 + 0x20) = uVar2;
  lVar8 = __vcrt_getptd();
  *(undefined8 *)(lVar8 + 0x28) = uVar1;
  *(undefined8 *)((longlong)*(int *)(UVar4 + 0x1c) + *plVar6) = 0xfffffffffffffffe;
  return pvVar10;
}


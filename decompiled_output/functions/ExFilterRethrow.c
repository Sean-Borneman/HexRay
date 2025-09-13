// Function: ExFilterRethrow
// Address: 1400045a0
// Size: 134 bytes
============================================================


/* Library Function - Single Match
    int __cdecl ExFilterRethrow(struct _EXCEPTION_POINTERS * __ptr64,struct EHExceptionRecord *
   __ptr64,int * __ptr64)
   
   Library: Visual Studio 2015 Release */

int __cdecl ExFilterRethrow(_EXCEPTION_POINTERS *param_1,EHExceptionRecord *param_2,int *param_3)

{
  PEXCEPTION_RECORD pEVar1;
  longlong lVar2;
  int iVar3;
  
  pEVar1 = param_1->ExceptionRecord;
  *param_3 = 0;
  if (pEVar1->ExceptionCode == 0xe06d7363) {
    if ((pEVar1->NumberParameters == 4) && ((int)pEVar1->ExceptionInformation[0] + 0xe66cfae0U < 3))
    {
      iVar3 = *param_3;
      if (pEVar1->ExceptionInformation[1] == *(ULONG_PTR *)(param_2 + 0x28)) {
        iVar3 = 1;
      }
      *param_3 = iVar3;
    }
    if ((((pEVar1->ExceptionCode == 0xe06d7363) && (pEVar1->NumberParameters == 4)) &&
        ((int)pEVar1->ExceptionInformation[0] + 0xe66cfae0U < 3)) &&
       (pEVar1->ExceptionInformation[2] == 0)) {
      lVar2 = __vcrt_getptd();
      *(undefined4 *)(lVar2 + 0x40) = 1;
      *param_3 = 1;
      return 1;
    }
  }
  return 0;
}


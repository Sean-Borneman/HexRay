// Function: _CxxThrowException
// Address: 140004bc0
// Size: 160 bytes
============================================================


/* Library Function - Single Match
    _CxxThrowException
   
   Library: Visual Studio 2019 Release */

void __stdcall _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
  ULONG_PTR UVar1;
  PVOID local_38;
  ULONG_PTR local_30;
  void *local_28;
  ThrowInfo *local_20;
  PVOID local_18;
  
  UVar1 = 0x19930520;
  if ((pThrowInfo != (ThrowInfo *)0x0) && ((pThrowInfo->attributes & 0x10) != 0)) {
                    /* WARNING: Load size is inaccurate */
    pThrowInfo = *(ThrowInfo **)(*(longlong *)(*pExceptionObject + -8) + 0x30);
    (*(code *)PTR__guard_dispatch_icall_14000e260)();
  }
  local_38 = RtlPcToFileHeader(pThrowInfo,&local_38);
  if ((pThrowInfo != (ThrowInfo *)0x0) &&
     (((pThrowInfo->attributes & 8) != 0 || (local_38 == (PVOID)0x0)))) {
    UVar1 = 0x1994000;
  }
  local_30 = UVar1;
  local_28 = pExceptionObject;
  local_20 = pThrowInfo;
  local_18 = local_38;
  RaiseException(0xe06d7363,1,4,&local_30);
  return;
}


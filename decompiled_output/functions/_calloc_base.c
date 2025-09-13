// Function: _calloc_base
// Address: 140006f04
// Size: 117 bytes
============================================================


/* Library Function - Single Match
    _calloc_base
   
   Library: Visual Studio 2019 Release */

LPVOID _calloc_base(ulonglong param_1,ulonglong param_2)

{
  int iVar1;
  undefined8 uVar2;
  LPVOID pvVar3;
  __acrt_ptd *p_Var4;
  SIZE_T dwBytes;
  
  if ((param_1 == 0) || (param_2 <= 0xffffffffffffffe0 / param_1)) {
    dwBytes = param_1 * param_2;
    if (dwBytes == 0) {
      dwBytes = 1;
    }
    do {
      pvVar3 = HeapAlloc(DAT_140019738,8,dwBytes);
      if (pvVar3 != (LPVOID)0x0) {
        return pvVar3;
      }
      iVar1 = FUN_1400059b0();
    } while ((iVar1 != 0) && (uVar2 = FUN_140009898(dwBytes), (int)uVar2 != 0));
  }
  p_Var4 = FUN_140006ee4();
  *(undefined4 *)p_Var4 = 0xc;
  return (LPVOID)0x0;
}


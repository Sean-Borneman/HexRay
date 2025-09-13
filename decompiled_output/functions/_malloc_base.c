// Function: _malloc_base
// Address: 140008c4c
// Size: 94 bytes
============================================================


/* Library Function - Single Match
    _malloc_base
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

LPVOID _malloc_base(ulonglong param_1)

{
  int iVar1;
  undefined8 uVar2;
  LPVOID pvVar3;
  __acrt_ptd *p_Var4;
  
  if (param_1 < 0xffffffffffffffe1) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    do {
      pvVar3 = HeapAlloc(DAT_140019738,0,param_1);
      if (pvVar3 != (LPVOID)0x0) {
        return pvVar3;
      }
      iVar1 = FUN_1400059b0();
    } while ((iVar1 != 0) && (uVar2 = FUN_140009898(param_1), (int)uVar2 != 0));
  }
  p_Var4 = FUN_140006ee4();
  *(undefined4 *)p_Var4 = 0xc;
  return (LPVOID)0x0;
}


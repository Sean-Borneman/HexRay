// Function: _msize_base
// Address: 14000ac44
// Size: 57 bytes
============================================================


/* Library Function - Single Match
    _msize_base
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined8 _msize_base(longlong param_1)

{
  __acrt_ptd *p_Var1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    p_Var1 = FUN_140006ee4();
    *(undefined4 *)p_Var1 = 0x16;
    FUN_140006c8c();
    return 0xffffffffffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x00014000ac76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = HeapSize(DAT_140019738,0,param_1);
  return uVar2;
}


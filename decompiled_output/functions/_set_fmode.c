// Function: _set_fmode
// Address: 140005858
// Size: 61 bytes
============================================================


/* Library Function - Single Match
    _set_fmode
   
   Library: Visual Studio 2012 Release */

errno_t __cdecl _set_fmode(int _Mode)

{
  errno_t eVar1;
  __acrt_ptd *p_Var2;
  
  if (((_Mode - 0x4000U & 0xffff3fff) == 0) && (_Mode != 0xc000)) {
    LOCK();
    UNLOCK();
    eVar1 = 0;
    DAT_140019184 = _Mode;
  }
  else {
    p_Var2 = FUN_140006ee4();
    *(undefined4 *)p_Var2 = 0x16;
    FUN_140006c8c();
    eVar1 = 0x16;
  }
  return eVar1;
}


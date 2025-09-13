// Function: strcpy_s
// Address: 140005fb8
// Size: 95 bytes
============================================================


/* Library Function - Single Match
    strcpy_s
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

errno_t __cdecl strcpy_s(char *_Dst,rsize_t _SizeInBytes,char *_Src)

{
  char cVar1;
  __acrt_ptd *p_Var2;
  errno_t eVar3;
  char *pcVar4;
  
  if ((_Dst != (char *)0x0) && (_SizeInBytes != 0)) {
    if (_Src != (char *)0x0) {
      pcVar4 = _Dst;
      do {
        cVar1 = pcVar4[(longlong)_Src - (longlong)_Dst];
        *pcVar4 = cVar1;
        pcVar4 = pcVar4 + 1;
        if (cVar1 == '\0') {
          return 0;
        }
        _SizeInBytes = _SizeInBytes - 1;
      } while (_SizeInBytes != 0);
      *_Dst = '\0';
      p_Var2 = FUN_140006ee4();
      eVar3 = 0x22;
      goto LAB_140005fdb;
    }
    *_Dst = '\0';
  }
  p_Var2 = FUN_140006ee4();
  eVar3 = 0x16;
LAB_140005fdb:
  *(errno_t *)p_Var2 = eVar3;
  FUN_140006c8c();
  return eVar3;
}


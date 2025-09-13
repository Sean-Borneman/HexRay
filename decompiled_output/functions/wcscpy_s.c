// Function: wcscpy_s
// Address: 140006cf4
// Size: 101 bytes
============================================================


/* Library Function - Single Match
    wcscpy_s
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

errno_t __cdecl wcscpy_s(wchar_t *_Dst,rsize_t _SizeInWords,wchar_t *_Src)

{
  wchar_t wVar1;
  __acrt_ptd *p_Var2;
  errno_t eVar3;
  wchar_t *pwVar4;
  
  if ((_Dst != (wchar_t *)0x0) && (_SizeInWords != 0)) {
    if (_Src != (wchar_t *)0x0) {
      pwVar4 = _Dst;
      do {
        wVar1 = *(wchar_t *)(((longlong)_Src - (longlong)_Dst) + (longlong)pwVar4);
        *pwVar4 = wVar1;
        pwVar4 = pwVar4 + 1;
        if (wVar1 == L'\0') {
          return 0;
        }
        _SizeInWords = _SizeInWords - 1;
      } while (_SizeInWords != 0);
      *_Dst = L'\0';
      p_Var2 = FUN_140006ee4();
      eVar3 = 0x22;
      goto LAB_140006d18;
    }
    *_Dst = L'\0';
  }
  p_Var2 = FUN_140006ee4();
  eVar3 = 0x16;
LAB_140006d18:
  *(errno_t *)p_Var2 = eVar3;
  FUN_140006c8c();
  return eVar3;
}


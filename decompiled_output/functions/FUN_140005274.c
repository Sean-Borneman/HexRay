// Function: FUN_140005274
// Address: 140005274
// Size: 282 bytes
============================================================


undefined8 * FUN_140005274(wchar_t *param_1)

{
  errno_t eVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  wchar_t *pwVar5;
  wchar_t wVar6;
  longlong lVar7;
  ulonglong _SizeInWords;
  undefined8 *puVar8;
  
  wVar6 = *param_1;
  lVar7 = 0;
  pwVar5 = param_1;
  while (wVar6 != L'\0') {
    lVar2 = lVar7 + 1;
    if (wVar6 == L'=') {
      lVar2 = lVar7;
    }
    lVar7 = -1;
    do {
      lVar3 = lVar7;
      lVar7 = lVar3 + 1;
    } while (pwVar5[lVar7] != L'\0');
    pwVar5 = pwVar5 + lVar3 + 2;
    lVar7 = lVar2;
    wVar6 = *pwVar5;
  }
  puVar4 = (undefined8 *)_calloc_base(lVar7 + 1,8);
  puVar8 = puVar4;
  if (puVar4 == (undefined8 *)0x0) {
LAB_1400052df:
    FUN_140006f7c((LPVOID)0x0);
    puVar4 = (undefined8 *)0x0;
  }
  else {
    for (; *param_1 != L'\0'; param_1 = param_1 + _SizeInWords) {
      lVar7 = -1;
      do {
        lVar2 = lVar7;
        lVar7 = lVar2 + 1;
      } while (param_1[lVar7] != L'\0');
      _SizeInWords = lVar2 + 2;
      if (*param_1 != L'=') {
        pwVar5 = (wchar_t *)_calloc_base(_SizeInWords,2);
        if (pwVar5 == (wchar_t *)0x0) {
          free_environment<>(puVar4);
          FUN_140006f7c((LPVOID)0x0);
          goto LAB_1400052df;
        }
        eVar1 = wcscpy_s(pwVar5,_SizeInWords,param_1);
        if (eVar1 != 0) {
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        *puVar8 = pwVar5;
        puVar8 = puVar8 + 1;
        FUN_140006f7c((LPVOID)0x0);
      }
    }
    FUN_140006f7c((LPVOID)0x0);
  }
  return puVar4;
}


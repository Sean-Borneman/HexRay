// Function: thunk_FUN_140006fcc
// Address: 1400075e4
// Size: 5 bytes
============================================================


void thunk_FUN_140006fcc(undefined8 *param_1,undefined8 *param_2)

{
  byte bVar1;
  int iVar2;
  BOOL BVar3;
  __acrt_ptd *p_Var4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  HANDLE hFindFile;
  LPVOID pvVar7;
  ushort uVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  short *psVar13;
  ulonglong uVar14;
  longlong *plVar15;
  undefined1 auStackY_2f8 [32];
  longlong *plStack_2c8;
  longlong *plStack_2c0;
  undefined8 uStack_2b8;
  ulonglong uStack_2b0;
  undefined8 *puStack_2a8;
  _WIN32_FIND_DATAW _Stack_298;
  short *psStack_48;
  ulonglong uStack_40;
  
  uStack_40 = DAT_140018038 ^ (ulonglong)auStackY_2f8;
  puStack_2a8 = param_2;
  if (param_2 == (undefined8 *)0x0) {
    p_Var4 = FUN_140006ee4();
    *(undefined4 *)p_Var4 = 0x16;
    FUN_140006c8c();
  }
  else {
    *param_2 = 0;
    pwVar5 = (wchar_t *)*param_1;
    plStack_2c8 = (longlong *)0x0;
    plStack_2c0 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    uStack_2b8 = 0;
    while (pwVar5 != (wchar_t *)0x0) {
      psStack_48 = (short *)CONCAT26(psStack_48._6_2_,0x3f002a);
      pwVar6 = wcspbrk(pwVar5,(wchar_t *)&psStack_48);
      pwVar5 = (wchar_t *)*param_1;
      if (pwVar6 == (wchar_t *)0x0) {
        iVar2 = copy_and_add_argument_to_buffer<wchar_t>
                          (pwVar5,(wchar_t *)0x0,0,(argument_list<wchar_t> *)&plStack_2c8);
        plVar12 = plStack_2c8;
        plVar10 = plStack_2c0;
        if (iVar2 != 0) {
          plVar10 = plStack_2c8;
          if (plStack_2c8 != plStack_2c0) {
            do {
              FUN_140006f7c((LPVOID)*plVar10);
              plVar10 = plVar10 + 1;
            } while (plVar10 != plStack_2c0);
          }
          goto LAB_1400072cf;
        }
      }
      else {
        while ((pwVar6 != pwVar5 &&
               ((0x2d < (ushort)(*pwVar6 + L'￑') ||
                ((0x200000000801U >> ((ulonglong)(ushort)(*pwVar6 + L'￑') & 0x3f) & 1) == 0))))) {
          pwVar6 = pwVar6 + -1;
        }
        if ((*pwVar6 != L':') || (pwVar6 == pwVar5 + 1)) {
          uVar8 = *pwVar6 + L'￑';
          if ((0x2d < uVar8) || (bVar1 = 1, (0x200000000801U >> ((ulonglong)uVar8 & 0x3f) & 1) == 0)
             ) {
            bVar1 = 0;
          }
          hFindFile = FindFirstFileExW(pwVar5,FindExInfoStandard,&_Stack_298,FindExSearchNameMatch,
                                       (LPVOID)0x0,0);
          if (hFindFile != (HANDLE)0xffffffffffffffff) {
            lVar11 = (longlong)plVar10 - (longlong)plVar12 >> 3;
            do {
              if (((_Stack_298.cFileName[0] != L'.') ||
                  ((_Stack_298.cFileName[1] != L'\0' &&
                   ((_Stack_298.cFileName[1] != L'.' || (_Stack_298.cFileName[2] != L'\0')))))) &&
                 (iVar2 = copy_and_add_argument_to_buffer<wchar_t>
                                    (_Stack_298.cFileName,pwVar5,
                                     -(ulonglong)bVar1 &
                                     ((longlong)pwVar6 - (longlong)pwVar5 >> 1) + 1U,
                                     (argument_list<wchar_t> *)&plStack_2c8), iVar2 != 0)) {
                FindClose(hFindFile);
                goto LAB_14000722c;
              }
              BVar3 = FindNextFileW(hFindFile,&_Stack_298);
              plVar10 = plStack_2c0;
              plVar12 = plStack_2c8;
            } while (BVar3 != 0);
            lVar9 = (longlong)plStack_2c0 - (longlong)plStack_2c8 >> 3;
            if (lVar11 != lVar9) {
              FUN_14000a370((undefined1 *)(plStack_2c8 + lVar11),lVar9 - lVar11,8,&LAB_140006fb8);
            }
            FindClose(hFindFile);
            goto LAB_1400071f1;
          }
        }
        iVar2 = copy_and_add_argument_to_buffer<wchar_t>
                          (pwVar5,(wchar_t *)0x0,0,(argument_list<wchar_t> *)&plStack_2c8);
        plVar10 = plStack_2c0;
        plVar12 = plStack_2c8;
        if (iVar2 != 0) {
LAB_14000722c:
          plVar12 = plStack_2c8;
          plVar10 = plStack_2c8;
          if (plStack_2c8 != plStack_2c0) {
            do {
              FUN_140006f7c((LPVOID)*plVar10);
              plVar10 = plVar10 + 1;
            } while (plVar10 != plStack_2c0);
          }
          goto LAB_1400072cf;
        }
      }
LAB_1400071f1:
      param_1 = param_1 + 1;
      pwVar5 = (wchar_t *)*param_1;
    }
    uVar14 = ((longlong)plVar10 - (longlong)plVar12 >> 3) + 1;
    uStack_2b0 = 0;
    for (plVar15 = plVar12; plVar15 != plVar10; plVar15 = plVar15 + 1) {
      lVar11 = -1;
      do {
        lVar11 = lVar11 + 1;
      } while (*(short *)(*plVar15 + lVar11 * 2) != 0);
      uStack_2b0 = uStack_2b0 + 1 + lVar11;
    }
    pvVar7 = __acrt_allocate_buffer_for_argv(uVar14,uStack_2b0,2);
    if (pvVar7 == (LPVOID)0x0) {
      FUN_140006f7c((LPVOID)0x0);
      for (plVar15 = plVar12; plVar15 != plVar10; plVar15 = plVar15 + 1) {
        FUN_140006f7c((LPVOID)*plVar15);
      }
LAB_1400072cf:
      FUN_140006f7c(plVar12);
    }
    else {
      psVar13 = (short *)((longlong)pvVar7 + uVar14 * 8);
      psStack_48 = psVar13;
      if (plVar12 != plVar10) {
        plVar15 = plVar12;
        do {
          lVar11 = -1;
          do {
            lVar9 = lVar11;
            lVar11 = lVar9 + 1;
          } while (*(short *)(*plVar15 + lVar11 * 2) != 0);
          lVar9 = lVar9 + 2;
          iVar2 = FUN_140006d5c(psVar13,uStack_2b0 - ((longlong)psVar13 - (longlong)psStack_48 >> 1)
                                ,*plVar15,lVar9);
          if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          *(short **)((longlong)plVar15 + ((longlong)pvVar7 - (longlong)plVar12)) = psVar13;
          plVar15 = plVar15 + 1;
          psVar13 = psVar13 + lVar9;
        } while (plVar15 != plVar10);
      }
      *puStack_2a8 = pvVar7;
      FUN_140006f7c((LPVOID)0x0);
      for (plVar15 = plVar12; plVar15 != plVar10; plVar15 = plVar15 + 1) {
        FUN_140006f7c((LPVOID)*plVar15);
      }
      FUN_140006f7c(plVar12);
    }
  }
  FUN_14000d520(uStack_40 ^ (ulonglong)auStackY_2f8);
  return;
}


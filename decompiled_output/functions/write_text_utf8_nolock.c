// Function: write_text_utf8_nolock
// Address: 14000b4c8
// Size: 368 bytes
============================================================


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* Library Function - Single Match
    struct `anonymous namespace'::write_result __cdecl write_text_utf8_nolock(int,char const *
   __ptr64 const,unsigned int)
   
   Library: Visual Studio 2019 Release */

void __cdecl write_text_utf8_nolock(int param_1,char *param_2,uint param_3)

{
  short sVar1;
  HANDLE hFile;
  uint uVar2;
  BOOL BVar3;
  DWORD DVar4;
  short *psVar5;
  undefined4 in_register_0000000c;
  DWORD *pDVar6;
  uint uVar7;
  ulonglong uVar8;
  short *psVar9;
  undefined4 in_register_00000084;
  uint in_R9D;
  short *psVar10;
  undefined1 auStackY_1498 [32];
  DWORD local_1458 [4];
  short local_1448 [856];
  undefined1 local_d98 [3424];
  ulonglong local_38;
  undefined8 uStack_30;
  
  psVar9 = (short *)CONCAT44(in_register_00000084,param_3);
  pDVar6 = (DWORD *)CONCAT44(in_register_0000000c,param_1);
  uStack_30 = 0x14000b4e4;
  local_38 = DAT_140018038 ^ (ulonglong)auStackY_1498;
  psVar10 = (short *)((ulonglong)in_R9D + (longlong)psVar9);
  hFile = *(HANDLE *)
           ((&DAT_140019190)[(longlong)(int)(uint)param_2 >> 6] + 0x28 +
           (ulonglong)((uint)param_2 & 0x3f) * 0x48);
  pDVar6[0] = 0;
  pDVar6[1] = 0;
  pDVar6[2] = 0;
  do {
    if (psVar10 <= psVar9) {
LAB_14000b609:
      FUN_14000d520(local_38 ^ (ulonglong)auStackY_1498);
      return;
    }
    psVar5 = local_1448;
    do {
      if (psVar10 <= psVar9) break;
      sVar1 = *psVar9;
      psVar9 = psVar9 + 1;
      if (sVar1 == 10) {
        *psVar5 = 0xd;
        psVar5 = psVar5 + 1;
      }
      *psVar5 = sVar1;
      psVar5 = psVar5 + 1;
    } while (psVar5 < local_1448 + 0x354);
    uVar2 = __acrt_WideCharToMultiByte
                      (0xfde9,0,local_1448,(int)((longlong)psVar5 - (longlong)local_1448 >> 1));
    if (uVar2 == 0) {
LAB_14000b601:
      DVar4 = GetLastError();
      *pDVar6 = DVar4;
      goto LAB_14000b609;
    }
    uVar8 = 0;
    if (uVar2 != 0) {
      do {
        BVar3 = WriteFile(hFile,local_d98 + uVar8,uVar2 - (int)uVar8,local_1458,(LPOVERLAPPED)0x0);
        if (BVar3 == 0) goto LAB_14000b601;
        uVar7 = (int)uVar8 + local_1458[0];
        uVar8 = (ulonglong)uVar7;
      } while (uVar7 < uVar2);
    }
    pDVar6[1] = (int)psVar9 - param_3;
  } while( true );
}


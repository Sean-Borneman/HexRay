// Function: FUN_140004e7c
// Address: 140004e7c
// Size: 418 bytes
============================================================


void FUN_140004e7c(short *param_1,undefined8 *param_2,short *param_3,longlong *param_4,
                  longlong *param_5)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  bVar1 = false;
  do {
    sVar4 = 0x22;
    if (*param_1 == 0x22) {
      bVar1 = !bVar1;
    }
    else {
      *param_5 = *param_5 + 1;
      if (param_3 != (short *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      sVar4 = *param_1;
      if (sVar4 == 0) goto LAB_140004f13;
    }
    param_1 = param_1 + 1;
  } while ((bVar1) || ((sVar4 != 0x20 && (sVar4 != 9))));
  if (param_3 != (short *)0x0) {
    param_3[-1] = 0;
  }
LAB_140004f13:
  bVar1 = false;
  while (sVar4 = *param_1, sVar4 != 0) {
    while ((sVar4 == 0x20 || (sVar4 == 9))) {
      param_1 = param_1 + 1;
      sVar4 = *param_1;
    }
    if (sVar4 == 0) break;
    if (param_2 != (undefined8 *)0x0) {
      *param_2 = param_3;
      param_2 = param_2 + 1;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      uVar3 = 1;
      uVar2 = 0;
      for (; *param_1 == 0x5c; param_1 = param_1 + 1) {
        uVar2 = uVar2 + 1;
      }
      if (*param_1 == 0x22) {
        if ((uVar2 & 1) == 0) {
          if ((bVar1) && (param_1[1] == 0x22)) {
            param_1 = param_1 + 1;
          }
          else {
            bVar1 = !bVar1;
            uVar3 = 0;
          }
        }
        uVar2 = uVar2 >> 1;
      }
      while (uVar2 != 0) {
        uVar2 = uVar2 - 1;
        if (param_3 != (short *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      sVar4 = *param_1;
      if ((sVar4 == 0) || ((!bVar1 && ((sVar4 == 0x20 || (sVar4 == 9)))))) break;
      if (uVar3 != 0) {
        if (param_3 != (short *)0x0) {
          *param_3 = sVar4;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      param_1 = param_1 + 1;
    }
    if (param_3 != (short *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *param_5 = *param_5 + 1;
  }
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}


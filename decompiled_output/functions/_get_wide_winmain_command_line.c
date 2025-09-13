// Function: _get_wide_winmain_command_line
// Address: 140005458
// Size: 84 bytes
============================================================


/* Library Function - Single Match
    _get_wide_winmain_command_line
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

ushort * _get_wide_winmain_command_line(void)

{
  bool bVar1;
  ushort uVar2;
  ushort *puVar3;
  
  puVar3 = &DAT_140018ea0;
  bVar1 = false;
  if (DAT_140018f40 != (ushort *)0x0) {
    puVar3 = DAT_140018f40;
    bVar1 = false;
  }
  do {
    uVar2 = *puVar3;
    if (uVar2 < 0x21) {
      if (uVar2 == 0) {
        return puVar3;
      }
      if (!bVar1) {
        do {
          if (0x20 < uVar2) {
            return puVar3;
          }
          puVar3 = puVar3 + 1;
          uVar2 = *puVar3;
        } while (uVar2 != 0);
        return puVar3;
      }
    }
    if (uVar2 == 0x22) {
      bVar1 = !bVar1;
    }
    puVar3 = puVar3 + 1;
  } while( true );
}


// Function: FUN_140005704
// Address: 140005704
// Size: 49 bytes
============================================================


void FUN_140005704(UINT param_1)

{
  undefined4 uVar1;
  HANDLE hProcess;
  
  uVar1 = FUN_140005738();
  if ((char)uVar1 != '\0') {
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,param_1);
  }
  FUN_140005768(param_1);
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}


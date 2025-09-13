// Function: FUN_1400085ac
// Address: 1400085ac
// Size: 39 bytes
============================================================


void FUN_1400085ac(uint param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001400085cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LeaveCriticalSection
            ((&DAT_140019190)[(longlong)(int)param_1 >> 6] + (ulonglong)(param_1 & 0x3f) * 0x48);
  return;
}


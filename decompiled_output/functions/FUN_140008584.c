// Function: FUN_140008584
// Address: 140008584
// Size: 39 bytes
============================================================


void FUN_140008584(uint param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001400085a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EnterCriticalSection
            ((&DAT_140019190)[(longlong)(int)param_1 >> 6] + (ulonglong)(param_1 & 0x3f) * 0x48);
  return;
}


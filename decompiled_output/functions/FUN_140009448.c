// Function: FUN_140009448
// Address: 140009448
// Size: 88 bytes
============================================================


/* WARNING: Switch with 1 destination removed at 0x00014000948e */
/* WARNING: Switch with 1 destination removed at 0x00014000d920 */

INT_PTR FUN_140009448(undefined8 param_1)

{
  FARPROC UNRECOVERED_JUMPTABLE;
  INT_PTR IVar1;
  
  UNRECOVERED_JUMPTABLE =
       FUN_140009288(0x18,"AppPolicyGetProcessTerminationMethod",(uint *)&DAT_1400109b4,
                     (uint *)"AppPolicyGetProcessTerminationMethod");
  if (UNRECOVERED_JUMPTABLE == (FARPROC)0x0) {
    return 0xc0000225;
  }
                    /* WARNING: Could not recover jumptable at 0x00014000d900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar1 = (*UNRECOVERED_JUMPTABLE)(0xfffffffffffffffa,param_1);
  return IVar1;
}


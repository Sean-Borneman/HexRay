// Function: FUN_14000d45c
// Address: 14000d45c
// Size: 43 bytes
============================================================


undefined8 * FUN_14000d45c(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = type_info::vftable;
  if ((param_2 & 1) != 0) {
    thunk_FUN_140005f9c(param_1);
  }
  return param_1;
}


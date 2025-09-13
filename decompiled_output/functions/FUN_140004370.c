// Function: FUN_140004370
// Address: 140004370
// Size: 66 bytes
============================================================


undefined8 * FUN_140004370(undefined8 *param_1,uint param_2)

{
  *param_1 = std::exception::vftable;
  __std_exception_destroy(param_1 + 1);
  if ((param_2 & 1) != 0) {
    thunk_FUN_140005f9c(param_1);
  }
  return param_1;
}


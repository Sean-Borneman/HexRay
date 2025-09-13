// Function: FUN_140004308
// Address: 140004308
// Size: 30 bytes
============================================================


undefined8 * FUN_140004308(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad exception";
  *param_1 = std::bad_exception::vftable;
  return param_1;
}


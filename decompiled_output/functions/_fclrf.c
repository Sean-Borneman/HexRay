// Function: _fclrf
// Address: 14000cf1a
// Size: 20 bytes
============================================================


/* Library Function - Single Match
    _fclrf
   
   Library: Visual Studio */

void _fclrf(void)

{
  MXCSR = MXCSR & 0xffffffc0;
  return;
}


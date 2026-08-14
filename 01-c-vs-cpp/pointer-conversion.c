/*
Both lines below are constraint violations in ISO C, so a diagnostic is
required either way. The difference from C++ is what compilers traditionally
did about it: they warned and carried on.

GCC 14 promoted both diagnostics to errors by default, so the two -Wno-error
flags are what it now takes to see the historical behaviour.

Use: -std=c99 -Wno-error=int-conversion -Wno-error=incompatible-pointer-types
*/

int main()
{
  int x = 35;
  int *p = x; // Integer to pointer, warns but compiles in C

  double dval = 45.45;
  char *q = &dval; // double* to char*, warns but compiles in C

  return 0;
}

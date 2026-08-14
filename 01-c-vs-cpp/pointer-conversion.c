/*
The first two conversions below are constraint violations in ISO C, so a
diagnostic is required either way. The difference from C++ is what compilers
traditionally did about it: they warned and carried on.

The malloc line is a different case, that conversion is genuinely legal C and
draws no diagnostic at all. C++ rejects all three.

Casting malloc in C is not just unnecessary, it can hide a bug. Forget
<stdlib.h> under C89 and malloc is implicitly declared as returning int, so
the uncast version warns "makes pointer from integer without a cast", which is
exactly the clue you want. Write the cast and that clue is gone. From C99 on
the implicit declaration is an error by itself, so this argument is mostly a
C89 one, but it is why the C convention is to leave malloc uncast.

GCC 14 promoted both diagnostics to errors by default, so the two -Wno-error
flags are what it now takes to see the historical behaviour.

Use: -std=c99 -Wno-error=int-conversion -Wno-error=incompatible-pointer-types
*/

#include <stdlib.h>

int main()
{
  int x = 35;
  int *p = x; // Integer to pointer, warns but compiles in C

  double dval = 45.45;
  char *q = &dval; // double* to char*, warns but compiles in C

  int *n = malloc(sizeof(int)); //OK in C, and unlike the two above this one is
                                //not a violation at all, void* converts to any
                                //object pointer type implicitly. No cast needed
                                //here, C++ is what forces the cast.
                                //Not freed up.

  return 0;
}

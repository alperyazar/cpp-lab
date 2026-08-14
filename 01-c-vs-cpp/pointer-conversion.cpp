/*
C++ has no implicit conversion for either of these, so both are hard errors
with no flags at all and there is no -Wno-error to soften them. A cast is the
only way through, which is the point, it has to be written down.

Use: -std=c++98 -pedantic-errors
*/

#include <stdlib.h>

int main()
{
  int x = 35;
  int *p = x; // Not allowed

  double dval = 45.45;
  char *q = &dval; // Not allowed

  int *n = malloc(sizeof(int)); //Not allowed, explicit conversion needed.
                                //Not freed up.

  return 0;
}

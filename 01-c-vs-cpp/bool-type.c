/*
Note: The following notes should be reviewed if you consider C23 or further.
In C23 bool, true and false became keywords and <stdbool.h> no longer defines
them as macros. The code below still compiles and prints the same values under
C23, but for a different reason than the one explained here.

The _Bool type is introduced to C in C99. However, C programmers tend to use
int to hold boolean values. The _Bool type is an unsigned integer type in C99.
*/

#include <stdio.h>

int main()
{
  /*
  Allowed, but NOT because _Bool is an unsigned integer type. Conversion to
  _Bool is not a modular reduction: C99 6.3.1.2 says the result is 0 if the
  value compares equal to 0, and 1 otherwise. That is why 2 becomes 1 here,
  while a modular wrap into a single value bit would have given 0.
  */
  _Bool x = 2;

  //1 in my case but the size is implementation defined
  printf("sizeof(_Bool) is %zu\n", sizeof(_Bool));
  printf("x is %u\n", x); //1

  /*
  Just for demo, DO NOT USE headers like that! C11 7.1.2p4 says a standard
  header shall be included outside of any external declaration or definition,
  so this is not conforming. No diagnostic is required for it, which is why it
  still compiles cleanly.
  */
  #include <stdbool.h> //Up to C17, this is what defines bool, true and false.

  bool y = true;
  printf("y is %u\n", y); //1

  //_Bool in C is subject to integer promotion.

  printf("%u\n", y + 1); //2
}

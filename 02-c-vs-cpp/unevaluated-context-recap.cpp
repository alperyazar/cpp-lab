/*
This is not a difference between C and Cpp but just for recap

Compile with: -std=c++11 -pedantic-errors
%zu needs C++11, under -std=c++98 it is not a supported length modifier.
The same source compiles and behaves identically as C with -std=c99.
*/

#include <stdio.h>

int main()
{
  int x = 10;
  size_t y = sizeof x++;

  printf("%zu %d\n", y, x); //4 10
  return 0;
}

/*
Remember that operand of sizeof operator is an unevaluated context. No machine
code is generated for x++ in this case. This is same for C and C++.
*/

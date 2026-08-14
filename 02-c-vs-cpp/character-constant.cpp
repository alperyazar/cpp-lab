/*
In Cpp, character constant (literal) type is char.

Use: -std=c++98 -pedantic-errors
*/

#include <stdio.h>

int main()
{
  printf("sizeof(int) is %zu\n", sizeof(int)); //4
  printf("sizeof('A') is %zu\n", sizeof('A')); //1
}

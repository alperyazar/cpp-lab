/*
In C, character constant type is int.

Use: -std=c99 -pedantic-errors
*/

#include <stdio.h>

int main()
{
  printf("sizeof(int) is %zu\n", sizeof(int)); //4
  printf("sizeof('A') is %zu\n", sizeof('A')); //4
}

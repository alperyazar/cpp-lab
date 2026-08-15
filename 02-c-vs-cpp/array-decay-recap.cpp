/*
Compile with: -std=c++11 -pedantic-errors

Array decay, which the standard calls array to pointer conversion.

This is not a C vs C++ difference, just a recap. Holds for both C and Cpp, the
same source compiles as C99 and prints the same thing.
*/

#include <stdio.h>

int main()
{
  int a[10]; //a names an object of type int[10]

  //The expression a is an lvalue of type int[10]. In most contexts it
  //undergoes array to pointer conversion, informally called ARRAY DECAY, and
  //the result of that conversion is a different expression, a value of type
  //int* pointing at a[0]. Both statements are about expressions, they are just
  //not the same expression. Note that decay is the name of the conversion, it
  //does not change the type of the array expression itself.
  int *p = &a[0]; //a[0] is an lvalue of type int, so &a[0] has type int*
  int *q = a;     //here the converted expression has type int*, value == &a[0]
  printf("p == q is %d\n", p == q); //1

  printf("sizeof(int) is %zu\n", sizeof(int)); //4

  //sizeof(a) is one of the contexts where there is NO decay, so the operand
  //expression keeps its type int[10]
  printf("sizeof(a) is %zu\n", sizeof(a)); //40, that is 10 * sizeof(int)

  //a + 1 decays a first, so this is int* arithmetic and the step is
  //sizeof(int)
  printf("a step is %td\n", (char *)(a + 1) - (char *)a); //4

  //& is the other context with no decay, so the operand expression stays
  //int[10] and &a has type int(*)[10]. Pointer arithmetic then steps by the
  //whole array
  printf("&a step is %td\n", (char *)(&a + 1) - (char *)&a); //40

  return 0;
}

/*
The two exceptions above, sizeof and &, are the ones worth memorising. The
third is a string literal initialising an array, char s[] = "alper"; copies the
characters instead of decaying, see string-literal.cpp in this directory. C11
also lists _Alignof, and C++ adds binding to a reference to array, for example
int (&r)[10] = a; where r keeps the type int[10].

Note that the addresses are the same, only the types differ: a and &a point at
the same byte. It is the type of the expression that decides what + 1 means.
*/

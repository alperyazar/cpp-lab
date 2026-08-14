/*
Let's define an enum.

Use: -std=c++11 -pedantic-errors
(scoped enums and the fixed underlying type are both C++11)
*/

#include <stdio.h>

enum Color {White, Gray, Brown, Black}; //In C it is always enum Color but in
                                        //Cpp we can use Color;

//In Cpp the underlying type is whatever fits, so an enumerator too big for int
//just widens the type. C is stricter than that: before C23 an enumerator that
//does not fit in int is a constraint violation, C does NOT pick a wider type
//for you. C23 is what lifted the restriction.
//Careful though, that restriction is about the enumerator VALUES, not about
//the size of the enum type. C leaves the enumerated type implementation
//defined (compatible with char, a signed or an unsigned integer type), so
//assert(sizeof(int) == sizeof(enum Color)); CAN fail. gcc -fshort-enums makes
//it fail, sizeof(enum Color) becomes 1. What C guarantees before C23 is that
//the enumerators themselves have type int.

enum X {A, B = 12345678912345L, C}; //Cpp: fine. C: error before C23

//In Cpp, it is possible to provide underlying type

enum Y : unsigned char {K}; //Cpp11 and C23, not valid in C17 or earlier

enum class Z {L, M, N}; //Scoped enum in Cpp, not a class

int main()
{
  printf("sizeof(int) is %zu\n", sizeof(int)); //4
  printf("sizeof(Color) is %zu\n", sizeof(Color)); //4
  printf("sizeof(X) is %zu\n", sizeof(X)); //8
  printf("sizeof(Y) is %zu\n", sizeof(Y)); //1

  //C allows conversion from arithmetic types to enum or between different enum
  //types.

  Color mycolor;
  //mycolor = 3; //Not possible in Cpp, possible in C

  //Both C and Cpp allows conversion from enum to arithmetic types.
  mycolor = White;
  int x = mycolor;

  //But this not allowed in scoped enum
  Z myZ = Z::L;
  //int y = myZ; //Error because myZ has type scoped enum.
}

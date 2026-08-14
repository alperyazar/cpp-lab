/*
Recap: Linkage is related to linking multiple compilation units into single
executable file.

External linkage: Same name used in different files but is the same object
in the memory.

Internal linkage: (Same) name but different objects in different files.

No linkage: Like local variables.

This file compiles as both C and C++, the difference is only visible in the
symbol table:

  gcc -std=c99 -pedantic-errors -c const-linkage.c -o cl.o && nm cl.o
  g++ -std=c++98 -pedantic-errors -x c++ const-linkage.c -c -o clpp.o && nm clpp.o

C gives `R a` (external), C++ gives `r _ZL1a` (internal).

Use: -std=c99 -pedantic-errors
*/

int x; // External linkage
static int y; //Internal linkage

const int a = 10; //External linkage in C but const objects have
                  //internal linkage in C++. In C const no effect.

int main(){}

/*
In Cpp, we can use using keyword as an alternative to typedef keyword.
typedef exists in both C and C++ but using keyword is only in C++, and only
since C++11. This file needs -std=c++11 or later, it does not compile with
-std=c++98. C has no equivalent, not even in C23.
*/

using Word = int; //typedef int Word;
typedef int (*FCMP)(const void *, const void*);  //Valid in C and Cpp
using FCMP = int(*)(const void *, const void*);  //Same as the above but easier
                                                 //to read, IMHO

/*
Note that the two FCMP lines above are not an error. An alias declaration and a
typedef declare the SAME kind of name, so the second line is just a
redeclaration of FCMP with the same type, which is allowed. Give the two lines
different types and it becomes a conflicting declaration error.

The alias declaration is not only sugar: unlike typedef it can be a template.
*/

int main(){return 0;}

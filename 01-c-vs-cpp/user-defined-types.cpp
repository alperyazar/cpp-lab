/*
Actually struct in C++ is different than in C. In C++ a struct IS a class.
*/

struct Data {
  int a, b, c;
};

/*
Unlike C, structs with no members are allowed in C++. But sizeof is 1, not 0:
no complete object type in C++ may have size zero. GCC's empty struct extension
in C gives 0 instead, see the .c file.
*/
struct Data3 {

};

/*
The typedef idiom of C still compiles in C++, but it is redundant here. The
class name is usable on its own already.
*/
typedef struct Data2 {
  int a, b, c;
} Data2;

int main()
{
  Data x; //Unlike C, in C++ we can use Data instead of struct Data
  struct Data y; //Also OK, this one is called an elaborated type specifier
  Data2 z; //OK, but the typedef above was not needed to make this work

  /*
  The struct prefix is not merely tolerated in C++. It becomes REQUIRED again
  once an ordinary identifier hides the class name, which is the C++ echo of
  the separate tag namespace explained in the .c file.
  */
  int Data = 0;

  // Data w; //Error now, Data names the int above, not the class
  struct Data w; //OK, the elaborated type specifier still finds the class

  return Data;
}

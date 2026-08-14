/*
User defined types are constructed with struct, enum and union keywords
*/

/*
The "Data" identifier is called structure tag (or union tag in union and enum
tag in enum). Note that "struct" is the keyword here, "Data" is not, it is just
an identifier we picked.

The name of the defined type is "struct Data" not "Data"

The reason is that tags live in a namespace separate from ordinary identifiers.
That is why the struct prefix is needed to name the type, and it is also why
the tag "Data" and a variable named "Data" can happily coexist, see main below.
*/
struct Data {
  int a, b, c;
};

/*
The very same tag rule applies to enum and union
*/
enum Color {
  RED, GREEN, BLUE
};

union Value {
  int i;
  double d;
};

/*
We can use typedef, so that we don't have to write the struct prefix every time
*/

typedef struct Data2 {
  int a, b, c;
} Data2;

/*
struct with no member is not allowed in C, try with -std=c99 -pedantic-errors
if you don't get any error.
*/
struct Data3 {

};

int main()
{
  // Data x; //Error, the correct type name is struct Data
  struct Data x; //OK
  Data2 y; //OK

  enum Color c; //OK, the enum prefix is needed as well
  union Value v; //OK

  //OK, this does not collide with the struct tag "Data" above
  int Data = 0;

  return Data;
}

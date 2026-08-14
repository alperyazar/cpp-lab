/*
Cpp has native bool type. Unlike C, bool, false and true are keywords in Cpp.
No need to include stdbool.h to use them. In C they are macros, but only up to
C17: since C23 they are keywords in C as well.
*/

int* gp;

int main()
{
  bool x; //Declared but NOT initialized, its value is indeterminate.
  bool y = false;

  //++y; //Does not compile since C++17. ++ on bool was deprecated in C++98
         //and removed in C++17. -- on bool is different: it has never been
         //allowed, not even in C++98, so "since C++17" does not apply to it.

  int a = 42;
  double dval = 42.0;

  /*
  This one is UB, x above is indeterminate. Worse, a bool whose stored
  representation is neither 0 nor 1 can make both if(b) and if(!b) taken.
  Note that x is already a bool, so no conversion happens here at all.
  */
  bool b = x;

  bool c = dval; //OK, true. THIS is the implicit conversion to bool.
  bool ba = a; //OK, true

  /*
  For conversions to bool non-zero values are true, zero values are false.
  */

  int d = 100;
  int* ptr = &d;

  /*
  Similar to arithmetic types, pointer types can be converted to bool. If
  pointer is null pointer, then it is false, otherwise true.

  In this example gp has static storage duration and it has not been
  initialized explicitly. Objects with static storage duration are zero
  initialized. For a pointer, this means initialize to null pointer.

  Compare this with bool x above: that one has automatic storage duration, so
  it is default initialized instead and its value stays indeterminate.
  */

  bool b1 = ptr; //OK, true
  bool b2 = gp; //OK, false

  /* What about the opposite way ?*/

  bool b3 = true;
  bool b4 = false;

  int i = b3; //OK, i is 1
  int j = b4; //OK, j is 0

  //int *ptr1 = b4; //NOT OK, can't use to initialize a pointer.
}

/*
In Cpp, string literals, "", have type const char [] whereas in C char []

Use: -std=c++11 -pedantic-errors
*/

int main()
{
  const char *ptr = "alper"; // right type is const char [6] (null terminated string)

  //char *ptr2 = "alper"; // Error from C++11 on, because dropping the const is
                          // no longer allowed. Under -std=c++98 the same line
                          // is only a deprecated conversion, so it still
                          // compiles with a warning even with -pedantic-errors.
                          // Always legal in C, where the type is char [6].

  //int *ptr3 = &"alper"; // Uncomment this line to see type of "alper"
                          // Cpp says: cannot convert const char (*)[6] to int*
                          // C says:   incompatible pointer type char (*)[6]
                          // That pair of messages is the whole difference.
  return 0;
}

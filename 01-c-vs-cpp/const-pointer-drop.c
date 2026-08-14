/*
Dropping const while converting a pointer.

This is a constraint violation in C too, but compilers have always accepted it
with just a warning, so it takes -pedantic-errors to make it an error.

Use: -std=c99 -pedantic-errors
*/

int main()
{
  const int x = 10; //Type of &x is const int*
  int *p = &x; //Accepted with a warning by default, error with -pedantic-errors
               //although implicit conversion not recommended, cast it please!
}

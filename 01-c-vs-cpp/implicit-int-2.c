/*
 * Compile with --std=c89
 *
 * NEVER DO THAT IN C, A BAD PRACTICE!
 */

int main()
{
  int x = foo(10, 32);   /* foo is assumed as int foo(); */
  int y = bar(10, 32.5); /* bar is assumed as int bar(); */
  int z = baz(10, 32);   /* baz is assumed as int baz(); */
}

int foo(int x, int y)
{
  return x + y;
}

int bar(unsigned int x, unsigned int y)
{
  return x + y;
}

/* this gives error because baz() assumed to be returning int, not unsigned int*/
unsigned int baz(unsigned int x, unsigned int y)
{
  return x + y;
}

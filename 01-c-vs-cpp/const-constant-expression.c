/*
In C, expressions formed by const objects are not constant expressions.

Use: -std=c89 -pedantic-errors
*/

int main()
{
  const int x = 10;

  int a[x]; /* Error unless VLA is supported */

  x; /* Not a const expression in C; */

}

/* In C, an unnamed parameter in function definition NOT allowed */
/* This file doesn't compile unless C23 */
/* -std=c89 -pedantic-errors */

int foo(int x, int)
{
  return x;
}

int main()
{
  return foo(5, 10);
}

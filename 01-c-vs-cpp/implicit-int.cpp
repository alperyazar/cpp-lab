/*
 * The implicit int rule in C is prohibited in C++.
 * This file doesn't compile
 * NEVER DO THAT IN C, A BAD PRACTICE!
 */

static int foo(int x);

foo(int x)
{
  return x + 42;
}

int main()
{
  foo(5);
}


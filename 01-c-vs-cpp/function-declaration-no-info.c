
/* Empty parameter list in C says nothing about parameters */
/* This is fine until C23 (I think) */
int foo();

int main()
{
  foo(10, 32);
  return 0;
}

int foo(int x, int y)
{
  return x + y;
}

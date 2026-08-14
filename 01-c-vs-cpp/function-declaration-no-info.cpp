
/* Empty parameter list in Cpp behaves like int foo(void); */
/* This code doesn't compile */

int foo(); /* This is evaluated as int foo(void); */
int bar();

int main()
{
  foo(10, 32);
  bar(5); /* Error, bar should take no argument */
  return 0;
}

int foo(int x, int y)
{
  return x + y;
}

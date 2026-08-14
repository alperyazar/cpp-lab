/* This is OK in CPP even with c++98 */

int foo(int x, int)
{
  return x;
}

int main()
{
  return foo(5, 10);
}

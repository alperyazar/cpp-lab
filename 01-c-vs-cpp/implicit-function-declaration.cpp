int main()
{
  foo(); /* Error in Cpp, compiler assumes nothing about foo */
}

int foo(void)
{
  return 42;
}

/*
Unlike C case, CPP doesn't do any assumption about identifier foo. Even
with in c++98. This file doesn't compile.
*/

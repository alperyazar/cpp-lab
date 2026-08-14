/*
Cpp has some tools to avoid scope leakage.

Use: -std=c++17 -pedantic-errors
(the plain condition declaration below already works under -std=c++98,
 only the init-statement needs C++17)
*/

int foo()
{
  return 42;
}

int main()
{
  if(int x = foo()){} //Declaring in the condition, since C++98

  // x; This is error because x's scope is not leaked here.

  if(int y = foo(); y > 10){} //Init-statement, this is the C++17 addition

  // y; Also not visible here.

  for(int i = 0; i < 10; ++i){}

  // i; Not visible either, C99 got this one too.
}

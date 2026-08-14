/*
In C++, expressions formed by const objects can be constant expression.

Use: -std=c++98 -pedantic-errors
*/

int main()
{
  const int x = 10;

  int a[x]; /* OK */

  x; /*A const expression in Cpp; */

}

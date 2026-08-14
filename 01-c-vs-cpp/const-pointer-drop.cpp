/*
Dropping const while converting a pointer.

No flags needed to see this one fail, C++ has no such implicit conversion.

Use: -std=c++98 -pedantic-errors
*/

int main()
{
  const int x = 10;
  int *p = &x; //In Cpp, implicit conversion from const T* to T* not allowed!
}

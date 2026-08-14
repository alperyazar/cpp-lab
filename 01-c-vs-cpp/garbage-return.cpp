int foo()
{
  /* Unlike C, flowing off the end of a value-returning function is
  unconditionally UB in C++, regardless of whether the caller uses the
  result. foo(); below discards it, yet this program is still UB. */
}

int main()
{
  foo();
  return 0;
}

int foo()
{
  /* Garbage return is UB in C only if the caller uses the returned value.
  main() below discards it (foo();), so this program is not actually UB. */
}

int main()
{
  foo();
  return 0;
}

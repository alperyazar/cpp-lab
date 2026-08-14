/*
 * Compile with --std=c89
 * The implicit int rule implies that the declared function return int.
 *
 * NEVER DO THAT IN C, A BAD PRACTICE!
 */

static foo (int x);
static bar (int x);

int foo(int x)
{
  return x + 42;
}

/*
 * This will give conflicting types error during compilation
 * because due to implicit int rule,
 * the return value of bar() is declared as int (implicitly)
 */
double bar(int x)
{
  return x + 42.;
}

int main()
{
  foo(5);
  bar(5);
}


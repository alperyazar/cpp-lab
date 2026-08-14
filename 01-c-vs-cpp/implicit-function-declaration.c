/* use --std=c89 */

int main()
{
  foo(); /* C assumes that it is declared as int foo(); no parameter info */
}

/* if you make int to double, you get conflicting types */

int foo(void)
{
  return 42;
}

/*
During name lookup phase, if the C compiler cant find the identifier with
function call operator, (), it assumes that the identifier x is a function
with declared as int x();
*/

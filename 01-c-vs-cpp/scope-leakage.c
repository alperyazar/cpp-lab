/*
A variable that only the loop needs still has to outlive it.

C99 fixed this for the for loop, `for (int i = 0; ...)` scopes i to the loop,
but there is still no way to declare a variable in an if, while or switch
condition, so that part of the leak has no C answer in any standard.

Use: -std=c99 -pedantic-errors
*/

int main()
{
  int i;
  for (i = 0; i < 10; ++i){}
  i; //i is accessible here, can be a problem sometimes
}

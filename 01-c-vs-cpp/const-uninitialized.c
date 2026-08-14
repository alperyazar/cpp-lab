/*
It is legal (doesn't mean recommended) to have uninitialized const objects.

Use: -std=c99 -pedantic-errors
*/

const int x; //OK in C

int main(){}

/*
It is illegal to have uninitialized const objects.

Use: -std=c++98 -pedantic-errors
*/

const int x; //Not OK in C++

int main(){}

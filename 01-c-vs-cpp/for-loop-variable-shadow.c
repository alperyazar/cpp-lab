#include <stdio.h>

int main()
{
  for(int i = 0; i < 20; i++) {
    printf("%d\n", i); // 0 1 2 .. 19
    int i = 99;
    // Now new i shadows the loop counter i
    // Add -Wshadow to get the warning
    printf("%d\n", i); // 99 99 .. 99
  }

}

#include <stdio.h>

int main()
{
  for(int i = 0; i < 20; i++) {
    //{
    int i = 99;  // Can't shadow the loop counter i here, compilation error.
                 // Unlike an ordinary nested block, the for-header's i and
                 // this substatement share the SAME scope in C++, so this
                 // is a redeclaration, not a shadow (unlike in C, see .c
                 // file). Uncomment the { } below to make it a real nested
                 // block one level deeper, which shadows legally again -
                 // though then the printf after the closing } would print
                 // the outer loop's i (0..19), not 99, since the inner i
                 // would have gone out of scope by then.
    printf("%d\n", i);
    //}
    printf("%d\n", i);
  }

}

# C vs C++

More snippets showing where C and C++ disagree, continuing from
`01-c-vs-cpp`. Most topics come as a `.c` and a `.cpp` file with the same name,
so the two can be read side by side. Several files are meant to *fail* to
compile, that is exactly the point of the example, and the comments inside each
file say which standard is needed.

## character constant

- `character-constant.c` — A character constant has type `int` in C, so
  `sizeof('A')` is `sizeof(int)` and prints 4 here, not 1. The constant is an
  `int` that happens to hold a character value.
- `character-constant.cpp` — In C++ it is a character *literal* of type `char`,
  so `sizeof('A')` is 1 by definition.

## string literal

There is no `.c` file here yet. C has string literals too, the C side is
described in the comments instead.

- `string-literal.cpp` — A string literal is `const char [N]` in C++ and
  `char [N]` in C, so `char *p = "alper";` is ordinary C and a C++ error from
  C++11 on. Under `-std=c++98` it is only a deprecated conversion, which
  `-pedantic-errors` does not promote, so it still compiles there with a
  warning. The `int *ptr3 = &"alper";` line is a trick for reading the type off
  the compiler: C++ reports `const char (*)[6]` and C reports `char (*)[6]`,
  and that pair of messages is the entire difference.

## unevaluated context recap

Not a C vs C++ difference, just a recap. There is no `.c` file because there
is nothing to contrast: the same source compiles as C99 and prints the same
thing, so a counterpart would be a copy.

- `unevaluated-context-recap.cpp` — The operand of `sizeof` is an unevaluated
  context, so `sizeof x++` yields `sizeof(int)` and never increments `x`. No
  machine code is emitted for `x++` at all, only its type is used. Prints
  `4 10`, not `4 11`.

## array decay recap

Also not a difference, also a recap, and again no `.c` file because the same
source compiles as C99 and prints the same thing.

- `array-decay-recap.cpp` — **Array decay**, which the standard calls *array to
  pointer conversion*. Expressions have types, and the decay produces a
  *different* expression rather than changing the type of the old one. The
  expression `a` is an lvalue of type `int[10]`; the decayed expression is a
  value of type `int*` equal to `&a[0]`. The two contexts where there is no
  decay are `sizeof` and unary `&`, so the operand
  keeps type `int[10]` and `&a` has type `int(*)[10]`. That is why `a + 1`
  steps 4 bytes and `&a + 1` steps 40, from the same address — the type of the
  expression decides what `+ 1` means. A string literal initialising an array
  is the third exception, see `string-literal.cpp` above.

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

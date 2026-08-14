# C vs C++

Snippets showing where C and C++ disagree. Most topics come as a `.c` and a
`.cpp` file with the same name, so the two can be read side by side. Several
files are meant to *fail* to compile, that is exactly the point of the example,
and the comments inside each file say which standard is needed.

## bool type

- `bool-type.c` — `_Bool` arrived in C99 as an unsigned integer type in which
  any non-zero value converts to exactly `1`, while `bool`, `true` and `false`
  stayed `<stdbool.h>` macros until C23 made them keywords.
- `bool-type.cpp` — `bool` is a built-in keyword needing no header, arithmetic
  and pointer values convert to it implicitly, and `++` on a `bool` was removed
  in C++17 while `--` was never allowed at all.

## for loop variable shadowing

- `for-loop-variable-shadow.c` — A variable declared in the loop body sits in
  a nested scope and legally shadows the `for` header's counter (needs C99,
  and `-Wshadow` to see it).
- `for-loop-variable-shadow.cpp` — In C++ the `for` header and its
  substatement share a single scope, so the same declaration is a
  redeclaration error rather than a shadow.

## function declaration carrying no parameter info

- `function-declaration-no-info.c` — An empty parameter list says nothing
  about the parameters, so calling `foo(10, 32)` through `int foo();` compiles
  up to C17 and is rejected from C23 on.
- `function-declaration-no-info.cpp` — An empty parameter list means `(void)`
  in C++, so passing arguments is an error and this file does not compile.

## unnamed parameter in a function definition

- `function-definition-no-param-name.c` — Omitting a parameter name in a
  definition is not ISO C before C23, which `-std=c89 -pedantic-errors` shows
  (plain `-std=c89` accepts it as a GNU extension).
- `function-definition-no-param-name.cpp` — C++ has always allowed unnamed
  parameters, even under `-std=c++98`.

## garbage return

- `garbage-return.c` — Flowing off the end of a value-returning function is
  undefined in C only when the caller uses the result, which this program never
  does.
- `garbage-return.cpp` — The very same code is unconditionally undefined in
  C++, whether or not the returned value is used.

## implicit function declaration

- `implicit-function-declaration.c` — Calling an undeclared function makes a
  C89 compiler assume `int foo();`, so this builds with `-std=c89` and becomes
  an error from C99 on.
- `implicit-function-declaration.cpp` — C++ assumes nothing about an
  undeclared identifier, so the same call fails to compile even under
  `-std=c++98`.

## implicit int

- `implicit-int.c` — Under the C89 implicit int rule a declaration with no
  type returns `int`, which then conflicts with the later `double bar(int)`
  definition.
- `implicit-int-2.c` — The same rule seen from the call site, where three
  implicitly declared functions are all assumed to return `int` and the
  `unsigned int` definition of `baz()` therefore conflicts.
- `implicit-int.cpp` — The implicit int rule is prohibited in C++, so a
  definition with no return type does not compile.

## user defined types

- `user-defined-types.c` — Struct, enum and union tags live in a namespace of
  their own, which is why the tag prefix is needed to name the type, why the
  `typedef` idiom exists, and why an empty struct is not ISO C.
- `user-defined-types.cpp` — A C++ struct is a class, the tag prefix is
  optional unless an ordinary identifier hides the class name, and an empty
  struct has size 1 rather than 0.

## using keyword

There is no `.c` file here, C has no counterpart to this feature in any
standard, C23 included.

- `using-keyword.cpp` — The alias declaration `using X = T;` is the C++11
  alternative to `typedef T X;`. It reads left to right, which is what makes it
  easier than `typedef` for function pointer types, it declares the very same
  kind of name (so aliasing a type twice is a redeclaration, not an error), and
  unlike `typedef` it can be templated. Needs `-std=c++11`.

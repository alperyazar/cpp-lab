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

## const and linkage

There is no `.cpp` file here. The same source is valid C and valid C++, so one
file serves both and the difference shows up only in the object file, which is
why this snippet is read with `nm` rather than by watching it fail to compile.

- `const-linkage.c` — `int x;` has external linkage and `static int y;` has
  internal linkage in both languages, but `const int a = 10;` at file scope
  differs: `const` says nothing about linkage in C, so `a` is external
  (`nm` shows `R a`), while in C++ a namespace scope `const` object has
  internal linkage by default (`nm` shows `r _ZL1a`, the `_ZL` mangling marking
  it internal). The practical consequence is that defining `const int a = 10;`
  in a header is a multiple definition link error in C, and fine in C++ because
  each translation unit gets its own copy. Add `extern` in C++ to get the C
  behaviour back.

## const in a constant expression

- `const-constant-expression.c` — A `const` object in C is a read-only object,
  not a compile time constant, so `x` is never a constant expression and
  `int a[x]` is rejected under `-std=c89 -pedantic-errors`. From C99 on the
  same line compiles, but only because it becomes a variable length array, not
  because `x` became constant; at file scope, where a VLA cannot rescue it, it
  stays an error in every C standard.
- `const-constant-expression.cpp` — A `const` integral object initialized with
  a constant expression *is* itself a constant expression in C++, so `int a[x]`
  is an ordinary fixed size array with no VLA involved, already under
  `-std=c++98`.

## const without an initializer

- `const-uninitialized.c` — C lets a `const` object be declared with no
  initializer. At file scope it is a tentative definition and ends up zero, at
  block scope its value is indeterminate and can never legally be set, so it is
  legal without being useful.
- `const-uninitialized.cpp` — C++ requires a `const` object to be initialized
  at its declaration, at either scope, so the same declaration is a compile
  error.

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

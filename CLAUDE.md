# Instructions

## Git

- Commit ONLY IF I explicitly ask for it. If the request is ambiguous, do not
  commit, just leave the changes in the working tree and wait for an explicit
  commit request.
- Commit directly on the default branch, master, unless I instruct otherwise.
  Do not create a topic branch.
- NEVER push.

## Snippets

- Every snippet says in its own comments which standard it needs, for example
  `-std=c89 -pedantic-errors` or `-std=c++11`. Use that, do not assume the
  compiler default.
- Several files are meant to FAIL to compile, that is the point of the example.
  A compile error is not automatically a bug to fix.
- A topic is normally a `.c` and a `.cpp` file with the same name so the two can
  be read side by side. A file with no counterpart means the other language has
  no equivalent, and that is worth stating explicitly.
- Every snippet gets an entry in the README.md of its directory.
- Markdown is linted with `markdownlint-cli2 <file>`.

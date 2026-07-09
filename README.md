# Problem Solving

A collection of my problem solving solutions and data structure implementations in **C++**, built while working through the ProgrammingAdvices roadmap by Dr. Mohammed Abu-Hadhoud.

## Structure

```
Problem-Solving/
│
├── Fundamentals/       Number manipulation, digits, custom math functions, Fibonacci series
├── Patterns/           Loop-based pattern printing (triangles, letter grids)
├── Security/           Brute-force guessing, simple encryption, key generation
├── Arrays/             Array searching, filtering, copying, and stats
├── Matrices/           2D array operations: fill, sum, search, compare, transpose
├── StringsAndText/     Word/character manipulation: case, counting, splitting, joining, trimming
├── DataStructures/     Stack, queue, singly/doubly linked lists (built from scratch)
├── DateAndTime/        Date arithmetic, calendars, periods, comparisons
├── ClientFileSystem/   Progressive mini-project: client records saved to and read from a text file
└── MiniProjects/       Small complete programs (games, ATM, bank system)
```

## Topics Covered
- Numbers, digits, and custom math functions (round, ceil, floor, sqrt, abs)
- Fibonacci series, solved both iteratively and recursively
- Pattern printing with nested loops
- Arrays: searching, filtering, copying, counting, shuffling
- Matrix operations: random fill, row/column sums, min/max, identity/scalar/sparse checks, transpose, palindrome check
- String processing: case conversion, vowel/character counting, splitting into words, joining, trimming, punctuation removal, word replacement
- Data structures built from scratch: stack, queue, singly & doubly linked lists
- Date and calendar arithmetic: comparisons, periods, business days, formatting
- A step-by-step file-based client system: convert a record to a line and back, save to file, list/find/update/delete by account number, culminating in two small complete programs with a menu
- Mini projects: Rock-Paper-Scissors, a math quiz game, an ATM simulator, and an extended bank system with user permissions

## Technologies
- Language: C++
- Platform: ProgrammingAdvices roadmap exercises

## Notes
- Every file has a short header comment describing the problem it solves.
- Some topics (e.g. date arithmetic, the client file system) have several versions in sequence (v1, v2, Base / Full) reflecting how the solution was refined step by step during the course.
- The `ClientFileSystem` folder builds up step by step: earlier files solve one small piece (e.g. parsing a line, saving to a file) and the later `BankSystem_*` files combine everything into complete menu-driven programs. `ClientRecord.txt` is the data file these programs read from and write to.

## Goal
Improve problem solving skills and algorithmic thinking as part of my journey through the ProgrammingAdvices roadmap.

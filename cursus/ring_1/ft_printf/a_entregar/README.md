*This project has been created as part of the 42 curriculum by dichacon.*

# ft_printf

## Description

The `ft_printf` project is a custom implementation of the standard C library `printf` function. Its objective is to reproduce the behavior of the original function by parsing a format string and printing formatted output to the standard output.

The implementation supports the mandatory conversion specifiers:

- `%c` Character
- `%s` String
- `%p` Pointer
- `%d` Signed decimal integer
- `%i` Signed integer
- `%u` Unsigned decimal integer
- `%x` Lowercase hexadecimal
- `%X` Uppercase hexadecimal
- `%%` Percent sign

The function returns the total number of characters written or `-1` if a write operation fails.

This project provides practical experience with:

- Variadic functions (`stdarg.h`)
- Recursive algorithms
- String parsing
- Number base conversions
- Modular program design

---

# File Structure Overview

| File | Description |
|------|-------------|
| `ft_printf.c` | Main entry point and format parser. |
| `ft_printf.h` | Function prototypes, includes and macros. |
| `process_chars.c` | Character and string conversions (`%c`, `%s`). |
| `process_hex.c` | Hexadecimal and pointer conversions (`%x`, `%X`, `%p`). |
| `process_nums.c` | Signed and unsigned decimal conversions (`%d`, `%i`, `%u`). |
| `ft_printf_utils.c.c` | Helper functions shared by the different modules. |

---

# Technical Decisions: Algorithms & Data Structures

## Parsing Algorithm

The implementation follows a **single-pass linear parsing algorithm**.

The format string is traversed exactly once from left to right.

- Ordinary characters are immediately written to the standard output.
- When a `%` character is found, the next character is interpreted as a conversion specifier.
- Control is dispatched to the corresponding conversion function.

### Why this algorithm?

This solution was chosen because:

- it performs only one traversal of the input string;
- it has **O(n)** time complexity, where *n* is the length of the format string;
- it closely matches the behavior of the original `printf`;
- it keeps the code simple and modular.

---

## Number Conversion

Decimal and hexadecimal numbers are printed using a **recursive division algorithm**.

Each recursive call divides the number by its base until the most significant digit is reached. During the recursive return, every remainder is converted into its corresponding character and printed.

### Why recursion?

The recursive solution was selected because:

- digits are naturally printed in the correct order;
- no temporary buffers are required;
- no string reversal is necessary;
- memory consumption remains constant except for the recursion stack.

---

## Pointer Formatting

Pointers are treated as unsigned memory addresses.

The implementation first prints the `"0x"` prefix and then reuses the hexadecimal conversion algorithm to print the address.

### Why reuse the hexadecimal algorithm?

This avoids duplicated code while keeping pointer formatting consistent with the standard library implementation.

---

## Variadic Arguments

Variable arguments are handled through the standard C macros defined in `<stdarg.h>`:

- `va_list`
- `va_start`
- `va_arg`
- `va_end`

Each argument is extracted only when its corresponding format specifier is encountered.

---

## Data Structures

The project intentionally avoids complex data structures.

Only the following are required:

- the input format string (`const char *`);
- a `va_list` object to access variable arguments;
- constant character arrays representing decimal and hexadecimal bases.

No linked lists, arrays, trees, queues or stacks are necessary because the parser processes the input sequentially and prints each result immediately.

---

## Memory Management

The implementation writes characters directly using the `write()` system call.

No intermediate formatted strings are generated.

### Why?

This design:

- minimizes memory usage;
- avoids dynamic allocations during printing;
- prevents memory leaks;
- keeps the implementation efficient and simple.

---

# Call Graph & Execution Flow

```text
                       ┌──────────────────────────┐
                       │  ft_printf (Entry Point) │
                       └─────────────┬────────────┘
                                     │
            ┌────────────────────────┼──────────────────────────┐
            ▼                        ▼                          ▼
  ┌───────────────────┐      ┌───────────────────┐      ┌───────────────────┐
  │ process_chars.c   │      │ process_hex.c     │      │ process_nums.c    │
  └─────────┬─────────┘      └─────────┬─────────┘      └─────────┬─────────┘
            │                          │                          │
     ┌──────┴──────┐            ┌──────┴──────┐            ┌──────┴──────┐
     ▼             ▼            ▼             ▼            ▼             ▼
 print_char     print_str    print_ptr     print_hex    	  print_int  
```

## Call Graph Explanation

### ft_printf()

Acts as the dispatcher.

It scans the format string one character at a time.

- Regular characters are printed immediately.
- Conversion specifiers invoke the appropriate processing function.
- Every function returns the number of printed characters.

---

### Character Module

Handles:

- `%c`
- `%s`

Responsible for character-by-character output and NULL string handling.

---

### Hexadecimal Module

Handles:

- `%x`
- `%X`
- `%p`

Uses a shared hexadecimal conversion algorithm.

Pointers additionally print the `"0x"` prefix.

---

### Numeric Module

Handles:

- `%d`
- `%i`
- `%u`

Signed and unsigned decimal conversions share the same recursive printing strategy.

---

# Function Descriptions

## `int ft_printf(const char *format, ...)`

### Description

Main dispatcher that parses the format string and prints formatted output.

### Parameters

- `format` : format string.
- `...` : variable arguments.

### Returns

Total number of printed characters or `-1` on failure.

---

## `int print_char(char c)`

### Description

Prints one character.

### Parameters

- `c` : character to print.

### Returns

Always returns `1`.

---

## `int print_str(char *s)`

### Description

Prints a string.

If `s == NULL`, prints `(null)`.

### Parameters

- `s` : string pointer.

### Returns

Number of printed characters.

---

## `int print_int(int n)`

### Description

Prints a signed decimal integer.

### Parameters

- `n` : integer value.

### Returns

Number of printed characters.

---

## `int print_hex(unsigned int n, char format)`

### Description

Prints an unsigned integer in hexadecimal.

### Parameters

- `n` : value.
- `format` : `'x'` or `'X'`.

### Returns

Number of printed characters.

---

## `int process_ptr(unsigned long long ptr)`

### Description

Prints a pointer using hexadecimal notation prefixed with `"0x"`.

### Parameters

- `ptr` : memory address.

### Returns

Number of printed characters.

---

# Instructions

## Manual Compilation

Compile every source file and create the static library:

```bash
cc -Wall -Wextra -Werror ft_printf.c process_chars.c process_hex.c process_nums.c ft_printf_utils.c.c -c
ar rcs libftprintf.a *.o
```

---

## Compile with a custom `main.c`

After creating the library, compile your own test program:

Using the library directly:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a
```

Or using the linker:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf
```

Execute the generated program:

```bash
./a.out
```

---

# Makefile Commands

| Command | Description |
|---------|-------------|
| `make` | Builds the static library `libftprintf.a`. |
| `make clean` | Removes all object files. |
| `make fclean` | Removes object files and the library. |
| `make re` | Performs `fclean` followed by `make`. |
| `make test` | Compiles the library together with `main.c` for testing. |
| `make debug` | Compiles with debug symbols (`-g`) for GDB debugging. |

---

# Resources

## Documentation

- `printf(3)`
- `stdarg(3)`
- The C Programming Language (Kernighan & Ritchie)

## Tutorials

- 42 Network documentation
- Peer evaluations and collaborative learning sessions

## AI Usage

An AI assistant (Gemini) was used **exclusively for documentation purposes** to help structure, organize and translate this `README.md`.

No source code, algorithms or project implementation were generated or modified using AI.

*This project has been created as part of the 42 curriculum by dichacon.*

# ft_printf

## Description
The `ft_printf` project is a custom implementation of the standard C library `printf` function. The main goal is to mimic its behavior by parsing a format string and printing formatted output to the standard output. It supports various conversion specifiers (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`) and returns the total number of characters printed, or a negative value on failure. This project provides a deep understanding of variadic functions in C and string manipulation.

## File Structure Overview
- `ft_printf.c`: Contains the main entry point and format parsing loop.
- `ft_printf.h`: Header file containing prototypes, macros, and standard includes.
- `ft_printf_chars.c`: Handles character and string printing operations.
- `ft_printf_hex.c`: Implements hexadecimal translations and pointer formatting.
- `ft_printf_nums.c`: Implements signed and unsigned base-10 integer outputs.
- `ft_printf_utils.c`: Contains low-level helper functions for standard conversions.

## Technical Decisions: Algorithms & Data Structures
- **Parsing Algorithm:** The project uses a single-pass sequential scanning algorithm. It iterates through the format string character by character. When a `%` symbol is encountered, it dispatches the control flow to specialized conversion functions using a variadic argument list (`va_list`).
- **Data Structures:** Variadic arguments are handled using the standard `va_list` structure defined in `<stdarg.h>`. The architecture avoids dynamic allocations where possible, directly printing to the standard output to optimize performance and prevent memory leaks.
- **Hexadecimal Handling:** Lowercase and uppercase conversions share the same underlying base-16 conversion algorithm, utilizing a flag argument to switch character arrays.

## Call Graph
```text
ft_printf (Entry Point)
   │
   ├──► Handle Chars (ft_printf_chars.c)
   │     ├──► ft_print_char
   │     └──► ft_print_str
   │
   ├──► Handle Hex   (ft_printf_hex.c)
   │     ├──► ft_print_ptr
   │     └──► ft_print_hex
   │
   ├──► Handle Nums  (ft_printf_nums.c)
   │     ├──► ft_print_int
   │     └──► ft_print_unsigned
   │
   └──► Utilities    (ft_printf_utils.c)
         └──► Helper functions
```

## Function Descriptions

### 1. `int ft_printf(char const *format, ...)`
- **Description:** The main dispatcher function that iterates over the format string and processes arguments.
- **Parameters:**
  - `format`: The string containing text and format specifiers.
  - `...`: A variable number of arguments corresponding to the specifiers.
- **Return Value:** The total count of characters written to stdout, or `-1` if an error occurs.

### 2. `int ft_print_char(char c)`
- **Description:** Outputs a single character to standard output.
- **Parameters:**
  - `c`: The character to display.
- **Return Value:** The number of characters printed (always 1).

### 3. `int ft_print_str(char *s)`
- **Description:** Iterates through a string and outputs each character to stdout. Handles NULL strings safely.
- **Parameters:**
  - `s`: Pointer to the string to display.
- **Return Value:** The length of the string printed, or 6 if the string is NULL (printing "(null)").

### 4. `int ft_print_int(int n)`
- **Description:** Converts a signed integer into its ASCII representation and prints it.
- **Parameters:**
  - `n`: The signed integer value to output.
- **Return Value:** Total count of digits and signs printed.

### 5. `int ft_print_unsigned(unsigned int n)`
- **Description:** Converts an unsigned integer into its ASCII representation and prints it.
- **Parameters:**
  - `n`: The unsigned integer value to output.
- **Return Value:** Total count of digits printed.

### 6. `int ft_print_hex(unsigned int n, char format)`
- **Description:** Converts an unsigned integer into a base-16 string (hexadecimal) and prints it.
- **Parameters:**
  - `n`: The value to convert.
  - `format`: Character ('x' or 'X') indicating lowercase or uppercase formatting.
- **Return Value:** Total hexadecimal digits printed.

### 7. `int ft_print_ptr(unsigned long long ptr)`
- **Description:** Formats a pointer memory address into hexadecimal notation prefixed with "0x".
- **Parameters:**
  - `ptr`: The memory address to convert and print.
- **Return Value:** Total characters printed including the "0x" prefix.

## Instructions

### Manual Compilation
To compile all the source files manually without using the Makefile configuration, execute the following terminal command:
```bash
cc -Wall -Wextra -Werror ft_printf.c ft_printf_chars.c ft_printf_hex.c ft_printf_nums.c ft_printf_utils.c -c
ar rcs libftprintf.a *.o
```

### Makefile Commands
The project includes a robust Makefile supporting compilation, testing, and debugging workflows:
- `make`: Compiles all source files and generates the static library archive `libftprintf.a`.
- `make clean`: Removes all intermediary object files (`.o`) generated during compilation.
- `make fclean`: Cleans all object files and deletes the final `libftprintf.a` library file.
- `make re`: Triggers a full clean and rebuilds the library from scratch (`fclean` followed by `make`).
- `make test`: Compiles the library alongside a `main.c` file to quickly run functional tests.
- `make debug`: Compiles the project with debug symbols (`-g`) enabled for debugging via GDB.

## Resources
- **Documentation:** Standard C Library documentation for `printf(3)` and `stdarg(3)` manual pages.
- **Tutorials:** 42 Network documentation and peer-guided learning guides for variadic functions.
- **AI Usage:** An AI assistant (Gemini) was utilized exclusively for documentation purposes to structure, format, and translate this comprehensive `README.md` file following specific project requirements. No application source code was generated or altered by AI tools.

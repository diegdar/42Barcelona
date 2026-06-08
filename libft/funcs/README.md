# *This project has been created as part of the 42 curriculum by <dichacon>.*

# Libft

## Description

**Libft** is a custom C library developed as part of the 42 School curriculum. The goal of this project is to recreate a set of standard C library functions while gaining a deeper understanding of memory management, string manipulation, linked lists, and low-level programming concepts.

This library serves as a foundation for future 42 projects and provides a collection of utility functions that can be reused throughout the cursus.

The project is divided into three main parts:

1. **Libc Functions Recreation**

   * Reimplementation of commonly used functions from the standard C library.

2. **Additional Utility Functions**

   * Custom functions not present in the standard library but frequently useful in C programming.

3. **Linked List Functions**

   * A complete set of functions for managing singly linked lists.

---

## Features

### Character Checks

| Function     | Description                                      |
| ------------ | ------------------------------------------------ |
| `ft_isalpha` | Checks if a character is alphabetic              |
| `ft_isdigit` | Checks if a character is a digit                 |
| `ft_isalnum` | Checks if a character is alphanumeric            |
| `ft_isascii` | Checks if a character belongs to the ASCII table |
| `ft_isprint` | Checks if a character is printable               |
| `ft_toupper` | Converts a character to uppercase                |
| `ft_tolower` | Converts a character to lowercase                |

---

### String Functions

| Function      | Description                                                   |
| ------------- | ------------------------------------------------------------- |
| `ft_strlen`   | Calculates string length                                      |
| `ft_strchr`   | Finds first occurrence of a character                         |
| `ft_strrchr`  | Finds last occurrence of a character                          |
| `ft_strncmp`  | Compares strings up to n characters                           |
| `ft_strdup`   | Duplicates a string                                           |
| `ft_strlcpy`  | Copies strings safely                                         |
| `ft_strlcat`  | Concatenates strings safely                                   |
| `ft_strnstr`  | Finds a substring in a string                                 |
| `ft_substr`   | Extracts a substring                                          |
| `ft_strjoin`  | Joins two strings                                             |
| `ft_strtrim`  | Removes specified characters from both ends                   |
| `ft_split`    | Splits a string into an array of strings                      |
| `ft_strmapi`  | Applies a function to each character and creates a new string |
| `ft_striteri` | Applies a function to each character in-place                 |

---

### Memory Functions

| Function     | Description                                      |
| ------------ | ------------------------------------------------ |
| `ft_memset`  | Fills memory with a constant byte                |
| `ft_bzero`   | Sets memory to zero                              |
| `ft_memcpy`  | Copies memory blocks                             |
| `ft_memmove` | Copies memory blocks safely with overlap support |
| `ft_memchr`  | Searches memory for a byte                       |
| `ft_memcmp`  | Compares memory blocks                           |
| `ft_calloc`  | Allocates and initializes memory                 |

---

### Conversion Functions

| Function  | Description                     |
| --------- | ------------------------------- |
| `ft_atoi` | Converts a string to an integer |
| `ft_itoa` | Converts an integer to a string |

---

### File Descriptor Output Functions

| Function        | Description                             |
| --------------- | --------------------------------------- |
| `ft_putchar_fd` | Writes a character to a file descriptor |
| `ft_putstr_fd`  | Writes a string to a file descriptor    |
| `ft_putendl_fd` | Writes a string followed by a newline   |
| `ft_putnbr_fd`  | Writes an integer to a file descriptor  |

---

### Linked List Functions

The linked list implementation is based on the following structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function          | Description                                             |
| ----------------- | ------------------------------------------------------- |
| `ft_lstnew`       | Creates a new node                                      |
| `ft_lstadd_front` | Adds a node at the beginning                            |
| `ft_lstadd_back`  | Adds a node at the end                                  |
| `ft_lstsize`      | Counts the number of nodes                              |
| `ft_lstlast`      | Returns the last node                                   |
| `ft_lstdelone`    | Deletes a single node                                   |
| `ft_lstclear`     | Deletes and frees an entire list                        |
| `ft_lstiter`      | Applies a function to every node                        |
| `ft_lstmap`       | Creates a new list by applying a function to every node |

---

## Project Structure

```text
libft/
├── Makefile
├── libft.h
├── README.md
├── ft_atoi.c
├── ft_bzero.c
├── ft_calloc.c
├── ...
└── ft_lstmap.c
```

---

## Instructions

### Compiler and Flags

The project is compiled using either `cc` or `gcc` with the following flags:

```bash
-Wall -Wextra -Werror
```

These flags enforce strict compilation rules:

| Flag      | Purpose                                             |
| --------- | --------------------------------------------------- |
| `-Wall`   | Enables most common compiler warnings               |
| `-Wextra` | Enables additional warnings not included in `-Wall` |
| `-Werror` | Treats all warnings as compilation errors           |

Using these flags helps maintain clean, reliable, and production-quality code.

---

## Building the Library

### `make`

```bash
make
```

This is the default target of the Makefile.

When executed, it performs the following steps:

1. Compiles every `.c` source file into an object file (`.o`).
2. Uses the generated object files to create the static library:

   ```bash
   libft.a
   ```
3. Skips recompilation of files that have not changed since the last build.

Example:

```text
ft_strlen.c  -> ft_strlen.o
ft_memcpy.c  -> ft_memcpy.o
ft_split.c   -> ft_split.o
...
```

All generated object files are then archived into `libft.a`.

The resulting library can be linked into future projects without recompiling every source file.

---

## Cleaning Object Files

### `make clean`

```bash
make clean
```

Removes all generated object files (`*.o`) while preserving the library file (`libft.a`).

Example:

Before:

```text
libft.a
ft_strlen.o
ft_memcpy.o
ft_split.o
...
```

After:

```text
libft.a
```

This target is useful when you want to rebuild object files from scratch but keep the library archive.

---

## Full Cleanup

### `make fclean`

```bash
make fclean
```

Performs everything from `make clean` and additionally removes the generated library:

```text
libft.a
```

After running this command, the project directory returns to a state similar to a fresh clone of the repository.

Before:

```text
libft.a
ft_strlen.o
ft_memcpy.o
ft_split.o
...
```

After:

```text
ft_strlen.c
ft_memcpy.c
ft_split.c
...
```

Only source files and project files remain.

---

## Rebuilding the Project

### `make re`

```bash
make re
```

Performs a complete rebuild of the library.

Internally, it is equivalent to:

```bash
make fclean
make
```

The process:

1. Removes all object files.
2. Removes the existing library.
3. Recompiles every source file.
4. Creates a fresh version of `libft.a`.

This target is useful after major code changes or when you want to ensure that no outdated object files remain.

---

## Using the Library in Another Project

Once the library has been generated, it can be linked with any C program.

Example:

```bash
gcc -Wall -Wextra -Werror main.c libft.a -I. -o program
```

Explanation:

| Option       | Description                                 |
| ------------ | ------------------------------------------- |
| `main.c`     | Source file to compile                      |
| `libft.a`    | Static library to link                      |
| `-I.`        | Search for headers in the current directory |
| `-o program` | Name of the executable                      |

Run the executable:

```bash
./program
```

---

## Example Build Workflow

A typical development cycle looks like:

```bash
make
```

Modify source files:

```bash
vim ft_split.c
```

Rebuild:

```bash
make
```

Clean temporary files:

```bash
make clean
```

Complete rebuild:

```bash
make re
```

This workflow minimizes compilation time while keeping the project clean and reproducible.

## Example Usage

```c
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi("42"));
	return (0);
}
```

Compile:

```bash
gcc -Wall -Wextra -Werror main.c libft.a -I. -o program
```

Run:

```bash
./program
```

---

## Technical Decisions

* Written in ISO C.
* Dynamic memory is managed manually using `malloc` and `free`.
* Functions were implemented without relying on their standard library equivalents whenever prohibited by the project subject.
* Linked list functions are fully generic thanks to the use of `void *content`.
* Designed to be reused in future 42 projects such as `get_next_line`, `so_long`, `push_swap`, `minishell`, and others.

---

## Resources

### Official Documentation

* The Open Group Base Specifications:
  https://pubs.opengroup.org/onlinepubs/9699919799/

* Linux Manual Pages:
  https://man7.org/linux/man-pages/

* GNU C Library Documentation:
  https://www.gnu.org/software/libc/manual/

* C Reference:
  https://en.cppreference.com/w/c

---

### Recommended Reading

* *The C Programming Language* by Brian W. Kernighan and Dennis M. Ritchie
* *Expert C Programming: Deep C Secrets* by Peter van der Linden
* *Understanding and Using C Pointers* by Richard Reese

---

### AI Usage

Artificial Intelligence tools were used exclusively as learning aids and code review assistants.

Typical use cases included:

* Clarifying C language concepts.
* Understanding pointer behavior and memory management.
* Reviewing implementations for potential memory leaks or segmentation faults.
* Receiving feedback on coding style and project requirements.
* Improving project documentation.

No AI-generated code was copied directly into the final implementation without prior analysis, understanding, and adaptation by the author.

---

## Author

**<dichacon>**

42 School Project


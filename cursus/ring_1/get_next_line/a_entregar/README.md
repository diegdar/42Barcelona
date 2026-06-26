*This project was created as part of the 42 curriculum by dichacon.*

# Get Next Line - 42 Barcelona

## 📝 Description
The goal of this project is simple yet crucial: to program a C function capable of reading and returning a complete line from a file descriptor (fd), ending with a newline character (`\n`) whenever one exists. 

Repeatedly calling `get_next_line()` allows you to read the full content of a text file or the standard input (`stdin`) line by line. This method processes data efficiently without loading the entire document into the system memory all at once. This project serves as an immersive introduction to the fundamental concept of static variables in C and dynamic memory allocation using variable buffer sizes managed at compile time.

---

## ⚙️ Compilation and Usage Instructions

The function is designed to be integrated seamlessly into other software or tested using custom main programs. Compilation requires defining the buffer size for the `read()` system call using the `-D BUFFER_SIZE=n` flag[cite: 102, 103].

### Basic Compilation
To compile the project alongside your own test file (e.g., `main.c`), run the following command in your terminal:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test

```

If no `BUFFER_SIZE` is explicitly provided during compilation, the header file `get_next_line.h` includes a safe default fallback value of `4096`.

### Execution

To read from a standard text file:

```bash
./gnl_test your_file.txt

```

To read directly from the terminal's standard input (`stdin`):

```bash
./gnl_test

```

---

## 🧠 Algorithmic Strategy and Justification

The core challenge of this project lies in preserving text read "from the future" between consecutive function calls. Since the read chunk size is bound by an arbitrary `BUFFER_SIZE` , a single call to `read()` might fetch multiple lines or leave a partial line fragment behind.

### Algorithmic Workflow

```
[Call to get_next_line]
         │
         ▼
 ┌──────────────┐
 │ fill_storage │ ◄──── Reads from fd in BUFFER_SIZE chunks and calls
 └───────┬──────┘       ft_strjoin_with_free until a '\n' or EOF is found.
         │
         ▼
 ┌──────────────┐
 │ Has a \n?    ├─► YES: Extracts line up to \n using ft_strndup.
 └───────┬──────┘        Updates storage by cutting the remainder via cut_excess.
         │
         └────────► NO: Returns the remaining storage as the last line
                        and cleans up memory (storage = NULL).

```

### Key Components:

1. The Static Variable (`static char storage`): Serves as persistent memory inside the data segment of the application. It preserves fragments of text fetched by `read()` that belong to subsequent lines, keeping them available for the next call to `get_next_line()`.

2. `fill_storage`: Iteratively reads from the file descriptor and appends incoming chunks into the `storage` accumulator utilizing `ft_strjoin_with_free`. The loop breaks optimally as soon as a newline character (`\n`) is identified in memory or the end of the file (EOF) is reached.
3. 
Leak-Free Memory Management: Every utility function assumes a strict responsibility over freeing obsolete pointers. `ft_strjoin_with_free` safely deallocates the previous instance of `storage` before reassigning the newly joined memory slice, and `cut_excess` makes an exact duplicate of the leftover string following the `\n` before freeing the processed parent node.

---

## 📚 Resources and AI Statement

### Consulted References

- Linux Programmer's Manual for input/output system calls: `man 2 read`.
- Memory duration and scope of local static variables in the C standard.
- Memory leak analysis and register inspection using debugging utilities like GDB.
- w3schools to understand how read works with clear examples. 

### Artificial Intelligence Implementation Disclosure

In alignment with the academic regulations of 42 , AI tools were used mindfully and exclusively as learning aids for the following technical tasks:
 
Conceptual Clarification: Theoretical deep-dives regarding the lifecycle and scope of local static variables versus global parameters.
 
Technical Debugging: Diagnostic support identifying dynamic allocation issues—specifically tracking a `double free` error caused by variable scope overlap during helper function modularization—and correcting preprocessor formatting rules required by the Norminette (`PREPROC_BAD_INDENT`).
 
Performance Analysis: Understanding kernel-level behaviors (such as lazy allocation or page fault traps) when executing code with extreme boundary values for `BUFFER_SIZE` (ranging from `1` to `1,000,000,000`).

No functional code blocks were automated or plagiarized, keeping the emphasis on peer learning, line-by-line validation, and original algorithmic reasoning.

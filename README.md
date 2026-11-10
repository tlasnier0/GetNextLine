*This activity has been created as part of the 42 curriculum by tlasnier.*

# get_next_line

## Description
**get_next_line** is a project of the 42 curriculum. The goal is to program a function that returns a line read from a file descriptor, allowing you to read text line by line efficiently, whether from a file, standard input (stdin), or network redirection.

Features:
- Reads a file descriptor line by line, including the terminating newline character (`\n`) when present.
- Works seamlessly with any arbitrary `BUFFER_SIZE`.
- Manages static memory storage (*stash*) to handle leftover bytes between successive calls without losing data.

---

## Instructions

### Compilation
This project does not require a `Makefile` and is compiled directly using `cc` with the standard 42 flags (`-Wall -Wextra -Werror`).

- **Compile with a custom `BUFFER_SIZE`** (e.g., `42`):
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

- **Compile without the `-D BUFFER_SIZE` flag** (uses the default `BUFFER_SIZE` of `2048` defined in `get_next_line.h`):
```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
```

### Execution
Run the compiled binary:
```bash
./gnl
```
---

## Algorithm and Data Structure

- **Static Variable (*Stash*)**: A local static pointer retains data remaining in the buffer between function calls, ensuring that no read bytes are ever lost across multiple calls to `get_next_line`.
- **Modular Sub-functions**:
  - Reading loop (`stash_next_line`) accumulates data from the file descriptor into the reserve until a newline is found or EOF is reached.
  - Extraction routine (`extract_line`) isolates the exact line up to the newline.
  - Cleanup routine (`clean_stash`) trims the consumed text and preserves only the remaining surplus for the next call.

---

## Resources & AI Disclosure

### References
- Linux Programmer's Manual (`man 2 read`) for system call behavior and file descriptor management.
- C standard library documentation regarding dynamic memory allocation (`malloc`, `free`) and string utilities.
- [DeepL](https://www.deepl.com) - Translation tool used to assist with writing the README file.

### AI Usage
Artificial Intelligence was used strictly as a conceptual tutor and language assistant:

- Conceptual Learning: Explaining low-level C mechanisms and complex programming logic (such as pointer arithmetic, heap allocation behavior, and data structures) for theoretical understanding, without writing or generating any project code.
- Documentation Review: Reviewing and refining the English translation of this README, correcting phrasing errors, and improving overall language fluency.

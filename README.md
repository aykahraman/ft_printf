*This project has been created as part of the 42 curriculum by akahrama.*

# ft_printf

## Description

**ft_printf** is a custom implementation of the C standard library function `printf()`. The goal is to replicate the behavior and return values of the original `printf` while adhering to the strict 42 School Norm constraints. The implementation handles the following format specifiers:

| Specifier | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string (handles `NULL` → `(null)`) |
| `%p` | Prints a pointer address in hexadecimal (handles `NULL` → `(nil)`) |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a number in lowercase hexadecimal |
| `%X` | Prints a number in uppercase hexadecimal |
| `%%` | Prints a literal percent sign |

The function returns the total number of characters printed, or `-1` on write failure.

## Algorithm & Data Structure

### Architecture

The implementation follows a **modular dispatch** pattern:

1. `ft_printf` iterates through the format string character by character.
2. When a `%` is encountered, the next character (specifier) is passed to `ft_parse_format`.
3. `ft_parse_format` dispatches to the appropriate handler function based on the specifier.
4. Each handler uses **recursive digit decomposition** to convert numbers to their string representation.

### Why Recursion?

Numeric conversions (`%d`, `%u`, `%x`, `%p`) use recursive functions instead of arrays or buffers:

- **No buffer management** — digits are printed in the correct order naturally via the call stack.
- **Minimal memory footprint** — no need for `malloc` or temporary arrays.
- **Stack depth** is bounded: at most 20 recursive calls (for `UINT64_MAX` in hex), well within safe limits.

### Error Propagation

Every `write()` call is checked. If any write fails (`-1`), the error propagates upward through all function calls, and `ft_printf` returns `-1`. This is achieved via:

- A `len` pointer passed into recursive functions, set to `-1` on failure.
- A `ft_check_write` helper that stops accumulation on any negative value.

### Edge Case Handling

| Case | Behavior |
|---|---|
| `%s` with `NULL` | Prints `(null)` (matches `printf` behavior) |
| `%p` with `NULL` | Prints `(nil)` |
| `%d` with `INT_MIN` | Cast to `long` to avoid overflow on negation |
| `%%` | Prints a single `%` |
| `NULL` format string | Returns `-1` |

## Instructions

### Compilation

```bash
make        # Builds libftprintf.a and .o files
make clean  # Removes object files
make fclean # Removes object files and the library
make re     # Full recompile
```

### Usage

Include the header and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you are %d years old!\n", "akahrama", 42);
    return (0);
}
```

Compile with:

```bash
cc main.c -L. -lftprintf -o my_program
```

### File Structure

```
ft_printf/
├── ft_printf.h           — Header (macros & prototypes)
├── ft_printf.c           — Main function & format dispatcher
├── ft_print_char.c       — %c and %s handlers
├── ft_print_nbr.c        — %d and %i handlers
├── ft_print_hex.c        — %x, %X, and %p handlers
├── ft_print_unsigned.c   — %u handler
└── Makefile              — Build system
```

## Resources

- [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html) — Official printf manual page
- [man 3 stdarg](https://man7.org/linux/man-pages/man3/stdarg.3.html) — Variadic function documentation (`va_start`, `va_arg`, etc.)
- [42 Norm v4](https://github.com/42School/norminette) — 42 School coding standards and the Norminette tool
- [Francinette](https://github.com/xicodomingues/francinette) — Community-built tester for 42 projects

### AI Usage

AI (Gemini) was used as a pair-programming assistant for:
- **Architecture design** — planning file structure and modular function decomposition.
- **Code generation** — writing the initial implementation of all source files.
- **Edge case analysis** — identifying and handling cases like `INT_MIN`, `NULL` pointers, and write failures.
- **Testing** — creating a comparison test suite against the standard `printf`.

All generated code was reviewed, verified for Norm compliance, and tested before submission.

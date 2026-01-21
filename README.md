# get_next_line
This project has been created as part of the 42 curriculum by lhaydar

## Description

`get_next_line` is a C function that reads a line from a file descriptor. The function returns one line at a time from a text file, no matter the size of the line or the file. This project introduces the concept of static variables in C and teaches efficient file reading with buffers.

The function prototype is:
```c
char *get_next_line(int fd);
```
### Key Features:
- Reads and returns one line at a time from any file descriptor
- Handles multiple file descriptors without losing track of reading position
- Uses static variables to maintain state between function calls
- Configurable buffer size through `BUFFER_SIZE` macro
- Properly manages memory allocation and deallocation
- Handles edge cases (empty files, EOF, read errors)

### Return Values:
- **Read line**: The line that was read (including the terminating `\n` character, if present)
- **EOF reached**: NULL when the end of file is reached and there's no more content
- **Error**: NULL when an error occurs



## Instructions
### Compilation

Compile the project with:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o get_next_line
```

You can adjust the `BUFFER_SIZE` value to control the number of bytes read at a time:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c -o get_next_line
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c main.c -o get_next_line
```
### Files Structure

- **get_next_line.c**: Main function implementation
- **get_next_line_utils.c**: Helper/utility functions
- **get_next_line.h**: Header file with function prototypes and macros
- **main.c**: Test file for the function
- **file.txt**: Sample text file for testing


## Data Structures and Algorithms
### Data Structures

1. **Static Variable (`static char *left_c`)**
   - Maintains the leftover characters between function calls
   - Persists across multiple invocations of `get_next_line`
   - Stores the remaining text after extracting a complete line
   - Essential for maintaining state in a stateful function

2. **Character Buffers**
   - `char *buffer`: Temporary buffer for reading chunks from file descriptor
   - Size determined by `BUFFER_SIZE` macro
   - Allocated dynamically and freed after use

3. **Dynamic Strings**
   - All strings are dynamically allocated using `malloc`
   - Allows handling of arbitrary line lengths
   - Requires careful memory management to prevent leaks

### Algorithms

1. **Buffered Reading Algorithm**
   - Reads `BUFFER_SIZE` bytes at a time from the file descriptor
   - More efficient than reading one byte at a time
   - Reduces the number of system calls (`read()`)
   - Continues reading until a newline (`\n`) is found or EOF is reached

2. **String Concatenation Pattern**
   - Uses `ft_strjoin` to concatenate newly read data with leftover data
   - Creates new string and frees old one to prevent memory leaks
   - Pattern: `tmp = left_c; left_c = ft_strjoin(tmp, buffer); free(tmp);`

3. **Line Extraction Algorithm**
   - Searches for newline character in the accumulated buffer
   - Extracts the line up to and including the newline
   - Saves remaining characters in static variable for next call
   - Uses `ft_substr` to split the buffer at the newline position

4. **State Management**
   - Static variable maintains reading position across calls
   - Handles EOF by returning NULL and resetting state
   - Error handling clears static variable to prevent memory leaks

### Helper Functions

- **ft_strlen**: Calculates string length 
- **ft_strdup**: Duplicates a string 
- **ft_substr**: Extracts substring from string 
- **ft_strjoin**: Joins two strings 
- **ft_strchr**: Finds character in string 
- **fill_str**: Helper for ft_strjoin to copy characters 


## Resources
- [Static Variables](https://www.geeksforgeeks.org/c/static-variables-in-c/)
- [Youtube](https://www.youtube.com/watch?v=kR4FyNzVDBE)
- Linux Manual Page
- [GeeksforGeeks](https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/)


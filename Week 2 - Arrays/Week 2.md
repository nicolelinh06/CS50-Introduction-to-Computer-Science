# Week 2 - Arrays

## Welcome!
In our previous session, we learned about **C**, a text-based programming language. This week, we are diving deeper into programming fundamentals with a focus on **problem-solving** and how to approach computer science challenges.

## Compiling
*Encryption* is the act of hiding plain text from prying eyes. *Decrypting* is the act of taking an encrypted piece of text and returning it to a human-readable form.

### Key Points:
- **Compiler**: A program that converts *source code* into *machine code*.
- **Clang**: The compiler used in CS50, invoked via the `make` command.
- **Steps in Compilation**:
  1. ***Preprocessing***: Includes header files like `#include <stdio.h>`.
  2. ***Compiling***: Converts your program into *assembly code*.
  3. ***Assembling***: Turns *assembly code* into *machine code*.
  4. ***Linking***: Combines library and your code into an executable.

## Debugging
Coding involves mistakes. There are different methods to debug code:

- **Print Statements**: Modify your code to see variable values.
- **VS Code Debugger**: Set breakpoints and step through code.
- **Rubber Duck Debugging**: Explain your code out loud to identify errors.

## Arrays
In Week 0, we talked about *data types* such as `bool`, `int`, `char`, `string`, etc.

Each data type requires a certain amount of system resources:
- `bool` 1 byte
- `int` 4 bytes
- `long` 8 bytes
- `float` 4 bytes
- `double` 8 bytes
- `char` 1 byte
- `string` ? bytes

Inside of your computer, you have a finite amount of memory available.

*Arrays* allow storing data back-to-back in memory.
```C
#include <stdio.h>

const int N = 3;  // Constant
float average(int length, int array[]); // Prototype

int main(void)
{
    for (int i = 0; i < N; i++) // Get scores
    {
        printf("Score: ");
        scanf("%i", &scores[i]);
    }
    printf("Average: %f\n", average(N, scores));  // Print average
}

float average(int length, int array[])  // Calculate average
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
```
Notice that `score[0]` examines the value at this location of memory by `indexing into` the array called `scores` at location `0` to see what value is stored there.

## Strings
A **string** is an *array* of characters. Each string ends with a special `\0` (NUL) character.

``` C
#include <stdio.h>

int main(void)
{
    char* words[2];

    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
}
```
 `char*` (char pointer): a pointer to the first character in such an *array*.

## String Length
Calculate string length by iterating until `\0`:.
```C
int string_length(string s) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}
```
Imagine we wanted to create a program that converted all *lowercase* characters to *uppercase* ones. 
```C
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    // Declare a buffer to hold the input string
    char s[100];  // Adjust the size if needed

    // Get the input string from the user, including spaces
    printf("Before: ");
    scanf("%[^\n]", s);  // This reads until a newline (Enter key) is encountered

    // Print the modified string in uppercase
    printf("After:  ");
    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");

    return 0;
}
```
- `%[^\n]`: `scanf()` read all characters until it encounters a newline (`\n`). The `^` character means "not".
- **Buffer size** (`char s[100];`): The buffer is declared to store up to 99 characters plus a `null terminator`.

## Command-Line Arguments
**Command-line arguments** are those arguments that are passed to your program at the command line. 

Using the syntax of this program, executing `./greet David` and the program saying `hello, David`.
```C
int main(int argc, string argv[]) {
    if (argc == 2) {
        printf("hello, %s\n", argv[1]);
    } else {
        printf("hello, world\n");
    }
}
```
- `int argc`: represents the **argument count**, which tells you how many arguments were passed to the program (including the program name).
- `string argv[]`: an *array* of strings (character arrays), where each element contains one of the arguments passed to the program.
- `argc == 2`: checks if exactly two arguments were passed. 
  - The first argument `argv[0]`: the name of the program (`./greet `).
  - The second argument `argv[1]`:  the first user-provided argument (`David`).

## Exit Status
- When a program ends, a special exit code is provided to the computer.
  - When a program exits without error, a status code of `0` is provided the computer. 
  - When an error occurs that results in the program ending, a status of `1` is provided by the computer.

```C
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}
```

## Cryptography
- *Cryptography** is the art of ciphering and deciphering a message.
- `plaintext` and a `key` are provided to a `cipher`, resulting in ciphered text.

The `key` is a special argument passed to the `cipher` along with the `plaintext`. The `cipher` uses the `key` to make decisions about how to implement its `cipher` algorithm.

## Summing Up
In this lesson, you learned more details about *compiling* and *how data is stored within a computer*. 
- The compilation process.
- Debugging methods.
- Using and passing arrays.
- Working with strings.
- Handling command-line arguments.
- Basic cryptography principles.
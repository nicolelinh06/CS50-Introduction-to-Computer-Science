# Week 1 - C

## Welcome!

In this week's session, we covered fundamental programming concepts and introduced the C programming language.

### Recall

- **Source Code vs. Machine Code:** Machines understand binary (machine code), while humans write source code. A compiler translates source code into machine code.
- **Evaluating Code:** Code is evaluated based on correctness (does it work as intended?), design (how well is it structured?), and style (is it aesthetically pleasing and consistent?).

## Hello World

We used Visual Studio Code (VS Code) for our development environment. 
The compiler can be divided into a number of regions:

- ***file explorer*** is on the left side where you can find your files.
- **Text Editor**: the region in the middle where you can edit your program.
- **Command Line Interface**: known as CLI, command line, or terminal window where we can send commands to the computer in the cloud.

The key commands and steps:

1. **Create a File:** 
    ```bash
    code hello.c
    ```
2. **Compile the Code:** 
    ```bash
    make hello
    ```
3. **Run the Program:** 
    ```bash
    ./hello
    ```

### Code Example: Hello World

```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```
- `void`: the function does not return any values. Hence, `(void)`: no values are being provided to the function.
- `#include <stdio.h>`: Includes the standard input/output *library*, a *header* file.
- `printf`: Function to print text. \n is an escape character for a new line.

Compile your code by executing `make hello`. The `.c` extension is omitted in the `make` command, compiler will look for our `hello.c` file and turn it into a program called `hello`.

#### Understanding the Files
- `hello.c`: This is your source code file. It contains the human-readable C code that you wrote.
- `hello`: This is the executable/binary file created by the compiler and contains the machine code generated from `hello.c`. It can be run but cannot be read by the compiler.

## Functions
In C, functions like ``printf` output text. Common errors include missing semicolons and incorrect use of *escape characters*.

You can read about all the capabilities of this library on the [Manual Pages](https://manual.cs50.io/). It provide a means by which to better understand what various commands do and how they function.

Libraries are collections of pre-written functions that others have written in the past that we can utilize in our code.
For example, `cs50.h`is CS50 own library

## Variables

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}
```
- `get_string`: function used to get a string from the user - from CS50 library.
- `%s`: tells the `printf` function to prepare itself to receive a *string*.
- `answer`: a special holding place we call a variable. 

There are many *data types*, such as `int`, `bool`, `char`, and many others.


`printf` allows for many format codes. For example: 
- `%s`: string variables.
- `%i`: int or integer variables. 
- `%f`: float variables.
- `%c`: char or character variables. 

## Conditionals
In C, you can assign a value to an `int` or integer as follows:

``` C
int counter = 0;
counter = counter + 1;
```

C can also be programmed to add one to `counter` as follows: 
``` C
counter = counter++;
```
Or, subtract one to `counter` as follows: 
``` C
counter = counter--;
```

Using this new knowledge about how to assign values to variables, you can program your first conditional statement.
``` C
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}
```
- `get_int`: function used to get a integer from the user.
- `if`, `else if`, `else`: Control structures for branching.

`Flow charts` are a way by which you can examine how a computer program functions. Such charts can be used to examine the efficiency of our code.

In the text editor, write code as follows:
``` C
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user to agree
    char c = get_char("Do you agree? ");

    // Check whether agreed
    if (c == 'Y' || c == 'y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not agreed.\n");
    }
}
```

**Relational Operators**
- `==`: Check if *equal*.
- `!=`: Check if *not equal*.
- `>`: Check if *greater*.
- `<`: Check if *smaller*.
- `>=`: Check if *greater or equal*.
- `<=`: Check if *smaller or equal*.

**Logical Operators**
- `&&`: and
- `||`: or
- `!`: not

## Loops
*Loops* repeat code execution.

### `while` Loop
``` C
int i = 3;
while (i > 0)
{
    printf("meow\n");
    i--;
}
```

### Infinite Loop
``` C
while (true)
{
    printf("meow\n");
}
```
- Use `control-C` to break an infinite loop.

### `for` Loop
``` C
#include <stdio.h>

void meow(int n);

int main(void)
{
    meow(3);
}

// Meow some number of times
void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```

#### Function Declaration (Prototype)
``` C
void meow(int n);
``` 
- **Purpose**: This is a function prototype or declaration.
- **Location**: It is typically placed before the main function or at the top of the file.
- **Purpose of Declaration**: It tells the compiler about the function’s name, return type, and parameters before it is actually used or defined in the code.

## Operators and Abstraction
**Mathematical Operators**
- `+` for addition.
- `-` for subtraction.
- `*` for multiplication.
- `/` for division.
- `%` for remainder.

***Abstraction*** is the art of simplifying our code such that it deals with smaller and smaller problems.
```C
#include <cs50.h>
#include <stdio.h>

int add(int a, int b);

int main(void)
{
    // Prompt user for x
    int x = get_int("x: ");

    // Prompt user for y
    int y = get_int("y: ");

    // Perform addition
    printf("%i\n", add(x, y));
}

int add(int a, int b)
{
    return a + b;
}
```
## Linux and the Command Line
**Linux** is an operating system accessible via the terminal in VS Code. Common commands:
- `cd`: change directory
- `cp`: copy files/directories
- `ls`: list files
- `mkdir`: create a directory
- `mv`: move/rename files
- `rm`: remove files
- `rmdir`: remove directories

Example: `ls` lists files, and `mv Hello.c hello.c` renames `Hello.c` to `hello.c`.

## Comments
Add comments using `//` to explain your code.
```C
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for positive integer
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);

    // Print an n-by-n grid of bricks
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
```

## Types
- **Types** are very important because each type has specific limits. 
- Because of the limits in memory, the highest value of an `int` can be `4294967295`. If you attempt to count an int higher, *integer overflow* will result where an incorrect value will be stored in this variable.
- The number of bits limits how high and low we can count.

**Types** with which you might interact:
- `bool`: true/false
- `char`: single character
- `double`: large floating-point numbers
- `float`: floating-point numbers
- `int`: integers
- `long`: large integers
- `string`: string of characters

## Summing Up
- How to create your first program in C.
- Variables, conditionals, and loops in C.
- Linux command-line basics.
- Adding comments and understanding types.
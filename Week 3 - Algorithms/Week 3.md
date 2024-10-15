# Week 3 - Algorithms

## Welcome!
We introduced the idea of an **algorithm**: a black box that may take an input and create an output. This week, we expand upon algorithms using **pseudocode** and dive into **code** itself. Additionally, we explore the **efficiency** of these algorithm, building on some *low-level concepts* from last week.

An algorithm's design impacts its **time efficiency**. Efficient algorithms can solve problems more quickly, but there’s always a limit!

## Linear Search
Recall the idea of an **array**, blocks of memory that are *consecutive*: *side-by-side* with one another.

Imagine an array of red lockers. We want to *search* if the number 50 is inside. Returning the value true or false.

```c
For each door from left to right
    If 50 is behind door
        Return true
Return false
```
Notice that the above instructions are called **pseudocode**: A human-readable version of the instructions that we could provide the computer. 

You can translate that pseudocode as follows:
```c
For i from 0 to n-1
    If 50 is behind doors[i]
        Return true
Return false
```

## Binary Search
- *Binary search* is another *search algorithm* that could be employed in our task of finding the 50.
- Assuming that the values have been arranged from smallest to largest, here is our pseudocode:
```text
If no doors left
    Return false
If 50 is behind middle door
    Return true
Else if 50 < middle door
    Search left half
Else if 50 > middle door
    Search right half
```
- Using the nomenclature of code, we can further modify our algorithm as follows:
```text
If no doors left
    Return false
If 50 is behind doors[middle]
    Return true
Else if 50 < doors[middle]
    Search doors[0] through doors[middle - 1]
Else if 50 > doors[middle]
    Search doors[middle + 1] through doors[n - 1]
```

## Running Time
*running time* involves an analysis using ***big O notation***.

![alt text](image.png)
- Computer scientists discuss *efficiency* in terms of the *order* of various running times.
- In the above graph, the first algorithm is `O(n)` or in the order of n. The second is in `O(n)` as well. The third is in `O(log n)`.

- The **shape of the curve** that shows the *efficiency* of an *algorithm*. Some common running times we may see are:

  - `O(n²)` 
  - `O(n log n)` - Merge sort
  - `O(n)` - Linear search
  - `O(log n)` - Binary search
  - `O(1)`

Of the running times above, `O(n²)` is considered the worst running time, `O(1)` is the fastest.

- Linear search was of order `O(n)` because it could take `n` steps in the worst case to run.
- Binary search was of order `O(log n)` because it would take fewer and fewer steps to run even in the worst case.

Programmers are interested in both the worst case, or *upper bound*, and the best case, or *lower bound*.

- The `Ω` symbol is used to denote the best case of an algorithm, such as `Ω(log n)`.
- The `Θ` symbol is used to denote where the upper bound and lower bound are the same, where the best case and the worst case running times are the same.

## search.c
Implement **linear search** ourselves by typing code `search.c` in your terminal window:
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // An array of integers
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    // Search for number
    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```
- `int numbers[]`: define the values of each element of the array as we create it. 
- `for loop`: implementation of *linear search*. 
- `return 0`: indicate success and exit the program. 
- `return 1`: exist the program with an error (**failure**).

What if we wanted to search for a *string* within an array?
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // An array of strings
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    // Search for string
    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```
Notice that we cannot utilize `==` as in our previous iteration of this program. Instead, we use `strcmp`, which comes from the `string.h` library. `strcmp` will **return 0** if the strings are the same.

If you see a *segmentation fault*, a part of memory was touched by your program that it should not have access to, do make sure you have `i < 6` instead of `i < 7`.

Combine these ideas of both numbers and strings into a single program. Type code `phonebook.c` into your terminal window:
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Arrays of strings
    string names[] = {"Carter", "David", "John"};
    string numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"};

    // Search for name
    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

## Data Structures
- C allows a way by which we can create our own *data types* via a `struct`.
- Would it not be useful to create our own *data type* called a `person`, that has inside of it a `name` and `number`:
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[3];

    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-617-495-1000";

    people[2].name = "John";
    people[2].number = "+1-949-468-2750";

    // Search for name
    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

## Sorting
- **Sorting** is the act of taking an *unsorted* list of values and transforming this list into a *sorted* one.
- When a list is sorted, searching that list is far less taxing on the computer. We can use binary search on a sorted list, but not on an unsorted one.
- There are many different types of **sorting algorithms**. You can [visualize](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html) a comparison of these algorithms.

## Selection Sort
**Selection sort** is an algorithm that selects the smallest element and moves it to the front. I
```c
For i from 0 to n–1
    Find smallest number between numbers[i] and numbers[n-1]
    Swap smallest number with numbers[i]
```
- Its time complexity is `O(n²)` in the *worst case*. Even when all values are sorted, it will take the same number of steps. 
- Therefore, the *best case* can be noted as `Ω(n²)`. 
- Since both the *upper bound* and *lower bound* cases are the same, the efficiency of this algorithm as a whole can be regarded as `Θ(n²)`.

## Bubble Sort
**Bubble sort** is an algorithm that works by repeatedly swapping elements to “bubble” larger elements to the end.
```c
Repeat n-1 times
    For i from 0 to n–2
        If numbers[i] and numbers[i+1] out of order
            Swap them
    If no swaps
        Quit
```
It has a *worst-case* time complexity of `O(n²)` but can have a *best-case* of `O(n)` if the list is already sorted.

## Recursion
**Recursion** is a concept within programming where a function calls itself. 
```text
If no doors left
    Return false
If number behind middle door
    Return true
Else if number < middle door
    Search left half
Else if number > middle door
    Search right half
```
Notice that we are calling `search` on smaller and smaller iterations of this problem.

This `Week 0`code could have been simplified, to highlight its **recursive properties**:
```text
Pick up phone book
Open to middle of phone book
Look at page
If person is on page
    Call person
Else if person is earlier in book
    Search left half of book
Else if person is later in book
    Search right half of book
Else
    Quit
```

Consider how in `Week 1` we wanted to create a pyramid structure as follows:
```text
  #
  ##
  ###
  ####
```

To implement this using recursion, type `code recursion.c` into your terminal window and write code as follows:
```c
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    // Get height of pyramid
    int height = get_int("Height: ");

    // Draw pyramid
    draw(height);
}

void draw(int n)
{
    // If nothing to draw
    if (n <= 0)
    {
        return;
    }

    // Draw pyramid of height n - 1
    draw(n - 1);

    // Draw one more row of width n
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
```
- Notice the `base case` will ensure the code does not run forever. 
- The line if `(n <= 0)` terminates the recursion because the problem has been solved. 
- Every time `draw` calls itself, it calls itself by `n-1`. At some point, `n-1` will equal `0`, resulting in the `draw` function returning and the program will end.

## Merge Sort
Leverage recursion in our quest for a more *efficient sort algorithm* and implement what is called **merge sort**.
```text
If only one number
    Quit
Else
    Sort left half of number
    Sort right half of number
    Merge sorted halves
```
- **Merge sort** is a very efficient sort algorithm with a *worst case* of `O(n log n)`. 
- The *best case* is still `Ω(n log n)` because the algorithm still must visit each place in the list. 
- Since  the *upper bound* and *lower bound* cases are the same, merge sort is also `Θ(n log n)`.

## Summing Up
In this lesson, you learned:
- Algorithms.
- **Big O notation**.
- **Binary search** and **linear search**.
- Various **sort algorithms** (bubble sort, selection sort, and merge sort).
- Recursion.
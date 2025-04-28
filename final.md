*Snippets from Slides 11-13, HW 6-9, and ChatGPT examples


# Prototype Example
```c
#include <stdio.h>

// Function prototype with parameters
int multiply(int x, int y);

int main() {
    int a = 4, b = 5;
    int result = multiply(a, b); // Call the function with arguments
    printf("The product is: %d\n", result);
    return 0;
}

// Function definition
int multiply(int x, int y) {
    return x * y;
}

```

# Flowchart
Symbol Meanings  
<img src="flowchart-symbols.jpg" width="50%" height="50%">

Example   
<img src="flowchartexample.jpg" width="30%" height="30%">

# File IO

Common File Modes

| Mode  | Meaning                             |
|-------|-------------------------------------|
| "r"   | Read (file must exist)              |
| "w"   | Write (overwrite/create new)        |
| "a"   | Append (write at end of file)        |
| "r+"  | Read + Write (no overwrite)          |
| "w+"  | Read + Write (overwrite/create new) |
| "a+"  | Read + Append                       |


File Write Example
```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("output.txt", "w"); // "w" = write mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fp, "Hello, world!\n");
    fprintf(fp, "Number: %d\n", 42);

    fclose(fp);
    return 0;
}
```
- Always check if `fopen` returned `NULL`
<br></br>          

File Read Example
```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("output.txt", "r");
    char buffer[100];

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer); // print each line
    }

    fclose(fp);
    return 0;
}
```

# Union, Enum, Struct

# Palindrome Checking Recursive

# Static Memory, Dynamic Memory, and Ghost Memory (memory leaks)

```c
#include <stdio.h>
#include <stdlib.h>

// Static memory: global variable
int someStaticMemoryVar = 10;

int main() {
    // Static memory: local (stack) variable
    int localArray[5] = {1, 2, 3, 4, 5};

    // Dynamic memory: allocated at runtime
    int *dynamicArray = (int *)malloc(5 * sizeof(int));
    if (dynamicArray == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Fill dynamic memory
    for (int i = 0; i < 5; i++) {
        dynamicArray[i] = i * 10;
    }

    // Simulate ghost memory: lose the pointer without freeing
    dynamicArray = NULL; // Now the memory is leaked (ghost memory)

    // Program continues...
    printf("Static variable: %d\n", staticVar);
    printf("Local array first element: %d\n", localArray[0]);

    // dynamicArray is NULL now, can't access dynamic memory anymore

    return 0;
}
```

# Pointer logic + swapping 
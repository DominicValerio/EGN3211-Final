#include <stdio.h>

// Tagged struct with typedef
typedef struct Person {
    char name[50];
    int age;
} Person;

// Anonymous enum with typedef
typedef enum {
    RED,
    GREEN,
    BLUE
} Color;

// The difference is that with an anonymous enum 
// you can't say "enum Color favorite" for example

void printPerson(const Person* p, Color favoriteColor);

int main() {
    // Now you can refer to the struct and enum without having to say
    // "struct Person alice" for example
    Person alice = {"Alice", 30}; 
    Color favorite = GREEN;

    printPerson(&alice, favorite);

    return 0;
}

void printPerson(const Person* p, Color favoriteColor) {
    const char* colorName;
    switch (favoriteColor) {
        case RED: colorName = "Red"; break;
        case GREEN: colorName = "Green"; break;
        case BLUE: colorName = "Blue"; break;
        default: colorName = "Unknown";
    }

    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Favorite Color: %s\n", colorName);
}

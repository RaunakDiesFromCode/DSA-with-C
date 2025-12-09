#include <stdio.h>

// Function to swap two integers using call by value
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to swap two integers using call by reference
void swapByReference(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    printf("Before swapping: x = %d, y = %d\n", x, y);

    // Call swapByValue function
    swapByValue(x, y);
    printf("After swapByValue: x = %d, y = %d\n", x, y);

    // Call swapByReference function
    swapByReference(&x, &y);
    printf("After swapByReference: x = %d, y = %d\n", x, y);

    return 0;
}
#include <stdio.h>
int main() {
    int num = 10;
    int *ptr = &num;

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value of ptr: %p\n", ptr);
    printf("Value pointed by ptr: %d\n", *ptr);
    printf("Value pointed by ptr: %d\n", &num);

    // Modify the value using the pointer
    *ptr = 20;

    printf("Modified value of num: %d\n", num);

    return 0;
}
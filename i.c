#include <stdio.h>

int main() {
    int num = 5;
    
    printf("Initial value of num: %d\n", num);
    
    // Postfix increment operator
    int result1 = num++;
    printf("Value of num after postfix increment: %d\n", num);
    printf("Value of result1: %d\n", result1);

    // Prefix increment operator
    int result2 = ++num;
    printf("Value of num after prefix increment: %d\n", num);
    printf("Value of result2: %d\n", result2);
    
    return 0;
}
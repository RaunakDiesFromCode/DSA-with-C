#include <stdio.h>

void swap(int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;
    printf("Swappped value are : %d and %d", a, b);
}

int main()
{

    int aa;
    int bb;
    printf("Enter first number: ");
    scanf("%d", &aa);
    printf("Enter second number: ");
    scanf("%d", &bb);
    swap(aa, bb);
    return 0;
}
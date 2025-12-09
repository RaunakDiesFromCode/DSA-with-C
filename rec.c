#include <stdio.h>

int rec(int n)
{
    if (n > 1)
    {
        return n * rec(n - 1);
    }
        return 1;
}

int main()
{
    printf("Hi %d", rec(5));
    return 0;
}

#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);
    int sum = 0;
    int ncpy = n; 
    while (n>0)
    {
        int t = n % 10;
        sum += factorial(t);
        n /= 10;
    }
    if(sum == ncpy)
    {
        printf("The number is a Krishnamurthy number\n");
    }
    else
    {
        printf("The number is not a Krishnamurthy number\n");
    }
    
    return 0;
}


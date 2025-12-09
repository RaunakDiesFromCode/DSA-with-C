#include <stdio.h>

int generate_divisible_numbers()
{
    int num;
    for (num = 100000000; num <= 999999999; num++)
    {
        if (num % 9 == 0)
        {
            int newnum = num;
            int divisor;
            for (divisor = 8; divisor >= 2; divisor--)
            {
                if (newnum % divisor != 0)
                    break;
                newnum /= 10;
            }
            if (divisor == 1)
            {
                printf("%d\n", num);
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    if (!generate_divisible_numbers())
    {
        printf("No such number found.\n");
    }
    return 0;
}

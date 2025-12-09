#include <stdio.h>

int gen()
{
    int i, higher = 999999999, lower = 100000000, tempsum;
    for (i = lower; i <= higher; i++)
    {
        if (i % 9 == 0)
        {
            tempsum = i;
            int div;
            for (div = 8; div >= 2; div--)
            {
                if (tempsum % div != 0)
                {
                    break;
                }
                tempsum /= 10;
            }
            if (div == 1)
            {
                // printf("%d\n", i);keepkeepke
                return i;
                break;
            }
        }
    }
}

int check(int num, int len)
{
    printf("\n%d is a %d digit number.\n\n", num, len);
    int i;
    for (i = len; i >= 2; i--)
    {
        printf("%d is divisible by %d. And the value is %d\n", num, len, (num / len));
        num = num / 10;
        len--;
    }
    printf("\n");
    return 0;
}

int main()
{
    check(gen(), 9);
    return 0;
}
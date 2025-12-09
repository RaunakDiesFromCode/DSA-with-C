#include <stdio.h>
#include <math.h>

int checkprime(int p)
{
    if (p <= 1)
    {
        return 0;
    }

    for (int i = 2; i <= sqrt(p); i++)
    {
        if (p % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    for (int i = 0; i <= 100; i++)
    {
        (checkprime(i) == 1) ? printf("%d, ", i) : printf("");
    }

    return 0;
}

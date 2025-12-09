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
    printf("%d\n", checkprime(2));
    printf("%d\n", checkprime(1));
    printf("%d\n", checkprime(23));
    printf("%d\n", checkprime(3));
    printf("%d\n", checkprime(7));
    printf("%d\n", checkprime(21));
    return 0;
}

#include <stdio.h>

int leap(int y)
{
    if ((y >= 1000) && (y <= 9999))
    {
        if (y % 400 == 0)
        {
            return 1;
        }

        if ((y % 100 == 0))
        {
            return 0;
        }

        if ((y % 4 == 0))
        {
            return 1;
        }

        return 0;
    }
    return 0;
}

int main()
{
    printf("%d\n", leap(2000));
    printf("%d\n", leap(1900));
    printf("%d\n", leap(2024));
    printf("%d\n", leap(2012));
    printf("%d\n", leap(206));
    return 0;
}

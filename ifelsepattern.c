#include <stdio.h>

int main()
{
    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            if ((i + j == 3) || (i + j == 2) || (i + j == 1) || (i + j == 0))
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}

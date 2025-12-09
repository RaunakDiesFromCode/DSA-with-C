#include <stdio.h>

void gennum()
{
    int higher = 999999999,
        lower = 100000000;
    int div = 9;
    int result = 0;

    for (int i = lower; i <= higher; i++)
    {
        if (i % div == 0)
        {
            div--;
            while (i%div == 0){
                
            }
            
        }
        if (div == 1)
        {
            result = higher;
        }
    }
    printf("\n\n result = %d", result);
}

int main()
{
    // printf("%d", gennum());
    gennum();
    return 0;
}

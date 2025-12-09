#include <stdio.h>

void arr(int size)
{
    // nigga declares and initializes the arrays
    int i, j;
    int arr1[size][size], arr2[size][size];
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("Enter value at position [%d][%d]: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("Enter value at position [%d][%d]: ", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }
    // nigga prints the arrays
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d\t", arr1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d\t", arr2[i][j]);
        }
        printf("\n");
    }

    // baler matrix add
    int arrsum[size][size];
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            arrsum[i][j] = arr1[i][j] + arr2[i][j];
        }
        printf("\n");
    }
    printf("\nSum of matrix is: \n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d\t", arrsum[i][j]);
        }
        printf("\n");
    }

    // baler matrix substract
    int arrsub[size][size];
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            arrsub[i][j] = arr1[i][j] - arr2[i][j];
        }
        printf("\n");
    }
    printf("\nSubstract of matrix is: \n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d\t", arrsub[i][j]);
        }
        printf("\n");
    }

    // baler matrix multiply
    int arrmul[size][size];
    int k;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            arrmul[i][j] = 0;
            for (k = 0; k < size; k++)
            {
                arrmul[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf("\nProduct of matrices is: \n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d\t", arrmul[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    arr(3);
    return 0;
}

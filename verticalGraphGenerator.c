#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findLargest(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void printVerticalGraph(int arr[], int size, int largest)
{
    int dirt[size];
    int cobble[size];
    int snow[size];

    for (int i = 0; i < size; i++)
    {
        dirt[i] = arr[i] - 2;
        if (dirt[i] < 0)
        {
            dirt[i] = 0;
        }
        cobble[i] = arr[i] + rand() % 3 - 7;
        if (cobble[i] < 0)
        {
            cobble[i] = 0;
        }
        snow[i] = arr[i] + rand() % 3 - 7;
        if (snow[i] < 0)
        {
            snow[i] = 0;
        }
    }

    for (int level = largest; level > 0; level--)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] >= level)
            {
                if (arr[i] > 9 && level > dirt[i])
                {
                    printf("\033[38;5;15m█\033[0m");
                }
                else if (level > dirt[i])
                {
                    printf("\033[38;5;22m█\033[0m");
                }
                else if (level <= cobble[i])
                {
                    printf("\033[38;5;240m█\033[0m");
                }
                else
                {
                    printf("\033[38;5;94m█\033[0m");
                }
            }
            else
            {
                printf("\033[34m█\033[0m");
            }
        }
        printf("\n");
    }
    for (int extra = 0; extra < 1; extra++)
    {
        for (int i = 0; i < size; i++)
        {
            printf("\033[38;5;240m█\033[0m");
        }
        printf("\n");
    }

    for (int extra = 0; extra < 1; extra++)
    {
        for (int i = 0; i < size; i++)
        {
            if (rand() % 2 == 0)
            {
                printf("\033[38;5;240m█\033[0m");
            }
            else
            {
                printf("\033[38;5;238m█\033[0m");
            }
        }
        printf("\n");
    }

    for (int extra = 0; extra < 3; extra++)
    {
        for (int i = 0; i < size; i++)
        {
            printf("\033[38;5;238m█\033[0m");
        }
        printf("\n");
    }
}

int main()
{
    int arr[100];

    srand(time(NULL));
    int j = 0;
    int randomDigit = rand() % 10;
    while (randomDigit >= 1)
    {
        for (int i = 0; i < randomDigit; i++)
        {
            arr[j] = randomDigit;
        }
        randomDigit += rand() % 3 - 1;
        j++;
        if (randomDigit <= 0 || randomDigit >= 20 || j >= 100)
        {
            break;
        }
    }

    int largest = findLargest(arr, j);
    printVerticalGraph(arr, j, largest);

    return 0;
}

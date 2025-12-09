#include <stdio.h>

#define SIZE 5

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
    for (int level = largest; level > 0; level--)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] >= level)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int array[SIZE];
    printf("Enter each values of individual elements:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter the value of element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("\n");

    int largest = findLargest(array, SIZE);
    printVerticalGraph(array, SIZE, largest);

    return 0;
}

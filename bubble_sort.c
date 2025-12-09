#include <stdio.h>

int main()
{
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int len = 7;
  printf("Original array: \n");
  for (int i = 0; i < 7; i++)
  {
    printf("%d ", arr[i]);
  }

  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < len - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  printf("\nSorted array: \n");
  for (int i = 0; i < 7; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n__________________________\n");
  printf("Time complexity: O(n^2)\n");
  printf("Space complexity: O(1)\n");
}
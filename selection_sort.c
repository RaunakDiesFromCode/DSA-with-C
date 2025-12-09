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
    for (int j = i + 1; j < len; j++)
    {
      if (arr[i] > arr[j])
      {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
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
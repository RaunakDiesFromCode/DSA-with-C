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

  for (int i = 1; i < len; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
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
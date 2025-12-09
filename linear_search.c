#include <stdio.h>

int main()
{
  int arr[] = {2, 4, 6, 8, 10, 12, 14};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 10;
  int result = -1;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] == target)
    {
      result = i; // Store the index of the target element
      break;
    }
  }

  if (result != -1)
  {
    printf("Element found at index %d\n", result);
  }
  else
  {
    printf("Element not found in the array\n");
  }

  return 0;
}

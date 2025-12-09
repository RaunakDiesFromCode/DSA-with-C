#include <stdio.h>

int main()
{
  int size, target, i;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements of the array: ");
  for (i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);
  }
  printf("Enter the target element: ");
  scanf("%d", &target);
  int low = 0, high = size - 1, mid;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (arr[mid] == target)
    {
      printf("Element found at index %d\n", mid);
      return 0;
    }
    else if (arr[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  printf("Element not found\n");
  return 0;
}

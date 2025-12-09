#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int leftArr[n1], rightArr[n2];
  for (int i = 0; i < n1; i++)
  {
    leftArr[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++)
  {
    rightArr[j] = arr[mid + 1 + j];
  }
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2)
  {
    if (leftArr[i] <= rightArr[j])
    {
      arr[k] = leftArr[i];
      i++;
    }
    else
    {
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
    arr[k] = leftArr[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    arr[k] = rightArr[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

int main()
{
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int len = 7;
  printf("Original array: \n");
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  merge_sort(arr, 0, len - 1);
  printf("\nSorted array: \n");
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n__________________________\n");
  printf("Time complexity: O(n log n)\n");
  printf("Space complexity: O(n)\n");
  return 0;
}

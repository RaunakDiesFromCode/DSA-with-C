#include <stdio.h>

// Function to swap two elements
void swap(int A[], int i, int j)
{
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

// Partition function
int Partition(int A[], int low, int high)
{
  int left = low, right = high;
  int pivot_item = A[low]; // Choosing the first element as the pivot

  while (left < right)
  {
    // Move left pointer while elements are less than or equal to the pivot
    while (left <= right && A[left] <= pivot_item)
      left++;

    // Move right pointer while elements are greater than the pivot
    while (A[right] > pivot_item)
      right--;

    // Swap elements if left is still less than right
    if (left < right)
    {
      swap(A, left, right);
    }
  }

  // Place the pivot in its final position
  A[low] = A[right];
  A[right] = pivot_item;

  return right; // Return the partition index
}

// QuickSort function
void QuickSort(int A[], int low, int high)
{
  if (low < high)
  {
    int pivot = Partition(A, low, high); // Partition the array
    QuickSort(A, low, pivot - 1);        // Sort the left subarray
    QuickSort(A, pivot + 1, high);       // Sort the right subarray
  }
}

// Main function
int main()
{
  int n;

  // Input the size of the array
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int A[n];

  // Input the array elements
  printf("Enter the elements of the array:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  // Call QuickSort
  QuickSort(A, 0, n - 1);

  // Print the sorted array
  printf("Sorted array:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");

  return 0;
}
#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10
int main() {
    int arr1[MAX_ROWS][MAX_COLS];
    int arr2[MAX_ROWS][MAX_COLS];
    int result[MAX_ROWS][MAX_COLS];
    int size;

    printf("Enter the size of the square array: ");
    scanf("%d", &size);

    printf("Enter elements of the first array:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter elements of the second array:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    // Perform array multiplication and print the result
    printf("Result of array multiplication:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>

int main() {
    // Define a 4x5 sparse matrix
    int sparseMatrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };
    
    int m = 4, n = 5;  // Matrix dimensions
    int nonZeroCount = 0;

    // First, count the number of non-zero elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (sparseMatrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    // Arrays to store row indices, column indices, and values of non-zero elements
    int rows[nonZeroCount], cols[nonZeroCount], values[nonZeroCount];
    
    // Populate the arrays with non-zero elements and their positions
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (sparseMatrix[i][j] != 0) {
                rows[index] = i;
                cols[index] = j;
                values[index] = sparseMatrix[i][j];
                index++;
            }
        }
    }
    
    // Print the sparse matrix representation
    printf("Array Representation (row, column, value):\n");
    for (int i = 0; i < nonZeroCount; i++) {
        printf("(%d, %d, %d)\n", rows[i], cols[i], values[i]);
    }

    return 0;
}

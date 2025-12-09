#include <stdio.h>

#define INF 99999 // Define a large number to represent "infinity"
#define MAX 50    // Maximum number of nodes

int x[MAX][MAX]; // Matrix for shortest paths
int d[MAX][MAX]; // Distance matrix

// Function to compute the shortest paths using Floyd-Warshall Algorithm
void apsp(int n)
{
  int i, j, k;

  // Initialize the shortest path matrix with input distances
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      x[i][j] = d[i][j];
    }
  }

  // Print initial distance matrix
  printf("\nInitial Distance Matrix (X0):\n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      if (x[i][j] == INF)
        printf("INF\t");
      else
        printf("%d\t", x[i][j]);
    }
    printf("\n");
  }

  // Floyd-Warshall Algorithm
  for (k = 1; k <= n; k++)
  {
    printf("\nAfter considering node %d:\n", k);

    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
      {
        int q = x[i][k] + x[k][j];
        if (q < x[i][j])
        {
          x[i][j] = q; // Update shortest path
        }
      }
    }

    // Print updated distance matrix
    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
      {
        if (x[i][j] == INF)
          printf("INF\t");
        else
          printf("%d\t", x[i][j]);
      }
      printf("\n");
    }
  }
}

int main()
{
  int n, i, j;

  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  printf("Enter the adjacency matrix (use %d for no connection):\n", INF);
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      scanf("%d", &d[i][j]);
    }
  }

  apsp(n); // Call the function to compute shortest paths

  // getch(); // Pause before exiting (Only in Turbo C)
  return 0;
}

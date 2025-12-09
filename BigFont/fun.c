#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  const char *x = "Doraemon Shinchan Nobita";
  int a = 9;
  int b = 8;
  char *y = (char *)malloc((b + 1) * sizeof(char));
  strncpy(y, x + a, b);
  y[b] = '\0';
  printf("%s\n", y);
  free(y);
  return 0;
}

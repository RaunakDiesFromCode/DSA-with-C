#include <stdio.h>
#include <string.h>

int main()
{
  char str[] = "slytherin";
  char temp;
  int len = strlen(str);

  for (int i = 0; i < len / 2; i++)
  {
    temp = str[i + 3];
    str[i + 3] = str[i + 2];
    str[i + 2] = temp;
  }

  printf("%s\n", str);
  return 0;
}
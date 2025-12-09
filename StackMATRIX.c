#include <stdio.h>
#define MAX 5

int info[MAX];
int top;

void push(int item)
{
  if (top == MAX - 1)
  {
    printf("\nStack overflow");
    return;
  }
  info[++top] = item;
}

void pop()
{
  if (top == -1)
  {
    printf("\nstack underflow");
    return;
  }
  printf("%d\n", info[top--]);
  return;
}

void display()
{
  printf("\n");
  int j;
  for (j = top; j >= 0; j--)
  {
    printf("%d\n", info[j]);
  }
}

int main()
{
  int i, x;
  top = -1;
  i = 1;
  while (i)
  {
    printf("\n\n1: Press 1 to push an Element\n");
    printf("2: press 2 to pop an Element\n");
    printf("3: press 3 to display the whole Stack\n");
    printf("0: press 0 to Exit\n");
    printf("Enter your choice\n");
    scanf("%d", &i);
    switch (i)
    {
      case 1:
        printf("\nEnter data: ");
        scanf("%d", &x);
        push(x);
        break;
      case 2:
        pop();
        break;
      case 3:
        display();
        break;
    }
  }
  return 0;
}
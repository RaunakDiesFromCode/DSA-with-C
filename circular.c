#include <stdio.h>
#define SIZE 5
void enqueue(int);
void dequeue();
void display();

int cq[SIZE], front = -1, rear = -1;
void enqueue(int value)
{
  if (front == 0 && rear == SIZE - 1 || front == rear + 1)
    printf("\nCircular queue is full\n");
  else
  {
    if (rear == SIZE - 1)
    {
      rear = -1;
    }
    cq[++rear] = value;
    if (front == -1)
      front = 0;
  }
}
void dequeue()
{
  if (front == -1 && rear == -1)
    printf("empty queue\n");
  else
  {
    printf("\ndeleted element: %d\n", cq[front++]);
    if (front == SIZE)
      front = 0;
    if (front - 1 == rear)
      front = rear = -1;
  }
}
void display()
{
  if (front == -1)
    printf("queue is empty\n");
  else
  {
    int i = front;
    if (front <= rear)
    {
      while (i <= rear)
        printf("%d\t", cq[i++]);
    }
    else
    {
      while (i <= SIZE - 1)
        printf("%d\t", cq[i++]);
      i = 0;
      while (i <= rear)
        printf("%d\t", cq[i++]);
    }
  }
}
void main()
{
  int choice, value;
  // clrscr();
  while (1)
  {
    printf("\n1:insert\n2:delete\n3:display\n4:exit\nenter choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("\nenter value to be inserted:");
      scanf("%d", &value);
      enqueue(value);
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    case 4:
      exit(1);
      break;
    default:
      printf("wrong input\n");
    }
  }
}

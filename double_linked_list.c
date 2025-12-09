#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

Node *head = NULL;

void createList()
{
  int n, data;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("Enter data for node %d: ", i + 1);
    scanf("%d", &data);
    insertAtEnd(data);
  }
}

void traverseList()
{
  Node *temp = head;
  if (temp == NULL)
  {
    printf("List is empty.\n");
    return;
  }
  printf("List elements: ");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void insertAtBeginning(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = head;

  if (head != NULL)
  {
    head->prev = newNode;
  }
  head = newNode;
  printf("Node inserted at the beginning.\n");
}

void insertAtEnd(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL)
  {
    newNode->prev = NULL;
    head = newNode;
    return;
  }

  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = newNode;
  newNode->prev = temp;
  printf("Node inserted at the end.\n");
}

void deleteAtBeginning()
{
  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  Node *temp = head;
  head = head->next;
  if (head != NULL)
  {
    head->prev = NULL;
  }
  free(temp);
  printf("Node deleted from the beginning.\n");
}

void deleteAtEnd()
{
  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  if (temp->prev != NULL)
  {
    temp->prev->next = NULL;
  }
  else
  {
    head = NULL;
  }
  free(temp);
  printf("Node deleted from the end.\n");
}

int main()
{
  int choice, data;

  while (1)
  {
    printf("\n1. Enter 1 to create a link list.\n");
    printf("2. Enter 2 to traverse a link list.\n");
    printf("3. Enter 3 to insert at beginning.\n");
    printf("4. Enter 4 to insert at end.\n");
    printf("5. Enter 5 to delete at beginning.\n");
    printf("6. Enter 6 to delete at end.\n");
    printf("7. Enter 0 to EXIT.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      createList();
      break;
    case 2:
      traverseList();
      break;
    case 3:
      printf("Enter data to insert at beginning: ");
      scanf("%d", &data);
      insertAtBeginning(data);
      break;
    case 4:
      printf("Enter data to insert at end: ");
      scanf("%d", &data);
      insertAtEnd(data);
      break;
    case 5:
      deleteAtBeginning();
      break;
    case 6:
      deleteAtEnd();
      break;
    case 0:
      exit(0);
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
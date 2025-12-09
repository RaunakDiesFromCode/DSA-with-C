#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} ND;

ND *start = NULL;

void insert_beg(int data)
{
  ND *temp = (ND *)malloc(sizeof(ND));
  temp->data = data;
  temp->next = start;
  start = temp;
}

void insert_end(int data)
{
  ND *temp = (ND *)malloc(sizeof(ND));
  temp->data = data;
  temp->next = NULL;

  if (start == NULL)
  {
    start = temp;
    return;
  }

  ND *current = start;
  while (current->next)
  {
    current = current->next;
  }
  current->next = temp;
}

void insert_before(int data)
{
  int bef;
  printf("Enter node before which to be inserted:");
  scanf("%d", &bef);
  ND *temp = (ND *)malloc(sizeof(ND));
  temp->data = data;
  temp->next = NULL;

  if (start == NULL)
  {
    printf("List is empty.\n");
    free(temp);
    return;
  }

  if (start->data == bef)
  {
    temp->next = start;
    start = temp;
    return;
  }

  ND *current = start; // the node jetar agey dhokabo
  ND *before = NULL;

  while (current->data != bef && current)
  {
    before = current;
    current = current->next;
  }

  if (current == NULL)
  {
    printf("Node not found.\n");
    free(temp);
    return;
  }

  before->next = temp;
  temp->next = current;
}

void insert_after(int data)
{
  if (start == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  int aft;
  printf("Enter node after which to be inserted:");
  scanf("%d", &aft);

  ND *temp = (ND *)malloc(sizeof(ND));
  temp->data = data;

  ND *current = start;
  while (current && current->data != aft)
  {
    current = current->next;
  }

  if (current == NULL)
  {
    printf("Node not found.\n");
    free(temp);
    return;
  }

  temp->next = current->next;
  current->next = temp;
}

void del_beg()
{
  if (start == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  ND *temp = start;
  start = start->next;
  free(temp);
}

void del_end()
{
  if (start == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  ND *current = start, *before = NULL;

  if (current->next == NULL)
  {
    free(current);
    start = NULL;
    return;
  }

  while (current->next)
  {
    before = current;
    current = current->next;
  }
  before->next = NULL;
  free(current);
}

void del_pos()
{
  if (start == NULL)
  {
    printf("List is empty.\n");
    return;
  }
  int pos, i = 1;
  printf("Enter position to delete: ");
  scanf("%d", &pos);
  ND *current = start;
  ND *before = NULL;

  if (pos == 1)
  {
    start = start->next;
    free(current);
    return;
  }

  while (current != NULL && i < pos)
  {
    before = current;
    current = current->next;
    i++;
  }

  if (current == NULL)
  {
    printf("Position not found.\n");
    return;
  }

  before->next = current->next;
  free(current);
}

void display()
{
  ND *current = start;
  while (current)
  {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL");
}

void count()
{
  ND *current = start;
  int count = 0;
  while (current)
  {
    count++;
    current = current->next;
  }
  printf("Count = %d", count);
}

int main()
{
  int opt, val;
  while (1)
  {
    printf("\n1:insert at beginning\n2:insert at end\n3:insert before a node\n4:insrt after a node\n5:delete at beginning\n6:delete at end\n7:delete at any position\n8:display\n9:count\n10:exit\nenter your option: ");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
      printf("enter the value to be inserted at beginning:\n");
      scanf("%d", &val);
      insert_beg(val);
      break;
    case 2:
      printf("enter the value to be inserted at end:\n");
      scanf("%d", &val);
      insert_end(val);
      break;
    case 3:
      printf("enter value to be inserted:\n");
      scanf("%d", &val);
      insert_before(val);
      break;
    case 4:
      printf("enter value to be inserted:\n");
      scanf("%d", &val);
      insert_after(val);
      break;
    case 5:
      del_beg();
      break;
    case 6:
      del_end();
      break;
    case 7:
      del_pos();
      break;
    case 8:
      display();
      break;
    case 9:
      count();
      break;
    case 10:
      exit(0);
      break;
    default:
      printf("wrong input\n");
    }
  }
  return 1;
}

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (!newNode)
  {
    printf("Memory error\n");
    return NULL;
  }
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Function to insert a node into the binary tree
struct Node *insertNode(struct Node *root, int data)
{
  if (root == NULL)
  {
    root = createNode(data);
    return root;
  }
  if (data < root->data)
  {
    root->left = insertNode(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = insertNode(root->right, data);
  }
  return root;
}

// In-order traversal
void inOrderTraversal(struct Node *root)
{
  if (root == NULL)
  {
    return;
  }
  inOrderTraversal(root->left);
  printf("%d ", root->data);
  inOrderTraversal(root->right);
}

// Pre-order traversal
void preOrderTraversal(struct Node *root)
{
  if (root == NULL)
  {
    return;
  }
  printf("%d ", root->data);
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

// Post-order traversal
void postOrderTraversal(struct Node *root)
{
  if (root == NULL)
  {
    return;
  }
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  printf("%d ", root->data);
}

// Function to search for a value in the binary tree
int searchNode(struct Node *root, int key)
{
  if (root == NULL)
  {
    return 0;
  }
  if (root->data == key)
  {
    return 1;
  }
  if (key < root->data)
  {
    return searchNode(root->left, key);
  }
  else
  {
    return searchNode(root->right, key);
  }
}

// Main function
int main()
{
  struct Node *root = NULL;
  int choice, value;

  while (1)
  {
    printf("\nBinary Tree Operations:\n");
    printf("1. Insert\n");
    printf("2. In-order Traversal\n");
    printf("3. Pre-order Traversal\n");
    printf("4. Post-order Traversal\n");
    printf("5. Search\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value to insert: ");
      scanf("%d", &value);
      root = insertNode(root, value);
      break;
    case 2:
      printf("In-order Traversal: ");
      inOrderTraversal(root);
      printf("\n");
      break;
    case 3:
      printf("Pre-order Traversal: ");
      preOrderTraversal(root);
      printf("\n");
      break;
    case 4:
      printf("Post-order Traversal: ");
      postOrderTraversal(root);
      printf("\n");
      break;
    case 5:
      printf("Enter value to search: ");
      scanf("%d", &value);
      if (searchNode(root, value))
      {
        printf("Value %d found in the tree.\n", value);
      }
      else
      {
        printf("Value %d not found in the tree.\n", value);
      }
      break;
    case 6:
      printf("Exiting program.\n");
      exit(0);
    default:
      printf("Invalid choice! Please try again.\n");
    }
  }

  return 0;
}

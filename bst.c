#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree Node
struct BSTNode
{
  int data;
  struct BSTNode *left;
  struct BSTNode *right;
};

// Function to create a new BST node
struct BSTNode *createBSTNode(int data)
{
  struct BSTNode *newNode = (struct BSTNode *)malloc(sizeof(struct BSTNode));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

// Function to insert a node into the BST
struct BSTNode *insert(struct BSTNode *root, int data)
{
  if (root == NULL)
    return createBSTNode(data);

  if (data < root->data)
    root->left = insert(root->left, data);
  else if (data > root->data)
    root->right = insert(root->right, data);

  return root;
}

// In-order Traversal
void inOrder(struct BSTNode *root)
{
  if (root == NULL)
    return;
  inOrder(root->left);
  printf("%d ", root->data);
  inOrder(root->right);
}

int main()
{
  struct BSTNode *root = NULL;

  // Insert elements into BST
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printf("In-order traversal of BST: ");
  inOrder(root);
  printf("\n");

  return 0;
}

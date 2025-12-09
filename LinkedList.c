#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node
typedef struct Node
{
    int roll;
    char name[100];
    struct Node *next;
} Node;

// Function to create a new node
Node *create_node(int roll, char *name)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new_node->roll = roll;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    return new_node;
}

// Insert at the beginning
void insert_begin(Node **head, int roll, char *name)
{
    Node *new_node = create_node(roll, name);
    if (!new_node)
        return;
    new_node->next = *head;
    *head = new_node;
}

// Insert at the end
void insert_end(Node **head, int roll, char *name)
{
    Node *new_node = create_node(roll, name);
    if (!new_node)
        return;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
}

// Insert before a node
void insert_before(Node **head, int target_roll, int roll, char *name)
{
    Node *new_node = create_node(roll, name);
    if (!new_node)
        return;

    if (*head == NULL)
    {
        printf("List is empty, cannot insert before.\n");
        free(new_node);
        return;
    }

    if ((*head)->roll == target_roll)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;
    Node *prev = NULL;
    while (current && current->roll != target_roll)
    {
        prev = current;
        current = current->next;
    }

    if (!current)
    {
        printf("Target node with roll %d not found.\n", target_roll);
        free(new_node);
        return;
    }

    prev->next = new_node;
    new_node->next = current;
}

// Insert after a node
void insert_after(Node *head, int target_roll, int roll, char *name)
{
    Node *current = head;
    while (current && current->roll != target_roll)
    {
        current = current->next;
    }

    if (!current)
    {
        printf("Target node with roll %d not found.\n", target_roll);
        return;
    }

    Node *new_node = create_node(roll, name);
    if (!new_node)
        return;

    new_node->next = current->next;
    current->next = new_node;
}

// Delete a node
void delete_node(Node **head, int roll)
{
    Node *current = *head;
    Node *prev = NULL;

    while (current && current->roll != roll)
    {
        prev = current;
        current = current->next;
    }

    if (!current)
    {
        printf("Node with roll number %d not found.\n", roll);
        return;
    }

    if (prev == NULL)
    {
        *head = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    free(current);
    printf("Node with roll number %d deleted.\n", roll);
}

// Count the number of nodes
int count_nodes(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Search for a node by roll number 
Node *search_node(Node *head, int roll)
{
    Node *current = head;
    while (current)
    {
        if (current->roll == roll)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Display the list
void traverse(Node *head)
{
    if (!head)
    {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked list contents:\nRoll number\tName\n");
    Node *current = head;
    while (current)
    {
        printf("%d\t\t%s\n", current->roll, current->name);
        current = current->next;
    }
}

// Main function
int main()
{
    Node *head = NULL;
    int choice, roll, target_roll;
    char name[100];

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert before a node\n");
        printf("4. Insert after a node\n");
        printf("5. Delete a node\n");
        printf("6. Count the number of nodes\n");
        printf("7. Search a node\n");
        printf("8. Traverse the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter roll number: ");
            scanf("%d", &roll);
            printf("Enter name: ");
            scanf("%s", name);
            insert_begin(&head, roll, name);
            break;
        case 2:
            printf("Enter roll number: ");
            scanf("%d", &roll);
            printf("Enter name: ");
            scanf("%s", name);
            insert_end(&head, roll, name);
            break;
        case 3:
            printf("Enter the roll number before which to insert: ");
            scanf("%d", &target_roll);
            printf("Enter new roll number: ");
            scanf("%d", &roll);
            printf("Enter name: ");
            scanf("%s", name);
            insert_before(&head, target_roll, roll, name);
            break;
        case 4:
            printf("Enter the roll number after which to insert: ");
            scanf("%d", &target_roll);
            printf("Enter new roll number: ");
            scanf("%d", &roll);
            printf("Enter name: ");
            scanf("%s", name);
            insert_after(head, target_roll, roll, name);
            break;
        case 5:
            printf("Enter roll number to delete: ");
            scanf("%d", &roll);
            delete_node(&head, roll);
            break;
        case 6:
            printf("Number of nodes: %d\n", count_nodes(head));
            break;
        case 7:
            printf("Enter roll number to search: ");
            scanf("%d", &roll);
            Node *found = search_node(head, roll);
            if (found)
            {
                printf("Node found: Roll number: %d, Name: %s\n", found->roll, found->name);
            }
            else
            {
                printf("Node with roll number %d not found.\n", roll);
            }
            break;
        case 8:
            traverse(head);
            break;
        case 9:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}

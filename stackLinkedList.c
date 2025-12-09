#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record
{
    int roll;
    char name[100];
};

typedef struct record RD;

struct Node
{
    RD info;
    struct Node *next;
};

typedef struct Node ND;

void push(ND **top, RD item)
{
    ND *temp = (ND *)malloc(sizeof(ND));
    if (!temp)
    {
        printf("Stack overflow\n");
        return;
    }
    temp->info = item;
    temp->next = *top;
    *top = temp;
}

void pop(ND **top)
{
    if (*top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    
    ND *temp = *top;
    *top = (*top)->next;
    
    printf("Roll number: %d\n", temp->info.roll);
    printf("Name: %s\n", temp->info.name);
    
    free(temp);
}

void traverse(ND *ptr)
{
    printf("\n");
    if (!ptr)
    {
        printf("The stack is empty.\n");
        return;
    }

    printf("Stack contents:\n");
    printf("Roll number\tName\n");
    while (ptr)
    {
        printf("%d\t\t%s\n", ptr->info.roll, ptr->info.name);
        ptr = ptr->next;
    }
}

int main()
{
    ND *stack = NULL;
    int choice;
    RD student;

    while (1)
    {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &student.roll);
                printf("Enter name: ");
                scanf(" %[^\n]", student.name);

                push(&stack, student);
                break;

            case 2:
                pop(&stack);
                break;
                
            case 3:
                traverse(stack);
                break;

            case 4:
                while (stack != NULL)
                {
                    pop(&stack);
                }
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}


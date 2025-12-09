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

void push(ND **front, ND **rear, RD item)
{
    ND *temp = (ND *)malloc(sizeof(ND));
    if (!temp)
    {
        printf("Queue overflows\n");
        return;
    }
    temp->info = item;
    temp->next = NULL;

    if (*rear)
    {
        (*rear)->next = temp;
    }
    else
    {
        *front = temp;
    }
    *rear = temp;
}

void pop(ND **front, ND **rear)
{
    if (*front == NULL)
    {
        printf("Queue underflows\n");
        return;
    }

    ND *temp = *front;
    *front = (*front)->next;
    
    if (*front == NULL)
    {
        *rear = NULL;
    }

    printf("Roll number: %d\n", temp->info.roll);
    printf("Name: %s\n", temp->info.name);
    
    free(temp);
}

void display(ND *front)
{
    if (!front)
    {
        printf("The queue is empty.\n");
        return;
    }

    printf("Queue contents:\n");
    printf("Roll number\tName\n");
    while (front)
    {
        printf("%d\t\t%s\n", front->info.roll, front->info.name);
        front = front->next;
    }
}

int main()
{
    ND *front = NULL;
    ND *rear = NULL;
    int choice;
    RD student;

    while (1)
    {
        printf("\nQueue Menu:\n");
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

                push(&front, &rear, student);
                break;

            case 2:
                pop(&front, &rear);
                break;
                
            case 3:
                display(front);
                break;

            case 4:
                while (front != NULL)
                {
                    pop(&front, &rear);
                }
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}


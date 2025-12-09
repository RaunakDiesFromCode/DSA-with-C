#include <stdio.h>
#define MAX 10

typedef struct queue {
    int items[MAX];
    int front, rear;
} que;

void push(que* q, int item) {
    if(q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    q->items[++q->rear] = item;
}

int pop(que* q) {
    if(q->front > q->rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->items[q->front++];
}

void display(que* q) {
    if(q->front > q->rear) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for(i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}

int main() {
    int ch = 0, n;
    que q;
    q.front = 0;
    q.rear = -1;

    while(ch != 4) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("\nEnter number: ");
                scanf("%d", &n);
                push(&q, n);
                break;
            case 2:
                printf("\nRemoved element: %d\n", pop(&q));
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("\nBye\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}

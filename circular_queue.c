#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
  int queue[MAX_SIZE];
  int front;
  int rear;
} CircularQueue;

int isFull(CircularQueue *q) {
  return (q->rear + 1) % MAX_SIZE == q->front;
}

int isEmpty(CircularQueue *q) {
  return q->front == -1;
}

void enqueue(CircularQueue *q, int data) {
  if (isFull(q)) {
    printf("Queue overflow\n");
    return;
  }
  if (q->front == -1) {
    q->front = 0;
  }
  q->rear = (q->rear + 1) % MAX_SIZE;
  q->queue[q->rear] = data;
  printf("Element %d inserted\n", data);
}

int dequeue(CircularQueue *q) {
  if (isEmpty(q)) {
    printf("Queue underflow\n");
    return -1;
  }
  int data = q->queue[q->front];
  if (q->front == q->rear) {
    q->front = q->rear = -1;
  } else {
    q->front = (q->front + 1) % MAX_SIZE;
  }
  return data;
}

void display(CircularQueue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements: ");
  int i = q->front;
  while (i != q->rear) {
    printf("%d ", q->queue[i]);
    i = (i + 1) % MAX_SIZE;
  }
  printf("%d\n", q->queue[q->rear]);
}

int main() {
  CircularQueue q = {.front = -1, .rear = -1};
  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  display(&q);
  printf("Dequeued element: %d\n", dequeue(&q));
  display(&q);
  return 0;
}

# define MAX 5
# include <stdio.h>

typedef struct Stack {
    int top;
    int info[MAX];
} STK;

void push(STK *s, int item) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->info[++s->top] = item;
}

int pop(STK *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->info[s->top--];
}

void display(STK *s) {
    int i;
    if (s->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (i = s->top; i >= 0; i--) {
        printf("%d\t", s->info[i]);
    }
    printf("\n");
}

int main() {
  STK s;
  int i, x;
  s.top = -1;
  i = 1;

  while(i) {
    printf("Enter 1 to push, 2 to pop, 3 to display, and 0 to exit: ");
    scanf("%d", &i);
    switch(i) {
      case 1:
        printf("Enter the element to be pushed: ");
        scanf("%d", &x);
        push(&s, x);
        break;
      case 2:
        x = pop(&s);
        if (x != -1) {
          printf("The popped element is %d\n", x);
        }
        break;
      case 3:
        display(&s);
        break;
      case 0:
        break;
      default:
        printf("Invalid choice\n");
    }
  }
}
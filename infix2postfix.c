#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100 // Maximum size for stack and expressions

// Stack structure
struct Stack
{
  int top;
  char items[MAX];
};

// Function to initialize the stack
void initStack(struct Stack *s)
{
  s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s)
{
  return s->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *s, char c)
{
  if (s->top == MAX - 1)
  {
    printf("Stack overflow\n");
    return;
  }
  s->items[++(s->top)] = c;
}

// Function to pop an element from the stack
char pop(struct Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack underflow\n");
    return '\0';
  }
  return s->items[(s->top)--];
}

// Function to peek the top element of the stack
char peek(struct Stack *s)
{
  if (isEmpty(s))
  {
    return '\0';
  }
  return s->items[s->top];
}

// Function to determine precedence of operators
int precedence(char op)
{
  switch (op)
  {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return 0;
  }
}

// Function to check if a character is an operator
int isOperator(char c)
{
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix expression to postfix
void infixToPostfix(char *infix, char *postfix)
{
  struct Stack s;
  initStack(&s);
  int i, j = 0;
  char c;

  for (i = 0; infix[i] != '\0'; i++)
  {
    c = infix[i];

    if (isalnum(c))
    { // If the character is an operand
      postfix[j++] = c;
    }
    else if (c == '(')
    { // If the character is '('
      push(&s, c);
    }
    else if (c == ')')
    { // If the character is ')'
      while (!isEmpty(&s) && peek(&s) != '(')
      {
        postfix[j++] = pop(&s);
      }
      pop(&s); // Pop the '('
    }
    else if (isOperator(c))
    { // If the character is an operator
      while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c))
      {
        postfix[j++] = pop(&s);
      }
      push(&s, c);
    }
  }

  // Pop all remaining operators from the stack
  while (!isEmpty(&s))
  {
    postfix[j++] = pop(&s);
  }

  postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main()
{
  char infix[MAX], postfix[MAX];

  printf("Enter infix expression: ");
  scanf("%s", infix);

  infixToPostfix(infix, postfix);

  printf("Postfix expression: %s\n", postfix);

  return 0;
}

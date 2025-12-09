#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

typedef struct Stack {
    int top;
    char arr[MAX];
} STK;

void push(STK *, char);
char pop(STK *);

int isDigit(char);
int eval(int, int, char);
int evalPostfix(char[]);

int isOperator(char);
int precedence(char);
void infixToPostfix(char[], char[]);

void push(STK *s, char val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = val;
}

char pop(STK *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

int evalPostfix(char s[MAX]) {
    STK stk;
    stk.top = -1;
    int i = 0;
    while (s[i] != '\0') {
        if (isDigit(s[i])) {
            push(&stk, s[i] - '0');
        } else if (isOperator(s[i])) {
            int b = pop(&stk);
            int a = pop(&stk);
            push(&stk, eval(a, b, s[i]));
        }
        i++;
    }
    return pop(&stk);
}

int eval(int a, int b, char ch) {
    switch (ch) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return 0;
    }
}

int isDigit(char x) {
    return (x >= '0' && x <= '9');
}

void infixToPostfix(char a[MAX], char postfix[MAX]) {
    STK stk;
    stk.top = -1;
    int i = 0, j = 0;
    push(&stk, '(');
    strcat(a, ")");
    
    while (stk.top != -1) {
        if (a[i] == '(') {
            push(&stk, a[i]);
        } else if (isDigit(a[i])) {
            postfix[j++] = a[i];
        } else if (isOperator(a[i])) {
            while (precedence(stk.arr[stk.top]) >= precedence(a[i])) {
                postfix[j++] = pop(&stk);
            }
            push(&stk, a[i]);
        } else if (a[i] == ')') {
            while (stk.arr[stk.top] != '(') {
                postfix[j++] = pop(&stk);
            }
            pop(&stk); // remove '('
        }
        i++;
    }
    postfix[j] = '\0'; // End the postfix string
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        case '(': return 0;
        default: return -1;
    }
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    // printf("Postfix expression: %s\n", postfix);
    printf("The result is: %d\n", evalPostfix(postfix));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    int* stackArray;
} Stack;

typedef int element;
typedef struct Stacktype {
    element* data;
    int capacity;
    int top;
} StackType;

void init(StackType* sptr, int ofs) {
    sptr->data = (element*)malloc(sizeof(StackType) * ofs);
    sptr->top = -1;
    sptr->capacity = ofs;
}

int is_full(StackType* sptr) {
    if (sptr->top == sptr->capacity - 1) {
        sptr->capacity = sptr->capacity * 2;
        sptr->data = (element*)realloc(sptr->data, sptr->capacity * sizeof(element));
    }
    return 0;
}

int is_empty(StackType* sptr) {
    return (sptr->top == -1);
}

void push(StackType* sptr, element item) {
    if (is_full(sptr)) {
        fprintf(stderr, "Stack is full\n");
        return;
    }
    else {
        sptr->top = sptr->top + 1;
        sptr->data[sptr->top] = item;
    }
}

element pop(StackType* sptr) {
    element r;
    if (is_empty(sptr)) {
        fprintf(stderr, "stack is empty\n");
        return -1;
    }
    else {
        return (sptr->data[(sptr->top)--]);
    }
}

element peek(StackType* sptr) {
    element r;
    if (is_empty(sptr)) {
        fprintf(stderr, "stack is empty\n");
        return -1;
    }
    else {
        return (sptr->data[sptr->top]);
    }
}

void stack_print(StackType* sptr) {
    for (int i = sptr->top; i >= 0; i--) {
        printf("[%d]", sptr->data[i]);
    }
}

int eval(char expression[]) {
    int len;
    StackType s;

    init(&s, 20);
    len = strlen(expression);
    for (int i = 0; i < len; i++) {
        int ch = expression[i];
        int value;
        int op1, op2;

        printf("expression : %c\n", expression[i]);
        if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/')) {
            op1 = pop(&s);
            op2 = pop(&s);
            switch (ch) {
                case '+': push(&s, op2 + op1); break;
                case '-': push(&s, op2 - op1); break;
                case '*': push(&s, op2 * op1); break;
                case '/': push(&s, op2 / op1); break;
                default:;
            }
        }
        else if ((ch >= '0') && (ch <= '9')) {
            value = ch - '0';
            push(&s, value);
        }
    }
    return (pop(&s));
}

int main() {
    char expression[MAX_STACK_SIZE];
    int result;

    printf("postfix Expression: ");
    fgets(expression, sizeof(expression), stdin);
    result = eval(expression);
    printf("Result: %d\n", result);

    return 0;
}
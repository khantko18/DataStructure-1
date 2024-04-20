#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct Stacktype {
    element* data;
    int capacity;
    int top;
} StackType;

void init(StackType* sptr, int ofs) {
    sptr->data = (element*)malloc(sizeof(element) * ofs);
    sptr->top = -1;
    sptr->capacity = ofs;
}

int is_full(StackType* sptr) {
    return (sptr->top == sptr->capacity - 1);
}

int is_empty(StackType* sptr) {
    return (sptr->top == -1);
}

void push(StackType* sptr, element item) {
    if (is_full(sptr)) {
        fprintf(stderr, "Stack is full\n");
        return;
    }
    sptr->data[++(sptr->top)] = item;
}

element pop(StackType* sptr) {
    if (is_empty(sptr)) {
        fprintf(stderr, "stack is empty\n");
        return -1;
    }
    return sptr->data[(sptr->top)--];
}

element peek(StackType* sptr) {
    if (is_empty(sptr)) {
        fprintf(stderr, "stack is empty\n");
        return -1;
    }
    return sptr->data[sptr->top];
}

void stack_print(StackType* sptr) {
    for (int i = sptr->top; i >= 0; i--) {
        printf("[%d]", sptr->data[i]);
    }
}

int prec(char op) {
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

void infix_to_postfix(char infixExpression[], char postfixExpression[]) {
    StackType stack;
    init(&stack, MAX_STACK_SIZE);
    int i, j;
    char ch, top_op;

    j = 0;
    for (i = 0; infixExpression[i] != '\0'; i++) {
        ch = infixExpression[i];
        switch (ch) {
            case '(':
                push(&stack, ch);
                break;
            case ')':
                top_op = pop(&stack);
                while (top_op != '(') {
                    postfixExpression[j++] = top_op;
                    top_op = pop(&stack);
                }
                break;
            case '+': case '-': case '*': case '/':
                while (!is_empty(&stack) && prec(ch) <= prec(peek(&stack))) {
                    postfixExpression[j++] = pop(&stack);
                }
                push(&stack, ch);
                break;
            default:
                postfixExpression[j++] = ch;
                break;
        }
    }

    while (!is_empty(&stack)) {
        postfixExpression[j++] = pop(&stack);
    }

    postfixExpression[j] = '\0';
}

int eval(char* postfixExpression) {
    StackType stack;
    init(&stack, MAX_STACK_SIZE);

    for (int i = 0; postfixExpression[i] != '\0'; i++) {
        char ch = postfixExpression[i];
        if (ch >= '0' && ch <= '9') {
            push(&stack, ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (ch) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&stack);
}

int main(int argc, char* argv[]) {
    int result;
    char infixExpression[MAX_STACK_SIZE];
    char postfixExpression[MAX_STACK_SIZE];
    while (1) {
        printf("\n다음과 같은 메뉴로 동작하는 프로그램입니다:\n");
        printf("1. 중위식을 입력 받음\n");
        printf("2. 중위식을 후위식으로 변환\n");
        printf("3. 후위식을 계산\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하세요: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("중위식을 입력하세요: ");
                getchar();
                fgets(infixExpression, sizeof(infixExpression), stdin);
                printf("입력된 중위식: %s", infixExpression);
                break;

            case 2:
                infix_to_postfix(infixExpression, postfixExpression);
                printf("후위식: %s\n", postfixExpression);
                break;

            case 3:
                result = eval(postfixExpression);
                printf("계산 결과: %d\n", result);
                break;

            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;

            default:
                printf("잘못된 메뉴 선택입니다. 다시 선택하세요.\n");
                break;
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 5

typedef int element;

typedef struct StackType {
    element *data;
    int top;
    int capacity;
} StackType;

void init(StackType* sptr) {
    sptr->top = -1;
    sptr->capacity = MAX_STACK_SIZE;
    sptr->data = (element *)malloc(sizeof(element) * sptr->capacity);
}

int is_full(StackType *sptr) {
    if (sptr->top == sptr->capacity - 1) {
        sptr->capacity = sptr->capacity * 2;
        sptr->data = (element *)realloc(sptr->data, sptr->capacity * sizeof(element));
        return 1;
    }
    return 0;
}

int is_empty(StackType *sptr) {
    return (sptr->top == -1);
}

void push(StackType *sptr, element item) {
    if (is_full(sptr)) {
        fprintf(stderr, "Stack is FULL\n");
        return;
    } else {
        sptr->top = sptr->top + 1;
        sptr->data[sptr->top] = item;
    }
}

element pop(StackType *sptr) {
    if (is_empty(sptr)) {
        fprintf(stderr, "Stack is empty\n");
        return -1;
    } else {
        return sptr->data[(sptr->top)--];
    }
}

int main() {
    StackType s;
    element e;
    srand(time(NULL)); // Seed the random number generator

    init(&s);

    for (int i = 0; i < 30; i++) {
        int rand_num = (rand() % 100) + 1;
        printf("%d\n", rand_num);
        if (rand_num % 2 == 0) {
            push(&s, rand_num);
            printf("Push Stack %d\n", rand_num);
        } else {
            e = pop(&s);
            printf("Pop Stack %d\n", e);
        }
    }
    return 0;
}
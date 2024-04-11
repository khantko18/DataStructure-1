#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 10

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

// Function to check if the stack is full
int is_full(StackType *sptr) {
    if (sptr->top == sptr->capacity - 1) {
        sptr ->capacity = sptr -> capacity * 2;
        sptr -> data = (element *) realloc (sptr-> data, sptr->capacity * sizeof(element));
        return 1;
    }
    return 0;
}

// Function to check if the stack is empty
int is_empty(StackType *sptr) {
    return (sptr->top == -1);
}

// Function to push an element onto the stack
void push(StackType *sptr, element item) {
    if (is_full(sptr)) {
        fprintf(stderr, "Stack is FULL\n");
        return;
    } else {
        sptr->top = sptr->top + 1;
        sptr->data[sptr->top] = item;
    }
}

// Function to peek at the top element of the stack
element peek(StackType *sptr) {
    if (is_empty(sptr)) {
        fprintf(stderr, "Stack is empty\n");
        return -1;
    } else {
        return sptr->data[sptr->top];
    }
}

// Function to pop an element from the stack
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
    int numOfStack;
    printf("How many elements does the stack have? ");
    scanf("%d", &numOfStack);
    
    init(&s);

    int rand_num = (rand() % 100) + 1;
    printf("%d\n", rand_num);
    if (rand_num % 2 == 0) {
        push(&s, rand_num);
        printf("Push Stack %d\n", rand_num);
    } else {
        e = pop(&s);
        printf("Pop Stack %d\n", e);
    }

    rand_num = (rand() % 100) + 1;
    if (rand_num % 2 == 0) {
        push(&s, rand_num);
        printf("Push %d\n", rand_num);
    } else {
        e = pop(&s);
        printf("Pop %d\n", e);
    }

    rand_num = (rand() % 100) + 1;
    if (rand_num % 2 == 0) {
        push(&s, rand_num);
        printf("Push %d\n", rand_num);
    } else {
        e = pop(&s);
        printf("Pop %d\n", e);
    }

    rand_num = (rand() % 100) + 1;
    if (rand_num % 2 == 0) {
        push(&s, rand_num);
        printf("Push %d\n", rand_num);
    } else {
        e = pop(&s);
        printf("Pop %d\n", e);
    }

    free(s.data); // Free the dynamically allocated memory

    return 0;
}
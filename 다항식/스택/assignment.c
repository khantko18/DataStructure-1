#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 5

typedef int element;

element *stack;
int top = -1;
int capacity = MAX_STACK_SIZE;

// Function to check if the stack is full
int is_full() {
    return (top == capacity - 1);
}

// Function to check if the stack is empty
int is_empty() {
    return (top == -1);
}

// Function to push an element onto the stack
void push(element item) {
    if (is_full()) {
        capacity *= 2;
        stack = (element *)realloc(stack, capacity * sizeof(element));
    }
    top++;
    stack[top] = item;
}

// Function to pop an element from the stack
element pop() {
    if (is_empty()) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    } else {
        return stack[top--];
    }
}

int main(int argc, char* argv[]) {
    stack = (element *)malloc(capacity * sizeof(element));
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100 + 1; // Generate a random number between 1 and 100
        printf("current random number: %d\n", rand_num);
        if (rand_num % 2 == 0) {
            printf("Even -> push\n");
            push(rand_num);
            printf("Stack elements : ");
            for (int j = 0; j <= top; j++) {
                printf("%d ", stack[j]);
            }
            printf("\n\n");
        } else {
            printf("Odd number -> pop\n");
            if (!is_empty()) {
                printf("Stack elements:\n");
                printf("Popped element: %d\n\n", pop());
            } else {
                printf("Stack is Empty\n\n");
            }
        }
    }

    free(stack); // Free the dynamically allocated memory

    return 0;
}
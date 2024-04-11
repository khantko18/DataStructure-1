#include <stdio.h>
#include <stdlib.h> // Include this header for the exit() function
#include <time.h>

#define MAX_STACK_SIZE 10
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

// Function to check if the stack is full
int is_full() {
    return (top == MAX_STACK_SIZE - 1);
}

// Function to check if the stack is empty
int is_empty() {
    return (top == -1);
}

// Function to push an element onto the stack
void push(element item) {
    if (top == MAX_STACK_SIZE - 1) {
        fprintf(stderr, "Stack is FULL\n");
        return;
    } else {
        top = top + 1;
        stack[top] = item;
    }
}

// Function to peek at the top element of the stack
element peek() {
    if (is_empty()) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    } else {
        return stack[top];
    }
}

// Function to pop an element from the stack
element pop() {
    element r;
    if (is_empty()) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    } else {
        return stack[top--];
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    element e;
    e = (rand() % 100) + 1;
    if (e % 2 == 0) {
        push(e);
        printf("Push %d\n", e);
    } else {
        e = pop();
        printf("Pop %d\n", e);
    }

    e = (rand() % 100) + 1;
    if (e % 2 == 0) {
        push(e);
        printf("Push %d\n", e);
    } else {
        e = pop();
        printf("Pop %d\n", e);
    }

    e = (rand() % 100) + 1;
    if (e % 2 == 0) {
        push(e);
        printf("Push %d\n", e);
    } else {
        e = pop();
        printf("Pop %d\n", e);
    }

    e = (rand() % 100) + 1;
    if (e % 2 == 0) {
        push(e);
        printf("Push %d\n", e);
    } else {
        e = pop();
        printf("Pop %d\n", e);
    }
    return 0; 
}
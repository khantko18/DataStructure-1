#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
    element data;
    struct listNode* link;
} ListNode;

ListNode* insert_first(ListNode* tail, element data) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if(tail == NULL) {
        tail = node;
        node->link = tail;
    }
    else {
        node->link = tail->link;
        tail->link = node;
    }
    return tail;
}

void print_list(ListNode* tail) {
    ListNode *p;
    if(tail == NULL) return;
    p = tail->link;
    do {
        printf("[%2d] ", p->data);
        p = p->link;
    } while (p != tail->link);
}

ListNode* insert_last(ListNode* tail, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if(tail == NULL) {
        tail = node;
        node->link = tail;
    }
    else {
        node->link = tail->link;
        tail->link = node;
        tail = node; // Update the tail to the new node
    }
    return tail;
}

int main() {
    ListNode* tail = NULL; 
    tail = insert_first(tail, 30);
    tail = insert_first(tail, 20);
    tail = insert_first(tail, 10);
    print_list(tail);
    
    tail = insert_last(tail, 40);
    tail = insert_last(tail, 50);
    tail = insert_last(tail, 60);
    print_list(tail);

    return 0;
}

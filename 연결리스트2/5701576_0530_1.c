#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct listNode {
    element data;
    struct listNode* link;
} ListNode;

ListNode* insert_first(ListNode* tail, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (tail == NULL) {
        tail = node;
        node->link = tail;
    }
    else {
        node->link = tail->link;
        tail->link = node;
    }
    return tail;
}

ListNode* insert_last(ListNode* tail, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (tail == NULL) {
        tail = node;
        node->link = tail;
    }
    else {
        node->link = tail->link;
        tail->link = node;
        tail = node;
    }
    return tail;
}

void print_list(ListNode* tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    ListNode* p = tail->link;
    do {
        printf("%d ", p->data);
        p = p->link;
    } while (p != tail->link);
    printf("\n");

}

ListNode* delete_first(ListNode* tail, element* data) {
    if (tail == NULL) {
        fprintf(stderr, "No data to be deleted\n");
        return NULL;
    }

    ListNode* head = tail->link;
    if (tail == head) {
        *data = head->data;
        free(head);
        return NULL;
    }
    else {
        tail->link = head->link;
        *data = head->data;
        free(head);
        return tail;
    }
}

ListNode* push(ListNode* tail, element data) {
    return insert_first(tail, data);
}

ListNode* pop(ListNode* tail, element* data) {
    return delete_first(tail, data);
}

int main() {

    ListNode* top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    element pd;
    top = pop(top, &pd);
    printf("Popped data = %d\n", pd);
    print_list(top);

    top = pop(top, &pd);
    printf("Popped data = %d\n", pd);
    print_list(top);

    return 0;
}

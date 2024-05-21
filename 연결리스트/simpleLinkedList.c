#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
    element data;
    struct listNode* link;
} ListNode;

ListNode* insert_first(ListNode* h, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = h;
    h = p;
    return h;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
    if (pre == NULL) {
        fprintf(stderr, "Insert parameter error: pre is NULL\n");
        return head;
    }

    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode* delete_first(ListNode* h) {
    if (h == NULL) return NULL;

    ListNode* remove = h;
    h = remove->link;
    free(remove);
    return h;
}

ListNode* delete(ListNode* h, ListNode* pre) {
    if (pre == NULL || pre->link == NULL) {
        fprintf(stderr, "Delete parameter error: invalid pre node\n");
        return h;
    }

    ListNode* remove = pre->link;
    pre->link = remove->link;
    free(remove);
    return h;
}

void print_list(ListNode* h) {
    while (h != NULL) {
        printf("[%d] ", h->data);
        h = h->link;
    }
    printf("\n");
}

int main() {
    ListNode* head = NULL;

    head = insert_first(head, 10);
    print_list(head);

    head = insert(head, head, 20);
    print_list(head);

    head = insert(head, head, 15);
    print_list(head);

    ListNode* p = head;
    for (int i = 0; i < 2; i++) {
        if (p->link != NULL) {
            p = p->link;
        } else {
            break;
        }
    }
    head = insert(head, p, 40);
    print_list(head);

    head = delete(head, head);
    print_list(head);

    head = delete_first(head);
    print_list(head);

    while (head != NULL) {
        head = delete_first(head);
    }

    return 0;
}

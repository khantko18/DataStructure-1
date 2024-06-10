#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DListNode {
    element data;
    struct DListNode *llink, *rlink;
} DListNode;

void init(DListNode* phead) {
    phead->llink = phead->rlink = phead;
}

void dinsert(DListNode *before, element data) {
    DListNode *newnode = (DListNode*)malloc(sizeof(DListNode)); //<1>
    newnode->data = data;
    newnode->llink = before; //<2>
    newnode->rlink = before->rlink; //<3>
    before->rlink = newnode; //<4>
    newnode->rlink->llink = newnode; //<5>
}

void print_dlist(DListNode* head) {
    DListNode *p = head;
    for( p = p->rlink; p != head; p = p->rlink) {
        printf("[%2d] ", p->data);
    }
    printf("\n");
}

element ddelete(DListNode* head, DListNode* removed) {
    element r;
    if(removed == head) return;
    r = removed->data;

    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->link;
    return r;
}

int main() {
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    dinsert(head, 10);
    dinsert(head, 20);
    dinsert(head->rlink->rlink, 5);
    dinsert(head->llink, 2);
    print_dlist(head);

    element deleted;
    deleted = ddelete(DListNode * head, head->rlink);
    printf( "Deleted = %d/n", deleted);

    print_dlist(head);

    ddelete(DListNode * head, DListNode * remove);
    
    return(0);
}
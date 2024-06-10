#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

void init(DListNode** phead) {
    *phead = (DListNode*)malloc(sizeof(DListNode));
    (*phead)->llink = *phead;
    (*phead)->rlink = *phead;
}

void dinsert_first(DListNode* head, element data) {
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    newnode->data = data;
    
    newnode->llink = head;
    newnode->rlink = head->rlink;
    head->rlink->llink = newnode;
    head->rlink = newnode;
}

void dinsert_last(DListNode* head, element data) {
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    newnode->data = data;
    
    newnode->rlink = head;
    newnode->llink = head->llink;
    head->llink->rlink = newnode;
    head->llink = newnode;
}

void ddelete_first(DListNode* head) {
    if (head->rlink == head) {
        printf("리스트가 비어있습니다.\n");
        return;
    }
    DListNode* removed = head->rlink;
    head->rlink = removed->rlink;
    removed->rlink->llink = head;
    free(removed);
}

void ddelete_last(DListNode* head) {
    if (head->llink == head) {
        printf("리스트가 비어있습니다.\n");
        return;
    }
    DListNode* removed = head->llink;
    head->llink = removed->llink;
    removed->llink->rlink = head;
    free(removed);
}

void print_dlist(DListNode* head) {
    DListNode* p;
    for (p = head->rlink; p != head; p = p->rlink) {
        printf("%d -> ", p->data);
    }
    printf("(head)\n");
}

int main() {
    DListNode* head;
    int choice, data;
    
    init(&head);
    
    while (1) {
        printf("\n메뉴\n");
        printf("(1) 숫자 입력 받아서 리스트 처음에 추가\n");
        printf("(2) 숫자 입력 받아서 리스트 마지막에 추가\n");
        printf("(3) 리스트 처음 노드 삭제\n");
        printf("(4) 리스트 마지막 노드 삭제\n");
        printf("(5) 리스트 프린트\n");
        printf("(6) 종료\n");
        printf("선택 : ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("추가할 숫자를 입력하세요: ");
                scanf("%d", &data);
                dinsert_first(head, data);
                break;
            case 2:
                printf("추가할 숫자를 입력하세요: ");
                scanf("%d", &data);
                dinsert_last(head, data);
                break;
            case 3:
                ddelete_first(head);
                break;
            case 4:
                ddelete_last(head);
                break;
            case 5:
                print_dlist(head);
                break;
            case 6:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 메뉴 선택입니다. 다시 선택하세요.\n");
        }
    }
    
    return 0;
}
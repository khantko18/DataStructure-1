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

ListNode* insert(ListNode* head, ListNode* pre, element value, int* count) {
    (*count)++;
    if (pre == NULL) {
        fprintf(stderr, "삽입 파라미터 오류: pre가 NULL입니다\n");
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

ListNode* delete(ListNode* h, ListNode* pre, int* count) {
    (*count)++;
    if (pre == NULL || pre->link == NULL) {
        fprintf(stderr, "삭제 파라미터 오류: 잘못된 pre 노드입니다\n");
        return h;
    }

    ListNode* remove = pre->link;
    pre->link = remove->link;
    free(remove);
    return h;
}

void print_list(ListNode* h) {
    while (h != NULL) {
        printf("%d -> ", h->data);
        h = h->link;
    }
    printf("NULL\n");
}

int main() {
    ListNode* head = NULL;
    int choice, value, position, count;
    ListNode* p;

    while (1) {
        printf("\n메뉴:\n");
        printf("1. 숫자를 위치에 산입\n");
        printf("2. 위치에서 삭제\n");
        printf("3. 리스트 출력\n");
        printf("0. 프로그램 종료\n");
        printf("선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("산입할 숫자를 입력하세요: ");
                scanf("%d", &value);
                printf("산입할 숫자를 입력하세요: ");
                scanf("%d", &position);
                p = head;
                count = 0;
                if (position == 0) {
                    head = insert_first(head, value);
                } else {
                    for (int i = 0; i < position - 1; i++) {
                        if (p != NULL) {
                            p = p->link;
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (p != NULL) {
                        head = insert(head, p, value, &count);
                    } else {
                        fprintf(stderr, "잘못된 위치\n");
                    }
                }
                printf("산입할 링크에 따라 이동한 홧수: %d\n", count);
                break;

            case 2:
                printf("삭제할 위치를 입력하세요: ");
                scanf("%d", &position);
                p = head;
                count = 0;
                if (position == 0) {
                    head = delete_first(head);
                } else {
                    for (int i = 0; i < position - 1; i++) {
                        if (p != NULL) {
                            p = p->link;
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (p != NULL && p->link != NULL) {
                        head = delete(head, p, &count);
                    } else {
                        fprintf(stderr, "잘못된 위치\n");
                    }
                }
                printf("삭제시 링크에 따라 이동한 홧수: %d\n", count);
                break;

            case 3:
                print_list(head);
                break;

            case 0:
                while (head != NULL) {
                    head = delete_first(head);
                }
                exit(0);

            default:
                printf("잘못된 선택입니다. 다시 시도해주세요.\n");
                break;
        }
    }

    return 0;
}

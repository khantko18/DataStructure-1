#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[100];
} element;

typedef struct ListNode { // Node type
	element data;
	struct ListNode *link;
} ListNode;

// Error handling function
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode *head, element value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert_last(ListNode *head, element value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	ListNode *temp = head;

	p->data = value;
	p->link = NULL;

	if (head == NULL) {
		return p;
	} else {
		while (temp->link != NULL) {
			temp = temp->link;
		}
		temp->link = p;
	}
	return head;
}

ListNode* find(ListNode *head, char* name) {
	ListNode *p = head;
	while (p != NULL) {
		if (strcmp(p->data.name, name) == 0) {
			return p;
		}
		p = p->link;
	}
	return NULL;
}

ListNode* delete_node(ListNode *head, char* name, ListNode **deleted) {
	ListNode *p = head;
	ListNode *prev = NULL;

	while (p != NULL) {
		if (strcmp(p->data.name, name) == 0) {
			if (prev == NULL) {
				head = p->link;
			} else {
				prev->link = p->link;
			}
			p->link = NULL;
			*deleted = insert_first(*deleted, p->data);
			free(p);
			return head;
		}
		prev = p;
		p = p->link;
	}
	printf("%s는 리스트에 없습니다.\n", name);
	return head;
}

void print_list(ListNode *head) {
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%s -> ", p->data.name);
	printf("NULL\n");
}

void print_deleted_list(ListNode *head) {
	printf("삭제된 과일: ");
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%s -> ", p->data.name);
	printf("NULL\n");
}

int main(void) {
	ListNode *head = NULL;
	ListNode *deleted = NULL;
	element data;
	char fruit_name[100];
	int choice;

	// Initial fruit list
	char* initial_fruits[] = {
		"Mango", "Orange", "Apple", "Grape", "Cherry",
		"Plum", "Guava", "Raspberry", "Banana", "Peach"
	};

	for (int i = 0; i < 10; i++) {
		strcpy(data.name, initial_fruits[i]);
		head = insert_last(head, data);
	}

	while (1) {
		printf("\n메뉴:\n");
		printf("1. 리스트의 매 마지막에 새로운 과일 추가\n");
		printf("2. 리스트에 있는 과일을 삭제\n");
		printf("3. 삭제된 과일 목록 출력\n");
		printf("4. 종료\n");
		printf("번호를 선택해주세요: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("추가하고 싶은 과일 이름을 입력하세요: ");
				scanf("%s", fruit_name);
				if (find(head, fruit_name) == NULL) {
					strcpy(data.name, fruit_name);
					head = insert_last(head, data);
					print_list(head);
				} else {
					printf("%s 리스트에 이미 존재하고 있습니다.\n", fruit_name);
				}
				break;

			case 2:
				printf("삭제하고 싶은 과을 이름을 입력하세요: ");
				scanf("%s", fruit_name);
				head = delete_node(head, fruit_name, &deleted);
				print_list(head);
				break;

			case 3:
				print_deleted_list(deleted);
				break;

			case 4:
				while (head != NULL) {
					head = delete_node(head, head->data.name, &deleted);
				}
				while (deleted != NULL) {
					ListNode *temp = deleted;
					deleted = deleted->link;
					free(temp);
				}
                printf("프로그램을 종료했습니다\n.");
				exit(0);

			default:
				printf("잘못된 선택입니다. 다시 선택해주세요\n");
				break;
		}
	}

	return 0;
} 
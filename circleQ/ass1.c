#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message) {
    fprintf(stderr, "%s", message);
}

int is_full(QueueType* q) {
    return (q->front == ((q->rear + 1) % MAX_QUEUE_SIZE));
}

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

void enqueue(QueueType *q, element item) {
    if (is_full(q)) {
        error("큐가 가득 찼습니다.\n");
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
}

element dequeue(QueueType* q) {
    if (is_empty(q)) {
        error("큐가 비어있습니다.");
        return -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        return (q->data[q->front]);
    }
}

void print_queue(QueueType* q) {
    int i;
    for (i = (q->front + 1) % MAX_QUEUE_SIZE; i != (q->rear + 1) % MAX_QUEUE_SIZE; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("[%2d] %2d, ", i, q->data[i]);
    }
    printf("\n");
}

int main() {
    QueueType queue;
    element e;
    int choice;

    init_queue(&queue);

    while (1) {
        printf("1. 큐에 원소를 삽입\n");
        printf("2. 큐에서 원소를 삭제\n");
        printf("3. 큐의 원소를 출력\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("큐에 삽입할 숫자를 입력하세요: ");
                scanf("%d", &e);
                enqueue(&queue, e);
                break;
            case 2:
                e = dequeue(&queue);
                printf("제거된 숫자: %d\n", e);
                break;
            case 3:
                printf("원형 큐 내용:\n");
                print_queue(&queue);
                break;
            default:
                printf("프로그램을 종료합니다.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5

typedef struct 
{
    int id;
    int arrival_time;
    int severce_time;  
}element;

// typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s", message);
	return -1;
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

void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("Queue is full\n");
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("Queue is empty\n");
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return (q->data[q->front]);
	}
}

void print_queue(QueueType* q) {
	int i;
	for (i = (q->front + 1) % MAX_QUEUE_SIZE; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
		printf("[%2d] %2d, ", i, q->data[i]);
	}
	printf("[%2d] %2d\n", i, q->data[i]);
}


main() {
    QueueType
    int minutes = 60;
    int total_customer = 0;
    int severce_time = 0;
    int severce_customer = 0;
    int total_wait = 0;

    init_queue(&queue);
    srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) {
        printf("현재시간 = %d", clock);
        /* producer */
        if (rand() % 10 < 3) {
            element customer;
            customer .id = total_customer++;
            customer .arrival_time = clock;
            customer .severce_time =rand() % 3 + 1;
            enqueue(&queue, customer);
            printf("고객 %d가 %d분에 들어옵니다. 업무처리 시간은 %d분입니다.", customer .id, customer .arrival_time, customer .severce_time);
        }
        /* consumer */
        if(severce_time == 0) {/*업무처리 완료. 새로운 작업 가져오기*/
            if(is_empty()) {
                element customer = dequeue(&queue);
                severce_time = customer .severce_time
                printf("고객 %ddl %d분에 업무를 시작합니다. 대기 시간을 %d분입니다.\n", customer .id, clock - customer .arrival_time);
                total_wait = total_wait + (clock - customer .arrival_time);
            }
        } 
    } else {
        severce_time--;
        printf("고객 %d의 업무처리 중입니다.")
    }

}
printf("\n Total Wait = %d, Average Wait = %f",total_wait, total_wait /)

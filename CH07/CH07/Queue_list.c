#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}QueueNode;
typedef struct LinkedQueueType {
	QueueNode* front, * rear;
}LinkedQueueType;

void init(LinkedQueueType* q) { q->front = q->rear = 0; }
int is_empty(LinkedQueueType* q) { return q->front == NULL; }
void enqueue(LinkedQueueType* q, element data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;
	if (is_empty(q)) q->front = q->rear = temp;
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
}
element dequeue(LinkedQueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "스택 공백 에러");
		exit(1);
	}
	QueueNode* temp = q->front;    // 동적 해제를 위함
	element data = q->front->data;  // 값 반환을 위함
	q->front = q->front->link;
	if (q->front == 0) q->rear = 0;
	free(temp);
	return data;
}
void print_queue(LinkedQueueType* q) {
	QueueNode* p;
	for (p = q->front; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

// 실습 : 큐 합 구하기
int queue_sum(LinkedQueueType* q) {
	QueueNode* p;
	int sum = 0;
	for (p = q->front; p != NULL; p = p->link) sum += p->data;
	return sum;
}

int main() {
	LinkedQueueType queue;
	init(&queue);

	enqueue(&queue, 1); print_queue(&queue);
	enqueue(&queue, 2); print_queue(&queue);
	enqueue(&queue, 3); print_queue(&queue);

	/*dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);*/

	printf("element sum = %d\n", queue_sum(&queue));
}
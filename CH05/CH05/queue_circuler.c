#include <stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}Queue;

void error(char* message) {
	fprintf(stderr, "%s", message);
	exit(1);
}
void init(Queue* q) { q->rear = q->front = 0; }
int is_empty(Queue* q) { return (q->front == q->rear); }
int is_full(Queue* q) { return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); }
void queue_print(Queue* q) {
	printf("front = %d, rear = %d : ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
void enqueue(Queue* q, element n) {
	if (is_full(q)) error("큐 포화 에러");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = n;
}
element dequeue(Queue* q) {
	if (is_empty(q)) error("큐 공백 에러");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element peek(Queue* q) {
	if (is_empty(q)) error("큐 공백 에러");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main() {
	Queue q;
	int i = 10;
	init(&q);

	while (!is_full(&q)) {
		enqueue(&q, i);
		i += 10;
		queue_print(&q);
	}
	printf("큐 포화 상태\n\n");

	while (!is_empty(&q)) {
		printf("꺼내진 수 : %d\n",dequeue(&q));
		queue_print(&q);
	}
	printf("큐 공백 상태\n\n");
}
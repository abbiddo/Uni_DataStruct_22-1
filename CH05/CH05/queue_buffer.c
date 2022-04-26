#include <stdio.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}Queue;

void init(Queue* q) { q->front = q->rear = 0; }
void error(char* message) { fprintf(stderr, "%s", message); exit(1); }
int is_empty(Queue* q) { return (q->front == q->rear); }
int is_full(Queue* q) { return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); }
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
void queue_print(Queue* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
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

int main() {
	Queue q;
	int a;

	init(&q);

	/*enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 10); queue_print(&q);
	dequeue(&q); queue_print(&q);
	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 10); queue_print(&q);*/

	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		if (rand() % 5 == 0) enqueue(&q, rand() % 100);
		queue_print(&q);
		if (rand() % 10 == 0) a = dequeue(&q);
		queue_print(&q);
	}
}
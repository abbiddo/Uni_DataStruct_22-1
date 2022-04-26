#include <stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}Queue;

void init(Queue* q) {
	q->front = -1;
	q->rear = -1;
}
void error(char* message) {
	fprintf(stderr, "%s", message);
	exit(1);
}
int is_empty(Queue* q) {
	return (q->front == q->rear);
}
int is_full(Queue* q) {
	return (q->rear == MAX_QUEUE_SIZE - 1);
}
void queue_print(Queue* q) {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i > q->front && i <= q->rear) printf("%d | ", q->data[i]);
		else printf("  | ");
	}
	printf("\n");
}
void enqueue(Queue* q, int n) {
	if (is_full(q)) error("큐 포화 에러");
	q->data[++(q->rear)] = n;
}
element dequeue(Queue* q) {
	if (is_empty(q)) error("큐 공백 에러");
	return q->data[++(q->front)];
}

int main() {
	Queue q;
	init(&q);

	enqueue(&q, 1); queue_print(&q);
	enqueue(&q, 2); queue_print(&q);
	enqueue(&q, 3); queue_print(&q);

	printf("%d\n", dequeue(&q)); queue_print(&q);
	printf("%d\n", dequeue(&q)); queue_print(&q);
	printf("%d\n", dequeue(&q)); queue_print(&q);
}


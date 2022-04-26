#include <stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}Deque;

void init(Deque* d) { d->front = d->rear = 0; }
void error(char* message) { fprintf(stderr, "%s", message); exit(1); }
int is_empty(Deque* d) { return (d->front == d->rear); }
int is_full(Deque* d) { return ((d->rear + 1) * MAX_QUEUE_SIZE == d->front); }
void deque_print(Deque* d) {
	printf("front : %d, rear : %d = ", d->front, d->rear);
	if (!is_empty(d)) {
		int i = d->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", d->data[i]);
		} while (i != d->rear);
	}
	printf("\n");
}
void add_rear(Deque* d, int n) {
	if (is_full(d)) error("큐 포화 상태");
	d->rear = (d->rear + 1) % MAX_QUEUE_SIZE;
	d->data[d->rear] = n;
}
void add_front(Deque* d, int n) {
	if (is_full(d)) error("큐 포화 상태");
	d->data[d->front] = n;
	d->front = (d->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(Deque* d) {
	element prev = d->data[d->rear];
	if (is_empty(d)) error("큐 공백 상태");
	d->rear=(d->rear-1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return prev;
}
element delete_front(Deque* d) {
	if (is_empty(d)) error("큐 공백 상태");
	d->front = (d->front + 1) % MAX_QUEUE_SIZE;
	return d->data[d->front];
}

element get_rear(Deque* d) {
	if (is_empty(d)) error("큐 공백 상태");
	return (d->data[d->rear]);
}
element get_front(Deque* d) {
	if (is_empty(d)) error("큐 공백 상태");
	return (d->data[(d->front + 1) % MAX_QUEUE_SIZE]);
}

int main() {
	Deque d;

	init(&d);
	for (int i = 0; i < 3; i++) {
		add_front(&d, i);
		deque_print(&d);
	}

	for (int i = 0; i < 3; i++) {
		delete_rear(&d);
		deque_print(&d);
	}
}
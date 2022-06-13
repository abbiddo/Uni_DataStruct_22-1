#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void init_queue(QueueType* q) { q->front = q->rear = 0; }
int is_empty(QueueType* q) { return q->front == q->rear; }
void enqueue(QueueType* q, element item) {
	q->rear++;
	q->rear %= MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
	q->front++;
	q->front %= MAX_QUEUE_SIZE;
	return q->data[q->front];
}

#define BUCKETS 10
#define DIGITS 4
void radix_sort(int list[], int n) {
	int i, b, d, factor = 1;
	QueueType q[BUCKETS];

	for (b = 0; b < BUCKETS; b++) init_queue(&q[b]);
	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++) enqueue(&q[(list[i] / factor) % 10], list[i]);
		for (b = i = 0; b < BUCKETS; b++)
			while (!is_empty(&q[b]))
				list[i++] = dequeue(&q[b]);
		factor *= 10;
	}
}

#define SIZE 10

int main() {
	int n = 10, list[SIZE];
	srand(time(NULL));
	for (int i = 0; i < n; i++) list[i] = rand() % 100;

	printf("\n 정렬 전 : \n");
	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);

	radix_sort(list, SIZE);

	printf("\n 정렬 후 : \n");
	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);
}
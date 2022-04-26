#include <stdio.h>
#define MAX_QUEUE_SIZE 50

typedef struct {
	int id, arrival_time, service_time;
}element;
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
		} while (i != q->rear);
	}
	printf("\n");
}
void enqueue(Queue* q, element n) {
	if (is_full(q)) error("ť ��ȭ ����");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = n;
}
element dequeue(Queue* q) {
	if (is_empty(q)) error("ť ���� ����");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element peek(Queue* q) {
	if (is_empty(q)) error("ť ���� ����");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main() {
	int minutes = 60;
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customers;

	Queue q;
	init(&q);

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) {
		printf("����ð� %d��\n", clock);
		if (rand() % 10 < 5) {
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&q, customer);
			printf("�� %d�� %d�п� ���ɴϴ�. ���� ó�� �ð� : %d��\n", customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time > 0) {
			printf("�� %d�� ���� ó�� ���Դϴ�.\n", service_customers);
			service_time--;
		}
		else {
			if (!is_empty(&q)) {
				element customer = dequeue(&q);
				service_time = customer.service_time;
				service_customers = customer.id;
				printf("�� %d�� %d�п� ������ �����մϴ�. ��� �ð��� %d�� �Դϴ�.\n", service_customers, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}
		if (clock % 10 == 0) queue_print(&q);
	}
	printf("��ü ��� �ð� : %d��", total_wait);
}
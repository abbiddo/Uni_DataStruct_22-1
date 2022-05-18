#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

typedef TreeNode* element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void init_queue(QueueType* q) { q->front = q->rear = 0; }
int is_empty(QueueType* q) { return q->front == q->rear; }
int is_full(QueueType* q) { return (q->rear + 1) % MAX_QUEUE_SIZE == q->front; }
void enqueue(QueueType* q, element item){
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void order_level(TreeNode* n) {
	QueueType q;
	init_queue(&q);
	enqueue(&q, n);
	while (!is_empty(&q)) {
		n = dequeue(&q);
		printf("[%d] ", n->data);
		if (n->left) enqueue(&q, n->left);
		if (n->right) enqueue(&q, n->right);
	}
}

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

int main() {
	printf("·¹º§ ¼øÈÖ : ");
	order_level(root);
}
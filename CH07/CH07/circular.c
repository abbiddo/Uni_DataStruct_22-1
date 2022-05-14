#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		/*head = node;
		node->link = head;*/

		head = node;
		head->link = head;

		// printf("%p %p\n\n", head->link, node->link);
		// �����ϰ� node�� �����ϸ� head���� ���氪�� �ݿ��ǳ�? �׷��� ��

		/*node->link = head;
		head = node;*/
		// �� ��
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (!head) {
		head = node;
		node->link = head;   // ���� �߿�
	}
	else {
		node->link = head->link;
		head->link = node;             // ��?
		head = node;
	}
	return head;
}
void print_list(ListNode* head) {
	ListNode* p;
	if (!head) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
}

// �ǽ� : ����Ʈ ���� ���
int count_list(ListNode* head) {
	int cnt = 0;
	ListNode* p;

	if (!head) return 0;

	p = head->link;
	do {
		p = p->link;
		cnt++;
	} while (p != head->link);

	return cnt;
}

int main() {
	ListNode* head = NULL;

	//head = insert_last(head, 40);
	head = insert_first(head, 10);
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	print_list(head);
	printf("\n > element count = %d\n", count_list(head));
}
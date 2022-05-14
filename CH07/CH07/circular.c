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
		// 대입하고 node를 변경하면 head에도 변경값이 반영되나? 그런가 봄

		/*node->link = head;
		head = node;*/
		// 안 됨
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
		node->link = head;   // 순서 중요
	}
	else {
		node->link = head->link;
		head->link = node;             // 왜?
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

// 실습 : 리스트 개수 출력
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
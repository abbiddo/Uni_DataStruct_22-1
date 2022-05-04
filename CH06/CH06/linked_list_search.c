#include <stdio.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void error(char* message) {
	fprintf(stderr, "%s", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
void print_list(ListNode* head) {
	for (ListNode* p = head; p != 0; p = p->link) printf("%d->", p->data);
	printf("NULL\n");
}

ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;

	while (p != NULL) {
		if (p->data == x) return p;
		p = p->link;
	}
	return NULL;
}

// 추가 : 합 출력
int sum_list(ListNode* head) {
	int sum = 0;
	ListNode* p = head;

	//if (head == 0) error("리스트 공백, 합 출력 불가");

	while (p != NULL) {
		sum += p->data;
		p = p->link;
	}
	return sum;
}

int main() {
	ListNode* head = 0;
	
	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);

	if (search_list(head, 30) != NULL) printf("30을 찾음\n");
	else printf("30을 찾지 못 함\n");

	printf("sum = %d", sum_list(head));
}

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
// 실습 insert_last
ListNode* insert_last(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = 0;

	if (!head) return p; //head = p;

	ListNode* tmp;
	tmp = head;
	while (tmp->link != 0) tmp = tmp->link;
	tmp->link = p;

	return head;
}
ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == 0) error("리스트 공백 에러");
	removed = head;
	head = removed->link;
	free(removed);         // 왜...? 인서트할 때 동적할당해서?
	return head;
}
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	if (head == 0) error("리스트 공백 에러");
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
void print_list(ListNode* head) {
	for (ListNode* p = head; p != 0; p = p->link) printf("%d->", p->data);
	printf("NULL\n");
}

int main() {
	ListNode* head = 0;
	for (int i = 0; i < 5; i++) {
		head = insert_last(head, i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
}

#include <stdio.h>
#include <string.h>

// 이거 바뀜
typedef struct {
	char name[100];
}element;

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
ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == 0) error("리스트 공백 에러");
	removed = head;
	head = removed->link;
	free(removed);
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
	//여기도 바뀜
	for (ListNode* p = head; p != 0; p = p->link) printf("%s->", p->data.name);
	printf("NULL\n");
}

int main() {
	ListNode* head = 0;
	element data;

	strcpy(data.name, "APPLE");
	head = insert_first(head, data); // 그냥 "APPLE"는 안되네 아 element가 구조체니까
	print_list(head);

	strcpy(data.name, "KIWI");
	head = insert_first(head, data); // data.name아님
	print_list(head);

	strcpy(data.name, "BANANA");
	head = insert_first(head, data); // data.name아님
	print_list(head);

	for (int i = 0; i < 3; i++) {
		head = delete_first(head);
		print_list(head);
	}
}

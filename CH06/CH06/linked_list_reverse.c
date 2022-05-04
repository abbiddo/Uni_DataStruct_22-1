#include <stdio.h>
#include <string.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
ListNode* reverse(ListNode* head) {
	ListNode* p, * pp, * ppp;
	p = head; pp = NULL;

	while (p != NULL) {
		ppp = pp;
		pp = p;
		p = p->link;
		pp->link = ppp;
	}
	return pp;
}

int main() {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);
	head1 = insert_first(head1, 40);
	print_list(head1);

	head2 = reverse(head1);
	print_list(head2);
}
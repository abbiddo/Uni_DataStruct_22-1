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
ListNode* concat_list(ListNode* head1, ListNode* head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		ListNode* p;
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

int main(void)
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	printf("> head1 list 持失.\n");
	head1 = insert_first(head1, 10);
	print_list(head1);
	head1 = insert_first(head1, 20);
	print_list(head1);
	head1 = insert_first(head1, 30);
	print_list(head1);

	printf("> head2 list 持失.\n");
	head2 = insert_first(head2, 100);
	print_list(head2);
	head2 = insert_first(head2, 200);
	print_list(head2);
	head2 = insert_first(head2, 300);
	print_list(head2);

	printf("> After concat.\n");
	ListNode *total = concat_list(head1, head2);
	print_list(head1);

	return 0;
}
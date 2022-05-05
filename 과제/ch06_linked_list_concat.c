#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
typedef int element;

//
typedef struct ListNode { 	// ��� Ÿ���� ����ü�� �����Ѵ�.
	element data;
	struct ListNode* link;
} ListNode;

// ���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;								//(2)
	p->link = head;	// ��� �������� ���� ����		//(3)
	head = p;		// ��� ������ ����				//(4)
	return head;
}

//
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

//
ListNode* concat_list(ListNode* head1, ListNode* head2)
{
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

// ����
// concat_list3() �Լ�: �Ķ���ͷ� ���޵� 3���� list�� �ϳ��� �����ϴ� �Լ�
ListNode* concat_list3(ListNode* head1, ListNode* head2, ListNode* head3) {
	ListNode* p;
	if (head1 == NULL && head2 == NULL) p = head3;
	else if (head1 == NULL && head3 == NULL) p = head2;
	else if (head2 == NULL && head3 == NULL) p = head1;
	else if (head1 == NULL) {
		ListNode* pp;
		pp = head2;
		while (pp->link != NULL) pp = pp->link;
		pp->link = head3;
		p = head2;
	}
	else if (head2 == NULL) {
		ListNode* pp;
		pp = head1;
		while (pp->link != NULL) pp = pp->link;
		pp->link = head3;
		p = head1;
	}
	else if (head3 == NULL) {
		ListNode* pp;
		pp = head1;
		while (pp->link != NULL) pp = pp->link;
		pp->link = head2;
		p = head1;
	}
	else {
		ListNode* pp;
		pp = head1;
		while (pp->link != NULL) pp = pp->link;
		pp->link = head2;
		while (pp->link != NULL) pp = pp->link;
		pp->link = head3;
		p = head1;
	}
	return p;
}

// �׽�Ʈ ���α׷�
int main(void)
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	ListNode* head3 = NULL;
	ListNode* total = NULL;

	printf("> head1 list ����.\n");
	head1 = insert_first(head1, 10);
	print_list(head1);
	head1 = insert_first(head1, 20);
	print_list(head1);

	printf("> head2 list ����.\n");
	head2 = insert_first(head2, 100);
	print_list(head2);
	head2 = insert_first(head2, 200);
	print_list(head2);

	printf("> head3 list ����.\n");
	head3 = insert_first(head3, 1000);
	print_list(head3);
	head3 = insert_first(head3, 2000);
	print_list(head3);

	printf("> After concat.\n");
	total=concat_list3(head1, head2, head3);
	print_list(total);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
typedef int element;

//
typedef struct ListNode { 	// 노드 타입을 구조체로 정의한다.
	element data;
	struct ListNode* link;
} ListNode;

// 오류 처리 함수
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
	p->link = head;	// 헤드 포인터의 값을 복사		//(3)
	head = p;		// 헤드 포인터 변경				//(4)
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

// 과제
// concat_list3() 함수: 파라메터로 전달된 3개의 list를 하나로 결합하는 함수
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

// 테스트 프로그램
int main(void)
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	ListNode* head3 = NULL;
	ListNode* total = NULL;

	printf("> head1 list 생성.\n");
	head1 = insert_first(head1, 10);
	print_list(head1);
	head1 = insert_first(head1, 20);
	print_list(head1);

	printf("> head2 list 생성.\n");
	head2 = insert_first(head2, 100);
	print_list(head2);
	head2 = insert_first(head2, 200);
	print_list(head2);

	printf("> head3 list 생성.\n");
	head3 = insert_first(head3, 1000);
	print_list(head3);
	head3 = insert_first(head3, 2000);
	print_list(head3);

	printf("> After concat.\n");
	total=concat_list3(head1, head2, head3);
	print_list(total);

	return 0;
}
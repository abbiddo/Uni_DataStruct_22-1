#include <stdio.h>
#include <stdlib.h>

// ������ ���� ������ �����ȴ�. 
// ���� element : int
#define	MAX_STACK_SIZE 100		// ������ �ִ� ũ��
// #define MAX_STRING 100

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

/** 
struct stack_structEle {
	int student_no;             // �й�
	char name[MAX_STRING];      // �̸�
	char address[MAX_STRING];   // �ּ�
};

typedef	struct stack_structEle element;			// �������� �ڷ���
**/

element stack[MAX_STACK_SIZE];	// 1���� �迭
int  top = -1;

// ���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// ���� �Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// ���� �Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// ��ũ �Լ�
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

void print_stack(StackType* s) {
	printf("stack (%d)�� : ", s->top + 1);
	for (int i = 0; i <= s->top; i++) printf("[%d]", s->data[i]);
	printf("\n");

}

void init_stack(StackType* s) {
	s->top = -1;
}

int main(void)
{
	StackType s;

	init_stack(&s);

	push(&s,1);
	print_stack(&s);
	push(&s,2);
	print_stack(&s);
	push(&s,3);
	print_stack(&s);
	
	pop(&s);
	print_stack(&s);
	pop(&s);
	print_stack(&s);
	pop(&s);
	print_stack(&s);

	return 0;
}
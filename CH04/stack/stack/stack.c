#include <stdio.h>
#include <stdlib.h>

// 스택이 전역 변수로 구현된다. 
// 스택 element : int
#define	MAX_STACK_SIZE 100		// 스택의 최대 크기
// #define MAX_STRING 100

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

/** 
struct stack_structEle {
	int student_no;             // 학번
	char name[MAX_STRING];      // 이름
	char address[MAX_STRING];   // 주소
};

typedef	struct stack_structEle element;			// 데이터의 자료형
**/

element stack[MAX_STACK_SIZE];	// 1차원 배열
int  top = -1;

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입 함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제 함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크 함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

void print_stack(StackType* s) {
	printf("stack (%d)개 : ", s->top + 1);
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
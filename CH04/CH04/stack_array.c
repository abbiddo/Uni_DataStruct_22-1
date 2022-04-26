#include <stdio.h>
//#include <stdlib.h>
#define MAX_STACK_SIZE 100

// 전역 변수
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

element is_empty() { return (top == -1); }
element is_full() { return (top == MAX_STACK_SIZE - 1); }
void push(element n) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러");
		exit(1);
	}
	stack[++top] = n;
}
element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러");
		exit(1);
	}
	return stack[top--];
}
element peak() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러");
		exit(1);
	}
	return stack[top];
}

int main() {
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
}

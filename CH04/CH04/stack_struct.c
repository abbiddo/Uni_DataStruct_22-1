#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef struct {
	int data[MAX_STACK_SIZE];
	int top;
}Stack;

void init(Stack* s) { s->top = -1; }
int is_empty(Stack* s) { return (s->top == -1); }
int is_full(Stack* s) { return (s->top == MAX_STACK_SIZE - 1); }
void push(Stack* s, int n) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러");
		exit(1);
	}
	s->data[++(s->top)] = n;
}
int pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러");
		exit(1);
	}
	return s->data[(s->top)--];
}
int peak(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러");
		exit(1);
	}
	return s->data[s->top];
}

int main() {
	Stack s;
	Stack ss;

	init(&s);
	init(&ss);

	push(&s,1);
	push(&s,2);
	push(&s,3);

	push(&ss, pop(&s));
	push(&ss, pop(&s));
	push(&ss, pop(&s));

	printf("%d\n", pop(&ss));
	printf("%d\n", pop(&ss));
	printf("%d\n", pop(&ss));
}

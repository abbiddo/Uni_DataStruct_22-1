#include <stdio.h>

typedef int element;
typedef struct {
	element *data;
	int capacity;
	int top;
}Stack;

void init(Stack* s) { 
	s->top = -1; 
	s->capacity = 1;
	s->data = (int*)malloc(s->capacity * sizeof(int));
}
int is_empty(Stack* s) { return (s->top == -1); }
int is_full(Stack* s) { return (s->top == s->capacity - 1); }
void push(Stack* s, int n) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (int*)realloc(s->data,s->capacity * sizeof(int));
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

	init(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
}

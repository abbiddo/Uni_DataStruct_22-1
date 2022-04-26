#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}Stack;

void init(Stack* s) { s->top = -1; }
int is_empty(Stack* s) { return (s->top == -1); }
int is_full(Stack* s) { return (s->top == MAX_STACK_SIZE - 1); }
void push(Stack* s, element n) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러");
		exit(1);
	}
	s->data[++(s->top)] = n;
}
element pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러");
		exit(1);
	}
	return (s->data[(s->top)--]);
}
element peek(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러");
		exit(1);
	}
	return (s->data[s->top]);
}

int prec(char ch) {
	switch (ch) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

void infix_to_postfix(const char* p) {
	Stack s;
	char ch, pch;
	int len = strlen(p);

	init(&s);
	for (int i = 0; i < len; i++) {
		ch = p[i];
		switch (ch) {
		case '+': case '-': case '/': case '*':
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) printf("%c", pop(&s));
			push(&s, ch);
			break;
		case '(': push(&s, ch); break;
		case ')':
			pch = pop(&s);
			while (pch != '(') {
				printf("%c", pch);
				pch = pop(&s);
			}
			break;
		default: printf("%c", ch); break;
		}
	}
	while (!is_empty(&s)) printf("%c", pop(&s));
}
int main() {
	int result;
	char* p = "(2+3)*4+9";
	infix_to_postfix(p);
}
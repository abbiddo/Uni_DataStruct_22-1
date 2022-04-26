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

int check(const char p[]) {
	Stack s;
	int len = strlen(p);
	char ch,pch;

	init(&s);
	for (int i = 0; i < len; i++) {
		ch = p[i];
		switch (ch) {
		case '(': case '{': case'[':
			push(&s, ch);
			break;
		case ')': case '}': case']':
			if (is_empty(&s)) return 0;
			pch = pop(&s);
			if ((ch == ')' && pch != '(') || (ch == '}' && pch != '{') || (ch == ']' && pch != '[')) return 0;
			break;
		}
	}
	if (is_empty(&s)) return 1;
	return 0;
}

int main() {
	char* p = "{ A[(i+1)]=; }";
	if (check(p) == 1) printf("%s 괄호 검사 성공", p);
	else printf("%s 괄호 검사 실패", p);
}
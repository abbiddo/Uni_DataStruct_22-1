#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}Stack;

void init(Stack* s) { s->top = -1; }
int is_empty(Stack* s) { return (s->top == -1); }
int is_full(Stack* s) { return (s->top == MAX_STACK_SIZE - 1); }
void push(Stack* s, int n) { s->data[++(s->top)] = n; }
int pop(Stack* s) { return s->data[(s->top)--]; }
int peek(Stack* s) { return s->data[s->top]; }

void pair(char p[]) {
	Stack s;
	int len = strlen(p);
	int k=0;
	char ch;

	init(&s);
	for (int i = 0; i < len; i++) {
		ch = p[i];
		if (ch == '(') {
			push(&s, (++k));
			printf("%d ", k);
		}
		else printf("%d ", pop(&s));
	}
}
int main() {
	char* p = "((())(()))";
	pair(p);
}
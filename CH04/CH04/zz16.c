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
void push(Stack* s, int n) { s->data[++(s->top)] = n; }
int pop(Stack* s) { return s->data[(s->top)--]; }
int peek(Stack* s) { return s->data[s->top]; }

int main() {
	char p[100] = { 0 };
	int len;
	char ch;
	Stack s;
	init(&s);
	
	scanf_s("%[^\n]s", p,100);
	len = strlen(p);

	for (int i = 0; i < len; i++) {
		ch = p[i];
		if (ch > 64 && ch < 81) {
			p[i] += 32;
			push(&s, p[i]);
		}
		else if (ch > 96 && ch < 123) push(&s, ch);
	}

	for (int i = 0; i < len; i++) {
		if (p[i] > 96 && p[i] < 123) {
			ch = pop(&s);
			if (ch != p[i]) {
				printf("회문이 아닙니다");
				return 0;
			}
		}
	}
	if (is_empty(&s)) printf("회문입니다.");
	else printf("회문이 아닙니다");
}
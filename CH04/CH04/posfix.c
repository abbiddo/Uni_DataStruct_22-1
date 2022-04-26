#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}Stack;

void init(Stack* s) { s->top = -1; }
int is_empty(Stack* s) { return (s->top == -1); }
int is_full(Stack* s) { return (s->top == MAX_STACK_SIZE - 1); }
void push(Stack* s, element n) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����");
		exit(1);
	}
	s->data[++(s->top)] = n;
}
element pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����");
		exit(1);
	}
	return (s->data[(s->top)--]);
}
element peek(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����");
		exit(1);
	}
	return (s->data[s->top]);
}

int eval(char* p) {
	Stack s;
	int op1, op2;
	char ch;
	int len = strlen(p);

	init(&s);

	for (int i = 0; i < len; i++) {
		ch = p[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') push(&s, (ch - '0'));
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) {
			case'+': push(&s, op1 + op2); break;
			case'-': push(&s, op1 - op2); break;
			case'*': push(&s, op1 * op2); break;
			case'/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

int main() {
	int result;
	char* p = "82/3-32*+";
	printf("���� ǥ�� ���� %s\n", p);
	result = eval(p);
	printf("��� ���� %d", result);
}
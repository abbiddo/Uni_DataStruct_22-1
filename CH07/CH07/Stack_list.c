#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
}StackNode;
typedef struct {
	StackNode* top;
}LinkedStackType;

void init(LinkedStackType* s) { s->top = NULL; }
int is_empty(LinkedStackType* s) { return (s->top == NULL); }
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}
void print_stack(LinkedStackType* s) {
	for (StackNode* p = s->top; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}
element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr,"스택 공백 에러");
		exit(1);
	}
	StackNode* temp = s->top;
	int data = temp->data;         // 리턴을 위해 미리 저장해 둠
	s->top = temp->link;             // s->top = s->top->link;
	free(temp);
	return data;
}
element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr,"스택 공백 에러");
		exit(1);
	}
	return s->top->data;
}

// 실습 : 스택 최댓값 구하기
element stack_max(LinkedStackType* s) {
	StackNode* p;
	int max = s->top->data;
	for (p = s->top->link; p != NULL; p = p->link)
		if (max < p->data) max = p->data;
	return max;
}

int main() {
	LinkedStackType s;
	init(&s);

	push(&s, 1); print_stack(&s);
	push(&s, 2); print_stack(&s);
	push(&s, 3); print_stack(&s);

	/*pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);*/

	printf("Stack max : %d", stack_max(&s));
}
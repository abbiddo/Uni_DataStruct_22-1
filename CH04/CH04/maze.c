#include <stdio.h>
#include <string.h>
#include <windows.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {
	short r, c;
}element;
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

element here = { 1,0 }, entry = { 1,0 };
char maze[MAZE_SIZE][MAZE_SIZE] = {
{ '1', '1', '1', '1', '1', '1' },
{ 'e', '0', '1', '0', '0', '1' },
{ '1', '0', '0', '0', '1', '1' },
{ '1', '0', '1', '0', '1', '1' },
{ '1', '0', '1', '0', '0', 'x' },
{ '1', '1', '1', '1', '1', '1' },
};

void push_loc(Stack* s, int r, int c) {
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp = { r,c };
		push(s, tmp );
	}
}

void maze_print(char m[MAZE_SIZE][MAZE_SIZE]) {
	printf("\n");
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) printf("%c ", maze[i][j]);
		printf("\n");
	}
}

int main() {
	int r, c;
	Stack s;

	init(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x') {
		system("cls");
		r = here.r;
		c = here.c;
		maze[r][c] = '.';

		maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);

		if (is_empty(&s)) {
			printf("실패");
			return 0;
		}
		else here = pop(&s);
		Sleep(1000);
	}
	printf("성공");
}
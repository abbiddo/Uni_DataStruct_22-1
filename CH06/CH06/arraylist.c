#include <stdio.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}List;

void error(char* message) {
	fprintf(stderr, "%s", message);
	exit(1);
}
void init(List* L) { L->size = 0; }
int is_empty(List* L) { return (L->size == 0); }
int is_full(List* L) { return (L->size == MAX_LIST_SIZE); }
element get_entry(List* L, int pos) {
	if (pos < 0 || pos >= L->size) error("위치 오류");
	return (L->array[pos]);
}
void print_list(List* L) {
	for (int i = 0; i < L->size; i++) printf("%d -> ", L->array[i]);
	printf("\n");
}
void insert_last(List* L, element item) {
	if (L->size >= MAX_LIST_SIZE) error("리스트 오버플로우");
	L->array[(L->size)++] = item;
}
void insert(List* L, int pos, element item) {
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		//for (int i = (L->size - 1); i >= pos; i--) L->array[i + 1] = L->array[i];
		//printf(">값(%d)를 (%d) --> (%d)\n", L->array[i], i, i + 1);

		for (int i = L->size; i > pos; i--)	{
			L->array[i] = L->array[i - 1];
			printf(">값(%d)를 (%d) --> (%d)\n", L->array[i], i - 1, i);
		}

		L->array[pos] = item;
		L->size++;
	}
	else if (is_full(L)) error("리스트 오버플로우");
	else error("위치 오류");
}
void delete(List* L, int pos) {
	//if (!is_empty(L) && pos>=0 && pos<=MAX_LIST_SIZE)
	element item;

	if (pos < 0 || pos >= L->size) error("위치 오류");
	item = L->array[pos];

	for (int i = pos; i < (L->size - 1); i++){
		L->array[i] = L->array[i + 1];
		printf(">값(%d)를 (%d) <-- (%d)\n", L->array[i + 1], i, i + 1);
	}

	L->size--;

	return item;
}

int main() {
	List list;

	init(&list);
	insert(&list, 0, 10); print_list(&list);
	insert(&list, 0, 20); print_list(&list);
	insert(&list, 0, 30); print_list(&list);
	insert_last(&list, 40); print_list(&list);
	delete(&list, 0); print_list(&list);
}

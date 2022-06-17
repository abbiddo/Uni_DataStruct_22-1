#include <stdio.h>
#include <time.h>
#define MAX_SIZE 100

int list[MAX_SIZE + 1];

int seq_search(int key, int low, int high) {
	for (int i = low; i <= high; i++)
		if (list[i] == key) return i;
	return -1;
}
int seq_search2(int key, int low, int high) {
	int i;
	list[high + 1] = key;
	for (i = 0; list[i] != key; i++);
	if (i == high + 1) return -1;
	return i;
}

int main(void)
{
	int i, result;
	clock_t start, end;

	int n = MAX_SIZE;
	//srand(time(NULL));
	srand(1);
	for (i = 0; i < n; i++) list[i] = rand() % 100;

	for (i = 0; i < n; i++) printf("%d ", list[i]);

	result = seq_search2(69, 0, n - 1);

	if (result == -1) printf("\n- Å½»ö ½ÇÆÐ(%d)\n", result);
	else 	printf("\n- Å½»ö ¼º°ø(%d)\n", result);

	return 0;
}
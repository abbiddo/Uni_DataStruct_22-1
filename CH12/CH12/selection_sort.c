#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )
#define MAX_SIZE 10

void selection_sort(int list[], int n) {
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++)
			if (list[least] > list[j]) least = j;
		SWAP(list[i], list[least], temp);
	}
}

// 실습 내림차순
void selection_sort2(int list[], int n) {
	int i, j, big, temp;
	for (i = 0; i < n - 1; i++) {
		big = i;
		for (j = i + 1; j < n; j++)
			if (list[big] < list[j]) big = j;
		SWAP(list[i], list[big], temp);
	}
}

int main() {
	int i;
	int n = MAX_SIZE;
	int list[MAX_SIZE];
	clock_t start, stop;

	srand(time(NULL));
	for (i = 0; i < n; i++) list[i] = rand() % 100;

	start = clock();
	selection_sort(list, n);
	stop = clock();
	for (i = 0; i < n; i++) printf("%d ", list[i]);
	printf("\n");

	selection_sort2(list, n);
	for (i = 0; i < n; i++) printf("%d ", list[i]);

	printf("\n%lf초\n", (double)(stop - start) / CLOCKS_PER_SEC);
}
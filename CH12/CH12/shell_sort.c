#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void inc_insertion_sort(int list[], int first, int last, int gap) {
	int i, j, key;
	for (i = first + gap; i <= last; i += gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j -= gap)		// 내림차순 부등호 반대로
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}
void shell_sort(int list[], int n) {
	int i, gap;
	for (int gap = n / 2; gap > 0; gap /= 2) {
		if (gap % 2 == 0) gap++;
		for (i = 0; i < gap; i++) inc_insertion_sort(list, i, n - 1, gap);
	}
}

int main() {
	int n = MAX_SIZE;
	int list[MAX_SIZE];
	clock_t start, stop;

	srand(time(NULL));
	for (int i = 0; i < n; i++) list[i] = rand();

	printf("\n 정렬 전 : \n");
	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);

	start = clock();
	shell_sort(list, n);
	stop = clock();

	printf("\n 정렬 후 : \n");
	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);

	printf("\n소요 시간 = %lf 초\n", (double)(stop - start) / CLOCKS_PER_SEC);
}
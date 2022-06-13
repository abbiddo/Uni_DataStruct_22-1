#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )
#define MAX_SIZE 10000

int partition(int list[], int left, int right) {
	int pivot = list[left] , temp;
	int low = left, high = right + 1;

	do {
		do low++; while (low <= right && list[low] < pivot);
		do high--; while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[high], list[left], temp);
	return high;
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
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
	quick_sort(list, 0, n - 1);
	stop = clock();

	printf("\n 정렬 후 : \n");
	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);

	printf("\n소요 시간 = %lf 초\n", (double)(stop - start) / CLOCKS_PER_SEC);
}
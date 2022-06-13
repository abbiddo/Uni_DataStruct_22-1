#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left, l;

	while (i <= mid && j <= right) {
		// 내림 차순 : >=
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}

	if (i > mid)
		for (l = j; l <= right; l++) sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++) sorted[k++] = list[l];

	for (l = left; l <= right; l++) list[l] = sorted[l];
}
void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
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
	merge_sort(list, 0, n-1);			// n-1까지 마지막 인덱스는 9999니까
	stop = clock();

	printf("\n 정렬 후 : \n");
	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);

	printf("\n소요 시간 = %lf 초\n", (double)(stop - start) / CLOCKS_PER_SEC);
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10000

void insertion_sort(int list[], int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) 
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}

// �ǽ� ��������
void insertion_sort2(int list[], int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] < key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}

int main() {
	int list[MAX_SIZE];
	int n = MAX_SIZE;
	clock_t start, stop;

	srand(time(NULL));
	for (int i = 0; i < n; i++)
		list[i] = rand();

	printf("\n ���� �� : \n");
	for (int i = 0; i < 100; i++)
		printf("%d ", list[i]);

	insertion_sort(list, n); // ���ĵ� ���� ������ ���� �ð��� �˾ƺ��� ����

	start = clock();
	insertion_sort(list, n);
	stop = clock();

	printf("\n �������� ���� �� : \n");
	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);

	insertion_sort2(list, n);

	printf("\n �������� ���� �� : \n");
	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);

	printf("\n�ҿ� �ð� = %lf ��\n", (double)(stop - start) / CLOCKS_PER_SEC);
}
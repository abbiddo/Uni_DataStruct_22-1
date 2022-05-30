#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )
#define MAX_SIZE 10000

int bubble_sort(int list[], int n) {
	int temp, cnt = 0;
	for (int i = 0; i < n - 1; i++) 
		for (int j = 0; j < n - i - 1; j++) 
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
				cnt++;
			}
	return cnt;
}

// �ǽ� ��������
int bubble_sort2(int list[], int n) {
	int temp, cnt = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (list[j] < list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
				cnt++;
			}
return cnt;
}

int main() {
	int i, count;
	int n = MAX_SIZE;
	int list[MAX_SIZE];
	clock_t start, stop;

	srand(time(NULL));
	for (i = 0; i < n; i++) list[i] = rand();

	printf("\n ���� �� : \n");
	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);

	start = clock(); 
	count = bubble_sort(list, n);
	stop = clock();

	printf("\n �������� ���� �� : \n");
	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);
	printf("\nswap count : %d\n", count);

	count = bubble_sort(list, n);
	printf("\n������ (0) swap count : %d\n", count);

	count = bubble_sort2(list, n);
	printf("\n������ (�ִ�) swap count : %d\n", count);

	printf("\n �������� ���� �� : \n");
	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);

	printf("\n�ҿ� �ð� = %lf ��\n", (double)(stop - start) / CLOCKS_PER_SEC);
}
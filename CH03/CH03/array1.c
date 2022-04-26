#include <stdio.h>
#define SIZE 6

void get_integers(int list[]) {
	printf("6개 정수 입력 : ");
	for (int i = 0; i < SIZE; i++) scanf_s("%d", &list[i]);
}

int cal_sum(int list[]) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++) sum += list[i];
	return sum;
}

int main() {
	int list[SIZE];
	get_integers(list);
	printf("%d", cal_sum(list));
}
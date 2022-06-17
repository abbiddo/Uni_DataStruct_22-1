#include <stdio.h>
#define MAX_ELEMENTS 16

//int list[MAX_ELEMENTS] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//int list[MAX_ELEMENTS] = { 1, 30, 80, 120, 130, 135, 146, 148, 149, 150 };
//int list[MAX_ELEMENTS] = { 1, 130, 142, 143, 144, 145, 146, 148, 149, 150 };
int list[MAX_ELEMENTS] = { 8,11,12,15,16,19,20,23,25,28,29,31,33,35,38,40 };
int count;

int search_binary2(int key, int n) {
	int left = 0, right = n - 1, middle;
	count = 0;

	while (left <= right) {
		count++;			// 중간값 - 1 숫자 검색하면 count : 1
		middle = (left + right) / 2;
		if (list[middle] == key) return middle;
		else if (list[middle] < key) left = middle + 1;
		else right = middle - 1;
	}
	return -1;
}

int search_interpolation(int key, int n) {
	int low = 0, high = n - 1;
	count = 0;

	while (list[high] >= key && key > list[low]) {
		count++;
		int j = ((float)(key - list[low]) / (list[high] - list[low]) * (high - low)) + low;
		if (key > list[j]) low = j + 1;
		else if (key < list[j])high = j - 1;
		else low = j;
	}

	if (list[low] == key) return low;
	return -1;
}

int main(){
	int i = 0, search_number;

	for (i = 0; i < MAX_ELEMENTS; i++) printf(" %d", list[i]);
	printf("\n");

	printf("> 탐색할 숫자를 입력하시요 : ");
	scanf_s("%d", &search_number);

	count = 0;
	i = search_binary2(search_number, MAX_ELEMENTS);

	printf("- 비교 수행 횟수 : %d\n ", count);
	if (i >= 0) printf("탐색 성공 i = %d\n", i);
	else printf("탐색 실패\n");

	count = 0;
	i = search_interpolation(search_number, MAX_ELEMENTS);

	printf("- 비교 수행 횟수 : %d\n ", count);
	if (i >= 0) printf("탐색 성공 i = %d\n", i);
	else printf("탐색 실패\n");
}
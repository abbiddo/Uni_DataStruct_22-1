#include <stdio.h>
#include <time.h>
#define MAX_ELEMENTS 16//00000L

int count;
int list[MAX_ELEMENTS] = { 8,11,12,15,16,19,20,23,25,28,29,31,33,35,38,40 };

int seqsearch(int list[], int n, int searchnum) {
	count = 0;
	for (int i = 0; i < n; i++){
		count++;
		if (list[i] == searchnum) return i;
	}
	return -1;
}

int binsearch2(int key, int low, int high) {
	int middle;
	if (low <= high) {
		middle = (low + high) / 2;
		if (key == list[middle]) return middle;
		else if (key < list[middle]) return binsearch2(key, low, middle - 1);
		else return binsearch2(key, middle + 1, high);
	}
	return -1;
}

int binsearch(int list[], int n, int searchnum) {
	int left = 0, right = n - 1, middle;
	count = 0;

	while (left <= right) {
		count++;			// 중간값 - 1 숫자 검색하면 count : 1
		middle = (left + right) / 2;
		//printf("%d   -   ", list[middle]);
		if (list[middle] == searchnum) return middle;
		else if (list[middle] < searchnum) left = middle + 1;
		else right = middle - 1;
	}
	return -1;
}

int main(){
	int i, search_number, return_value;
	clock_t	 start, finish, duration;

	//for (i = 0; i < MAX_ELEMENTS; i++) list[i] = i;

	printf("> 탐색할 숫자를 입력하시요 : ");
	scanf_s("%d", &search_number);

	start = clock();
	return_value = seqsearch(list, MAX_ELEMENTS, search_number);
	finish = clock();

	duration = finish - start;
	printf("> seq. search 시간 : %d milliseconds\n", duration);
	printf("- 비교 수행 횟수 : %d\n ", count);

	start = clock();
	return_value = binsearch(list, MAX_ELEMENTS, search_number);
	finish = clock();

	duration = finish - start;
	printf("> binary search 시간 : %d milliseconds\n", duration);
	printf("- 비교 수행 횟수 : %d\n ", count);

	start = clock();
	return_value = binsearch2(search_number, 0, MAX_ELEMENTS);
	finish = clock();

	duration = finish - start;
	printf("> binary search 시간 : %d milliseconds\n", duration);
	printf("- 비교 수행 횟수 : %d\n ", count);

	if (return_value == -1) printf("> 숫자가 발견되지 않았습니다.\n", &search_number);
	else printf("> 숫자가 위치 %d에서 발견되었습니다.\n", return_value);
}
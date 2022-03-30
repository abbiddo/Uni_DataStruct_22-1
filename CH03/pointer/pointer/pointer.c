#include <stdio.h>
void func(int n, int m);
void get_data(int data[], int length);

int main() {
	int a;
	int* p;

	a = 100;
	p = &a;

	printf("a = %d\n", a);
	printf("*p = %d\n", *p);
	printf("-------------------------\n");

	int n = 1, m = 2;
	printf("1> n = %d, m = %d\n", n, m);
	func(&n, &m);
	printf("2> n = %d, m = %d\n", n, m);
	printf("-------------------------\n");

	int data[4];
	get_data(data,4);
	for (int i = 0; i < 4; i++) printf("%d ", data[i]);
}

void func(int *n, int *m) {
	int tmp;

	printf("func-1> n = %d, m = %d\n", *n, *m); // *은 주소로 가서 값을 가져옴
	tmp = *n;
	*n = *m;
	*m = tmp;
	printf("func-2> n = %d, m = %d\n", *n, *m);
}

void get_data(int data[], int length){
	printf("get_data> 정수 4개를 입력하세요 : ");
	for (int i = 0; i < length; i++) scanf("%d", data+i); // &data[i]
}
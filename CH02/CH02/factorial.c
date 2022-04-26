#include <stdio.h>
#include <time.h>
int factorial(int n);
int factorial_iter(int n);

int main() {
	int result, i;
	//	double duration;;
	//	clock_t start, stop;

	//	start = clock();
	for (i = 2; i <= 10; i++) {
		result = factorial(i);
		printf("%d! = %d\n", i, result);
	}
	//	stop = clock();
	//	duration = (double)(stop - start)/CLOCKS_PER_SEC;
	//	printf("> 실행 시간 = %lfsec\n", duration);
	// 
		// 반복문 -> 0.001;
		// 재귀 -> 0.002;
}

int factorial(int n) {
	if (n < 1) {
		printf("해당 숫자에 대해서 factorial이 정의 되지 않음\n");
		return 0;
	}

	if (n < 2) return n;
	return factorial(n - 1) * n;
}

// 반복적 방법(iterative)으로 구현
int factorial_iter(int n) {
	int result = 1;

	if (n < 1) {
		printf("해당 숫자에 대해서 factorial이 정의 되지 않음\n");
		return 0;
	}

	for (int i = n; i > 1; i--) result *= i;
	return result;
}
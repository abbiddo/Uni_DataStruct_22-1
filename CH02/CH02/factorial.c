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
	//	printf("> ���� �ð� = %lfsec\n", duration);
	// 
		// �ݺ��� -> 0.001;
		// ��� -> 0.002;
}

int factorial(int n) {
	if (n < 1) {
		printf("�ش� ���ڿ� ���ؼ� factorial�� ���� ���� ����\n");
		return 0;
	}

	if (n < 2) return n;
	return factorial(n - 1) * n;
}

// �ݺ��� ���(iterative)���� ����
int factorial_iter(int n) {
	int result = 1;

	if (n < 1) {
		printf("�ش� ���ڿ� ���ؼ� factorial�� ���� ���� ����\n");
		return 0;
	}

	for (int i = n; i > 1; i--) result *= i;
	return result;
}
#include <stdio.h>
#include <time.h>

double slow_power(double x, int n) {
	double result = 1.0;
	for (int i = 0; i < n; i++) result *= x;
	return result;
}

double power(double x, int n) {
	if (n == 0) return 1;
	else if (n % 2 == 0) return power(x * x, n / 2);
	else return x * power(x * x, (n - 1) / 2);
}

// 내가 그냥 해 봄
double power3(double x, int n) {
	if (n == 0) return 1;
	else if (n % 3 == 0) return power3(x * x * x, n / 3);
	else if (n % 3 == 1) return x * power3(x * x * x, n / 3);
	return x * x * power(x * x * x, n / 3);
}

int main() {
	int x, n;
	scanf_s("%d %d", &x, &n);

	printf("%.0lf", power(x, n));
}
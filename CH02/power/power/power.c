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

int main() {
	int x, n;
	scanf_s("%d %d", &x, &n);

	printf("%.0lf", power(x, n));
}
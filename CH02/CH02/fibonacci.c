#include <stdio.h>
#include <time.h>

int fib(int n) {
	if (n < 2) return n;
	else if (n > 1) return fib(n - 1) + fib(n - 2);
}

int fib_iter(int n) {
	if (n < 2) return n;
	int i, tmp, current = 1, last = 0;
	for (int i = 2; i <= n; i++) {
		tmp = current;
		current += last;
		last = tmp;
	}
	return current;
}

int main() {
	//	double duration;
	//	clock_t start, stop;

	//	start = clock();
	for (int i = 0; i < 41; i++) printf("%d\n", fib_iter(i));
	//	stop = clock();

	//	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	//	printf("%lf sec", duration);
}
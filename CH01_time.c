#include <stdio.h>
#include <time.h>
int main() {
	int i;
	//clock_t start, stop; //clock은 단위가 clock (이거 쓰는 게 더 정확)
	time_t start, stop; // time은 단위가 sec (오차 발생 가능)
	double sum = 0.0, duration;

	//start = clock();
	start = time(NULL);
	for (int i = 0;i < 100000000;i++) {
		sum += i;
	}
	//stop = clock();
	stop = time(NULL);

	//duration = (double)(stop - start) / CLOCKS_PER_SEC;
	duration = difftime(stop,start);
	printf("> sum = %lf\nexe time = %lfsec\n", sum, duration);

	return 0; // 정상종료
}

#include <stdio.h>
#include <time.h>
int main() {
	int i;
	//clock_t start, stop; //clock�� ������ clock (�̰� ���� �� �� ��Ȯ)
	time_t start, stop; // time�� ������ sec (���� �߻� ����)
	double sum = 0.0, duration;

	//start = clock();
	start = time(NULL);
	for (int i = 0; i < 100000000; i++) {
		sum += i;
	}
	//stop = clock();
	stop = time(NULL);

	//duration = (double)(stop - start) / CLOCKS_PER_SEC;
	duration = difftime(stop, start);
	printf("> sum = %lf\nexe time = %lfsec\n", sum, duration);

	return 0; // ��������
}
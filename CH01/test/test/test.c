#include <stdio.h>
#define N 10
int main() {
	int data[N] = { 1,2,3,4,5,6,7,8,9,10 };
	int sum = 0, i, oddcnt = 0, evencnt = 0;
	int max, min;

	// Ȧ�� ����
	for (i = 0; i < N; i++) if (data[i] % 2 == 1) oddcnt++;
	// ¦�� ����
	for (i = 0; i < N; i++) if (data[i] % 2 == 0) evencnt++;
	// �ִ�
	max = data[0];
	for (i = 1; i < N; i++) if (max < data[i]) max = data[i];
	// �ּڰ�
	min = data[0];
	for (i = 1; i < N; i++) if (min > data[i]) min = data[i];

	// ��
	for (i = 0; i < N; i++) sum += data[i];

	printf("> Ȧ�� ���� = %d\n", oddcnt);
	printf("> ¦�� ���� = %d\n", evencnt);
	printf("> �ִ� = %d\n", max);
	printf("> �ּڰ� = %d\n", min);
	printf("> �� = %d\n", sum);
}
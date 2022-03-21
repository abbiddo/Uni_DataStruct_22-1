#include <stdio.h>
#define N 10
int main() {
	int data[N] = { 1,2,3,4,5,6,7,8,9,10 };
	int sum = 0, i, oddcnt = 0, evencnt = 0;
	int max, min;

	// È¦¼ö °³¼ö
	for (i = 0; i < N; i++) if (data[i] % 2 == 1) oddcnt++;
	// Â¦¼ö °³¼ö
	for (i = 0; i < N; i++) if (data[i] % 2 == 0) evencnt++;
	// ÃÖ´ñ°ª
	max = data[0];
	for (i = 1; i < N; i++) if (max < data[i]) max = data[i];
	// ÃÖ¼Ú°ª
	min = data[0];
	for (i = 1; i < N; i++) if (min > data[i]) min = data[i];

	// ÇÕ
	for (i = 0; i < N; i++) sum += data[i];

	printf("> È¦¼ö °³¼ö = %d\n", oddcnt);
	printf("> Â¦¼ö °³¼ö = %d\n", evencnt);
	printf("> ÃÖ´ñ°ª = %d\n", max);
	printf("> ÃÖ¼Ú°ª = %d\n", min);
	printf("> ÇÕ = %d\n", sum);
}
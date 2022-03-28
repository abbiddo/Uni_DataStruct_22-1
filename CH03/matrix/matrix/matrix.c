#include <stdio.h>
#define ROWS 	4
#define COLS 	4

void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS]);
void matrix_print(int A[ROWS][COLS]);

int main(void)
{
	int array1[ROWS][COLS] =
	{ { 5,3,1,2 },
	  { 4,9,8,7 },
	  { 2,0,5,6 },
	  { 1,2,4,9 } };
	int array2[ROWS][COLS];
	matrix_transpose(array1, array2);
	matrix_print(array1);
	matrix_print(array2);
	return 0;
}

// 행렬 전치 함수
void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS])
{
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			B[c][r] = A[r][c];
		}
	}
}

void matrix_print(int A[ROWS][COLS])
{
	printf("====================\n");
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			printf("%d ", A[r][c]);
		}
		printf("\n");
	}
	printf("====================\n");
}

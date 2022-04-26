#include <stdio.h>
#define ROW 3
#define COL 3

void matrix_transpose(int A[ROW][COL], int B[ROW][COL]) {
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			B[j][i] = A[i][j];
}

void matrix_print(int M[ROW][COL]) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++)
			printf("%d ", M[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main() {
	int array1[ROW][COL] = { {2,3,0},{8,9,1},{7,0,5} };
	int array2[ROW][COL];

	matrix_transpose(array1, array2);
	matrix_print(array1);
	matrix_print(array2);
}
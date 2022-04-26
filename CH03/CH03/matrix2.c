#include <stdio.h>
#define MAX_TERM 100

typedef struct {
	int row;
	int col;
	int value;
}element;

typedef struct {
	element data[MAX_TERM];
	int rows;
	int cols;
	int terms;
}SparseMatrix;

SparseMatrix matrix_transepose(SparseMatrix a) {
	SparseMatrix b;
	int bindex;
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;

	if (a.terms > 0) {
		bindex = 0;
		for (int i = 0; i < a.cols; i++) {                    // 오름차순? 의미 없쥬~
			for (int j = 0; j < a.terms; j++) {
				if (a.data[j].col == i) {
					b.data[bindex].col = a.data[j].row;
					b.data[bindex].row = a.data[j].col;
					b.data[bindex].value = a.data[j].value;
					bindex++;
				}
			}
		}
	}
	return b;
}

void matrix_print(SparseMatrix a) {
	for (int i = 0; i < a.terms;i++) printf("( %d, %d, %d )\n", a.data[i].row, a.data[i].col, a.data[i].value);
	printf("\n");
}

int main() {
	SparseMatrix m = { {{2,0,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},6,6,7 };

	SparseMatrix result;

	/*result = matrix_transepose(m);
	matrix_print(result);*/

	matrix_print(matrix_transepose(m));
}
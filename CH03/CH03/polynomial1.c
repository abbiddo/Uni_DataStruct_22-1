#include <stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial poly_add1(polynomial A, polynomial B) {
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);

	for (int i = 0; i <=C.degree; i++) {
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_b > degree_a) {
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
		else {
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
	}

	return C;
}

void print_poly(polynomial p) {
	int i = 0;
	while (p.coef[i] == 0) { i++; }
	for (i; i < p.degree; i++)
		printf("%.1fx^%d + ", p.coef[i], p.degree - i);
	printf("%.1f\n",p.coef[p.degree]);
}

int main() {
	/*polynomial a = { 5,{3,6,0,0,0,10} };
	polynomial b = { 4,{7,0,5,0,1} };*/

	polynomial a = { 3,{1,0,2,3} };
	polynomial b = { 3,{-1,0,4,-1} };
	polynomial c;

	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b);
	print_poly(c);
}
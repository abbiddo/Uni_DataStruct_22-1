#include <stdio.h>
#define MAX_TERM 101

typedef struct {
	float coef;
	int expon;
}polynomial;

polynomial terms[MAX_TERM] = { {8,3},{7,1},{1,0},{10,3},{3,2},{1,0} };
int avail = 6;

char compare(int a, int b) {
	if (a > b) return '>';
	else if(a < b) return '<';
	return '=';
}

void attach(float coef, int expon) {
	if (avail > MAX_TERM) {
		fprintf(stderr, "항의 개수가 너무 많음");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}

void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
	float tmpcoef;
	*Cs = avail;
	while (As <= Ae && Bs <= Be) {
		switch (compare(terms[As].expon, terms[Bs].expon)) {
		case '>':
			attach(terms[As].coef, terms[As].expon);
			As++;
			break;
		case '<':
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;
			break;
		case '=':
			tmpcoef = terms[As].coef + terms[Bs].coef;
			if (tmpcoef) attach(tmpcoef, terms[As].expon);
			As++; Bs++;
			break;
		}
	}

	for (; As <= Ae; As++) attach(terms[As].coef, terms[As].expon);
	for (; Bs <= Be; Bs++) attach(terms[Bs].coef, terms[Bs].expon);

	*Ce = avail - 1;
}
void print_poly(int s, int e) {
	for (int i=s; i < e; i++)
		printf("%.1fx^%d + ", terms[i].coef,terms[i].expon);
	printf("%.1f\n",terms[e].coef);
}

int main() {
	int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	print_poly(Cs, Ce);
}
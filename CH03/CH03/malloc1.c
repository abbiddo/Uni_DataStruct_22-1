#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct {
	char name[10];
	int age;
	double gpa;
}student;

int main() {
	student* s;

	s = (student*)malloc(sizeof(student));
	if (s == NULL) {
		fprintf(stderr, "메모리 할당 X, 메모리 부족");
		exit(1);
	}

	strcpy(s->name, "Park");
	s->age = 20;

	free(s);
}
#include <stdio.h>
typedef struct studentTag {
	char	name[10]; 	// ���ڹ迭�� �� �̸�
	int		age;	 	// ���̸� ��Ÿ���� ������
	double	gpa;		// ��� ������ ��Ÿ���� �Ǽ���
} student;

double AvgOfGPA(student data[], int num);

int main(void)
{
	double avg;
	student data[10] = { { "kim", 20, 4.0 },
							{ "choi", 20, 3.7 },
							{ "park", 20, 4.1 },
							{ "lee", 20, 3.5 },
							{ "jeong", 20, 3.3 },
							{ "song", 20, 3.2 },
							{ "hwang", 20, 3.6 },
							{ "koo", 20, 3.5 },
							{ "na", 20, 3.8 },
							{ "oh", 20, 3.9 }
	};

	avg = AvgOfGPA(data, 10);
	printf("> avg = %lf\n", avg);
	return 0;
}

double AvgOfGPA(student data[], int num)
{
	double result = 0.0;
	for (int i = 0; i < num; i++) result += data[i].gpa;
	result /= num;

	return result;
}

/*int main() {
	student st[2] = { {"kim",20,3.5}, {"park",20,3.8} }; // ����ü �迭
	
	for (int i = 0; i < 2; i++)
		printf("st[%d] : %s, %d, %lf\n",i, st[i].name, st[i].age, st[i].gpa);
}*/
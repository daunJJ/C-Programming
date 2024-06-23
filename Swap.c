#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// STUDENT ����ü ���� 
struct STUDENT {
	int st_no;
	char st_name[20];
	int kor;
	int eng;
	int mat;
	int tot;
	float avg;
};

// ����ü �����ͷ� ���ڸ� �޾� ����ü ������ swap�ϴ� �Լ� 
void swap(struct STUDENT* p1, struct STUDENT* p2);

int main(void)
{
	// STUDENT ����ü ���� st1�� st2�� �ʱ�ȭ 
	struct STUDENT st1 = { 1001, "IT", 77, 43, 77 }, st2 = { 1002, "CS", 15, 49, 97 };
	// swap�Լ��� �����ͷ� ������ �����ϱ� ���� �� ������ �����͵� ���� 
	struct STUDENT* p1 = &st1, * p2 = &st2;

	// st1�� ������ ��� 
	st1.tot = st1.kor + st1.eng + st1.mat;  
	// st1�� ����� ��� 
	st1.avg = (double) st1.tot / 3;

	// st2�� ������ ��� 
	st2.tot = st2.kor + st2.eng + st2.mat;
	// st2�� ����� ��� 
	st2.avg = (double)st2.tot / 3;

	// swap�� �� �Ǿ����� ������� Ȯ���ϱ� ���� swap����  ���
	printf("��ȯ ��\n"); 
	printf("str1: %d, %s, %d, %d, %d, %d, %.2f\n", st1.st_no, st1.st_name, st1.kor, st1.eng, st1.mat, st1.tot, st1.avg);
	printf("str2: %d, %s, %d, %d, %d, %d, %.2f\n", st2.st_no, st2.st_name, st2.kor, st2.eng, st2.mat, st2.tot, st2.avg);
	
	// swap �Լ��� st1�� st2�� �����͸� ���ڷ� ����, �� ����ü�� �й��� �̸�, �������� ��ȯ 
	swap(p1, p2);
	
	//  swap�� �� �Ǿ����� ������� Ȯ���ϱ� ���� swap�ĸ�  ���
	printf("��ȯ ��\n");
	printf("str1: %d, %s, %d, %d, %d, %d, %.2f\n", st1.st_no, st1.st_name, st1.kor, st1.eng, st1.mat, st1.tot, st1.avg);
	printf("str2: %d, %s, %d, %d, %d, %d, %.2f\n", st2.st_no, st2.st_name, st2.kor, st2.eng, st2.mat, st2.tot, st2.avg);

}

// ����ü �����ͷ� ���ڸ� �޾� ����ü ������ swap�ϴ� �Լ� 
void swap(struct STUDENT*p1, struct STUDENT*p2)
{
	struct STUDENT temp;  // �߰� �����ϴ� ������ �� ����ü ���� 

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 3 

// ����ü ���� 
struct STUDENT {
	int st_no;
	char st_name[20];
	int kor;
	int eng;
	int mat;
	int tot;
	float avg;
};

// �л� �����͸� �Է¹޾� ����ü�� ������ ������ �Լ� ����
struct STUDENT st_input(void);
// �л� �����͸� ���ڷ� �޾� ����� �Լ� ���� 
void st_output(struct STUDENT st);

int main(void)
{
	// ����ü �迭�� �����迭�� ����
	struct STUDENT st[MAX];
	int i, count;  // for���� ����, �л����� ������ ���� 

	for (i = 0; i < MAX; i++)
	{
		st[i] = st_input();   //����ü�� ������ ���� ������� 1:1 ������ �����ϹǷ� �Լ��� ���� ���ϵ� ����ü�� ����ü st[i]�� �����Ѵ� 
		if (st[i].st_no == 0)  // st_no�� 0�� �ԷµǸ� �ݺ����� �����Ű�� �� �̻� �л������͸� ���� ���� 
			break;
	}
	count = i;  // �Է¹��� �л��� ���� count�� ���� 

	printf("\n�л������� ���\n");
	printf("=================\n");
	for (i = 0; i < count; i++) // �Է¹��� �л��� ����ŭ �ݺ�
		st_output(st[i]);  // ����ü�� ���ڷ� �ǳ�, �Լ� �ȿ��� ����Ʈ�Ѵ�

	return 0;  // ��������
}

struct STUDENT st_input(void)  // ���ϰ��� STUDENT ����ü�� �Լ�
{
	struct STUDENT st;

	printf("�л� �����͸� �Է��Ͻÿ�(�ִ� 3��)\n");  // �ִ� 3���� �л������͸� �Է¹��� �� ������ �̸� �˸�
	// �й�, �̸�, ������ �Է¹���
	printf("�й�? ");
	scanf("%d", &st.st_no);
	printf("�̸�? ");
	scanf("%s", &st.st_name);
	printf("��������? ");
	scanf("%d", &st.kor);
	printf("�������� ? ");
	scanf("%d", &st.eng);
	printf("�������� ? ");
	scanf("%d", &st.mat);
	
	// ���� ��� 
	st.tot = st.kor + st.eng + st.mat;
	// ��� ��� (����� �Ҽ��� ����)
	st.avg = (float) st.tot / 3;

	return st;
}

void st_output(struct STUDENT st) // STUDENT ����ü�� ���� �޾� �� ���� ����� 
{
	printf("�й�: %d, �̸�: %s, ����: %d, ����: %d, ����: %d, ����: %d, ���: %.2f\n", st.st_no, st.st_name, st.kor, st.eng, st.mat, st.tot, st.avg);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i;  // for���� ����
	int num;  // �Է¹��� ���� ������ ����
	int count = 0;  // ����� ���� �� ����

	printf("input number ? ");   // ����� ����� ���ڸ� ǥ���Է����� �޾� num�� ����
	scanf("%d", &num);

	for (i = 1; i <= 100; i++)   // 1���� 100���� �ݺ����� �̿��� num�� ����� ���
	{
		if (i % num == 0) {   
			printf("%d ", i);
			count++;  // count�� ������� ��ŭ Ŀ��
		}
	}

	printf("\n");
	printf("count: %d\n", count);  // for�� �������µ� ����� count(����� ����)�� ���
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �Լ�������� 
int normal(int arr[]);  // �迭�� ���޹޾� �������� ��� ���� �ִ����� Ȯ���ϴ� �Լ� 
int min_f(int arr[]);  // �л� ������ ����� �迭�� ���ڷ� �޾� �� �� �ּҰ��� �����ϴ� �Լ� 
int max_f(int arr[]);  // �л� ������ ����� �迭�� ���ڷ� �޾� �� �� �ִ밪�� �����ϴ� �Լ�
double mean_f(int arr[]);  // �л� ������ ����� �迭�� ���ڷ� �޾� ����� �����ϴ� �Լ�


int main(void)
{
	int i;  //for���� ����
	int score[5];  // �л� ������ ������ �迭 
	
    // �������� ��� ���� �Էµ� �� ������ �ٽ� �ޱ� ���� �ݺ����� ����
	while (1) {
		// �л� ������ �Է¹޴� �Լ�
		for (i = 0; i < 5; i++) {
			printf("%d. �л� ����(0~100) ? ", i + 1);
			scanf("%d", &score[i]);
		}

		// �������� ��� ���� �ԷµǾ������� Ȯ���ϴ� �Լ�
		// ����� �ʾ����� 0�� ����, ��� ���� ������ 1�� ����
		if (normal(score) == 0)  
			break;  // while�� Ż�� 
		else {
			printf("�������� ��� ���� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���.\n");
			continue;  // while�� �ٽ� �ݺ�
		}
	}

	printf("\n");
	printf("%d, %d, %d, %d, %d, => ��� ���� : %.02f\n", score[0], score[1], score[2], score[3], score[4], mean_f(score));
	printf("�ְ� ����: %d, ���� ����: %d\n", max_f(score), min_f(score));
}

//�ּ������� ���ϴ� �Լ�
int min_f(int arr[])  // �迭�� ���޹޾� �� �� �ּҰ��� �����ϴ� �Լ�
{
	int i;  // for���� ����
	int min = arr[0];  // �켱 �迭�� ù��° ���� �ּҰ����� �ʱ�ȭ
		
	for (i = 1; i < 5; i++)  // for�ݺ����� �̿��� min�� �迭�� �� ���� ���ϸ� �� ���� ���� ���������� min�� ���� 
		if (arr[i] < min)
			min = arr[i];
	return min;
}

// �ִ������� ���ϴ� �Լ�
int max_f(int arr[])  // �迭�� ���޹޾� �� �� �ִ밪�� �����ϴ� �Լ�
{
	int i;  // for���� ���� 
	int max = arr[0];  // �켱 �迭�� ù��° ���� �ִ밪���� �ʱ�ȭ

	for (i = 1; i < 5; i++)  // for�ݺ����� �̿��� max�� �迭�� �� ���� ���ϸ� �� ū ���� ���������� max�� ����
		if (arr[i] > max)
			max = arr[i];
	return max;
}

// ����� ���ϴ� �Լ�
double mean_f(int arr[])  // �迭�� ���ڷ� �޾� ����� ����� ����
{
	int i;  // for���� ����
	int total = 0;  // ���� ������ ������ ������ 0���� �ʱ�ȭ
	double mean;  // ����� ������ ������ ����

	for (i = 0; i < 5; i++)  // for �ݺ����� �̿��� �迭�� �� ���� ���� total�� ����
		total = total + arr[i];

	mean = (double) total / 5;

	return mean;
}

int normal(int arr[])  // �迭�� ���޹޾� �������� ��� ���� ������ 1, ������ 0�� ����
{
	int i; // for���� ���� 
	int k = 0; // ���ϰ��� ������ ���� 

	for (i = 0; i < 5; i++) {
		if (arr[i] < 0 || arr[i] > 100)
			k = 1;  // �������� ��� ���� �ϳ��� ������ k = 1 
	}
	return k;  // ��� ���� �������� ����� ������ k = 0
}
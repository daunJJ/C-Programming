#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���������� �Լ�
// �⼮�ϼ��� �μ��� ���� �޾� �⼮������ ����ϰ�, ����� �����ϴ� �Լ�
int get_attend_score(int);

int main(void) 
{
	int score[4] = { 0 };  // �⼮�ϼ�, ����Ʈ����, �߰���� ����, �⸻��� ������ �����ϴ� �迭�� �ʱ�ȭ 
	double report, midterm, final, total;  // ���� �� ������ ����� ����� ������ ���� ���� 
	int attend;  // �⼮ ������ ������ ���� ���� (�⼮ ������ 0,5,10 ������ ������ ����)

	while(1) {
		// �⼮�ϼ��� ǥ���Է����� ���޹޾� score�迭�� 0��° �ε����� ����
		printf("�⼮ �ϼ� ? "); 
	    scanf("%d", &score[0]);

		if (score[0] < 0 || score[0] > 12) {  // �⼮�ϼ��� ������ ��� ��, �ٽ� �Է� �ڸǵ带 ���
			printf("�ٽ� �ѹ� �Է����ּ��� (0~12)\n");
			continue;  // while�� �ݺ�, score[0]���� �ٽ� ���� 
		}
		else
			break;  // �����Է� �� while�� Ż��
	}

	// ����Ʈ ����, �߰���� ����, �⸻��� ������ ���� ǥ���Է����� �޾� score�迭�� ���ʴ�� ���� 
	//  �������� ��� ���� �Էµ� �� �ٽ� �Է� 
	while (1) {

		printf("����Ʈ ���� ? (0~100) ");
		scanf("%d", &score[1]);

		if (score[1] < 0 || score[1] > 100) {  // ������ ������ ��� ��, �ٽ� �Է� �ڸǵ带 ���
			printf("�������� ��� ���� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���.\n");
			continue;  // while�� �ݺ�, score[1]���� �ٽ� ���� 
		}
		else
			break; // �����Է� �� while�� Ż�� 
	}

	// �߰���� ���� 

	while (1) {

		printf("�߰���� ���� ? (0~100) ");
		scanf("%d", &score[2]);

		if (score[2] < 0 || score[2] > 100) {  // ������ ������ ��� ��, �ٽ� �Է� �ڸǵ带 ���
			printf("�������� ��� ���� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���.\n"); 
			continue;  // while�� �ݺ�, score[2]���� �ٽ� ����
		}
		else
			break;  // �����Է� �� while�� Ż��
	}

	// �⸻��� ���� 

	while (1) {

		printf("�⸻��� ���� ? (0~100) ");
		scanf("%d", &score[3]);

		if (score[3] < 0 || score[3] > 100) {   // ������ ������ ��� ��, �ٽ� �Է� �ڸǵ带 ���
			printf("�������� ��� ���� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���.\n"); 
			continue;  // while�� �ݺ�, score[3]���� �ٽ� ����
		}
		else
			break;  // �����Է� �� while�� Ż��
	}
	

	// �� ���� �� ������ ������ ���
	report = 0.2 * score[1];
	midterm = 0.3 * score[2];
	final = 0.4 * score[3];
	attend = get_attend_score(score[0]);  // ��� ������ ������� ��� �Լ��� ���޹��� 
	total = report + midterm + final + attend;

	// ������� �ݿ��� ������ ������ �������� ���
	printf("\n");
	printf("������� �ݿ��� ������ ����\n");
	printf("����Ʈ ����: %.02f\n", report);
	printf("�߰���� ����: %.02f\n", midterm);
	printf("�⸻��� ����: %.02f\n", final);
	printf("��� ����: %d\n", attend);
	printf("\n");
	printf("�������� : %.02f\n", total);
}

// ��� ���� ��� �Լ��� ����
int get_attend_score(int num)
{   
	int attend;

	// ��� Ƚ���� ���� ������ ������ if���� �̿��� ��� ������ ���� 
	if (num < 5)  
		attend =  0;
	else if (5 <= num  && num <= 10)
		attend = 5;
	else                       // ���ʿ� ������ ���� ������ �Լ� ������ ��Ű�� ���� ���� ����
		attend = 10;

	return attend;
}

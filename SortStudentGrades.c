#include <stdio.h>

struct content {
	int ranking;  //���
	int st_num;  //�й�
	char name[20];  //�̸�
	int score_C;  //�������α׷��� ����
	int score_DS; //�����ͱ��� ����
	int score_DB; //�����ͺ��̽� ����
	int score_DA; //�����ͺм� ����
	int tot;  //����
	double mean;  //���
};

void draw_line(char ch, int len);

int main(void)
{          // ����4 ���� �߰�
	struct content student[] = {  // ����� 0���� �ʱ�ȭ. �������� �� ������ ��
		{0, 2016400, "���ٿ�", 100, 97, 100, 100}, {0, 2021100, "�Ѽ���", 90, 98, 90, 90},
		{0, 2021101, "������", 80, 80, 44, 80}, {0, 2021102, "ȫ�淡", 40, 100, 55,70},
		{0, 2021103, "�豤��", 66, 60, 60, 60}, {0, 2021104, "������", 50, 60, 75, 50},
		{0, 2021105, "�ѿ��", 70, 42, 65, 40}, {0, 2021106, "��âȣ", 30, 30, 30, 30},
		{0, 2021107, "�ڹ���", 10, 37, 10, 20}, {0, 2021108, "������", 12, 20, 20, 10},
	    {0, 2021109, "������", 80, 80, 80, 80}, 
	};
	struct content temp;  // ���������� ���� �߰������� ����ü���� 

	int i, j; // for���� ���� 
	int tot_C = 0;  // �������α׷��� ���� ���� 
	int tot_DS = 0;  // �����ͱ��� ���� ����
	int tot_DB = 0;  // �����ͺ��̽� ���� ����
	int tot_DA = 0;  // �����ͺм� ���� ����
	int tot_tot = 0;   // �л��� ������ ����
	double tot_mean = 0;  // �л��� ����� ����
	// �� �������� ����� ������ ����
	double mean_C, mean_DS, mean_DB, mean_DA, mean_tot, mean_mean;

	int size = sizeof(student) / sizeof(student[0]);  // �迭�� ũ�� ����, ������ ����� ���ϰ� �������� ����

	int max;  // ���������� ���� ����� ���� ū �л��� �ε����� ����

	// �� �л����� ������ ����� ���� 
	for (i = 0; i < size; i++) {
		student[i].tot = student[i].score_C + student[i].score_DS + student[i].score_DB + student[i].score_DA;
		student[i].mean = (double)student[i].tot / 4;
	}

	// ����� �̿��� ����� �������� 
	for (i = 0; i < size; i++) {
		max = i;  
		//i��° ����ü�� ��հ� j=(i~size)��° ����ü�� ����� ���Ͽ� ����� �� ū ���� �ε����� max�� ����
		for (j = i + 1; j < size; j++){
			if (student[i].mean <  student[j].mean)
				max = j; 
		}
		// i�� max�� �ƴ� ��, ������ �ʿ�
		if (i != max) {
			temp = student[i];
			student[i] = student[max];  // ����ü �迭�� i��° �ε����� ����� ū ����ü�� ���� 
			student[max] = temp;   // ���� ����� ū ����ü�� �ִ� �ε����� ������ i��° ����ü�� ���� ���� 
		}
	}  // ���������� ����� ū ����ü���� i= 0~size��° �迭�� ���������� �����

	// ���� �� ��� ���� 
	for(i=0; i<size; i++)
		student[i].ranking = i + 1;

	// ���� ������ �л������� ��, �л������ �� ���ϱ�
	for (i = 0; i < size; i++) {
		tot_C += student[i].score_C;
		tot_DS += student[i].score_DS;
		tot_DB += student[i].score_DB;
		tot_DA += student[i].score_DA;
		tot_tot += student[i].tot;
		tot_mean += student[i].mean;
	}
	// ���� ��հ� �л������� ���, �л������ ��� ���ϱ� 
	mean_C = (double) tot_C / size;  // ���� double�� ���ϱ� ���� ������� �� ��ȯ 
	mean_DS = (double) tot_DS / size;
	mean_DB = (double) tot_DB / size;
	mean_DA = (double) tot_DA / size;
	mean_tot = (double) tot_tot / size;
	mean_mean = tot_mean / size;

	// ����ϱ�
	// ���� ��
	draw_line('-', 92);
	printf("\n");
	// ù ��
	printf(" ���    �й�      �̸�   �������α׷��� �����ͱ��� �����ͺ��̽� �����ͺм�  ����     ���\n");
	// ���� ��
	draw_line('-', 92);
	printf("\n");
	// ���� ���
	for (i = 0; i < size; i++)
    printf("%3d %10d %10s %10d %10d %10d %10d %10d %10.2f\n", student[i].ranking, student[i].st_num, student[i].name, student[i].score_C, student[i].score_DS, student[i].score_DB, student[i].score_DA, student[i].tot, student[i].mean);
	// ���� ��
	draw_line('-', 92);
	printf("\n");
	// �������� �� ��� 
	draw_line(' ', 26);  // draw_line �Լ��� �̿��� ũ�⿡ �°� ������ ���
	printf("%10d %10d %10d %10d %10d %10.2f\n", tot_C, tot_DS, tot_DB, tot_DA, tot_tot, tot_mean);
	// �������� ��� ���
	draw_line(' ', 26);
	printf("%10.2f %10.2f %10.2f %10.2f %10.2f %10.2f\n", mean_C, mean_DS, mean_DB, mean_DA, mean_tot, mean_mean);
}

void draw_line(char ch, int len)  //ch: �� �׸� �� ����� ����
{                                 //len: ����� ������ ����
	int i;
	for (i = 0; i < len; i++)  //ch�� len�� ��ŭ ����Ѵ�
		printf("%c", ch);
}

// 
// ����ü �迭�� �л������͸� ���ϴ� ��ŭ �߰��ϱ⸸ �ϸ�, ������ ��� ���� �˾Ƽ� ���Ǿ� ��µǵ��� ���α׷��� ®�� 
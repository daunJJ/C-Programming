#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �� ��ǥ�� �Է¹��� ����ü
struct point {
	int x1, y1, x2, y2;
};

// �� ����ü�� �����͸� ���� �޾� swap�� �Լ� ����
void swap(struct point* p1, struct point* p2);

int main(void)
{
	// ���� �� ��ǥ�� ���� �� ��ǥ�� �� ȭ�鿡 ����ؾ��ϱ� ������, ���� �� ��ǥ�� ���� ����.
	struct point pt[5];  // �Է� ���� ��ǥ�� ����ü �迭 ����
	struct point swap_pt[5];  // ���� �� ��ǥ�� ����ü �迭 ����
	int i,j;  // for���� ���� 
	char arr[100][100] = { 0 };  // ȭ�鿡 ��ǥ�� ����� �迭 


	// ��ǥ�� �Է¹��� ��Ʈ�� ����ϰ�, ��ǥ�� ����ü �迭�� ���������� �Է¹��� 
	printf("5���� ��ǥ�� �Է��Ͻÿ�. �Է� ������ (12, 34), (56, 78)\n");
	for (i = 0; i < 5; i++) {
		printf("%d�� ��ǥ : ", i+1);
		scanf("(%d, %d), (%d, %d)", &pt[i].x1, &pt[i].y1, &pt[i].x2, &pt[i].y2);
		while (getchar() != '\n') {}  // �Է� ���۸� �����
	}

	//swap�Լ��� �̿��� ��ǥ�� ��ȯ, ���ο� ����ü �迭�� ���� 
	for (i = 0; i < 5; i++) 
		swap(&pt[i], &swap_pt[i]);  // ����ü �迭�� �ּҸ� ���� ����

	printf("\n");   // �Է°��� ������ ���ϵ��� �� �� �ٱ�
	for (i = 0; i < 5; i++) {
		printf("%d�� ��ǥ: ���� �� ��ǥ (%d, %d), (%d, %d) -> ���� �� ��ǥ (%d, %d), (%d, %d)\n", i + 1, pt[i].x1, pt[i].y1, pt[i].x2, pt[i].y2, swap_pt[i].x1, swap_pt[i].y1, swap_pt[i].x2, swap_pt[i].y2);
	}

	// ��ǥ�� �� ����ϱ�
	// ��ǥ�� ������ arr���� ���� �� ��ǥ�� *, ���� �� ��ǥ�� #�� ���� 
	for (i = 0; i < 5; i++) {
		arr[pt[i].x1][pt[i].y1] = '*';
		arr[pt[i].x2][pt[i].y2] = '*';
		arr[swap_pt[i].x1][swap_pt[i].y1] = '#';
		arr[swap_pt[i].x1][swap_pt[i].y1] = '#';
	}
	// ���� �����ϴ� ��ǥarr ��� 
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			if (arr[i][j] == '*')
				printf("*");
			else if (arr[i][j] == '#')
				printf("#");
			else
				printf(" ");
		}
	}
	printf("\n");
}

void swap(const struct point* p1, struct point *p2) {   //p1�� �Է� �Ű�����, p2�� ��¸Ű�����
	p2->x1 = p1->y1;
	p2->y1 = p1->x1;
	p2->x2 = p1->y2;
	p2->y2 = p1->x2;
}

// 1�� ��ǥ (36, 98), (12, 45)
// 2�� ��ǥ (46, 45), (34, 61)
// 3�� ��ǥ (11, 32), (89, 23)
// 4�� ��ǥ (98, 44), (22, 66)
// 5�� ��ǥ (13, 77), (51, 90)

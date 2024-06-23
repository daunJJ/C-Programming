#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 두 좌표를 입력받을 구조체
struct point {
	int x1, y1, x2, y2;
};

// 두 구조체의 포인터를 전달 받아 swap할 함수 선언
void swap(struct point* p1, struct point* p2);

int main(void)
{
	// 변경 전 좌표와 변경 후 좌표를 한 화면에 출력해야하기 때문에, 변경 후 좌표를 따로 저장.
	struct point pt[5];  // 입력 받을 좌표의 구조체 배열 선언
	struct point swap_pt[5];  // 변경 후 좌표의 구조체 배열 선언
	int i,j;  // for문용 변수 
	char arr[100][100] = { 0 };  // 화면에 좌표를 출력할 배열 


	// 좌표를 입력받을 멘트를 출력하고, 좌표를 구조체 배열에 순차적으로 입력받음 
	printf("5개의 좌표를 입력하시오. 입력 형식은 (12, 34), (56, 78)\n");
	for (i = 0; i < 5; i++) {
		printf("%d번 좌표 : ", i+1);
		scanf("(%d, %d), (%d, %d)", &pt[i].x1, &pt[i].y1, &pt[i].x2, &pt[i].y2);
		while (getchar() != '\n') {}  // 입력 버퍼를 지운다
	}

	//swap함수를 이용해 좌표를 교환, 새로운 구조체 배열에 저장 
	for (i = 0; i < 5; i++) 
		swap(&pt[i], &swap_pt[i]);  // 구조체 배열의 주소를 각각 전달

	printf("\n");   // 입력값과 구분이 편하도록 한 줄 뛰기
	for (i = 0; i < 5; i++) {
		printf("%d번 좌표: 변경 전 좌표 (%d, %d), (%d, %d) -> 변경 후 좌표 (%d, %d), (%d, %d)\n", i + 1, pt[i].x1, pt[i].y1, pt[i].x2, pt[i].y2, swap_pt[i].x1, swap_pt[i].y1, swap_pt[i].x2, swap_pt[i].y2);
	}

	// 좌표에 점 출력하기
	// 좌표를 저장할 arr에서 변경 전 좌표는 *, 변경 후 좌표는 #로 저장 
	for (i = 0; i < 5; i++) {
		arr[pt[i].x1][pt[i].y1] = '*';
		arr[pt[i].x2][pt[i].y2] = '*';
		arr[swap_pt[i].x1][swap_pt[i].y1] = '#';
		arr[swap_pt[i].x1][swap_pt[i].y1] = '#';
	}
	// 점을 포함하는 좌표arr 출력 
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

void swap(const struct point* p1, struct point *p2) {   //p1은 입력 매개변수, p2는 출력매개변수
	p2->x1 = p1->y1;
	p2->y1 = p1->x1;
	p2->x2 = p1->y2;
	p2->y2 = p1->x2;
}

// 1번 좌표 (36, 98), (12, 45)
// 2번 좌표 (46, 45), (34, 61)
// 3번 좌표 (11, 32), (89, 23)
// 4번 좌표 (98, 44), (22, 66)
// 5번 좌표 (13, 77), (51, 90)

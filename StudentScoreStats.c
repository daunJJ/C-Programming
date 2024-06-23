#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수선언부터 
int normal(int arr[]);  // 배열을 전달받아 범위에서 벗어난 값이 있는지를 확인하는 함수 
int min_f(int arr[]);  // 학생 점수가 저장된 배열을 인자로 받아 그 중 최소값을 리턴하는 함수 
int max_f(int arr[]);  // 학생 점수가 저장된 배열을 인자로 받아 그 중 최대값을 리턴하는 함수
double mean_f(int arr[]);  // 학생 점수가 저장된 배열을 인자로 받아 평균을 리턴하는 함수


int main(void)
{
	int i;  //for문용 변수
	int score[5];  // 학생 점수를 저장할 배열 
	
    // 범위에서 벗어난 값이 입력될 시 점수를 다시 받기 위한 반복문을 만듬
	while (1) {
		// 학생 점수를 입력받는 함수
		for (i = 0; i < 5; i++) {
			printf("%d. 학생 점수(0~100) ? ", i + 1);
			scanf("%d", &score[i]);
		}

		// 범위에서 벗어난 값이 입력되었는지를 확인하는 함수
		// 벗어나지 않았으면 0을 리턴, 벗어난 값이 있으면 1을 리턴
		if (normal(score) == 0)  
			break;  // while문 탈출 
		else {
			printf("범위에서 벗어난 값이 입력되었습니다. 다시 입력하세요.\n");
			continue;  // while문 다시 반복
		}
	}

	printf("\n");
	printf("%d, %d, %d, %d, %d, => 평균 점수 : %.02f\n", score[0], score[1], score[2], score[3], score[4], mean_f(score));
	printf("최고 점수: %d, 최저 점수: %d\n", max_f(score), min_f(score));
}

//최소점수를 구하는 함수
int min_f(int arr[])  // 배열을 전달받아 그 중 최소값을 리턴하는 함수
{
	int i;  // for문용 변수
	int min = arr[0];  // 우선 배열의 첫번째 값을 최소값으로 초기화
		
	for (i = 1; i < 5; i++)  // for반복문을 이용해 min과 배열의 각 값을 비교하며 더 작은 값을 최종적으로 min에 저장 
		if (arr[i] < min)
			min = arr[i];
	return min;
}

// 최대점수를 구하는 함수
int max_f(int arr[])  // 배열을 전달받아 그 중 최대값을 리턴하는 함수
{
	int i;  // for문용 변수 
	int max = arr[0];  // 우선 배열의 첫번째 값을 최대값으로 초기화

	for (i = 1; i < 5; i++)  // for반복문을 이용해 max와 배열의 각 값을 비교하며 더 큰 값을 최종적으로 max에 저장
		if (arr[i] > max)
			max = arr[i];
	return max;
}

// 평균을 구하는 함수
double mean_f(int arr[])  // 배열을 인자로 받아 평균을 계산해 리턴
{
	int i;  // for문용 변수
	int total = 0;  // 최종 점수를 저장할 변수를 0으로 초기화
	double mean;  // 평균을 저장할 변수의 선언

	for (i = 0; i < 5; i++)  // for 반복문을 이용해 배열의 각 값을 더해 total에 저장
		total = total + arr[i];

	mean = (double) total / 5;

	return mean;
}

int normal(int arr[])  // 배열을 전달받아 범위에서 벗어난 값이 있으면 1, 없으면 0을 리턴
{
	int i; // for문용 변수 
	int k = 0; // 리턴값을 저장할 변수 

	for (i = 0; i < 5; i++) {
		if (arr[i] < 0 || arr[i] > 100)
			k = 1;  // 범위에서 벗어난 값이 하나라도 있으면 k = 1 
	}
	return k;  // 모든 값이 범위에서 벗어나지 않으면 k = 0
}
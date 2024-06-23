#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 출결점수계산 함수
// 출석일수를 인수로 전달 받아 출석점수를 계산하고, 결과를 리턴하는 함수
int get_attend_score(int);

int main(void) 
{
	int score[4] = { 0 };  // 출석일수, 레포트점수, 중간고사 점수, 기말고사 점수를 저장하는 배열을 초기화 
	double report, midterm, final, total;  // 점수 별 비율을 계산한 결과를 저장할 변수 선언 
	int attend;  // 출석 점수를 저장할 변수 선언 (출석 점수는 0,5,10 점으로 무조건 정수)

	while(1) {
		// 출석일수를 표준입력으로 전달받아 score배열의 0번째 인덱스에 저장
		printf("출석 일수 ? "); 
	    scanf("%d", &score[0]);

		if (score[0] < 0 || score[0] > 12) {  // 출석일수가 범위를 벗어날 시, 다시 입력 코맨드를 출력
			printf("다시 한번 입력해주세요 (0~12)\n");
			continue;  // while문 반복, score[0]값을 다시 받음 
		}
		else
			break;  // 정상입력 시 while문 탈출
	}

	// 레포트 점수, 중간고사 점수, 기말고사 점수를 각각 표준입력으로 받아 score배열에 차례대로 저장 
	//  범위에서 벗어난 값이 입력될 시 다시 입력 
	while (1) {

		printf("레포트 점수 ? (0~100) ");
		scanf("%d", &score[1]);

		if (score[1] < 0 || score[1] > 100) {  // 점수가 범위를 벗어날 시, 다시 입력 코맨드를 출력
			printf("범위에서 벗어난 값이 입력되었습니다. 다시 입력하세요.\n");
			continue;  // while문 반복, score[1]값을 다시 받음 
		}
		else
			break; // 정상입력 시 while문 탈출 
	}

	// 중간고사 점수 

	while (1) {

		printf("중간고사 점수 ? (0~100) ");
		scanf("%d", &score[2]);

		if (score[2] < 0 || score[2] > 100) {  // 점수가 범위를 벗어날 시, 다시 입력 코맨드를 출력
			printf("범위에서 벗어난 값이 입력되었습니다. 다시 입력하세요.\n"); 
			continue;  // while문 반복, score[2]값을 다시 받음
		}
		else
			break;  // 정상입력 시 while문 탈출
	}

	// 기말고사 점수 

	while (1) {

		printf("기말고사 점수 ? (0~100) ");
		scanf("%d", &score[3]);

		if (score[3] < 0 || score[3] > 100) {   // 점수가 범위를 벗어날 시, 다시 입력 코맨드를 출력
			printf("범위에서 벗어난 값이 입력되었습니다. 다시 입력하세요.\n"); 
			continue;  // while문 반복, score[3]값을 다시 받음
		}
		else
			break;  // 정상입력 시 while문 탈출
	}
	

	// 각 점수 별 비율과 총점을 계산
	report = 0.2 * score[1];
	midterm = 0.3 * score[2];
	final = 0.4 * score[3];
	attend = get_attend_score(score[0]);  // 출결 점수는 출결점수 계산 함수로 전달받음 
	total = report + midterm + final + attend;

	// 백분율이 반영된 각각의 성적과 최종성적 출력
	printf("\n");
	printf("백분율이 반영된 각각의 성적\n");
	printf("레포트 점수: %.02f\n", report);
	printf("중간고사 점수: %.02f\n", midterm);
	printf("기말고사 점수: %.02f\n", final);
	printf("출결 점수: %d\n", attend);
	printf("\n");
	printf("최종성적 : %.02f\n", total);
}

// 출결 점수 계산 함수의 정의
int get_attend_score(int num)
{   
	int attend;

	// 출결 횟수에 따라 범위를 나누고 if문을 이용해 출결 점수를 저장 
	if (num < 5)  
		attend =  0;
	else if (5 <= num  && num <= 10)
		attend = 5;
	else                       // 애초에 범위밖 값을 받으면 함수 실행을 시키기 까지 오지 않음
		attend = 10;

	return attend;
}

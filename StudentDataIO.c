#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 3 

// 구조체 선언 
struct STUDENT {
	int st_no;
	char st_name[20];
	int kor;
	int eng;
	int mat;
	int tot;
	float avg;
};

// 학생 데이터를 입력받아 구조체에 저장해 리턴할 함수 선언
struct STUDENT st_input(void);
// 학생 데이터를 인자로 받아 출력할 함수 선언 
void st_output(struct STUDENT st);

int main(void)
{
	// 구조체 배열을 지역배열로 선언
	struct STUDENT st[MAX];
	int i, count;  // for문용 변수, 학생수를 저장할 변수 

	for (i = 0; i < MAX; i++)
	{
		st[i] = st_input();   //구조체형 변수는 같은 멤버끼리 1:1 대입이 가능하므로 함수를 통해 리턴된 구조체를 구조체 st[i]에 대입한다 
		if (st[i].st_no == 0)  // st_no에 0이 입력되면 반복문을 종료시키고 더 이상 학생데이터를 받지 않음 
			break;
	}
	count = i;  // 입력받은 학생의 수가 count에 저장 

	printf("\n학생데이터 출력\n");
	printf("=================\n");
	for (i = 0; i < count; i++) // 입력받은 학생의 수만큼 반복
		st_output(st[i]);  // 구조체를 인자로 건내, 함수 안에서 프린트한다

	return 0;  // 정상종료
}

struct STUDENT st_input(void)  // 리턴값이 STUDENT 구조체인 함수
{
	struct STUDENT st;

	printf("학생 데이터를 입력하시오(최대 3명)\n");  // 최대 3명의 학생데이터를 입력받을 수 있음을 미리 알림
	// 학번, 이름, 점수를 입력받음
	printf("학번? ");
	scanf("%d", &st.st_no);
	printf("이름? ");
	scanf("%s", &st.st_name);
	printf("국어점수? ");
	scanf("%d", &st.kor);
	printf("영어점수 ? ");
	scanf("%d", &st.eng);
	printf("수학점수 ? ");
	scanf("%d", &st.mat);
	
	// 총점 계산 
	st.tot = st.kor + st.eng + st.mat;
	// 평균 계산 (평균은 소수로 저장)
	st.avg = (float) st.tot / 3;

	return st;
}

void st_output(struct STUDENT st) // STUDENT 구조체를 전달 받아 그 값을 출력함 
{
	printf("학번: %d, 이름: %s, 국어: %d, 영어: %d, 수학: %d, 총점: %d, 평균: %.2f\n", st.st_no, st.st_name, st.kor, st.eng, st.mat, st.tot, st.avg);
}
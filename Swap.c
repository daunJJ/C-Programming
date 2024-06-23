#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// STUDENT 구조체 선언 
struct STUDENT {
	int st_no;
	char st_name[20];
	int kor;
	int eng;
	int mat;
	int tot;
	float avg;
};

// 구조체 포인터로 인자를 받아 구조체 변수를 swap하는 함수 
void swap(struct STUDENT* p1, struct STUDENT* p2);

int main(void)
{
	// STUDENT 구조체 변수 st1과 st2를 초기화 
	struct STUDENT st1 = { 1001, "IT", 77, 43, 77 }, st2 = { 1002, "CS", 15, 49, 97 };
	// swap함수에 포인터로 변수를 전달하기 위해 각 변수의 포인터도 저장 
	struct STUDENT* p1 = &st1, * p2 = &st2;

	// st1의 총점을 계산 
	st1.tot = st1.kor + st1.eng + st1.mat;  
	// st1의 평균을 계산 
	st1.avg = (double) st1.tot / 3;

	// st2의 총점을 계산 
	st2.tot = st2.kor + st2.eng + st2.mat;
	// st2의 평균을 계산 
	st2.avg = (double)st2.tot / 3;

	// swap이 잘 되었는지 결과에서 확인하기 위해 swap전을  출력
	printf("교환 전\n"); 
	printf("str1: %d, %s, %d, %d, %d, %d, %.2f\n", st1.st_no, st1.st_name, st1.kor, st1.eng, st1.mat, st1.tot, st1.avg);
	printf("str2: %d, %s, %d, %d, %d, %d, %.2f\n", st2.st_no, st2.st_name, st2.kor, st2.eng, st2.mat, st2.tot, st2.avg);
	
	// swap 함수에 st1과 st2의 포인터를 인자로 전달, 두 구조체의 학번과 이름, 점수까지 교환 
	swap(p1, p2);
	
	//  swap이 잘 되었는지 결과에서 확인하기 위해 swap후를  출력
	printf("교환 후\n");
	printf("str1: %d, %s, %d, %d, %d, %d, %.2f\n", st1.st_no, st1.st_name, st1.kor, st1.eng, st1.mat, st1.tot, st1.avg);
	printf("str2: %d, %s, %d, %d, %d, %d, %.2f\n", st2.st_no, st2.st_name, st2.kor, st2.eng, st2.mat, st2.tot, st2.avg);

}

// 구조체 포인터로 인자를 받아 구조체 변수를 swap하는 함수 
void swap(struct STUDENT*p1, struct STUDENT*p2)
{
	struct STUDENT temp;  // 중간 저장하는 역할을 할 구조체 선언 

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
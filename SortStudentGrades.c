#include <stdio.h>

struct content {
	int ranking;  //등수
	int st_num;  //학번
	char name[20];  //이름
	int score_C;  //기초프로그래밍 성적
	int score_DS; //데이터구조 성적
	int score_DB; //데이터베이스 성적
	int score_DA; //데이터분석 성적
	int tot;  //총점
	double mean;  //평균
};

void draw_line(char ch, int len);

int main(void)
{          // 과목4 점수 추가
	struct content student[] = {  // 등수는 0으로 초기화. 선택정렬 후 변경할 것
		{0, 2016400, "정다운", 100, 97, 100, 100}, {0, 2021100, "한석봉", 90, 98, 90, 90},
		{0, 2021101, "윤동주", 80, 80, 44, 80}, {0, 2021102, "홍경래", 40, 100, 55,70},
		{0, 2021103, "김광석", 66, 60, 60, 60}, {0, 2021104, "유관순", 50, 60, 75, 50},
		{0, 2021105, "한용운", 70, 42, 65, 40}, {0, 2021106, "안창호", 30, 30, 30, 30},
		{0, 2021107, "박문수", 10, 37, 10, 20}, {0, 2021108, "강유비", 12, 20, 20, 10},
	    {0, 2021109, "이지은", 80, 80, 80, 80}, 
	};
	struct content temp;  // 선택정렬을 위해 중간저장할 구조체변수 

	int i, j; // for문용 변수 
	int tot_C = 0;  // 기초프로그래밍 과목 총점 
	int tot_DS = 0;  // 데이터구조 과목 총점
	int tot_DB = 0;  // 데이터베이스 과목 총점
	int tot_DA = 0;  // 데이터분석 과목 총점
	int tot_tot = 0;   // 학생들 점수의 총점
	double tot_mean = 0;  // 학생들 평균의 총점
	// 각 점수들의 평균을 저장할 변수
	double mean_C, mean_DS, mean_DB, mean_DA, mean_tot, mean_mean;

	int size = sizeof(student) / sizeof(student[0]);  // 배열의 크기 저장, 총점과 평균을 구하고 선택정렬 위함

	int max;  // 선택정렬을 위해 평균이 가장 큰 학생의 인덱스를 저장

	// 각 학생들의 총점과 평균을 구함 
	for (i = 0; i < size; i++) {
		student[i].tot = student[i].score_C + student[i].score_DS + student[i].score_DB + student[i].score_DA;
		student[i].mean = (double)student[i].tot / 4;
	}

	// 평균을 이용해 등수를 선택정렬 
	for (i = 0; i < size; i++) {
		max = i;  
		//i번째 구조체의 평균과 j=(i~size)번째 구조체의 평균을 비교하여 평균이 더 큰 값의 인덱스를 max에 저장
		for (j = i + 1; j < size; j++){
			if (student[i].mean <  student[j].mean)
				max = j; 
		}
		// i가 max가 아닐 시, 정렬이 필요
		if (i != max) {
			temp = student[i];
			student[i] = student[max];  // 구조체 배열의 i번째 인덱스에 평균이 큰 구조체를 대입 
			student[max] = temp;   // 원래 평균이 큰 구조체가 있던 인덱스에 기존의 i번째 구조체의 값을 대입 
		}
	}  // 최종적으로 평균이 큰 구조체부터 i= 0~size번째 배열에 순차적으로 저장됨

	// 정렬 후 등수 저장 
	for(i=0; i<size; i++)
		student[i].ranking = i + 1;

	// 과목별 총점과 학생총점의 합, 학생평균의 합 구하기
	for (i = 0; i < size; i++) {
		tot_C += student[i].score_C;
		tot_DS += student[i].score_DS;
		tot_DB += student[i].score_DB;
		tot_DA += student[i].score_DA;
		tot_tot += student[i].tot;
		tot_mean += student[i].mean;
	}
	// 과목별 평균과 학생총점의 평균, 학생평균의 평균 구하기 
	mean_C = (double) tot_C / size;  // 몫을 double로 구하기 위해 명시적인 형 변환 
	mean_DS = (double) tot_DS / size;
	mean_DB = (double) tot_DB / size;
	mean_DA = (double) tot_DA / size;
	mean_tot = (double) tot_tot / size;
	mean_mean = tot_mean / size;

	// 출력하기
	// 구분 줄
	draw_line('-', 92);
	printf("\n");
	// 첫 줄
	printf(" 등수    학번      이름   기초프로그래밍 데이터구조 데이터베이스 데이터분석  총점     평균\n");
	// 구분 줄
	draw_line('-', 92);
	printf("\n");
	// 점수 출력
	for (i = 0; i < size; i++)
    printf("%3d %10d %10s %10d %10d %10d %10d %10d %10.2f\n", student[i].ranking, student[i].st_num, student[i].name, student[i].score_C, student[i].score_DS, student[i].score_DB, student[i].score_DA, student[i].tot, student[i].mean);
	// 구분 줄
	draw_line('-', 92);
	printf("\n");
	// 점수들의 합 출력 
	draw_line(' ', 26);  // draw_line 함수를 이용해 크기에 맞게 공백을 출력
	printf("%10d %10d %10d %10d %10d %10.2f\n", tot_C, tot_DS, tot_DB, tot_DA, tot_tot, tot_mean);
	// 점수들의 평균 출력
	draw_line(' ', 26);
	printf("%10.2f %10.2f %10.2f %10.2f %10.2f %10.2f\n", mean_C, mean_DS, mean_DB, mean_DA, mean_tot, mean_mean);
}

void draw_line(char ch, int len)  //ch: 선 그릴 때 사용할 문자
{                                 //len: 출력할 문자의 개수
	int i;
	for (i = 0; i < len; i++)  //ch를 len개 만큼 출력한다
		printf("%c", ch);
}

// 
// 구조체 배열에 학생데이터를 원하는 만큼 추가하기만 하면, 총점과 평균 등이 알아서 계산되어 출력되도록 프로그램을 짰음 
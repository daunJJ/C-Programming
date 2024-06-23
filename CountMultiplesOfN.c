#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i;  // for문용 변수
	int num;  // 입력받은 값을 저장할 변수
	int count = 0;  // 배수의 수를 셀 변수

	printf("input number ? ");   // 배수를 출력할 숫자를 표준입력으로 받아 num에 저장
	scanf("%d", &num);

	for (i = 1; i <= 100; i++)   // 1부터 100까지 반복문을 이용해 num의 배수만 출력
	{
		if (i % num == 0) {   
			printf("%d ", i);
			count++;  // count는 배수갯수 만큼 커짐
		}
	}

	printf("\n");
	printf("count: %d\n", count);  // for를 빠져나온뒤 저장된 count(배수의 갯수)를 출력
}

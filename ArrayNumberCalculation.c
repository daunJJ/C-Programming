#include <stdio.h>

int main(void)
{
	int i, j;  // for문용 변수 
	int data[3][7] = { 0 };  // 정수형 배열의 선언
	int k = 1;  // 6과 곱셈 역할을 할 변수 6*1 부터 시작하기에 1로 초기화 

	for (i = 0; i < 3; i++) {  //행의 인덱스를 순차적으로 바꾸는 반복문 
		for (j = 0; j < 5; j++) {  // 열의 인덱스를 순차적으로 바꾸는 반복문 
			data[i][j] = 6 * k; // 0~4열까지 6의 배수를 저장 
			data[i][5] += data[i][j];  // i번째 행 5열에는 반복문을 돌며, i번째 행의 0~4열까지의 값을 모두 더함.
			printf("%d ", data[i][j]); // 0~4열을 바로 출력
			k++;	// 각 열의 값을 6의 순차적인 배수로 만들어줄 k의 값을 1씩 증가시킴 
		}
		data[i][6] = data[i][5] / 5;  // i번째 행 6열에는 0~4열 값의 평균을 저장
		// 각 행의 5열 출력
		printf("-> %d 행의 합 : %d, ", i, data[i][5]);
		// 각 행의 6열 출력
		printf("평균 : %d", data[i][6]);
		printf("\n");  // 한 행이 끝나면 줄바꿈
	}
	// 행을 바꿔서 위 과정 다시 반복
}

// int data[3][7] 배열을 0으로 초기화한 이유는 반복문에서 data[i][5] += data[i][j]; 이 과정을 수행할 때 data[i][5]의 초기값이 지정되어 있어야함 

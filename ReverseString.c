#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // strlen함수 사용 

// str은 입력 매개변수, str 문자열을 역순으로 rts 문자열에 저장하는 함수 
void get_reverse(const char* str, int size, char* rts);

int main(void)
{
	// 문자배열의 크기가 충분히 크게, 널문자로 초기화 
	char str1[128] = "";  //입력 변수로 쓰일 것
	char str2[128] = "";  
	char rts1[128] = "";  //출력 변수로 쓰일 것
	char rts2[128] = "";  
	int size1, size2;  // 함수의 매개변수로 배열을 전달할 때, 별도로 배열의 크기도 전달 

	// 두개의 문자열 입력받기
	printf("입력 문자열1: "); 
	gets_s(str1, sizeof(str1));  // 공백문자를 읽어올 수 있는 get_s 함수를 사용, 문자열과 크기를 받아온다 
	printf("입력 문자열2: ");
	gets_s(str2, sizeof(str2));

	size1 = strlen(str1);  // 널문자 제외 문자열의 길이
	size2 = strlen(str2);

	// 함수를 이용해 str문자배열을 역순으로 만들어 rts에 저장
	get_reverse(str1, size1, rts1);
	get_reverse(str2, size2, rts2);

	printf("역순으로 변환 후\n");   // 변환 후 문자열 출력
	printf("출력 문자열1: %s\n", rts1);
	printf("출력 문자열2: %s\n", rts2);
}

// str은 입력 매개변수, str 문자열을 역순으로 rts 문자열에 저장하는 함수 
void get_reverse(const char* str, int size, char* rts)
{
	int i;  // for문용 변수 

	for (i = 0; i < size; i++)   // str문자열의 크기만큼 함수 반복 
		rts[i] = str[size -1 - i];  // 인덱스를 이용해 str 문자열의 뒤부분부터 차례대로 rts 문자열 앞부분에 저장  
}

//입력 문자열1 : 2021 Sookmyung Womens Univ.Fundamental C Programming, Welcome!
// 입력 문자열2 : Let's go together~
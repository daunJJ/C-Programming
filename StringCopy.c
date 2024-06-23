#include <stdio.h>
#include <string.h>

// 문자열 복사 함수 선언
// 문자열 포인터를 전달받아 str2문자열에 str1문자열을 복사, str1은 입력매개변수 
void my_Strcpy(char* str2, const char* str1);

int main(void)
{
	char str2[20] = "", str1[20]="kingdom";  //문자열 배열 선언 str2는 str1을 복사하여 저장할 변수로, 널 문자로 초기화

	// 변수의 초기값 출력
	printf("before str1: %s, str2: %s\n", str1, str2);

	// 함수를 이용해 str2에 str1을 복사 
	my_Strcpy(str2, str1);
	
	// 변경된 변수의 값을 출력
	printf("after str1: %s, str2: %s\n", str1, str2);

}


// 문자열 포인터를 전달받아 str2문자열에 str1문자열을 복사  
void my_Strcpy(char* str2, const char* str1)  // str1은 입력 매개변수 
{
	int i;  // for문용 변수 

	for (i = 0; str1[i] != 0; i++)   // str1의 문자열이 문자열의 끝인 널문자를 만날 때까지 str2에 str1을 복사 
		str2[i] = str1[i];
}
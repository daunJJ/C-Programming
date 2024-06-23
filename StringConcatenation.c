#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char sentence[30] = "";  // 최종 출력할 문자열을 널 문자로 초기화
	char str1[20] = "King", str2[20] = "Dom", str3[30] = "Sookmyung";

	printf("before str1: %s, str2: %s, str3: %s\n", str1, str2, str3);

	strcat(str1, str2);      // str1에 str2를 추가 -> str1 = "KingDom"
	strcat(sentence, str3);  // sentence 문자열에 str3추가 -> sentence = "Sookmyung"
	strcat(sentence, " ");   // sentence에 공백문자 추가 -> sentence = "Sookmyung "
	strcat(sentence, str1);  // sentence에 str1 추가 -> sentence = "Sookmyung KingDom"
	printf("after: %s\n", sentence);  //최종적으로 하나의 문자열을 출력 


	// sentence 문자열을 따로 지정하지 않고 출력하기
	// strcat(str1, str2);  // str1에 str2를 추가 -> str1 = "KingDom"
	// printf("after: %s %s\n", str3, str1);  // 중간에 공백을 두고 str3와 str1을 출력 
}
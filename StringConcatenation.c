#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char sentence[30] = "";  // ���� ����� ���ڿ��� �� ���ڷ� �ʱ�ȭ
	char str1[20] = "King", str2[20] = "Dom", str3[30] = "Sookmyung";

	printf("before str1: %s, str2: %s, str3: %s\n", str1, str2, str3);

	strcat(str1, str2);      // str1�� str2�� �߰� -> str1 = "KingDom"
	strcat(sentence, str3);  // sentence ���ڿ��� str3�߰� -> sentence = "Sookmyung"
	strcat(sentence, " ");   // sentence�� ���鹮�� �߰� -> sentence = "Sookmyung "
	strcat(sentence, str1);  // sentence�� str1 �߰� -> sentence = "Sookmyung KingDom"
	printf("after: %s\n", sentence);  //���������� �ϳ��� ���ڿ��� ��� 


	// sentence ���ڿ��� ���� �������� �ʰ� ����ϱ�
	// strcat(str1, str2);  // str1�� str2�� �߰� -> str1 = "KingDom"
	// printf("after: %s %s\n", str3, str1);  // �߰��� ������ �ΰ� str3�� str1�� ��� 
}
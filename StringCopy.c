#include <stdio.h>
#include <string.h>

// ���ڿ� ���� �Լ� ����
// ���ڿ� �����͸� ���޹޾� str2���ڿ��� str1���ڿ��� ����, str1�� �Է¸Ű����� 
void my_Strcpy(char* str2, const char* str1);

int main(void)
{
	char str2[20] = "", str1[20]="kingdom";  //���ڿ� �迭 ���� str2�� str1�� �����Ͽ� ������ ������, �� ���ڷ� �ʱ�ȭ

	// ������ �ʱⰪ ���
	printf("before str1: %s, str2: %s\n", str1, str2);

	// �Լ��� �̿��� str2�� str1�� ���� 
	my_Strcpy(str2, str1);
	
	// ����� ������ ���� ���
	printf("after str1: %s, str2: %s\n", str1, str2);

}


// ���ڿ� �����͸� ���޹޾� str2���ڿ��� str1���ڿ��� ����  
void my_Strcpy(char* str2, const char* str1)  // str1�� �Է� �Ű����� 
{
	int i;  // for���� ���� 

	for (i = 0; str1[i] != 0; i++)   // str1�� ���ڿ��� ���ڿ��� ���� �ι��ڸ� ���� ������ str2�� str1�� ���� 
		str2[i] = str1[i];
}
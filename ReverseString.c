#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // strlen�Լ� ��� 

// str�� �Է� �Ű�����, str ���ڿ��� �������� rts ���ڿ��� �����ϴ� �Լ� 
void get_reverse(const char* str, int size, char* rts);

int main(void)
{
	// ���ڹ迭�� ũ�Ⱑ ����� ũ��, �ι��ڷ� �ʱ�ȭ 
	char str1[128] = "";  //�Է� ������ ���� ��
	char str2[128] = "";  
	char rts1[128] = "";  //��� ������ ���� ��
	char rts2[128] = "";  
	int size1, size2;  // �Լ��� �Ű������� �迭�� ������ ��, ������ �迭�� ũ�⵵ ���� 

	// �ΰ��� ���ڿ� �Է¹ޱ�
	printf("�Է� ���ڿ�1: "); 
	gets_s(str1, sizeof(str1));  // ���鹮�ڸ� �о�� �� �ִ� get_s �Լ��� ���, ���ڿ��� ũ�⸦ �޾ƿ´� 
	printf("�Է� ���ڿ�2: ");
	gets_s(str2, sizeof(str2));

	size1 = strlen(str1);  // �ι��� ���� ���ڿ��� ����
	size2 = strlen(str2);

	// �Լ��� �̿��� str���ڹ迭�� �������� ����� rts�� ����
	get_reverse(str1, size1, rts1);
	get_reverse(str2, size2, rts2);

	printf("�������� ��ȯ ��\n");   // ��ȯ �� ���ڿ� ���
	printf("��� ���ڿ�1: %s\n", rts1);
	printf("��� ���ڿ�2: %s\n", rts2);
}

// str�� �Է� �Ű�����, str ���ڿ��� �������� rts ���ڿ��� �����ϴ� �Լ� 
void get_reverse(const char* str, int size, char* rts)
{
	int i;  // for���� ���� 

	for (i = 0; i < size; i++)   // str���ڿ��� ũ�⸸ŭ �Լ� �ݺ� 
		rts[i] = str[size -1 - i];  // �ε����� �̿��� str ���ڿ��� �ںκк��� ���ʴ�� rts ���ڿ� �պκп� ����  
}

//�Է� ���ڿ�1 : 2021 Sookmyung Womens Univ.Fundamental C Programming, Welcome!
// �Է� ���ڿ�2 : Let's go together~
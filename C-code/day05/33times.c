#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char* password = "13093944163", think[11] = { 0 };
	int i=0;
	for (; i < 3; i++)
	{
		printf("�������룺");
		scanf("%s", think);
		if (!think)
			return -1;
		if (strcmp(think,password) == 0)
		{
			printf("��¼�ɹ���");
			break;
		}
		else
		{
			printf("�������.");
		}
	}
	if (strcmp(think, password))
	{
		printf("�˳�����\n");
	}
	system("pause");
	return 0;
}
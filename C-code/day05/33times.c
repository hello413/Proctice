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
		printf("ÊäÈëÃÜÂë£º");
		scanf("%s", think);
		if (!think)
			return -1;
		if (strcmp(think,password) == 0)
		{
			printf("µÇÂ¼³É¹¦£¡");
			break;
		}
		else
		{
			printf("ÃÜÂë´íÎó.");
		}
	}
	if (strcmp(think, password))
	{
		printf("ÍË³ö³ÌÐò\n");
	}
	system("pause");
	return 0;
}
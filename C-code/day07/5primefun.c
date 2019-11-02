#include<stdio.h>

_Bool prime(int num)
{
	if (num%2 == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	printf("请输入一个数：");
	int num;
	scanf_s("%d", &num);
	if (prime(num) == 1)
	{
		printf("%d是素数。",num);
	}
	else
	{
		printf("%d不是素数。",num);
	}
	return 0;
}
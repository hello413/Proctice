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
	printf("������һ������");
	int num;
	scanf_s("%d", &num);
	if (prime(num) == 1)
	{
		printf("%d��������",num);
	}
	else
	{
		printf("%d����������",num);
	}
	return 0;
}
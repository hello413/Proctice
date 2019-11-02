#include<stdio.h>

int DigitSum(int num);
int main()
{
	int num;
	printf("输入想处理的值：");
	scanf_s("%d", &num);
	printf("%d", DigitSum(num));
	return 0;
}
int DigitSum(int num)
{
	if (num < 10)
	{
		return num;
	}
	else
	{
		return num % 10 + DigitSum(num / 10);
	}
}
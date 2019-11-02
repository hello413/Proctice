#include<stdio.h>

int Factorial1(int n);
int Factorial2(int n);
int main()
{
	int n;
	printf("输入n值：");
	scanf_s("%d", &n);
	printf("n!的值是：%d\n", Factorial1(n));
	printf("n!的值是：%d\n", Factorial2(n));
	return 0;
}
int Factorial1(int n)
{
	int val = 1;
	while(n-1 != 0)
	{
		val *= n;
		n--;
	}
	return val;
}
int Factorial2(int n)
{
	if (n - 1 != 0)
	{
		return n * Factorial2(n - 1);
	}
	else
	{
		return n;
	}
}
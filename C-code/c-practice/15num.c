#include <stdio.h>
/*��������������m��n���������Լ������С������*/
int Maximum(int num1, int num2)
{
	if (num2 < num1) 
	{
		num1 = num1 ^ num2;
		num2 = num1 ^ num2;
		num1 = num1 ^ num2;
	}
	for (int i = num1; i > 0; i--)
	{
		if (num1 % i == 0 && num2 % i == 0)
		{
			return i;
			break;
		}
	}
}
int minimum(int num1, int num2)
{
	if (num2 < num1)
	{
		num1 = num1 ^ num2;
		num2 = num1 ^ num2;
		num1 = num1 ^ num2;
	}
	for (int i = num2; i <= num1*num2; i++)
	{
		if (i % num1 == 0 && i % num2 == 0)
		{
			return i;
			break;
		}
	}
}
int main() 
{
	int m, n;
	printf("enter valus of m and n :");
	scanf_s("%d%d", &m, &n);
	printf("Maximum common divisor : %d \n minimum common multiple : %d", Maximum(m, n), minimum(m, n));
	return 0;
}
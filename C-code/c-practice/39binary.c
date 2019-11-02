#include<stdio.h>
//八进制与二进制相互转换
void toeight(int m)
{
	int arr[20] = { 0 }, i, n = 1;
	for (i = 0;i < 20; i++)
	{
		if (n==0)
		{
			break;
		}
		n = m % 1000;
		m /= 1000;
		arr[i] = n / 100 * 4 + n % 100 / 10 * 2 + n % 10;
	}
	i -= 2;
	while (i>=0)
	{
		printf("%d", arr[i--]);
	}
	printf("\n");
}
void totwo(int m)
{
	int n, arr[20], i=0;
	while (m)
	{
		n = m % 10;
		m = m / 10;
		if (n%2 == 0)
		{
			arr[i++] = 0;
		}
		else
		{
			arr[i++] = 1;
		}
		if (n == 1 || n == 0 || n == 4 || n == 5) 
		{
			arr[i++] = 0;
		}
		else
		{
			arr[i++] = 1;
		}
		if (n<4)
		{
			arr[i++] = 0;
		}
		else
		{
			arr[i++] = 1;
		}
	}
	i--;
	if (arr[i] == 0)
	{
		i--;
		if (arr[i] == 0)
		{
			i--;
		}
	}
	for  (i; i >=0; i--)
	{
		printf("%d", arr[i]);
	}
}
int main()
{
	toeight(111111);
	totwo(21);
	return 0;
}
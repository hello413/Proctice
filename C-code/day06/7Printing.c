#include <stdio.h>

int num(int n);
int main()
{
	num(1234);
	return 0;
}
int num(int n)
{
	if (n >= 10)
	{
		num(n / 10);
		printf("%d\t", n%10);
	}
	else
	{
		printf("%d\t", n);
	}
}

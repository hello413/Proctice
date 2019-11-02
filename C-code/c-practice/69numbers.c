#include<stdio.h>
/*二进制数中1的个数*/
#pragma warning(disable:4996)
int main()
{
	printf("enter a two-binary number:");
	int num,m=0;
	scanf("%d", &num);
	while (num > 0)
	{
		if (num % 10 == 1)
		{
			m++;
		}
		if (num % 10 > 1)
		{
			printf("enter error!\n");
		}
		num /= 10;
	}
	printf("numbers of one : %d", m);
	return 0;
}
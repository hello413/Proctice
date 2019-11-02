#include<stdio.h>
/*一个不多于5位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字*/
int main()
{
	int num, a = 0;
	printf("enter:");
	scanf_s("%d", &num);
	while (num)
	{
		printf("%d", num % 10);
		num /= 10;
		a++;
	}
	printf("\n%d位数\n", a);
	return 0;
}
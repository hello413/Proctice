#include<stdio.h>
/*��һ���������ֽ������������磺����90, ��ӡ��90 = 2 * 3 * 3 * 5*/
int main()
{
	printf("please enter a positive valus :");
	int num,i;
	scanf_s("%d", &num);
	printf("%d = ", num);
	for ( i = 2; i < num+1; i++)
	{
		while (num % i == 0 && num != i)
		{
			num = num / i;
			printf("%d * ", i);
		}
		if (num == i)
		{
			printf("%d", i);
		}
	}
	return 0;
}
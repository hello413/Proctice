#include<stdio.h>
//有1,2,3,4四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少

int main()
{
	int num = 0;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 1; k <= 4; k++)
			{
				if (i != j && i != k && j != k)
				{
					printf("%d%d%d\t", i, j, k);
					num++;
				}
			}
		}
	}
	printf("\nthese have %d numbers!\n", num);
	return 0;
}
#include<stdio.h>

int main()
{
	int i,num=0;
	for (i = 1; i <= 100; i++)
	{
		if (i/10==9)
		{
			num++;
		}
		if (i%10==0)
		{
			num++;
		}
	}
	printf("%d", num);
	return 0;
}

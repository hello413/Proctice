#include<stdio.h>

void table(int n);
int main()
{
	int n;
	printf(" ‰»În÷µ£∫");
	scanf_s("%d", &n);
	table(n);
	return 0;
}
void table(int n)
{
	int i,j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d\t", j, i, i * j);
		}
		printf("\n");
	}
}
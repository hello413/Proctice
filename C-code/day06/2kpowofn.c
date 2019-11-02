#include<stdio.h>

int pow(int n,int k);
int main()
{
	int n, k;
	printf("输入n值和k值（n^k）:");
	scanf_s("%d%d", &n, &k);
	printf("%d\n", pow(n, k));
	return 0;
}
int pow(int n, int k)
{
	if (k != 1) 
	{
		return n*pow(n, k - 1);
	}
	else
	{
		return n;
	}
}
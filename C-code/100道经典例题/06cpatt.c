#include<stdio.h>
/*用* 号输出字母C的图案*/
void out(int n, int m, int en)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf(" ");
	}
	for (j = 0; j < m; j++)
	{
		printf("* ");
	}
	if (en == 1)
	{
		printf("\n");
	} 
}
int main()
{
	out(5, 3, 1);
	out(4, 1, 0);
	out(4, 1, 1);
	out(3, 1, 1);
	out(3, 1, 1);
	out(4, 1, 0);
	out(4, 1, 1);
	out(5, 3, 1);
	return 0;
}
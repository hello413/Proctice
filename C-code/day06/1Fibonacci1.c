#include<stdio.h>

int main()
{
	int *a;
	int i,n;
	printf("请输入n值：");
	scanf_s("%d", &n);
	a = (int*)malloc(n * (sizeof(int)));//申请动态数组内存
	a[0] = 1; 
	a[1] = 1;
	if (n == 1 || n == 2)
	{
		printf("第%d个斐波那契数是1",n);
	}
	for (i = 2; i < n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
		if (i == n-1)
		{
			printf("第%d个斐波那契数是%d\n", n, a[i]);
		}
	}
	return 0;
}
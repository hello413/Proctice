#include<stdio.h>
#include<stdlib.h>
/*输入数组，最大的与第一个元素交换，最小的与最后一个元素交换，输出数组*/
int main()
{
	int m;
	printf("enter the nums of array:");
	scanf_s("%d", &m);
	getchar();
	int* p;
	p = (int*)malloc(m * (sizeof(int)));//动态申请内存
	printf("enter the valus of array:");
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d", &p[i]);
	}
	int max = p[0], min = p[0], pmax = 0, pmin = 0;
	for (int i = 0; i < m; i++)
	{
		if (max < p[i]) 
		{
			max = p[i];
			pmax = i;
		}
	}
	p[0] = p[0] ^ p[pmax];
	p[pmax] = p[0] ^ p[pmax];
	p[0] = p[0] ^ p[pmax];
	for (int i = 0; i < m; i++)
	{
		if (min > p[i])
		{
			min = p[i];
			pmin = i;
		}
	}
	p[pmin] = p[pmin] ^ p[m - 1];
	p[m-1] = p[pmin] ^ p[m - 1];
	p[pmin] = p[pmin] ^ p[m - 1];
	for (int i = 0; i < m; i++)
	{
		printf("%3d", p[i]);
	}
	return 0;
}
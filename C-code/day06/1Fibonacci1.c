#include<stdio.h>

int main()
{
	int *a;
	int i,n;
	printf("������nֵ��");
	scanf_s("%d", &n);
	a = (int*)malloc(n * (sizeof(int)));//���붯̬�����ڴ�
	a[0] = 1; 
	a[1] = 1;
	if (n == 1 || n == 2)
	{
		printf("��%d��쳲���������1",n);
	}
	for (i = 2; i < n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
		if (i == n-1)
		{
			printf("��%d��쳲���������%d\n", n, a[i]);
		}
	}
	return 0;
}
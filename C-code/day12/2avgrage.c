#include<stdio.h>


int avg(int m, int n)
{
	return (m > n) ? (n + (m - n) / 2) : (m + (n - m) / 2);//�ŵ㣺��������Ŀ���
}


int main()
{
	printf("%d",avg(100, 20));
	return 0;
}
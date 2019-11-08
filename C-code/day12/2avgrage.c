#include<stdio.h>


int avg(int m, int n)
{
	return (m > n) ? (n + (m - n) / 2) : (m + (n - m) / 2);//优点：减少溢出的可能
}


int main()
{
	printf("%d",avg(100, 20));
	return 0;
}
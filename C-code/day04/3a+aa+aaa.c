#include<stdio.h>

int main()
{
	printf("please enter valus of a : ");
	int a;
	scanf_s("%d",&a);
	/*
	printf("%d\n", a*(1 + 11 + 111 + 1111 + 11111));
	*/
	int i, Sn=a,n=a;
	for ( i = 0; i < 4; i++)
	{
		a = a * 10 + n;
		Sn += a;
	}
	printf("%d\n", Sn);
	return 0;
}
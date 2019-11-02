#include<stdio.h>

void exchange(int a,int b);
int main()
{
	int a = 1, b = 2;
	exchange(a, b);
	return 0;
}
void exchange(int a, int b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a=%d,b=%d\n", a, b);
}
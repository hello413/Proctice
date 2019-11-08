#include<stdio.h>
/*输入3个数a, b, c，按大小顺序输出 利用指针方法*/
int main()
{
	int x, y, z;
	printf("enter valus of a,b and c:");
	scanf_s("%d%d%d", &x, &y, &z);
	int* a = &x, * b = &y, * c = &z;
	if (*a > * b)
	{
		*a = *a ^ *b;
		*b = *a ^ *b;
		*a = *a ^ *b;
	}
	if (*a > * c) 
	{
		*a = *a ^ *c;
		*c = *a ^ *c;
		*a = *a ^ *c;
	}
	if (*b > * c) 
	{
		*b = *b ^ *c;
		*c = *b ^ *c;
		*b = *b ^ *c;
	}
	printf("a=%d,b=%d,c=%d", *a, *b, *c);
	return 0;
}
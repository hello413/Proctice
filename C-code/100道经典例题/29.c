#include <stdio.h>
#pragma warning(disable:4996)
void prt(unsigned short x, char* msg)
{
	unsigned short i;
	printf("%s的二进制值:\n", msg);
	for (i = 15;; i--)
	{
		printf("%d", (x & (1 << i)) != 0);
		if (i == 0)break;
	}
	printf("\n");
}
int main()
{
	unsigned short a, b, c, n;
	scanf("%hd", &a);
	prt(a, "a");
	b = a & (15 << 3);
	prt(b, "提取右端开始的4~7位");
	printf("右移几位：");
	scanf("%hd", &n);
	c = (1 << n) - 1; //n位全1
	b = ((a & c) << (16 - n)) + ((a & ~c) >> n);
	prt(b, "循环右移后");
	return 0;
}
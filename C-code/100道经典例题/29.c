#include <stdio.h>
#pragma warning(disable:4996)
void prt(unsigned short x, char* msg)
{
	unsigned short i;
	printf("%s�Ķ�����ֵ:\n", msg);
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
	prt(b, "��ȡ�Ҷ˿�ʼ��4~7λ");
	printf("���Ƽ�λ��");
	scanf("%hd", &n);
	c = (1 << n) - 1; //nλȫ1
	b = ((a & c) << (16 - n)) + ((a & ~c) >> n);
	prt(b, "ѭ�����ƺ�");
	return 0;
}
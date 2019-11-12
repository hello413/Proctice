#include<stdio.h>
/*大小端的判断*/
int main()
{
	char c;
	int a = 490;
	int* p = &a;
	c = *p;
	printf("%d   %d\n", c, a);
	if (c == a)					//实质上就是判断是否溢出，没溢出就是小端，反之大端。
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}

	return 0;


}
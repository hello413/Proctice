#include "stdio.h"
int a, b, c;
void add()
{
	int a;
	a = 3;
	c = a + b;
}
void main()
{
	a = b = 4;
	add();
	printf("The value of c is equal to %d\n", c);
}

#include<stdio.h>

int main()
{
	char a[] = "hello";
	printf("%d", sizeof(a) / sizeof(a[0])-1);
	return 0;
}

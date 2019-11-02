#include<stdio.h>

void strlen2(char* string);
int main()
{
	char a[] = "hello";
	strlen2(a);
	return 0;
}
int m = 0;
void strlen2(char *string)
{
	if ('\0' != *(++string))
	{
		m++;
		strlen2(string);
	}
	else
	{
		m++;
		printf("×Ö·û³¤¶ÈÊÇ%d\n", m);
	}
}
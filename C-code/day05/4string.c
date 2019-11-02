#include<stdio.h>

int main()
{
	int ch;
	while ((ch = getchar()) != EOF) 
	{
		if (ch >= 'a' &&ch <= 'z')
		{
			printf("%c\n", ch-32);
		}
		if (ch >= 'A' && ch <= 'Z')
		{
			printf("%c\n", ch+32);
		}
		if (ch >= '0' && ch <= '9')
		{
			continue;
		}
	}
	return 0;
}
#include <stdio.h>

int main() 
{
	int i=0,ch;
	while ((ch=getchar())!= EOF) 
	{
		if (ch=='{')
		{
			i++;
		}
		if (ch=='}')
		{
			i--;
		}
		if (i<0)
		{
			break;
		}
	}
	if (i==0)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	return 0;
}

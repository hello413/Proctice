#include<stdio.h>

void reverse_string(char* string)
{
	if ('\0' != *(++string))
	{
		reverse_string(string);
	}
	printf("%c", *(string - 1));
}

int main()
{
	char* a = "abcde";
	reverse_string(a);
	printf("\n");
	return 0;
}

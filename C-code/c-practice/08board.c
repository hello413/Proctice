#include<stdio.h>
#include <windows.h>
/*Ҫ�����������������*/
int main()
{
	int i, j;
	SetConsoleOutputCP(437);
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++) 
		{
			if ((i + j) % 2 == 0)
			{
				printf("%c", 219);
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	return 0;
}
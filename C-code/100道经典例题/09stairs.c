#include<stdio.h>
#include <windows.h>
/*打印楼梯，同时在楼梯上方打印两个笑脸*/
int main()
{
	int i, j;
	SetConsoleOutputCP(437);
	printf("\n^v^^v^\n");/*输出两个笑脸*/
	for (i = 1; i < 11; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%c", 219);
		}
		printf("\n");
	}
	return 0;
}
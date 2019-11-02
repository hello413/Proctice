#include<stdio.h>
#include<stdlib.h>
/*可变数组*/
#pragma warning(disable:4996)
int main()
{
	int num = 1;
	while (num)
	{
		printf("\nenter number (exit:0) :");
		scanf("%d", &num);
		int* arr = (int*)malloc(num * sizeof(int));
		for (int i = 0; i < num; i++)
		{
			arr[i] = i;
			printf("%d\t", arr[i]);
		}
	}
	return 0;
}
#include <stdio.h> 
#pragma warning(disable:4996)
int main() 
{
	int m = 0, r = 0, k = 0;
	printf("输入m,r,k值：》");
	scanf("%d%d%d", &m, &r, &k);
	int** arr1 = NULL, ** arr2 = NULL;
	arr1 = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		*(arr1+i) = (int*)malloc(r * sizeof(int));
	}
	arr2 = (int**)malloc(r * sizeof(int*));
	for (int i = 0; i < r; i++)
	{
		*(arr2+i) = (int*)malloc(k * sizeof(int));
	}
	printf("输入第一个矩阵：》\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < r; j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}
	printf("输入第二个矩阵：》\n");
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &arr2[i][j]);
		}
	}
	int** arr3 = NULL;
	arr3 = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		*(arr3+i) = (int*)malloc(k * sizeof(int));
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			arr3[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int b = 0; b < k; b++)
		{
			for (int j = 0; j < r; j++)
			{
				arr3[i][b] += arr1[i][j] * arr2[j][b];
			}
		}
	}
	printf("输出：》\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}
	free(arr1,arr2,arr3);
	return 0;
}
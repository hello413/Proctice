#include<stdio.h>

/*杨氏矩阵 
>    有一个二维数组. 
>    数组的每行从左到右是递增的，每列从上到下是递增的. 
>    在这样的数组中查找一个数字是否存在。 
>    时间复杂度小于O(N)
>
>    数组： 
>    1 2 3 
>    2 3 4 
>    3 4 5 
>
>    1 3 4 
>    2 4 5 
>    4 5 6 
>
>    1 2 3 
>    4 5 6 
>    7 8 9 */
int t2(int arr[][3], int row, int col, int value)
{
	int ret = 0;

	// i,j为右上角坐标
	int i = 0;
	int j = col - 1;
	while (i < row && j >= 0)
	{
		if (value == arr[i][j])
		{
			ret = 1;
			break;
		}
		else if (arr[i][j] > value)
		{
			--j;
		}
		else
		{
			++i;
		}
	}

	return ret;
}

int main()
{
	int arr[][3] ={
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	if (t2(arr, 3, 3, 1))
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}
	return 0;
}
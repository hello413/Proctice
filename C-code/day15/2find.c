#include<stdio.h>

/*���Ͼ��� 
>    ��һ����ά����. 
>    �����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����. 
>    �������������в���һ�������Ƿ���ڡ� 
>    ʱ�临�Ӷ�С��O(N)
>
>    ���飺 
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

	// i,jΪ���Ͻ�����
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
		printf("����\n");
	}
	else
	{
		printf("������\n");
	}
	return 0;
}
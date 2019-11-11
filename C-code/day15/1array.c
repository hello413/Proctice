#include<stdio.h>
/*> 1. 调整数组使奇数全部都位于偶数前面。 
>
>    题目： 
>
>    输入一个整数数组，实现一个函数， 
>    来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分， 
>    所有偶数位于数组的后半部分。*/

void array(int arr[],int num)
{
	int left = 0, right = num - 1;
	while (left < right)
	{
		if (arr[left] % 2 == 0)
		{
			if (arr[right] % 2 != 0)         //arr[i] && 1
			{
				int tmp = arr[left];
				arr[left] = arr[right];
				arr[right] = tmp;
			}
			else                     //!(arr[i] && 1)
			{
				right--;
			}
		}
		else
		{
			left++;
		}
	}
	for (int i = 0; i < num; i++)
	{
		printf("%3d", arr[i]);
	}
}


int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int num = sizeof(arr) / sizeof(arr[0]);
	array(arr, num);
	return 0;
}
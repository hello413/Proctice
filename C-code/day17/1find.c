#include<stdio.h>

/*
> 1. 一个数组中只有两个数字是出现一次， 
>    其他所有数字都出现了两次。 
>    找出这两个数字，编程实现。 */

void find(int arr[10],int num)
{
	//先将其按从小到大排序
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	//提取
	for (int i = 0; i < num; i++)
	{
		if (i == 0)
		{
			if (arr[i] != arr[i + 1]) 
			{
				printf("%d", arr[i]);
			}
		}
		else if(i == num)
		{
			if (arr[i - 1] != arr[i])
			{
				printf("%d", arr[i]);
			}
		}
		else
		{
			if (arr[i] != arr[i + 1] && arr[i - 1] != arr[i])
			{
				printf("%d\t", arr[i]);
			}
		}
	}
}

int main()
{
	int arr[] = { 9,0,1,2,3,2,5,6,6,1,0 };
	int num = sizeof(arr) / sizeof(arr[0]);
	find(arr,num);
	return 0;
}
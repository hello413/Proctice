#include<stdio.h>

/*
> 1. һ��������ֻ�����������ǳ���һ�Σ� 
>    �����������ֶ����������Ρ� 
>    �ҳ����������֣����ʵ�֡� */

void find(int arr[10],int num)
{
	//�Ƚ��䰴��С��������
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
	//��ȡ
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
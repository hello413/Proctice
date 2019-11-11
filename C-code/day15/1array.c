#include<stdio.h>
/*> 1. ��������ʹ����ȫ����λ��ż��ǰ�档 
>
>    ��Ŀ�� 
>
>    ����һ���������飬ʵ��һ�������� 
>    �����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣� 
>    ����ż��λ������ĺ�벿�֡�*/

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
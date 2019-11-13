#include<stdio.h>


void sort(int* arr, int num)
{
	for (int i = 0; i < num-1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (arr[i] == arr[j])
			{
				for (int k = j; k < num-1; k++)
				{
					arr[j] = arr[j + 1];
				}
				num--;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,5,2,3 };
	int num = sizeof(arr) / sizeof(arr[0]);
	sort(arr,num);
	return 0;
}
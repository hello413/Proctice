#include<stdio.h>

int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int find;
	int mid,left=arr[0],right = sizeof(arr) / sizeof(arr[0])-1;
	printf("enter the valus you find :");
	scanf_s("%d", &find);
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid]  == find)
		{
			printf("find it,it is the %dth number.", mid+1);
			break;
		}
		else if(arr[mid] < find)
		{
			left = arr[mid + 1];
		}
		else if(arr[mid] > find) 
		{
			right = arr[mid - 1];
		}
	}
	if (left > right)
	{
		printf("-1");
	}
	return 0;
}
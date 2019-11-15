/*最大子数组之和*/
#include<stdio.h>

int main()
{
	int arr[] = { 1,-5,9,-1,3,5,-4,5,-2,4 };
	int num = sizeof(arr) / sizeof(arr[0]);
	int left = 0, right = num - 1;
	int max = 0, sum = 0;;
	while (left <= right)
	{
		for (right = num - 1; right >= left; right--)
		{
			sum = 0;
			for (int j = left; j <= right; j++)
			{
				sum += arr[j];
			}
			if (sum > max)
				max = sum;
			if (left == right)
			{
				left++;
				right = num - 1;
			}
		}
	}
	printf("%d\n", max);
	return 0;
}
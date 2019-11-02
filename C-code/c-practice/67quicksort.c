#include<stdio.h>

void Swap(int arr[], int low, int high)
{
	int tmp;
	tmp = arr[low];
	arr[low] = arr[high];
	arr[high] = tmp;
}

int Partition(int arr[], int low, int high) 
{	
	int base = arr[low];// 选取第一个数作为基准数
	while (low < high) {
		while (low < high && arr[high] >= base) {		//从high开始，向左遍历，直到找到小于基准数的元素，并将此数放到low位置
			high--;
		}
		Swap(arr, low, high);
		while (low < high && arr[low] <= base) {		//从low开始，向右遍历，直到找到大于基准数的元素，并将此数放到high位置
			low++;
		}
		Swap(arr, low, high);
	}
	return low;
}

void QuickSort(int arr[], int low, int high) 
{
	int base;
	if (low < high) {
		base = Partition(arr, low, high);		//调用一趟快速排序，将数组一分为二
		QuickSort(arr, low, base - 1);		//对左部子表递归排序
		QuickSort(arr, base + 1, high);		//对高子表递归排序
	}
}

int main() 
{
	int arr[] = { 48,62,35,77,55,14,35,98 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int i, j;
	printf("排序前:\n");
	for (i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n排序后:\n");
	QuickSort(arr, 0, length - 1);
	for (j = 0; j < length; j++) {
		printf("%d ", arr[j]);
	}
	printf("\n");
	return 0;
}
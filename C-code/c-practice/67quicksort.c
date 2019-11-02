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
	int base = arr[low];// ѡȡ��һ������Ϊ��׼��
	while (low < high) {
		while (low < high && arr[high] >= base) {		//��high��ʼ�����������ֱ���ҵ�С�ڻ�׼����Ԫ�أ����������ŵ�lowλ��
			high--;
		}
		Swap(arr, low, high);
		while (low < high && arr[low] <= base) {		//��low��ʼ�����ұ�����ֱ���ҵ����ڻ�׼����Ԫ�أ����������ŵ�highλ��
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
		base = Partition(arr, low, high);		//����һ�˿������򣬽�����һ��Ϊ��
		QuickSort(arr, low, base - 1);		//�����ӱ�ݹ�����
		QuickSort(arr, base + 1, high);		//�Ը��ӱ�ݹ�����
	}
}

int main() 
{
	int arr[] = { 48,62,35,77,55,14,35,98 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int i, j;
	printf("����ǰ:\n");
	for (i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n�����:\n");
	QuickSort(arr, 0, length - 1);
	for (j = 0; j < length; j++) {
		printf("%d ", arr[j]);
	}
	printf("\n");
	return 0;
}
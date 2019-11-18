#include<stdio.h>
#include<Windows.h>
/*给定一个序列，每次询问序列中第l个数到第r个数中第K大的数是哪个。*/
#pragma warning(disable:4996) 

void Sort(int* brr, int n)
{
	int i = 0, j = 0;
	for (; i < n - 1; i++){
		for (j = i + 1; j < n; j++){
			if (brr[i] < brr[j]){
				int temp = brr[i];
				brr[i] = brr[j];
				brr[j] = temp;
			}
		}
	}
}

int Find(int arr[], int l, int r, int k)
{
	int i = 0, j = 0;
	int* brr;
	brr = (int*)malloc(sizeof(int)*(r - l + 1));
	for (i = l-1; i <= r-1; i++){
		brr[j++] = arr[i];
	}
	Sort(brr, r - l + 1);
	return brr[k - 1];
	free(brr);
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int* arr = NULL;
	arr = (int*)malloc(sizeof(int)*n);
	if (arr == NULL){
		printf("false\n");
		exit(1);
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int m = 0;
	scanf("%d",&m);
	int* crr = NULL;
	crr = (int*)malloc(sizeof(int)*m);
	i = 0;
	int w = m;
	while (m--)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		crr[i++]=Find(arr,l,r,k);
	}
	for  (i = 0; i < w; i++)
	{
		printf("%d\n", crr[i]);
	}
	free(arr,crr);
	system("pause");
	return 0;
}
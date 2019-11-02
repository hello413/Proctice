#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int init(int arr[],int num);
void memset1(int arr[], int num);
int reverse(int arr[], int num);
int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	int num = sizeof(arr) / sizeof(arr[0]);
	memset1(arr, num);
	init(arr,num);  
	reverse(arr,num);
	return 0;
}
int init(int arr[], int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		arr[i] = i;
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}
void memset1(int arr[], int num)
{
	memset(arr, 0, sizeof(arr[0]) * num);
	int i;
	for (i = 0; i < num; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");	
}
int reverse(int arr[], int num)
{
	int i;
	for (i = 0; i < num/2; i++)
	{
		arr[i] = arr[i] ^ arr[num-i-1];
		arr[num-i-1] = arr[i] ^ arr[num - i-1];
		arr[i] = arr[i] ^ arr[num - i-1];
	}
	for (i = 0; i < num; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}
#include<stdio.h>

int main()
{
	int arr1[] = { 1,2,3 }, arr2[] = { 4,5,6 };
	int i;
	for (i = 0; i < 3; i++)
	{
		arr1[i] = arr1[i] ^ arr2[i];
		arr2[i] = arr1[i] ^ arr2[i];
		arr1[i] = arr1[i] ^ arr2[i];
	}
	for ( i = 0; i < 3; i++)
	{
		printf("%d\t",arr1[i]);
	}
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d\t", arr2[i]);
	}
	return 0;
}
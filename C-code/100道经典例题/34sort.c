#include<stdio.h>
#pragma warning(disable:4996)
int move(int array[20], int n, int m);
int main()
{
	int number[20], n, m, i;
	printf("the total numbers is:");
	scanf("%d", &n);
	printf("back m:");
	scanf("%d", &m);
	printf("enter valus of array:");
	for (i = 0; i < n; i++)
		scanf("%d,", &number[i]);
	move(number, n, m);
	for (i = 0; i < n; i++)
		printf("%d,", number[i]);
}

int move(int array[20],int n,int m)
{
	int* p, array_end;
	array_end = *(array + n - 1);
	for (p = array + n - 1; p > array; p--)
		*p = *(p - 1);
	*array = array_end;
	m--;
	if (m > 0) move(array, n, m);
}

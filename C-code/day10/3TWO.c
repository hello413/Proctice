#include<stdio.h>
/*���һ�����������Ƶ�ÿһλ�� */

#pragma warning(disable:4996)
void t_3(int number)
{
	int arr[32] = { 0 };
	int cnt = 0;
	int i = 0;
	while (number)
	{
		arr[i++] = number % 2;
		number /= 2;
		cnt++;
	}
	cnt--;
	for (int j = cnt; j >= 0; j -= 1)
	{
		printf("%d ", arr[j]); 
	}
}

int main()
{
	unsigned int number;
	scanf("%d", &number);
	t_3(number);
	return 0;
}
#include<stdio.h>
/*获取一个数二进制序列中所有的偶数位和奇数位， 
    分别输出二进制序列。 */

#pragma warning(disable:4996)
void t_2(int number)
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
	printf("\n");
	printf("even:");     //奇数
	for (int j = cnt; j >= 0; j -= 2)
	{
		printf("%d ", arr[j]);
	}
	printf("\n");
	printf("odd:");    //偶数
	for (int j = cnt - 1; j >= 0; j -= 2)
	{
		printf("%d ", arr[j]);
	}
	printf("\n");
}

int main()
{
	unsigned int number;
	scanf("%d", &number);
	t_2(number);
	return 0;
}
#include<stdio.h>
/*写一个函数返回参数二进制中 1 的个数 
     比如： 15 
            0000 1111 
            4 个 1 */

#pragma warning(disable:4996)
int count_one_bits(unsigned int value)
{
	int num=0;
	while (value) {
		if (value%2 == 1)
		{
			num++;
		}
		value = value / 2;
	}
	return num;
}

/* 2 */
int count_one_bits2(unsigned int value)
{
	int cnt = 0;
	while (value & 1)
	{
		cnt++;
	}
	valus=valus>>1; 
	return cnt;
}
/* 3 */
int count_one_bits3(unsigned int value)
{
	int cnt = 0;
	while (value)
	{
		cnt++;
		value = value & (value - 1);
	}
	return cnt;
}

int main()
{
	unsigned int value;
	scanf("%d", &value);
	printf("%d个1", count_one_bits(value));
	return 0;
}

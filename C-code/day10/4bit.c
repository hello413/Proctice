#include<stdio.h>
#pragma warning(disable:4996)
/*
> 4. 编程实现： 
>    两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
>    输入例子: 
>    1999 2299    
>    输出例子:7	*/
int count_one_bits(unsigned int value)
{
	int result = 0, k = 1, i, num = 0; 
	while (value) {
		i = value % 2;
		result = k * i + result;
		k = k * 10;
		value = value / 2;
		if (i == 1)
		{
			num++;
		}
	}
	return num;
}
int diffent(int m, int n)
{
	return count_one_bits(m ^ n);
}
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%d",diffent(m,n));
	return 0;
}
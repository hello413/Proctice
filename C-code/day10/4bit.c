#include<stdio.h>
#pragma warning(disable:4996)
/*
> 4. ���ʵ�֣� 
>    ����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
>    ��������: 
>    1999 2299    
>    �������:7	*/
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
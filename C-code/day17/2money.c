#include<stdio.h>
/*> 2. 喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水， 
>    给20元，可以买多少汽水。*/

int main()
{
	int num = 0, money = 20, count = 0;//汽水数，钱，空瓶数
	num = count = money;
	while (count>1)
	{
		num += count / 2;
		if (count & 1)
		{
			count = count / 2 + 1;
		}
		else
		{
			count /= 2;
		}
	}
	printf("%d", num);
	return 0;
}
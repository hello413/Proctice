#include<stdio.h>
#include<math.h>
/*二进制与十进制相互转换*/
void totwo(int m) 
{
	int s[20], i = 0, rem;
	while (m) {
		rem = m % 2;
		m = m / 2;
		s[i++] = rem;
	}
	while (i > 0)
	{
		printf("%d", s[--i]);
	}
	printf("\n");
}
void toten(int m)
{
	int num = 0, ten = 0, n = m;
	for (int i = 0; ; i++)
	{
		num++;
		n /= 10;
		if (n / 10 == 0) 
		{
			num++;
			break;
		}
	}
	while (m)
	{
		num--;
		if (m >= pow(10, num)) 
		{
			ten += pow(2, num);
		}
		m = m % (int)(pow(10, num));
	}
	printf("%d\t", ten);
}
int main()
{
	totwo(10);
	toten(1111);
	return 0;
}
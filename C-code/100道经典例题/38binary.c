#include<stdio.h>
#include<math.h>
/*八进制与十进制相互转换*/
void toeight(int m)
{
	int s[20], i = 0, rem;
	while (m) {
		rem = m % 8;
		m = m / 8;
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
	int n = m, num = 0, ten = 0;
	while (n)
	{
		n /= 10;
		num++;
	}
	while (m)
	{
		if (m/(pow(10,--num)))
		{
			ten += m / (pow(10, num)) * pow(8, num);
		}
		m %= (int)pow(10, num);
	}
	printf("%d\n", ten);
}
int main()
{
	toeight(9);
	toten(21);
	return 0;
}
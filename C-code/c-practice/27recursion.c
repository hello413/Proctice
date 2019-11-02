#include<stdio.h>
/*用递归完成最大公约数*/
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main()
{
	int m, n;
	printf("enter valus of m and n :");
	scanf_s("%d%d", &m, &n);
	if (m < n) {
		m = m ^ n;
		n = m ^ n;
		m = m ^ n;
	}
	printf("the greatest common divisor is %d", gcd(m, n));
	return 0;
}
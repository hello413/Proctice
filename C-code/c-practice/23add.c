#include<stdio.h>
/*求1 + 2!+ 3!+ ... + 20!的和*/
int Factorial(int n)
{
	int val = 1;
	for (int i = n; i > 0; i--) {
		val *= i;
	}
	return val;
}
int main()
{
	int add = 0;
	for (int i = 1; i <= 20; i++) {
		add += Factorial(i);
	}
	printf("1 + 2!+ 3!+ ... + 20!的和是：%d.\n", add);
	return 0;
}
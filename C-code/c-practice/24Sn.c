#include<stdio.h>
/*��һ�������У�2 / 1��3 / 2��5 / 3��8 / 5��13 / 8��21 / 13...���������е�ǰ20��֮�͡�*/
int main()
{
	double son = 2.0, mom = 1.0, temp;
	double sum = 0;
	for (int i = 0; i < 20; i++) {
		double num = son / mom;
		sum += num;
		temp = mom;
		mom = son;
		son = temp + mom;
	}
	printf("%.2lf\n", sum);
	return 0;
}
#include<stdio.h>
/*һ���100�׸߶��������£�ÿ����غ�����ԭ�߶ȵ�һ�룻�����£������ڵ�10�����ʱ�������������ף���10�η�����ߣ�*/
int main()
{
	double heigh = 100, s = 100;
	for (int i = 0; i < 10; i++)
	{
		s += heigh;
		heigh /= 2.0;
	}
	printf("the 10th heigh is %.2lf m.\nthe ways are %5.2lf m.\n", heigh, s - heigh);
	return 0;
}
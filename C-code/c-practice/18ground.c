#include<stdio.h>
/*一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？*/
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
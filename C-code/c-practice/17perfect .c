#include<stdio.h>
/*һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ��������������6 = 1��2��3.����ҳ�1000���ڵ�����������*/
int main()
{
	int num = 0;
	for (int i = 1; i < 1000; i++)
	{
		num = 0;
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0) 
			{
				num += j;
			}
		}
		if (num == i)
		{
			printf("%d\t", i);
		}
	}
	return 0;
}
#include<stdio.h>
//��1,2,3,4�ĸ����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ���

int main()
{
	int num = 0;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 1; k <= 4; k++)
			{
				if (i != j && i != k && j != k)
				{
					printf("%d%d%d\t", i, j, k);
					num++;
				}
			}
		}
	}
	printf("\nthese have %d numbers!\n", num);
	return 0;
}
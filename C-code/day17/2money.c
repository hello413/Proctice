#include<stdio.h>
/*> 2. ����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ�� 
>    ��20Ԫ�������������ˮ��*/

int main()
{
	int num = 0, money = 20, count = 0;//��ˮ����Ǯ����ƿ��
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
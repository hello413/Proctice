#include<stdio.h>
/*���Ŵ���ѧ�����������ġ��㾭���������һ�������ġ���Ǯ��ټ����⡱��
����һ��ֵǮ�壬��ĸһ��ֵǮ������������ֵǮһ����Ǯ��ټ������̡�ĸ���������Σ�*/
int main()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int z = 100 - i - j;
			if (z % 3) 
			{
				continue;
			}
			if (5 * i + 3 * j + z / 3 == 100) 
			{
				printf("man chicken has %d,women chichen has %d,baby chicken has %d.\n", i, j, z);
			}
		}
	}
	return 0;
}
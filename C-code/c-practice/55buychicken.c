#include<stdio.h>
/*国古代数学家张丘建在他的《算经》中提出了一个著名的“百钱买百鸡问题”，
鸡翁一，值钱五，鸡母一，值钱三，鸡雏三，值钱一，百钱买百鸡，问翁、母、雏各几何？*/
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
#include<stdio.h>
/*如果一个渔夫从 2011 年 1 月 1 日开始每三天打一次渔，两天晒一次网，
编程实现当输入 2011 1 月 1 日以后的任意一天，输出该渔夫是在打渔还是在晒网。*/
#pragma warning(disable:4996)
int main()
{
	int arr[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int year, month, day;
	printf("enter the day:");
	scanf("%d%d%d", &year, &month, &day);
	int days = 0, syear = year;
	do{
		if ((year % 4 == 0 && year % 100) || year % 400 == 0)
		{
			arr[1] = 29;
		}
		if (year == syear)
		{
			for (int i = 0; i < month - 1; i++)
			{
				days += arr[i];
			}
			days += day;
		}
		else
		{
			for (int i = 0; i < 12; i++)
			{
				days += arr[i];
			}
		}
		year--;
	} while (year >= 2011);
	if (days % 5 >= 1 && days % 5 <= 3) 
	{
		printf("he is fishing!");
	}
	else
	{
		printf("he is suning!");
	}
	return 0;
}
#include<stdio.h>

void leapyear(int year);
int main()
{
	int year;
	printf("输入年份：");
	scanf_s("%d", &year);
	leapyear(year);
	return 0;
}
void leapyear(int year)
{
	if ((year%4 == 0 && year%100 != 0) || (year%400 == 0))
	{
		printf("%d是闰年。", year);
	}
	else
	{
		printf("%d不是闰年。", year);
	}
}
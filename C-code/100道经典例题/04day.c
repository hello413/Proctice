#include<stdio.h>
/*输入某年某月某日，判断这一天是这一年的第几天？*/
int main()
{
	int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int year, monday, day;
	printf("please enter the day(2019 2 15):");
	scanf_s("%d%d%d", &year, &monday, &day);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
	{
		arr[1] = 29;
	}
	int days = 0,i;
	for (i = monday-2; i >= 0; i--) 
	{
		days += arr[i];
	}
	days += day;
	printf("%d\n", days);
	return 0;
}
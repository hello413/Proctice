#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int num = 0; //[1,3999]
	int thousand = 0;
	int hundred = 0;
	int ten = 0;
	int unit = 0;
	char* String_thousand[3] = { "M","MM","MMM" };
	char* String_hundred[9] = { "C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
	char* String_ten[9] = { "X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
	char* String_unit[9] = { "I","II","III","IV","V","VI","VII","VIII","IX" };
	char* String_Temp = NULL;
	scanf("%d", &num);

	thousand = num / 1000;
	hundred = num / 100 % 10;
	ten = num % 100 / 10;
	unit = num % 10;
	if (thousand != 0)
	{
		for (int i = 0; i < 3; i++)
		{
			if (thousand - 1 == i)
				String_Temp = String_thousand[i];
		}
	}
	if (String_Temp != NULL)
		printf("%s", String_Temp);
	String_Temp = NULL;
	if (hundred != 0)
	{
		for (int i = 0; i < 9; i++)
		{
			if (hundred - 1 == i)
				String_Temp = String_hundred[i];
		}
	}
	if (String_Temp != NULL)
		printf("%s", String_Temp);
	String_Temp = NULL;
	if (ten != 0)
	{
		for (int i = 0; i < 9; i++)
		{
			if (ten - 1 == i)
				String_Temp = String_ten[i];
		}
	}
	if (String_Temp != NULL)
		printf("%s", String_Temp);
	String_Temp = NULL;
	if (unit != 0)
	{
		for (int i = 0; i < 9; i++)
		{
			if (unit - 1 == i)
				String_Temp = String_unit[i];
		}
	}
	if (String_Temp != NULL)
		printf("%s\n", String_Temp);
	return 0;
}
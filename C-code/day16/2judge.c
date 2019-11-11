#include<stdio.h>

/*> 2. 判断一个字符串是否为另外一个字符串旋转之后的字符串。 
>    例如：给定s1 =AABCD和s2 = BCDAA，返回1，给定s1=abcd和s2=ACBD，返回0。*/

int left(char str[4],char str1[4],int num)
{
	for (int valus = 1; valus < num; valus++)
	{
		int temp = valus;
		while (valus)
		{
			char tmp = str[0];
			int i = 0;
			for (i = 0; ; i++)
			{
				if (str[i] == '\0')
				{
					break;
				}
				else
				{
					str[i] = str[i + 1];
				}
			}
			str[i - 1] = tmp;
			valus--;			//此处会改变valus的值，后面要换回来
		}
		valus = temp;
		if (strcmp(str, str1) == 0)
		{
			return 1;
			break;
		}
	}
	return 0;
}


int main()
{
	char str[] = "ABCD";
	char str1[] = "DABC";
	int num = sizeof(str) / sizeof(str[0]);
	printf("%d",left(str, str1, num));
	return 0;
}

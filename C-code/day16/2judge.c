#include<stdio.h>

/*> 2. �ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ����� 
>    ���磺����s1 =AABCD��s2 = BCDAA������1������s1=abcd��s2=ACBD������0��*/

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
			valus--;			//�˴���ı�valus��ֵ������Ҫ������
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

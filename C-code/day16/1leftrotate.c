#include<stdio.h>
/*
> 1. ʵ��һ�����������������ַ����е�k���ַ���
>    ABCD����һ���ַ��õ�BCDA
>    ABCD���������ַ��õ�CDAB */


void left(char* a,int valus)
{
	while (valus)
	{
		char tmp = a[0];
		int i = 0;
		for (i = 0; ; i++)
		{
			if (a[i] == '\0')
			{
				break;
			}
			else
			{
				a[i] = a[i + 1];
			}
		}
		a[i - 1] = tmp;

		valus--;
	}
}


int main()
{
	char a[] = "ABCD";
	left(a, 1);
	printf("%s", a);
}





// ��һ��ڶ��ַ���
/*
 ��ǰk���ַ�����ת����������ַ�����ת��Ȼ�������ַ�����ת
 */
void fun(char str[], int left, int right)
{
	while (left < right)
	{
		char tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		left++;
		right--;
	}
}
void t1_2()
{
	char str[100] = "ABCD";
	int len = strlen(str);
	int k = 0;
	scanf("%d", &k);

	while (k > len)    // ���ﴦ����һ��k>�ַ������ȵ����
	{               // �����Ϳ���ѭ����ȥ��
		k -= len;
	}

	fun(str, 0, k - 1);
	fun(str, k, len - 1);
	fun(str, 0, len - 1);
	printf("%s\n", str);
}
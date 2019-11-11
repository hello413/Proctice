#include<stdio.h>
/*
> 1. 实现一个函数，可以左旋字符串中的k个字符。
>    ABCD左旋一个字符得到BCDA
>    ABCD左旋两个字符得到CDAB */


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





// 第一题第二种方法
/*
 将前k个字符串反转，将后面的字符串反转，然后将整个字符串反转
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

	while (k > len)    // 这里处理了一下k>字符串长度的情况
	{               // 这样就可以循环下去了
		k -= len;
	}

	fun(str, 0, k - 1);
	fun(str, k, len - 1);
	fun(str, 0, len - 1);
	printf("%s\n", str);
}
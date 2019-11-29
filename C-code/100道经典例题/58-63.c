#include<stdio.h>
#include<string.h>
/*实现strlen
  实现strcmp
  实现strcpy
  实现strcat
  实现strchr()
  实现strstr()*/
#pragma warning(disable:4996)


int strlen(char* str1)
{
	if (*str1 == NULL)
	{
		printf("输入字符串有误\n");
		return NULL;
	}
	int i = 0;
	while (str1[i++] != '\0')
	{
		;
	}
	return --i;
}

int strcmp(char* str1, char* str2)
{
	while (1)
	{
		if (*str1 == '\0' || *str2 == '\0')
			return 0;
		int i = 0;
		if (str1 != str2)
		{
			return str1[i] - str2[i];
		}
		i++;
	}

}

char* strchr(char *str1, char ch)
{
	while (*str1 != '\0' && *str1 != ch)
	{
		++str1;
	}
	return *str1 == ch ? str1 : NULL;
}

char* strstr(char *str1, char *str2)
{
	int n = strlen(str2);
	for (; *str1 != 0; ++str1) {
		if (strncmp(str1, str2, n) == 0) {
			return (char*)str1;
		}
	}
	return NULL;
}

char *strcpy(char* str1, const char* str2)
{
	if (*str1 == NULL || *str2 == NULL)
	{
		printf("输入字符串有误\n");
		return NULL;
	}
	int i = 0;
	while (1)
	{
		str1[i] = str2[i];
		if (str1[i++] == '\0')
			break;
	}
	return str1;
}

char *strcat(char* str1, const char* str2)
{
	if (*str1 == NULL || *str2 == NULL)
	{
		printf("输入字符串有误\n");
		return NULL;
	}
	int i = 0, j = 0;
	while (str1[i++] != '\0')
	{
		;
	}
	i--;
	while (str1[j] != '\0')
	{
		str1[i + j] = str2[j];
		j++;
	}
	return str1;
}

int main()
{
	char arr1[20] = { "hello world" };
	printf("%d\n", strlen(arr1));   //字符串长度
	char arr2[] = { "hello c!" };
	printf("%d\n", strcmp(arr1, arr2));    //比较字符串
	strcpy(arr1, arr2);  //拷贝字符串
	printf("%s\n", arr1);
	strcat(arr1, arr2);    //连接字符串
	printf("%s\n", arr1);
	char c='c', * arr;
	arr = arr1;
	printf("%s\n", strchr(arr, c));   //在字符串中找字符
	char arr3[] = " c!hello";
	char arr4[] = "hello";
	char *arr0 = strstr(arr3, arr4);
	printf("%s\n", arr0);   //在字符串中找字符串
	return 0;
}
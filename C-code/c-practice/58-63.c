#include<stdio.h>
#include<string.h>
/*实现strlen
  实现strcmp
  实现strcpy
  实现strcat
  实现strchr()
  实现strstr()*/
#pragma warning(disable:4996)
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
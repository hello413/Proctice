#include<stdio.h>
#include<string.h>
/*ʵ��strlen
  ʵ��strcmp
  ʵ��strcpy
  ʵ��strcat
  ʵ��strchr()
  ʵ��strstr()*/
#pragma warning(disable:4996)
int main()
{
	char arr1[20] = { "hello world" };
	printf("%d\n", strlen(arr1));   //�ַ�������
	char arr2[] = { "hello c!" };
	printf("%d\n", strcmp(arr1, arr2));    //�Ƚ��ַ���
	strcpy(arr1, arr2);  //�����ַ���
	printf("%s\n", arr1);
	strcat(arr1, arr2);    //�����ַ���
	printf("%s\n", arr1);
	char c='c', * arr;
	arr = arr1;
	printf("%s\n", strchr(arr, c));   //���ַ��������ַ�
	char arr3[] = " c!hello";
	char arr4[] = "hello";
	char *arr0 = strstr(arr3, arr4);
	printf("%s\n", arr0);   //���ַ��������ַ���
	return 0;
}
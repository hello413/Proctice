#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int main()
{
	char s1[1000], s2[1000];
	int num1[1001], num2[1001], len1, len2, i, j;
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	printf("enter two numbers :>");
	scanf("%s%s", s1, s2);
	len1 = strlen(s1);
	len2 = strlen(s2);
	for (i = len1 - 1, j = 0; i >= 0; --i) //�Ӻ���ǰ��������ַ��������ַ������������
	{
		num1[j++] = s1[i] - '0';
	}
	for (i = len2 - 1, j = 0; i >= 0; --i)
	{
		num2[j++] = s2[i] - '0';
	}
	//��ӵĴ�����num2�����ӵ�i1�С���λ��1��ԭ����-10

	for (i = 0; i < (len2 > len1 ? len2 : len1); i++)
	{
		num1[i] += num2[i];
		if (num1[i] > 9)
		{
			num1[i + 1] += 1;
			num1[i] -= 10;
		}
	}
	printf("valus of add:>");
	if (num1[i])//������һλ��Ϊ0�������������һλҲ��������������
	{
		for (j = i; j >= 0; j--)
		{
			printf("%d", num1[j]);
		}
	}
	else
	{
		for (j = i - 1; j >= 0; j--)//������һλΪ0�����λ����Ҫ�����
			printf("%d", num1[j]);
	}
	printf("\n");
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
	if (strsSize == 0)//�������Ϊ�գ����������ʱ��̵ܶĻ������п���������ǿ��ַ�
	{
		return " ";
	}
	char* str = (char*)calloc(128, sizeof(char));//����128���ֽڵ��ڴ棬���洢����ǰ׺
	for (int i = 0, j; i < strlen(*strs); i++)//��ѭ�����Ե�һ���ַ����ĳ���Ϊѭ����������Ϊ�����ǰ׺�ĳ���С�ڵ�����
	{
		for (j = 0; j < strsSize - 1; j++)//��ѭ�������ַ�������Ϊѭ����������1��ԭ������Ϊѭ������j+1�������Ļ����ᷢ���ڴ�Խ��
		{
			if (strs[j][i] != strs[j + 1][i])//�����һ���ַ�����iλ�����ڵ�ǰ�ַ�����iλ��˵��ѭ��������i-1λ�������ǰ׺�����һ���ַ�
			{
				return str;
			}
		}
		str[i] = strs[j][i];//һ����ѭ��������˵����ǰ�ַ���һ���ж�ͨ���ˣ���ͨ�����ַ�����str   
	}
	return str;
}

int main()
{
	char* s[5] = { "dog0","dogl","dog2" };
	char* buff = { 0 };
	buff = longestCommonPrefix(s, 3);
	printf("%s\n", buff);
	free(buff);
	buff = NULL;
	return 0;
}

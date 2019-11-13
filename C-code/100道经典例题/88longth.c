#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
	if (strsSize == 0)//输入可能为空，如果答案消耗时间很短的话，很有可能输入的是空字符
	{
		return " ";
	}
	char* str = (char*)calloc(128, sizeof(char));//分配128个字节的内存，来存储公共前缀
	for (int i = 0, j; i < strlen(*strs); i++)//外循环，以第一个字符串的长度为循环次数，因为最长公共前缀的长度小于等于它
	{
		for (j = 0; j < strsSize - 1; j++)//内循环，以字符串个数为循环次数，减1的原因是因为循环内有j+1，不减的话，会发生内存越界
		{
			if (strs[j][i] != strs[j + 1][i])//如果下一个字符串的i位不等于当前字符串的i位，说明循环结束，i-1位是最长公共前缀的最后一个字符
			{
				return str;
			}
		}
		str[i] = strs[j][i];//一次内循环结束，说明当前字符这一轮判断通过了，将通过的字符存入str   
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

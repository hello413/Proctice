#include<stdio.h>
/*输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。*/
int main()
{
	char ch;
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
	printf("enter :");
	while ((ch = getchar()) != '\n') {
		if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
			num1++;
		}
		else if (ch == ' ')
		{
			num2++;
		}
		else if ('0' <= ch && ch <= '9')
		{
			num3++;
		}
		else
		{
			num4++;
		}
	}
	printf("Number of English letters are %d\nspaces are %d\nnumbers are %d\nother characters are %d\n", num1, num2, num3, num4);
	return 0;
}
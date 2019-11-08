#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
/*> 4. ��һ���ַ����������Ϊ:"student a am i", 
>    ���㽫��������ݸ�Ϊ"i am a student". 
>    Ҫ�� 
>    ����ʹ�ÿ⺯���� 
>    ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���*/

void reverse(char* start, char* end) {
	assert(start);
	assert(end);
	while (start < end) {
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
void reverse_str(char* str, int sz) 
{
	char* str1 = str;
	char* left = str;
	char* right = str + sz - 1;
	reverse(left, right);         //�Ƚ��ַ������巴ת
	while (*str1) {
		left = str1;
		while ((*str1 != '\0') && (*str1 != ' ')) { //�ҵ����ʣ��˴�һ��Ҫ��(*str1 != '\0')�������ƣ���Ϊ�ҵ����һ�����ʵ�ʱ��*str1��ԶҲ��Ϊ�ո�
			str1++;
		}
		right = str1 - 1;               //��ʱstr1ָ�򵥴ʺ󷽵Ŀո���Ҫ��һ����ָ�򵥴ʵ����һ����ĸ
		reverse(left, right);               //�����巴ת���ٴη�ת���ʣ���ʹ����ƴд˳��ָ�����
		if (*str1 == ' ')             //���ڿո���ָ�����һλ�����ܲ����´�ѭ����
		{
			str1++;
		}
	}
}
int main() 
{
	char arr[] = "student a am i";
	int sz = sizeof(arr) / sizeof(arr[0]) - 1;
	reverse_str(arr, sz);
	printf("%s", arr);
	return 0;
}

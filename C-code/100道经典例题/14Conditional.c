#include<stdio.h>
/*���������������Ƕ������ɴ��⣺ѧϰ�ɼ� >= 90�ֵ�ͬѧ��A��ʾ��60 - 89��֮�����B��ʾ��60�����µ���C��ʾ��*/
int main()
{
	printf("please enter your success :");
	int success;
	scanf_s("%d", &success);
	printf("The success is : %s", success > 90 ? "A" : success > 60 ? "B" : "C");
	return 0;
}
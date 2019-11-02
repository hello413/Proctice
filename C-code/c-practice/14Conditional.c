#include<stdio.h>
/*利用条件运算符的嵌套来完成此题：学习成绩 >= 90分的同学用A表示，60 - 89分之间的用B表示，60分以下的用C表示。*/
int main()
{
	printf("please enter your success :");
	int success;
	scanf_s("%d", &success);
	printf("The success is : %s", success > 90 ? "A" : success > 60 ? "B" : "C");
	return 0;
}
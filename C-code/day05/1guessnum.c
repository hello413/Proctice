#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand((unsigned)time(NULL));//rand�������ɵ���α�������һ������һ�κ󣬾Ͳ�����
	int num = rand() % 100;
	printf("%d\n", num);
	printf("enter the number you think :");
	int think;
	while (1)
	{
		scanf_s("%d",&think);
		if (think == num)
		{
			printf("you are right!");
			break;
		}
		if (think <= num)
		{
			printf("it is small, please enter again :");
		}
		if (think >= num)
		{
			printf("it is big, please enter again :");
		}
	}
	return 0;
}
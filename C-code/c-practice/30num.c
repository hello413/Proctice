#include<stdio.h>
/*һ��������5λ����������Ҫ��һ�������Ǽ�λ�������������ӡ����λ����*/
int main()
{
	int num, a = 0;
	printf("enter:");
	scanf_s("%d", &num);
	while (num)
	{
		printf("%d", num % 10);
		num /= 10;
		a++;
	}
	printf("\n%dλ��\n", a);
	return 0;
}
#include "stdio.h"
//���ⲿ����ʱ��ʹ��ֻ���ڱ�Դ�ļ���ʹ��
varfunc()
{
	int var = 0;
	static int static_var = 0;
	printf("var equal: %d \n", var);
	printf("static var equal: %d \n", static_var);
	printf("\n");
	var++;
	static_var++;
}
int main()
{
	int i;
	for (i = 0; i < 3; i++) {
		varfunc();//�ڴ�����иı�������������������ִ�ж�����
	}
	return 0;
}

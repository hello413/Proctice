#include "stdio.h"
//在外部声明时，使其只能在本源文件中使用
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
		varfunc();//在代码块中改变其作用域，让其在整个执行都存在
	}
	return 0;
}

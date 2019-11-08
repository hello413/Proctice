/*按任意键来改变颜色*/

//1 - f分别代表的颜色如下：
//
//0 = 黑色		1 = 蓝色		2 = 绿色	3 = 湖蓝色	4 = 红色	5 = 紫色		6 = 黄色	7 = 白色 	8 = 灰色        9 = 淡蓝色        
//A = 淡绿色       B = 淡浅绿色   C = 淡红色        D = 淡紫色         E = 淡黄色        F = 亮白色
#include <stdio.h>
#include <windows.h>
void color(short x)	//自定义函根据参数改变颜色 
{
	if (x >= 0 && x <= 15)//参数在0-15的范围颜色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色 
	else//默认的颜色白色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
int main()
{
	printf("此处为没调用颜色函数之前默认的颜色\n");
	//调用自定义color(x)函数 改变的颜色
	color(0);	printf("黑色\n");
	color(1); 	printf("蓝色\n");
	color(2); 	printf("绿色\n");
	color(3); 	printf("湖蓝色\n");
	color(4);  	printf("红色\n");
	color(5);  	printf("紫色\n");
	color(6); 	printf("黄色\n");
	color(7);  	printf("白色\n");
	color(8);  	printf("灰色\n");
	color(9); 	printf("淡蓝色\n");
	color(10); 	printf("淡绿色\n");
	color(11); 	printf("淡浅绿色\n");
	color(12);  printf("淡红色\n");
	color(13); 	printf("淡紫色\n");
	color(14); 	printf("淡黄色\n");
	color(15); 	printf("亮白色\n");
	color(16);    //因为这里大于15，恢复默认的颜色 
	printf("回到原来颜色\n");
	return 0;
}
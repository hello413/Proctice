# java-code-
1:switch语句的格式?针对格式的解释?以及注意事项?
> 	switch语句格式：  
> 	switch(表达式)  
> 	{  
> 		case 取值1:  
> 			执行语句；  
> 			break；  
> 		case 取值2:  
> 			执行语句；  
> 			break；  
> 			…...  
> 		default:  
> 			执行语句；  
> 			break；  
> 	}  

2:看程序，分析下面程序的结果：  
int x = 2,y=3;  
  
switch(x)  
{  
	default:  
		y++;  
	case 3:  
		y++;  
		break;  
	case 4:  
		y++;  
}  

System.out.println("y="+y);  

> //y=5  
3:根据输入的值，判断是星期几。(分别用if语句和switch语句实现)  
	输入：1	   
		输出：星期1  

4:for循环的格式?要能看懂执行流程。    
  用for循环完成如下案例    
  
  求和  
  求偶数和  
  求奇数和  
  打印水仙花数  
  统计水仙花数  
  九九乘法表  

5:while循环的格式?要能看懂执行流程  
  用while循环完成如下案例  
  
  求和  
  纸张折叠成珠穆朗玛峰高度的次数  

6:break,continue和return分别有什么用?  
> 	break 跳出总循环，不再执行循环(结束当前的循环体)  
> 	continue 跳出本次循环，继续执行下次循环(结束正在执行的循环 进入下一个循环条件)  
> 	return 程序返回，不再执行下面的代码(结束当前的方法 直接返回)  

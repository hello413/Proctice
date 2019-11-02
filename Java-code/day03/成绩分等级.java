import java.util.Scanner;
/*编写代码实现如下内容：if语句实现
考试成绩分等级。
	90~100	A等。
	80-89	B等。
	70-79	C等。
	60-69	D等。
	60以下	E等。
请根据给定成绩，输出对应的等级。*/
public class score{
	public static void main(String[] args) {
		System.out.print("请输入成绩：");
		int a=new Scanner(System.in).nextInt();
		if(a>90)System.out.println("A等");
		else if(a>80)System.out.println("B等");
		else if(a>70)System.out.println("C等");
		else if(a>60)System.out.println("D等");
		else System.out.println("E等");
	}
}
/*根据输入的值，判断是星期几。(分别用if语句和switch语句实现)
	输入：1	 
		输出：星期1*/
import java.util.Scanner;
public class practice {
	public static void main(String[] args) {
		System.out.println("输值：");
//		int a[]= {1,2,3,4,5,6,7};
//		for(int i=1;i<8;i++) {
//			if(new Scanner(System.in).nextInt()==a[i])
//				System.out.println("星期"+(i+1));
//		}
		int x=new Scanner(System.in).nextInt();
		switch(x)
		{
			case 1:
				System.out.println("星期"+x);
				break;
			case 2:
				System.out.println("星期"+x);
				break;
			case 3:
				System.out.println("星期"+x);
				break;
			case 4:
				System.out.println("星期"+x);
				break;
			case 5:
				System.out.println("星期"+x);
				break;
			case 6:
				System.out.println("星期"+x);
				break;
			case 7:
				System.out.println("星期"+x);
				break;
			default:
				System.out.println("输的值不对");
				break;
		}		
	}
}

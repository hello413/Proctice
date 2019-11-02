/*求和
  求偶数和
  求奇数和*/
public class add {
	public static void main(String[] args) {
		int add1=0,add2=0,add3=0;
		for(int i=0;i<=100;i++)
			add1+=i;
		System.out.println(add1);
		for(int i=1;i<=100;i=i+2)
			add2+=i;
		System.out.println(add2);
		for(int i=0;i<=100;i=i+2)
			add3+=i;
		System.out.println(add3);
	}
}

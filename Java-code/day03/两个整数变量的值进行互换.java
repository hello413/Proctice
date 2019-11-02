//如何实现对两个整数变量的值进行互换
/*public class sd {
	public static void main(String[] args) {
		int a=1,b=2,c;
		c=a;a=b;b=c;
		System.out.println(a+"----"+b);
	}
}*/
public class exchange {
	public static void main(String[] args) {
		int a=1,b=2;
		a=a^b;//a=01^10=11
		b=a^b;//b=11^10=01
		a=a^b;//a=11^01=10
		System.out.println(a+"----"+b);
	}
}
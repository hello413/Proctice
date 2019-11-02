/*函数的练习：
	A:求两个数据之和
	B:判断两个数据是否相等
	C:获取两个数中较大的值
	D:打印m行n列的星形矩形
	E:打印nn乘法表*/
public class function {
	public static void main(String[] args) {
		rectangle(5,6);
		multiplication(5);
	}
	public static int add(int a,int b) {
		return a+b;
	}
	public static boolean equal(int a,int b) {
		return a==b;
	}
	public static int big(int a,int b) {
		return a>b?a:b;
	}
	public static void rectangle(int m,int n) {
		for(int i=1;i<=m;i++) {
			for(int j=1;j<=n;j++)
				System.out.print("*");
			System.out.println();
		}
	}
	public static void multiplication(int n) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=i;j++)
				System.out.printf("%d*%d=%d\t",j,i,(i*j));
			System.out.println();
		}
	}
}

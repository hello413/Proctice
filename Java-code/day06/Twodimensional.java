/*A:二维数组遍历
	B:公司年销售额求和
		某公司按照季度和月份统计的数据如下：单位(万元)
		第一季度：22,66,44
		第二季度：77,33,88
		第三季度：25,45,65
		第四季度：11,66,99
	C:打印杨辉三角形(行数可以键盘录入)*/
import java.util.Scanner;
public class Twodimensional {
	public static void main(String[] args) {
		int[][] arr= {{22,66,44},{77,33,88},{25,45,65},{11,66,99}};
		yanghuitriangle();
	}
	public static void ergodic(int[][] arr) {
		for(int i=0;i<arr.length;i++) {
			for(int j=0;j<arr[i].length;j++)
				System.out.print(arr[i][j]+" ");
			System.out.println();
		}
	}
	public static void add(int[][] arr) {
		int add=0;
		for(int i=0;i<arr.length;i++)
			for(int j=0;j<arr[i].length;j++)
				add+=arr[i][j];
		System.out.println(add);
	}
	public static void yanghuitriangle() {
		int hang = new Scanner(System.in).nextInt();
		int[][] arr=new int[hang][hang];
		for(int a=0;a<arr.length;a++) {
			arr[a][0]=1;
			arr[a][a]=1;
		}
		for(int i=2;i<arr.length;i++)
			for(int j=1;j<arr[i].length;j++)
				arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
		for(int i=0;i<arr.length;i++) {
			for(int j=0;j<=i;j++)
				System.out.print(arr[i][j]+" ");
			System.out.println();
		}
	}
}

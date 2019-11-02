/*A:��ά�������
	B:��˾�����۶����
		ĳ��˾���ռ��Ⱥ��·�ͳ�Ƶ��������£���λ(��Ԫ)
		��һ���ȣ�22,66,44
		�ڶ����ȣ�77,33,88
		�������ȣ�25,45,65
		���ļ��ȣ�11,66,99
	C:��ӡ���������(�������Լ���¼��)*/
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

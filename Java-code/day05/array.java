/*数组遍历(依次输出数组中的每一个元素)
	数组获取最值(获取数组中的最大值最小值)
	数组元素逆序 (就是把元素对调)*/
public class array {
	public static void main(String[] args) {
		int[] arr= {2,5,6,4,3};
		inverse(arr);
	}
	public static void ergodic(int[] arr) {
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]);
	}
	public static void maxandmin(int[] arr) {
		int max=arr[0],min=arr[0];
		for(int i=0;i<arr.length;i++) {
			if(max<arr[i])
				max=arr[i];
			if(min>arr[i])
				min=arr[i];
		}
		System.out.print(max+"----"+min);
	}
	public static void inverse(int[] arr) {
		for(int i=0;i<arr.length/2;i++) {
			arr[i]=arr[i]^arr[arr.length-i-1];
			arr[arr.length-i-1]=arr[i]^arr[arr.length-i-1];
			arr[i]=arr[i]^arr[arr.length-i-1];
		}
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]);
	}
}

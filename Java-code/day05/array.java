/*�������(������������е�ÿһ��Ԫ��)
	�����ȡ��ֵ(��ȡ�����е����ֵ��Сֵ)
	����Ԫ������ (���ǰ�Ԫ�ضԵ�)*/
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

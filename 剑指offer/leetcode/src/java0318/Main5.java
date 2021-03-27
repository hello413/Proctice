package java0318;

public class Main5 {
    public static int getMaxArr(int[] arr){
        int max = arr[0];
        int sum = 0;
        int left = 0,right = 0;
        for(int i=0;i<arr.length;i++){
            for (int j=i;j<arr.length;j++){
                sum = 0;
                for (int k = i;k<=j;k++){
                    sum+=arr[k];
                }
                if (sum>max){
                    max = sum;
                    left = i;
                    right = j;
                }
            }
        }
        return arr[right]-arr[left];
    }

    public static void main(String[] args) {
        int[] arr = {-1,2,-7,5,-1};
        System.out.println(getMaxArr(arr));
    }
}

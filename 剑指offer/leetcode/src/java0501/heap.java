package java0501;

public class heap {
    public void heapsort(int[] arr,int k){
        createheap(arr,0,k-1);
        for (int i=k;i<arr.length;i++){
            if (arr[0]<arr[i]){
                exchange(arr,0,i);
                createheap(arr,0,k);
            }
        }
        for (int i=0;i<k;i++){
            System.out.print(arr[i]+" ");
        }
    }

    private void createheap(int[] arr, int index, int k) {
        for (int i = (k-1)/2;i>=0;i--){
            shiftdown(arr,0,k);
        }
    }

    private void shiftdown(int[] arr, int index, int k) {
        int left = 2*index+1;
        while (left<k){
            int right = left+1;
            int min = (arr[left]<arr[right])?left:right;
            if (arr[index]>arr[min]){
                exchange(arr,index,min);
            }
            index=min;
            left=2*index+1;
        }
    }

    private void exchange(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i]= arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {95,6,78,15,6,1,2,4,33,5,7,21,15};
        new heap().heapsort(arr,3);
    }
}

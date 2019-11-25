class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int []B=new int[A.length];
        for(int i=0;i<A.length;i++){
            for(int j=0;j<A.length;j++){
                if(i%2==0&&A[j]%2==0&&A[j]%2>=0){
                    B[i]=A[j];
                    A[j]=-1;
                    break;
                }
                else if (i%2!=0&&A[j]%2!=0&&A[j]%2>=0){
                    B[i]=A[j];
                    A[j]=-1;
                    break;
                }
            }
        }
        return B;
    }
}
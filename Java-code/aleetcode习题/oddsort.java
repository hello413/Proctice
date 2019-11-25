/*给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。

对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。

你可以返回任何满足上述条件的数组作为答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-array-by-parity-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
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
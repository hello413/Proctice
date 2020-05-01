package java_0430;

import java.util.Scanner;

/**
 *http://lx.lanqiao.cn/problem.page?gpid=T13
 */
public class KWellNumber {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while(input.hasNext()) {
            int K = input.nextInt();
            int L = input.nextInt();
            int value = numsOfknumber(K, L);
            System.out.println(value);
        }
    }

    private static int numsOfknumber(int K, int L) {
        int count = 0;
        int[][] arr = new int[L][K];
        for (int i=0;i<K;i++)arr[0][i] = 1;
        for (int i=1;i<L;i++){
            for (int j=0;j<K;j++){
                for (int a = 0;a<K;a++){
                    if (a!=j+1&&a!=j-1){
                        arr[i][j]+=arr[i-1][a];
                        if (arr[i][j]>1000000007)
                            arr[i][j]-=1000000007;
                    }
                }
            }
        }
        for (int i=1;i<K;i++){
            count+=arr[L-1][i];
            if (count>1000000007)count-=1000000007;
        }
        return count;
    }
}

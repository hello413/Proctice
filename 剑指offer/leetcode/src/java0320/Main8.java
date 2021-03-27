package java0320;

import java.util.Scanner;

public class Main8 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while (T-->0) {
            int N = input.nextInt();
            int M = input.nextInt();
            int[][] arr = new int[M][2];
            for (int i=0;i<M;i++){
                arr[i][0] = input.nextInt();
                arr[i][1] = input.nextInt();
            }
            System.out.println(T%2!=0?"Yes":"No");
        }
    }
}

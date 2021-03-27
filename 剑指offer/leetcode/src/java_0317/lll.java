package java_0317;

import java.util.Scanner;

public class lll {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        int p = input.nextInt();
        int[][] arr = new int[m][2];
        int index = n;
        for (int i=0;i<m;i++) {
            arr[i][0] = input.nextInt();
            arr[i][1] = input.nextInt();
            if (arr[i][0]==p)
                index--;
        }
        for (int i=1;i<=index;i++)
            System.out.print(i+" ");
    }
}

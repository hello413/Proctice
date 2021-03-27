package java_0317;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //[[2,3,5,9],[8,1,3,4],[5,0,6,1],[8,8,4,3]]
        Scanner input = new Scanner(System.in);
        String lines = input.nextLine();
        String[] line = lines.substring(1,lines.length()-2).split("],");
        int[][] arr = new int[line.length][line[0].substring(1).split(",").length];
        for (int i=0;i<arr.length;i++){
            String[] temp = line[i].substring(1).split(",");
            for (int j=0;j<temp.length;j++){
                arr[i][j] = Integer.parseInt(temp[j]);
            }
            System.out.println();
        }
        System.out.println(minPathSum(arr));
    }

    public static int minPathSum(int[][] arr){
        if (arr.length==0)return 0;
        int[][] dp = new int[arr.length][arr[0].length];
        for (int i=0;i<dp.length;i++){
            for (int j=0;j<dp[0].length;j++){
                if (i==0&&j!=0){
                    dp[i][j]=dp[i][j-1]+arr[i][j];
                }else if (j==0&&i!=0){
                    dp[i][j]=dp[i-1][j]+arr[i][j];
                }else if (i==0&&j==0){
                    dp[i][j] = arr[i][j];
                }else {
                    dp[i][j]=Math.min(dp[i][j-1],dp[i-1][j])+arr[i][j];
                }
            }
        }
        return dp[dp.length-1][dp[0].length-1];
    }
}

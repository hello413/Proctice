package java_0317;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        String count = input.next();
        char[] chars = count.toCharArray();
        int[] arr = new int[chars.length];
        for (int i=0;i<arr.length;i++) {
            arr[i] = chars[i] - '0';
        }
        System.out.println(getMIN(N,arr));
    }
    public static int getMIN(int N,int[] nums){
        int[] dp1 = new int[10];
        Arrays.fill(dp1,Integer.MAX_VALUE);
        int[] dp = new int[nums.length];
        dp[0] = 0;
        dp1[nums[0]]=0;
        for (int i=1;i<nums.length;i++){
            dp[i] = Math.min(dp[i-1],dp1[nums[i]])+1;
            dp1[nums[i]] = Math.min(dp1[nums[i]],dp[i]);
        }
        return dp[N-1];
    }
}

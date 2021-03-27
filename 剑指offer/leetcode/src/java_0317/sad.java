package java_0317;

import java.util.Scanner;

public class sad {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String s = input.next();
        String t = input.next();
        int k = input.nextInt();
        if (canConvertString(s,t,k))
            System.out.println(0);
    }

    public static boolean canConvertString(String s,String t,int k){
        if (s.length()!=t.length()){
            return false;
        }
        int[] count = new int[26];
        int length = s.length();
        for (int i=0;i<length;i++){
            int diff = t.charAt(i)-s.charAt(i);
            if (diff<0){
                diff+=26;
            }
            count[diff]++;
        }
        for (int i=1;i<26;i++){
            int maxCon = i+26*(count[i]-1);
            if (maxCon>k)return false;
        }
        return true;
    }
}

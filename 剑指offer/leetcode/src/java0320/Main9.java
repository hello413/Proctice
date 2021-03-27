package java0320;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main9 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        char[] s = input.next().toCharArray();
        exchangeArr(s);
        System.out.println(String.valueOf(s));
    }
    public static void exchangeArr(char[] s){
        int j=s.length-1;
        for (int i=0;i<s.length/2;i++){
            for (;j>i;j--){
                if (s[i]>s[j]){
                    char temp = s[i];
                    s[i] = s[j];
                    s[j]= temp;
                    break;
                }
            }
        }
    }
}
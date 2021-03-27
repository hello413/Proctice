package java0318;

import java.util.Scanner;

public class Main {
    static int calcSimilarity(String name1, String name2) {
        String[] arr = name1.split(" ");
        String[] brr = name2.split(" ");
        int count = 0;
        for (int i = 0; i < arr.length && i < brr.length; i++) {
            String n1 = arr[i];
            String n2 = brr[i];
            if (n1.equals(n2))continue;
            count += getAsc(n1, n2);
        }
        return count;
    }

    private static int getAsc(String n1, String n2) {
        int i=0;
        int temp = 0;
        for (; i < n1.length() && i < n2.length(); i++) {
            char c1 = n1.charAt(i);
            char c2 = n2.charAt(i);
            if (c1!=c2){
                temp+=(c1+c2);
            }
        }
        for (;i<n1.length();i++){
            temp+=n1.charAt(i);
        }
        for (;i<n2.length();i++){
            temp+=n2.charAt(i);
        }
        return temp;
    }

    /******************************结束写代码******************************/


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextLine()) {
            String name1 = in.nextLine();
            String name2 = in.nextLine();

            int sum = calcSimilarity(name1, name2);
            System.out.println(sum);
        }
    }
}

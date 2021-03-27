package java0320;

import java.util.Scanner;

public class Main3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        char[] arr = input.next().toCharArray();
        String target = input.next();
        int index = 0;
        int arrIndex = 0;
        int count = 0;
        while (index<target.length()){
            for (;index<target.length()&&arrIndex<26;arrIndex++){
                if (target.charAt(index)==arr[arrIndex]){
                    index++;
                    continue;
                }else {
                    count++;
                }
            }
            if (arrIndex==26)arrIndex=0;
        }
        System.out.println(count);
    }
}

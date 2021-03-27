package java0320;

import java.util.Scanner;

public class Main1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        int start = 0;
        int end = 0;
        while (num-->0){
            String[] temp = input.next().split(",");
            int[] arr = {Integer.parseInt(temp[0]),Integer.parseInt(temp[1])};
            start = end;



        }
        System.out.println(end);
    }
}

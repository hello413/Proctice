package java_0317;

import java.util.Scanner;

public class kk {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String[] lines = input.nextLine().split(",  ");
        String[] arr = lines[0].substring(1,lines[0].length()-1).split("\\.");
        String[] brr = lines[1].substring(1,lines[0].length()-1).split("\\.");
        System.out.println(compareVer(arr,brr));
    }

    private static int compareVer(String[] arr, String[] brr) {
        int min = Math.min(arr.length,brr.length);
        boolean Arr = arr.length>brr.length?true:false;
        int i=0;
        for (;i<min;i++){
            if (Integer.parseInt(arr[i])>Integer.parseInt(brr[i])){
                return 1;
            }else if (Integer.parseInt(arr[i])<Integer.parseInt(brr[i])){
                return -1;
            }
        }
        if (Arr){
            for (;i<arr.length;i++){
                if (Integer.parseInt(arr[i])!=0){
                    return 1;
                }
            }
        }else {
            for (;i<arr.length;i++){
                if (Integer.parseInt(brr[i])!=0){
                    return -1;
                }
            }
        }
        return 0;
    }
}

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();
        String[] nums = new String[n];
        for (int i=0;i<n;i++) {
            nums[i] = sc.next();
        }
        for (int i=0;i<n;i++){
            toEight(nums[i]);
            System.out.println();
        }
    }
    public static void toEight(String ch){
        char[] arr = ch.toCharArray();
        int leng=arr.length,i=0;
        char[] twoarr = new char[4*leng];
        while (leng--!=0){
            if (arr[leng]>='A'&&arr[leng]<='F'){
                int temp=arr[leng]-'A'+10;
                while (temp!=0){
                    twoarr[i++]=(char)(temp%2+'0');
                    temp/=2;
                }
            }else if (arr[leng]>='0'&&arr[leng]<='9'){
                int temp=arr[leng]-'0',num=0;
                while (temp!=0){
                    twoarr[i++]=(char)(temp%2+'0');
                    temp/=2;
                    num++;
                }
                while(num++!=4){
                    twoarr[i++]='0';
                }
            }
        }
        char[] eightarr=null;
        if (twoarr.length%3!=0) {
            eightarr = new char[twoarr.length / 3 + 1];//向上取整
        }else {
            eightarr = new char[twoarr.length / 3];//向上取整Math.ceil
        }
        int num=0,j=0;
        i=0;
        while (twoarr.length%3!=0){
            twoarr= Arrays.copyOf(twoarr,twoarr.length+1);
            twoarr[twoarr.length-1]='0';
        }
        while (i!=eightarr.length){
            eightarr[i++]=(char) ((twoarr[j++]-'0')+2*(twoarr[j++]-'0')+4*(twoarr[j++]-'0')+'0');
        }
        if (eightarr[--i]=='0'){
            i--;
        }
        for (;i>=0;i--){
            System.out.print(eightarr[i]);
        }
    }
}
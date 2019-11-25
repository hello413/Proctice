/*给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转*/
package com.itheima.demo;

public class HelloWorld {
    public static int reverse(int x) {
        System.out.println(x);
        if (x<-Math.pow(2,31)||x>Math.pow(2,31)-1)
            return 0;
        long num = 0;
        while(x!=0){
            num=num*10+x%10;
            x /= 10;
            if (num<-Math.pow(2,31)||num>Math.pow(2,31)-1)
            {
                return 0;
            }
        }
        return (int)num;
    }
    public static void main(String[] args){
        int []A={4,2,5,7};
        System.out.println(reverse(1534236469));
    }

}

package com.itheima.demo;
/*给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式*/
public class HelloWorld {

    public static String multiply(String num1, String num2) {
        if(num1.equals("0")||num2.equals("0")){
            return "0";
        }
        int []arr=new int[num1.length()+num2.length()];
        num1 = new StringBuffer(num1).reverse().toString();
        num2 = new StringBuffer(num2).reverse().toString();

        for (int i = 0; i < num1.length(); i++) {
            for (int j = 0; j < num2.length(); j++) {
                arr[i+j] += (num1.charAt(i)-'0')*(num2.charAt(j)-'0');
            }
        }
        int cf =0;  //进位
        for(int i = 0;i < arr.length;i++){
            arr[i] = cf+arr[i];
            cf = arr[i]/10;
            arr[i] %= 10;
        }
        int len = 0;
        if(arr[arr.length-1] == 0){  //判断是否有进位
            len = arr.length-2;
        }else{
            len = arr.length-1;
        }
        String str="";
        for (int i=len;i>=0;i--){
            str += arr[i];
        }
        return str;
    }
    public static String getType(Object o){ //获取变量类型方法
        return o.getClass().toString(); //使用int类型的getClass()方法
    }
    public static void main(String[] args){
        String num1="23";
        String num2="21";
        //System.out.println(num1);
        //multiply(num1,num2);
        System.out.println(multiply(num1,num2));
    }

}

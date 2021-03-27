package java_0313;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class main {
    public static void main(String[] args) {
        String a="love23next234csd9n3423javaeye";
        String regEx="[A-Za-z]";
        Pattern p = Pattern.compile(regEx);
        Matcher m = p.matcher(a);
        String[] trim = m.replaceAll(" ").trim().split("\\s+");
        int[] arr = new int[trim.length];
        for (int i=0;i<trim.length;i++){
            arr[i] = Integer.parseInt(trim[i]);
        }
        Arrays.sort(arr);
        for (int s:arr){
            System.out.println(s);
        }
//        String str="love23next234csd1n3423javaeye";
//        ArrayList<Integer> lists = new ArrayList<Integer>();
//        for (int i=0;i<str.length();i++){
//            char ch = str.charAt(i);
//            if (ch>='0'&&ch<='9'){
//                String temp = "";
//                for (int j=i;j<str.length();j++){
//                    char c = str.charAt(j);
//                    if (c>='0'&&c<='9'){
//                        temp+=c;
//                    }else {
//                        i=j;
//                        lists.add(Integer.parseInt(temp));
//                        break;
//                    }
//                }
//            }
//        }
//        Object[] objects = lists.toArray();
//        Arrays.sort(objects);
//        for (Object i:objects){
//            System.out.println(i);
//        }
    }
}

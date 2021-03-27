package java_0317;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class da {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String lines = input.nextLine();
        String[] str = lines.substring(1, lines.length() - 1).split(",");
        List<List<String>> list = getSeq(str);
        System.out.print("[");
        for (int i=0;i<list.size();i++){
            List<String> l1 = list.get(i);
            System.out.print("[");
            for (int j=0;j<l1.size();j++){
                if (j==l1.size()-1){
                    System.out.print(l1.get(j));
                }else {
                    System.out.print(l1.get(j) + ",");
                }
            }
            if (i==list.size()-1){
                System.out.print("]");
            }else {
                System.out.print("],");
            }
        }
        System.out.println("]");
    }

    private static List<List<String>> getSeq(String[] str) {
        List<List<String>> list = new ArrayList<>();
        list.add(new ArrayList<String>());
        int index = 0;
        for (int i=0;i<str.length;i++){
            if (!str[i].equals("#")) {
                list.get(index).add(str[i]);
            }
            if (i==Math.pow(2,index+1)-2){
                index++;
                list.add(new ArrayList<String>());
            }
        }
        if (list.get(index).size()==0)list.remove(index);
        return list;
    }
}

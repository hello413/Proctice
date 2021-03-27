package java0320;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String line1 = input.nextLine();
        String line2 = input.nextLine();
        String[] oldArr = line1.split(",");
        String[] newArr = line2.split(",");
        Map<String,String> oldmap = new HashMap<>();
        List<String> list = new ArrayList<>();
        for (String str: oldArr){
            String[] temp = str.split("-");
            oldmap.put(temp[0],temp[1]);
        }

        for (String str:newArr){
            String[] temp = str.split("-");
            if (oldmap.containsKey(temp[0])){
                if (!oldmap.get(temp[0]).equals(temp[1])){
                    list.add("modify-"+temp[0]);
                    oldmap.remove(temp[0]);
                }else {
                    oldmap.remove(temp[0]);
                    continue;
                }
            }else {
                list.add("add-"+temp[0]);
            }
        }
        for (String str:oldmap.keySet()){
            list.add("delete-"+str);
        }
        for (int i=0;i<list.size();i++){
            if (i!=list.size()-1) {
                System.out.print(list.get(i)+",");
            }else {
                System.out.print(list.get(i));
            }
        }
    }
}

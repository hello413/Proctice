package java0318;

import java.io.IOException;
import java.util.*;

public class Main1 {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        Map<String, List<String>> map = new HashMap<>();
        String str = "";
        while (in.hasNextLine()) {
            String line = in.nextLine();
            if (line.substring(0, 5).equals("dict:")) {
                String temp = line.substring(5);
                String[] arr = temp.split(":");
                List<String> li = new ArrayList<>();
                String[] strs = arr[1].split(",");
                for (String s : strs) {
                    li.add(s);
                }
                map.put(arr[0], li);
            } else if (line.substring(0, 6).equals("query:")) {
                str = line.substring(7);
                break;
            }
        }
        int i = 0, j = 1;
        while (i < str.length() && j < str.length()+1) {
            String index = str.substring(i, j);
            boolean bool = false;
            for (String s : map.keySet()) {
                if (map.get(s).contains(index)) {
                    System.out.println(index + ":[" + s + "]");
                    bool = true;
                    break;
                }
            }
            if (!bool){
                j++;
            }else {
                i = j;
                j = j + 1;
            }
            if (j==str.length()+1){
                i++;
                j=i+1;
            }
        }
    }
}

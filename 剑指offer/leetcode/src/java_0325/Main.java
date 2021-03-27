package java_0325;

import java.util.Stack;

public class Main {
    public String compressString (String str) {
        // write code here
        char[] chars = str.toCharArray();
        StringBuffer sb = new StringBuffer("");
        int num = 1;
        for (int i=0;i<chars.length;i++){
            if (i==0){
                sb.append(chars[i]);
            }else {
                if (chars[i]==chars[i-1]){
                    num++;
                }else {
                    sb.append(num+""+chars[i]);
                    num=1;
                }
            }
        }
        sb.append(num);
        return sb.toString().length()>=str.length()?str:sb.toString();
    }

    public int maxChunksToSorted (int[] arr) {
        // write code here
        Stack<Integer> stack = new Stack<>();
        for (int num:arr){
            if (!stack.empty()&&num<stack.peek()){
                int head = stack.pop();
                while (!stack.empty()&&num<stack.peek()){
                    stack.pop();
                }
                stack.push(head);
            }else {
                stack.push(num);
            }
        }
        return stack.size();
    }
}

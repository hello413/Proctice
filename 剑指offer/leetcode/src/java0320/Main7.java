package java0320;

import java.util.Scanner;
import java.util.Stack;

public class Main7 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double m0 = input.nextInt();
        double w0 = input.nextInt();
        double x0 = m0*w0/100;
        int n = input.nextInt();
        Stack<String> stack = new Stack<>();
        stack.push(m0+" "+w0+" "+x0);
        while (n-->0){
            String pop = stack.peek();
            String next = input.next();
            if (next.equals("A")){
                double m = input.nextInt();
                double w = input.nextInt();
                String[] s = pop.split(" ");
                double newM = m+ Integer.parseInt(s[0]);
                double newX = Double.parseDouble(s[2])+m*w/100;
                double newW = newX/newM*100;
                System.out.printf("%s %.5f",newM,newW);
                System.out.println();
                stack.push(newM+" "+newW+" "+newX);
            }else {
                if (stack.size()>1) {
                    stack.pop();
                }
                String peek = stack.peek();
                String[] s = peek.split(" ");
                System.out.printf("%s %.5f",s[0],Double.parseDouble(s[1]));
                System.out.println();
            }
        }
    }
}

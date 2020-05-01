package java_0430;

import java.util.HashSet;
import java.util.Set;

public class Solution202 {
    public boolean isHappy(int n) {
        Set<Integer> set = new HashSet<>();
        while (n!=1&&!set.contains(n)){
            set.add(n);
            n=getNext(n);
        }
        return n==1;
    }

    private int getNext(int n) {
        int sum = 0;
        while (n>0){
            sum+=Math.pow(n%10,2);
            n/=10;
        }
        return sum;
    }

}

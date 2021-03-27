public class Main{
    public static void main(String[] args){
        String str = "abcabc";
        System.out.println(isSame(str));
    }
    public static boolean isSame(String str){
        if(str.length()<=1){
            return false;
        }
        int time = 1;
        int length = str.length();
        while(time<length){
            if(length%(time+1)==0){
                boolean flag = true;
                int par_length = length/(time+1);
                for (int i=1;i<=time;i++) {
                    for (int j = 0; j < time; j++) {
                        if (str.charAt(j) != str.charAt(j + i * par_length)) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) {
                        break;
                    }
                }
                if(flag){
                    return true;
                }
            }
            time++;
        }
        return false;
    }
}
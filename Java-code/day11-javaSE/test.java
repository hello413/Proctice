package test;

import java.util.ArrayList;

/*定义一个方法，要求此方法把int数组转成存有相同元素的集合(集合里面的元素是Integer)，并返回。
## 四、Collection集合集合转数组
> 定义一个集合，并把集合(集合里面的元素是Integer)转成存有相同元素的数组，并将结果输出在控制台。（可以使用Object[]数组类型接收转换的数组）
## 五：Collection集合contains()方法使用
> 定义一个方法listTest(ArrayList<String> al, String s),要求使用contains()方法判断al集合里面是否包含s。
## 六：Collection集合isEmpty()方法的使用
> 定义一个方法listTest(ArrayList<String> al), 要求使用isEmpty()判断al里面是否有元素。
## 七、请简述迭代器的实现原理
>
## 八：Collection集合返回首次出现索引
>八、定义一个方法listTest(ArrayList<Integer> al, Integer s)，要求返回s在al里面第一次出现的索引，如果s没出现过返回-1。
*/
public class test {
    public static void main(String[] args) {
//        ArrayList<String> list = new ArrayList();
//        list.add("a");
//        list.add("a");
//        list.add("he");
//        list.add("ll");
//        list.add("0");
//        int a=listTest1(list,"a");
//        System.out.println(a);
//        int[] arr={1,2,3,4};
//        ArrayList<Integer> Arr=listTest2(arr);
//        System.out.println(Arr);
        ArrayList<String> list = new ArrayList<>();
        list.add("1");list.add("2");list.add("3");list.add("4");
//        listTest3(list);
//        for (String i:arr){
//            System.out.println(i);
//        }
//        listTest4(list,"1");
        int a= listTest6(list,"2");
        System.out.println(a);
    }

    private static int listTest6(ArrayList<String> list, String s) {
        for (int i=0;i<list.size();i++){
            if (list.get(i).equals(s)){
                return i;
            }
        }
        return -1;
    }

    private static void listTest5(ArrayList<String> list) {
        boolean boo = list.isEmpty();
        System.out.println(boo);
    }

    private static void listTest4(ArrayList<String> list, String s) {
        boolean boo = list.contains(s);
        System.out.println(boo);
    }

    private static String[] listTest3(ArrayList<String> list) {
        String[] arr=new String[list.size()];
        list.toArray(arr);
        return arr;
    }

    private static ArrayList listTest2(int[] arr) {
        ArrayList<Integer> Arr =new ArrayList<>();
        for (int x:arr){
            Arr.add(x);
        }
        return Arr;
    }

    private static int listTest1(ArrayList<String> list, String a) {
        int num=0;
        for (String str:list){
            if (str.equals(a)){
                num++;
            }
        }
        return num;
    }
}

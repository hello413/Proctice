package java_0505;

import java.lang.reflect.Field;

class Node{
    private int key = 25;
}
public class compare {
    public static void main(String[] args) throws NoSuchFieldException, IllegalAccessException {
        Node node = new Node();
        Class node_class = node.getClass();
        Field keyfile = node_class.getDeclaredField("key");
        keyfile.setAccessible(true);
        int key =(int) keyfile.get(node);
        System.out.println(key);
    }
}

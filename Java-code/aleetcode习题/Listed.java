import javax.print.DocFlavor;
import java.util.*;
import java.util.List;

class MyLinkedList {
    private int val;
    private MyLinkedList next = null;
    /** Initialize your data structure here. */
    public MyLinkedList() {

    }

    public MyLinkedList(int val) {
        this.val = val;
    }

    public int size(){
        int i = 0;
        for (MyLinkedList cur=this;cur!=null;cur=cur.next){
            i++;
        }
        return i;
    }
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if (index<0||index>size()){
            return -1;
        }
        int i = 0;
        for (MyLinkedList cur=this;cur!=null;cur=cur.next){
            if (i==index){
                return cur.val;
            }
            i++;
        }
        return -1;
    }
    private boolean first =true;
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        if (first){
            this.val=val;
            first=false;
            return;
        }
        MyLinkedList cur=new MyLinkedList(this.val);
        cur.next=this.next;
        this.val=val;
        this.next=cur;
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        if (first){
            this.val=val;
            first=false;
            return;
        }
        MyLinkedList cur=this;
        while (cur.next!=null){
            cur=cur.next;
        }
        cur.next=new MyLinkedList(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index<=0){
            addAtHead(val);
            return;
        }
        if (index == size()){
            addAtTail(val);
            return;
        }
        if (index>size()){
            return;
        }
        int i = 0;
        MyLinkedList prev=this;
        while(prev!=null){
            if (i==index-1){
                MyLinkedList cur = new MyLinkedList(val);
                cur.next=prev.next;
                prev.next=cur;
                return;
            }
            i++;
            prev=prev.next;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (index<0||index>=size()){
            return;
        }
        if (size()==1&&index==0){
            this.val=0;
            this.next=null;
            return;
        }
        if(index==0){
            this.val=this.next.val;
            this.next=this.next.next;
        }
        MyLinkedList cur = this;
        int i=0;
        while(cur!=null){
            if (i==index-1){
                cur.next=cur.next.next;
                return;
            }
            cur=cur.next;
            i++;
        }
    }
}

public class Listed {
    public static void main(String[] args){
//        int[][] grid = {{1,2,3},{4,5,6},{7,8,9}};
//        int[] A = {10,-10,10,-10,10,-10,10,-10};
        MyLinkedList linkedList = new MyLinkedList();
        linkedList.addAtHead(2);
        linkedList.deleteAtIndex(0);  //现在链表是1-> 3
    }
}
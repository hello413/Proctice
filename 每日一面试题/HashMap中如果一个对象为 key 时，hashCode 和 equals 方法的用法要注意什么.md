## HashMap中如果一个对象为 key 时，hashCode 和 equals 方法的用法要注意什么？

**问题描述**：

​		HashMap 了解不，介绍一下，如果一个对象为 key 时，hashCode 和 equals 方法的用法要注意什么？

---

 **hashcode()和equals()都继承于object** 

####  **1.hashcode()和equals()是在哪里被用到的？什么用的？** 

HashMap是基于散列函数，以数组和链表/红黑树的方式实现的。

 而对于每一个对象，通过其hashCode()方法可为其生成一个整形值（散列码），该整型值被处理后，将会作为数组下标，存放该对象所对应的Entry（存放该对象及其对应值）。

 equals()方法则是在HashMap中插入值或查询时会使用到。当HashMap中插入  值或查询值对应的散列码与数组中的散列码相等时，则会通过equals方法比较key值是否相等，所以想以自建对象作为HashMap的key，必须重写 该对象继承object的equals方法。

#### **2.本来不就有hashcode()和equals()了么？干嘛要重写，直接用原来的不行么？**

```java
Student st1 = new Student("wei","man");

Student st2 = new Student("wei","man"); 
```

正常理解这两个对象再存入到hashMap中应该是相等的，但如果你不重写 hashcode（）方法的话，比较是其地址，不相等！

 HashMap中的比较key是这样的，先求出key的hashcode(),比较其值是否相等，若相等再比较equals(),若相等则认为他们是相等的。若equals()不相等则认为他们不相等。如果只重写hashcode()不重写equals()方法，当比较equals()时只是看他们是否为同一对象（即进行内存地址的比较）,所以必定要两个方法一起重写。HashMap用来判断key是否相等的方法，其实是调用了HashSet判断加入元素 是否相等。 
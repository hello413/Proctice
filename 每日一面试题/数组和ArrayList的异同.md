##  数组和ArrayList的异同

**问题描述**	 

​	谈谈数组和ArrayList的异同，以及ArrayList的特点，知道其扩容是怎么扩的吗？ 

---

这个问题当初在面经上碰到还真没怎末在意，但我仔细一想，又很回答的不是令人很满意，所有就好好总结下...

---

**Array**和**ArrayList**的区别

​	首先不难想到这几点

  1. 数组定义时，数组的大小需要确定，很容易造成数组溢出或内存浪费，而ArrayList的大小就不需要确定了，它的大小是按照其中存储的数据来动态扩充与收缩的 

  2.   Array只能存储同种类型的数据，而ArrayList可以存储其他类型的数据。  

     ```
     int[] array = new int[5];	//只能存int类型
     
     ArrayList list = new ArrayList();
     list.add(1);
     list.add(true);
     list.add("hello");
     ```

     > 具体ArrayList可通过泛型来规范其类型

---

**分析**	本来我认为ArrayList底层上也是通过数组实现的，应该和数组一样在内存上是连续存储的，它有两个变量 DEFAULT_CAPACITY和size,通过size/DEFAULT_CAPACITY的比值，来实现扩容，有点像哈希因子是1的哈希表，具体可看源代码分析

![1588659917203](C:\Users\雷金鹏\AppData\Roaming\Typora\typora-user-images\1588659917203.png)

后来我翻了下官方文档，**文档上倒是没明确要求必须用 数组 实现**. 这个就不能排除其他的 JVM 的实现方式了. 但一般咱们常用的Oracle JDK 和 open JDK 对应的 Hotspot 虚拟机, 就是用数组实现的

故他们还有一个不同点

	3. 在Oracle JDK 和 open JDK中，ArrayList和数组都是在内存上连续存储

---

**Array**和**ArrayList**的相同之处

- 都具有索引(index),即可以通过index来直接获取和修改任意项。
- 他们引用保存在栈上, 所创建的对象都放在堆中。
- 都能够对自身进行枚举(因为都实现了IEnumerable接口)。 





 
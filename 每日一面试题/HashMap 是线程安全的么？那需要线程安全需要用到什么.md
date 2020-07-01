## HashMap 是线程安全的么？那需要线程安全需要用到什么？

**问题描述**：

​		HashMap 是线程安全的么？那需要线程安全需要用到什么？

---

**首先肯定HashMap是线程不安全的**

---

​	在jdk1.7的时候，头插法，两个缺点(环形死循环（扩容时），数据丢失(put时))

​	jdk1.8， 尾插法，一个缺点(数据丢失)

---

### 如何线程安全的使用HashMap

了解了HashMap为什么线程不安全，那现在看看如何线程安全的使用HashMap。这个无非就是以下三种方式：

- Hashtable
- **ConcurrentHashMap**（推荐）
- Synchronized Map

```
//Hashtable
Map hashtable = new Hashtable<>();
 
//synchronizedMap
Map synchronizedHashMap = Collections.synchronizedMap(new HashMap());
 
//ConcurrentHashMap
Map concurrentHashMap = new ConcurrentHashMap<>();
```

##### Hashtable

​	 HashTable源码中是使用大量的`synchronized`来保证线程安全的 ，相对效率低，举个例子，当一个线程使用put方法时，另一个线程不但不可以使用put方法，连get方法都不可以

##### ConcurrentHashMap

 利用CAS算法  ，继承 ReentrantLock 来进行加锁 

##### SynchronizedMap

 实际上是在Collections类中维护了一个静态内部类SynchronizedMap，该内部类中维护了一个普通的map和一个对象排斥锁mutex 
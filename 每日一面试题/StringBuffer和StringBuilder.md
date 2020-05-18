## StringBuffer和StringBuilder

**问题描述**：

​		StringBuffer和StringBuilder有什么区别，底层实现上呢？

---

> StringBuffer 与 StringBuilder 中的方法和功能完全是等价的。

​		**StringBuffer** 中的方法大都采用了 **synchronized** 关键字进行修饰，因此是**线程安全**的；
  	**StringBuilder** 没有这个修饰，可以被认为是**线程不安全**的。  

​	但是在安全的要求肯定带着一些条件，在单线程程序下，StringBuilder效率更快，因为它不需要加锁，不具备多线程安全;而StringBuffer则每次都需要判断锁，效率相对更低.


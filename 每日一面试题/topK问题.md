## topK问题

**问题描述**：

从arr[1, n]这n个数中，找出最大的k个数，这就是经典的TopK问题。

---

##### 一、暴力点，直接全局排序

如：	从arr[1, 12]={5,3,7,1,8,2,9,4,7,2,6,6} 这n=12个数中，找出最大的k=5个。

这种思路没啥好分析的，就是直接全局排序，然后前k大的数字

代码:

```java
sort(arr);
return arr[0,k];
```

**时间复杂度**：O(n*log(n))

**分析**：明明只需要TopK，却将全局都排序了，这也是这个方法复杂度非常高的原因。那能不能    <font color=red>不全局排序，而只局部排序</font>呢？这就引出了第二个优化方法。

---

##### 二、 **局部排序**

思路：冒泡排序（通过相邻数的比较，把无序最大值放在有序后面）

代码

```
for(int i = 0;i<k;i++)
	exchange(max,index);
return arr[0,k];
```

**时间复杂度**：O(k*n)

 **分析**：冒泡，将全局排序优化为了局部排序，非TopK的元素是不需要排序的，节省了计算资源。不少朋友会想到，需求是TopK，是不是<font color=red>这最大的k个元素也不需要排序</font>呢？这就引出了第三个优化方法。 

---

##### 三、堆排序

 **思路**：只找到TopK，不排序TopK。

>  先用前k个元素生成一个小顶堆，这个小顶堆用于存储，当前最大的k个元素。 
>
> 接着从第k+1个数 开始扫描，和堆顶（堆中最小的元素）比较，如果被扫描的元素大于堆顶，则替换堆顶的元素，并调整堆，以保证堆内的k个元素，总是当前最大的k个元素。 
>
>  直到，扫描完所有n-k个元素，最终堆中的k个元素，就是猥琐求的TopK。 

伪代码

```
createheap(arr,0,k);
for(int i = k;i<n;i++)
	if(arr[i]>heaphead(arr)){
		exchange(arr,i,0);
		shiftdown(arr,0,k);
	}
return arr[0,k];
```
代码

```
public class Heap {
    public void heapsort(int[] arr,int k){
        createheap(arr,0,k-1);
        for (int i=k;i<arr.length;i++){
            if (arr[0]<arr[i]){
                exchange(arr,0,i);
                createheap(arr,0,k);
            }
        }
        for (int i=0;i<k;i++){
            System.out.print(arr[i]+" ");
        }
    }

    private void createheap(int[] arr, int index, int k) {
        for (int i = (k-1)/2;i>=0;i--){
            shiftdown(arr,0,k);
        }
    }

    private void shiftdown(int[] arr, int index, int k) {
        int left = 2*index+1;
        while (left<k){
            int right = left+1;
            int min = (arr[left]<arr[right])?left:right;
            if (arr[index]>arr[min]){
                exchange(arr,index,min);
            }
            index=min;
            left=2*index+1;
        }
    }

    private void exchange(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i]= arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {95,6,78,15,6,1,2,4,33,5,7,21,15};
        new Heap().heapsort(arr,3);
    }
}
```
 ***\*时间复杂度\****：O(n*lg(k)) 

> *n个元素扫一遍，假设运气很差，每次都入堆调整，调整时间复杂度为堆的高度，即lg(k)，故整体时间复杂度是n\*lg(k)。* 
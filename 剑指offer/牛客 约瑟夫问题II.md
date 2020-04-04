
# 约瑟夫问题II

---
## 题目链接
---
<a href="https://www.nowcoder.com/practice/ff063da83b1a4d91913dd1b1e8b01466?tpId=8&&tqId=11045&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking">NowCoder</a>

## 题目描述
---


>约瑟夫问题是一个著名的趣题。这里我们稍稍修改一下规则。有n个人站成一列。并从头到尾给他们编号，第一个人编号为1。然后从头开始报数，第一轮依次报1，2，1，2...然后报到2的人出局。接着第二轮再从上一轮最后一个报数的人开始依次报1，2，3，1，2，3...报到2，3的人出局。以此类推直到剩下以后一个人。现在需要求的即是这个人的编号。

给定一个int n，代表游戏的人数。请返回最后一个人的编号

**测试样例**:
>输入：5
>返回：5



## 解题思路：
---

```java
import java.util.LinkedList;

public class Joseph {
    public int getResult(int n) {
        // write code here
        if (n<1){
            return -1;
        }
        LinkedList<Integer> list = new LinkedList<>();
        for (int i = 1;i <= n;i++){
            list.add(i);
        }
        int tem = 1;
        while (list.size()>1){
            tem++;
            int num = list.size(),j=0;
            for (int i = 0;i<num;i++){
                //当然可以写成i%tem+1!=0,这儿是省略了
                if (i%tem!=0){
                    list.remove(j);
                }else {
                    j++;
                }
            }
            if(list.size()>1){
                list.addFirst(list.removeLast());
            }
        }
        return list.remove(0);
    }
}

```


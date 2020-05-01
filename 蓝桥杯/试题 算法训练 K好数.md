## 试题 算法训练 K好数

 <b>问题描述</b>

​		如果一个自然数N的K进制表示中任意的相邻的两位都不是相邻的数字，那么我们就说这个数是K好数。求L位K进制数中K好数的数目。例如K =  4，L = 2的时候，所有K好数为11、13、20、22、30、31、33  共7个。由于这个数目很大，请你输出它对1000000007取模后的值。

---

 **输入格式**

输入包含两个正整数，K和L。

---

 **输出格式**

 输出一个整数，表示答案对1000000007取模后的值。 

---

 **样例输入**

> 4 2 

 **样例输出**

> 7 

---

**数据规模与约定**

对于30%的数据，KL <= 106；

对于50%的数据，K <= 16， L <= 10；

对于100%的数据，1 <= K,L <= 100。

---

**思路分析**

1. L位K进制数—— K进制数它的取值范围为[0，K-1]

2. **满足条件的2位4进制数：**

   ![1588297996631](C:\Users\雷金鹏\AppData\Roaming\Typora\typora-user-images\1588297996631.png)

   > 1 1、1 3 、2 0 、2 2 、 3 0、 3 1、 3 3

   **满足条件的3位4进制数：**

   > 1 1 1、1 1 3、
   >
   >  1 3 0、1 3 1 、1 3 3 
   >
   > 1 3 0、1 3 1 、1 3 3、
   >
   > 2 0 0、 2 0 2、 2 0 3、
   >
   > 2 2 0、 2 2 2、
   >
   > 3 0 0、 3 0 2、 3 0 3、
   >
   > 3 1 1、 3 1 3、
   >
   > 3 3 0、 3 3 1、 3 3 3

   ```
   不难发现这其实是个深度优先搜索，故采用 dp[i][j]=dp[i][j]+dp[i-1][k] 来做。 
   	i 代表所在的位数（i=0代表个位，i=1代表十位，以此类推）
   	j 代表取K进制数的一个数(如果是4进制数，那么j取[0,3]中的一个数)。
   	k和j同一个意思. 	
   ```

   <u>**即当前位置的数总数=当前位置的数的数目+前一个位置的数的总数。**</u>

代码实现：

```
import java.util.Scanner;

/**
 *http://lx.lanqiao.cn/problem.page?gpid=T13
 */
public class KWellNumber {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int K = input.nextInt();
        int L = input.nextInt();
        int value = numsOfknumber(K, L);
        System.out.println(value);
    }

    private static int numsOfknumber(int K, int L) {
        int count = 0;
        int[][] arr = new int[L][K];
        for (int i=0;i<K;i++)arr[0][i] = 1;
        for (int i=1;i<L;i++){
            for (int j=0;j<K;j++){
                for (int a = 0;a<K;a++){
                    if (a!=j+1&&a!=j-1){
                        arr[i][j]+=arr[i-1][a];
                        if (arr[i][j]>1000000007)
                            arr[i][j]-=1000000007;
                    }
                }
            }
        }
        for (int i=1;i<K;i++){
            count+=arr[L-1][i];
            if (count>1000000007)count-=1000000007;
        }
        return count;
    }
}

```


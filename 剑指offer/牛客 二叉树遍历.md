
# 猫狗收容所
---
## 题目链接
---
<a href="https://www.nowcoder.com/practice/6235a76b1e404f748f7c820583125c50?tpId=8&&tqId=11010&rp=3&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking">NowCoder</a>

## 题目描述
---

 有家动物收容所只收留猫和狗，但有特殊的收养规则，收养人有两种收养方式，第一种为直接收养所有动物中最早进入收容所的，第二种为选择收养的动物类型（猫或狗），并收养该种动物中最早进入收容所的。

   >给定一个操作序列int[][2] ope(C++中为vector<vector<int>>)代表所有事件。若第一个元素为1，则代表有动物进入收容所，第二个元素为动物的编号，正数代表狗，负数代表猫；若第一个元素为2，则代表有人收养动物，第二个元素若为0，则采取第一种收养方式，若为1，则指定收养狗，若为-1则指定收养猫。请按顺序返回收养的序列。若出现不合法的操作，即没有可以符合领养要求的动物，则将这次领养操作忽略。


###### 实例1：
>**输入**：[[1,1],[1,-1],[2,0],[2,-1]]
**返回**：[1,-1]



 


## 解题思路：
---

```java

import java.util.ArrayList;
import java.util.List;

public class CatDogAsylum {
    public ArrayList<Integer> asylum(int[][] ope) {
        // write code here
        List<Integer> asylum = new ArrayList<>();
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < ope.length; i++){
            if (ope[i][0] == 1){
                asylum.add(ope[i][1]);
            }else {
                switch (ope[i][1]){
                    case 0:
                        int temp = asylum.remove(0);
                        result.add(temp);
                        break;
                    case 1:
                        for (Integer k :asylum){
                            if (k>0){
                                asylum.remove(k);
                                result.add(k);
                                break;
                            }
                        }
                        break;
                    case -1:
                        for (Integer k :asylum){
                            if (k<0){
                                asylum.remove(k);
                                result.add(k);
                                break;
                            }
                        }
                        break;
                    default:
                        break;
                }
            }
        }
        return result;
    }
}
```


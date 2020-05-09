## MySQL分页查询方法及其优化

#####  **方法一：直接使用数据库提供的SQL语句** 

```
select * from student limit m, n;
```

适用场景：适用于**数据量较少**的情况(元组百/千级)

原因/缺点: **全表扫描**,速度会很慢 且 有的数据库**结果集返回不稳定**(如某次返回1,2,3,另外的一次返回2,1,3). limit限制的是从结果集的 m 位置处取出 n 条输出,其余抛弃.

> 其实在数据库select查询中好多都是涉及到全表查询，比如多表查询语句“select student_name from student,class where student_class_id = class_id and student_class_id<3;”,查询结果就是先利用笛卡尔积生成好多条记录然后再从中筛选满足条件的记录，所以在实际开发中尽量少用多表查询，一般都是利用索引来解决这些问题

#####  **方法二：建立主键或唯一索引，利用索引（假设每页2条）** 

思路： **利用MySQL支持order操作可以利用索引快速定位部分元祖，避免全表扫描**

例： 读第1000到1019行元组(pk是主键/唯一键). 

```
select * from your_table where pa >= 1000 order by pk asc limit 0,20;
```

例子：

```
select * from student where id_pk > (pageNum*10) limit m;//此时pageNum从0开始计数的
```

![1588943150012](C:\Users\雷金鹏\AppData\Roaming\Typora\typora-user-images\1588943150012.png)

适应场景: 适用于**数据量多**的情况(元组数上万)

原因: 索引扫描,速度会很快. 有朋友提出: 因为数据查询出来并不是按照pk_id排序的，所以会有漏掉数据的情况，只能方法3

#####  **方法三：基于索引再排序** 

```
select * from teacher where id_pk > (pageNum * 10) order by id_pk asc limit m;
```

适应场景: 适用于数据量多的情况(元组数上万). 最好 order by 后的列对象是主键或唯一索引,使得 order by 操作能利用索引被消除但结果集是稳定的(稳定的含义,参见方法1)

原因: 索引扫描,速度会很快. 

##### **方法四：基于索引使用prepare**

第一个问号表示pageNum，第二个问号表示每页元组数

```
prepare stmt_name from select * from teacher where id_pk > (? * ?) order by id_pk asc limit m;
```

适应场景: **大数据量**

原因: 索引扫描,速度会很快. prepare语句又比一般的查询语句快一点。
**注意**：
> 1. 导入驱动jar包
>> **导入关键要点击Add As Library,这个才是加入到项目中**
>>1. 驱动包版本高的话就用Class.forName("com.mysql.cj.jdbc.Driver");
>>2. 版本低则用Class.forName("com.mysql.jdbc.Driver"); 
> 2. 注册驱动
> 3. 获取数据库连接对象
> 4. 定义sql语句
> 5. 获取sql对象
> 6. 执行sql
> 7. 释放 
package cn.itcast.jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

/**
 *
 */
public class jdbcdemo01 {
    public static void main(String[] args) throws Exception {
        //1.注册驱动
        Class.forName("com.mysql.jdbc.Driver");
        //2.获取数据库连接对象
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/test","root","123456");
        //3.定义sql语句
        String sql="update note set like_num = 1 where n_id = 1";
        //获取sql对象
        Statement statement = connection.createStatement();
        //执行
        int count = statement.executeUpdate(sql);
        System.out.println(count);
        //释放
        statement.close();
        connection.close();
    }
}

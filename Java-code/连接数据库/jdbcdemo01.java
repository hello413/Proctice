package cn.itcast.jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

/**
 *
 */
public class jdbcdemo01 {
    public static void main(String[] args) throws Exception {
        //1.定义sql语句
        String sql="update note set like_num = 2 where n_id = 1";
        mysql(sql);
    }

    //执行DDL(库与表的操作)、DML(表数据的增删改)
    public static void mysql(String sql){
        Connection connection =null;
        Statement statement =null;
        try {
            //1.注册驱动
            Class.forName("com.mysql.jdbc.Driver");
            //2.获取数据库连接对象     驱动管理  //本地的话url也可简写成"jdbc:mysql:///test"
            connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/test","root","123456");
            //3.获取sql对象
            statement = connection.createStatement();
            //4.执行sql
            int count = statement.executeUpdate(sql);
            System.out.println(count);
            if(count>0){
                System.out.println("成功");
            }else {
                System.out.println("失败");
            }
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }catch (SQLException e) {
            e.printStackTrace();
        }finally {
            //5.释放资源
            if (statement!=null){
                try {
                    statement.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
            if (connection!=null){
                try {
                    statement.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

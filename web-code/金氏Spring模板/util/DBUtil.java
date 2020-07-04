package com.itpainter.util;

import com.mysql.jdbc.jdbc2.optional.MysqlDataSource;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DBUtil {

    private static final String URL = "jdbc:mysql://localhost:3306/blogdemo";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "root";

    /**
     * 创建数据库连接的方式：
     * 1.DriverManager：每次都是创建数据库物理连接，connection.close()关闭物理连接
     * 2.DataSource：初始化就创建一定数量的连接，connection.close()关闭只是重置连接对象，归还连接池
     * DataSource创建连接的方式，效率更好
     */
    private static volatile DataSource DATA_SOURCE;//volatile保证1可见性2禁止指令重排序、建立内存屏障

    private DBUtil(){}

    /**
     * 获取数据库连接池：使用双重校验锁的单例模式创建数据库连接池
     * 自己使用，不开放
     * @return
     */
    private static DataSource getDataSource(){
        if(DATA_SOURCE == null){//并发执行，提高效率
            synchronized (DBUtil.class){
                if(DATA_SOURCE == null){//保证只创建一次，满足单例同一对象的要求
                    DATA_SOURCE = new MysqlDataSource();
                    ((MysqlDataSource) DATA_SOURCE).setUrl(URL);
                    ((MysqlDataSource) DATA_SOURCE).setUser(USERNAME);
                    ((MysqlDataSource) DATA_SOURCE).setPassword(PASSWORD);
                }
            }
        }
        return DATA_SOURCE;
    }

    /**
     * 获取数据库连接：提供公共方法给其他地方操作jdbc时获取数据库连接
     * @return
     */
    public static Connection getConnection(){
        try {
            return getDataSource().getConnection();
        } catch (SQLException e) {
            throw new RuntimeException("获取数据库连接失败", e);
        }
    }

    /**
     * jdbc操作步骤：
     * （1）创建数据库连接
     * （2）创建操作命令对象Statement：
     *      Statement：简单sql语句的执行
     *      PreparedStatement：可以执行带参数的sql————（1）可以预编译，效率更高（2）防止一定程度的sql注入（单引号转义）
     * （3）执行sql
     * （4）如果是查询，处理结果集ResultSet
     * （5）释放资源（反向释放）
     */

    public static void close(Connection c, Statement s, ResultSet r){
        try {
            if(r != null)
                r.close();
            if(s != null)
                s.close();
            if(c != null)
                c.close();
        } catch (SQLException e) {
            throw new RuntimeException("关闭数据库连接失败", e);
        }
    }

    public static void close(Connection c, Statement s){
        close(c, s, null);
    }

}

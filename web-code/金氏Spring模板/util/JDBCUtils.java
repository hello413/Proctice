package com.itpainter.util;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;

/*
	1. 声明静态数据源成员变量
	2. 创建连接池对象
	3. 定义公有的得到数据源的方法
	4. 定义得到连接对象的方法
	5. 定义关闭资源的方法
 */
public class JDBCUtils {
    // 1.	声明静态数据源成员变量
    private static volatile DataSource DATA_SOURCE;

    public JDBCUtils() {
    }

    // 2. 创建连接池对象
    static {
//        // 加载配置文件中的数据
//        InputStream is = JDBCUtils.class.getClassLoader().getResourceAsStream("druid.properties");
//        Properties pp = new Properties();
//        try {
//            pp.load(is);
//            // 创建连接池，使用配置文件中的参数
//            DATA_SOURCE = DruidDataSourceFactory.createDataSource(pp);
//        } catch (IOException e) {
//            e.printStackTrace();
//        } catch (Exception e) {
//            e.printStackTrace();
//        }
    }

    // 3. 定义公有的得到数据源的方法
    public static DataSource getDataSource() {
        if (DATA_SOURCE == null) {//并发执行，提高效率
            synchronized (JDBCUtils.class) {
                if (DATA_SOURCE == null) {//保证只创建一次，满足单例同一对象的要求
                    InputStream is = JDBCUtils.class.getClassLoader().getResourceAsStream("druid.properties");
                    Properties pp = new Properties();
                    try {
                        pp.load(is);
                        // 创建连接池，使用配置文件中的参数
                        DATA_SOURCE = DruidDataSourceFactory.createDataSource(pp);
                    } catch (IOException e) {
                        e.printStackTrace();
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }
        }
        return DATA_SOURCE;
    }

    /**
     * jdbc操作步骤：
     * （1）创建数据库连接
     * （2）创建操作命令对象Statement：
     * Statement：简单sql语句的执行
     * PreparedStatement：可以执行带参数的sql————（1）可以预编译，效率更高（2）防止一定程度的sql注入（单引号转义）
     * （3）执行sql
     * （4）如果是查询，处理结果集ResultSet
     * （5）释放资源（反向释放）
     */
    // 4. 定义得到连接对象的方法
    public static Connection getConnection() throws SQLException {
        try {
            return getDataSource().getConnection();
        } catch (SQLException e) {
            throw new RuntimeException("获取数据库连接失败", e);
        }
    }

    // 5.定义关闭资源的方法
    public static void close(Connection conn, Statement stmt, ResultSet rs) {
        try {
            if (rs != null)
                rs.close();
            if (stmt != null)
                stmt.close();
            if (conn != null)
                conn.close();
        } catch (SQLException e) {
            throw new RuntimeException("关闭数据库连接失败", e);
        }
    }

    // 6.重载关闭方法
    public static void close(Connection conn, Statement stmt) {
        close(conn, stmt, null);
    }
}


package JDBCTest;

import com.mysql.jdbc.jdbc2.optional.MysqlDataSource;

import javax.sql.DataSource;
import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class JDBCtest {
    public static void main(String[] args) throws SQLException {
        DataSource dataSource = new MysqlDataSource();
        ((MysqlDataSource)dataSource).setURL("jdbc:mysql:///bit?useUnicode=true&characterEncoding=utf-8");
        ((MysqlDataSource)dataSource).setUser("root");
        ((MysqlDataSource)dataSource).setPassword("123456");
        Connection connection = null;
        PreparedStatement statement = null;
        try{
            connection = dataSource.getConnection();
            String sql = "insert into student values(?,?)";
            statement = connection.prepareStatement(sql);
            statement.setString(1,"1");
            statement.setString(2,"蔡徐坤");
            int ret = statement.executeUpdate();
            System.out.println(ret);
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            statement.close();
            connection.close();
        }

    }
}

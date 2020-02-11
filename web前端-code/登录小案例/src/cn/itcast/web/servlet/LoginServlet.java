package cn.itcast.web.servlet;

import cn.itcast.dao.UserDao;
import cn.itcast.domain.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/loginServlet")
public class LoginServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        User loginuser = new User(username,password);

        UserDao dao = new UserDao();//这儿有个问题，新建不了User,测试时又可以
        User user = dao.login(loginuser);

        if (user==null){
            System.out.println("没找到");
            request.getRequestDispatcher("/failServlet").forward(request,response);
        }else {
            request.setAttribute("user",user);
            System.out.println("找到了"+user);
            request.getRequestDispatcher("/successServlet").forward(request,response);
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request,response);
    }
}

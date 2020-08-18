package com.itpainter.web.servlet;

import com.itpainter.service.VisitorService;
import com.itpainter.service.impl.VisitorServiceImpl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/visitor/*")
public class VisitorServlet extends AbstractBaseServlet {
    private VisitorService service = new VisitorServiceImpl();

    public boolean regist(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        System.out.println("中国");
        if (1!=2){
            throw new RuntimeException("除了01");
        }
        return true;
    }

    public boolean login(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        System.out.println("真棒");
        return true;
    }
}

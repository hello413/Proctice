package com.itpainter.web.servlet;


import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.itpainter.domain.Info;
import com.itpainter.util.JSONUtil;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public abstract class AbstractBaseServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //System.out.println("baseServlet的service方法被执行了...");

        //完成方法分发
        //1.获取请求路径
        String uri = req.getRequestURI(); //   /travel/user/add
        System.out.println("请求uri:"+uri);//  /travel/user/add
        //2.获取方法名称
        String methodName = uri.substring(uri.lastIndexOf('/') + 1);
        //System.out.println("方法名称："+methodName);
        //3.获取方法对象Method
        //谁调用我？我代表谁
        //System.out.println(this);//UserServlet的对象cn.itcast.travel.web.servlet.UserServlet@4903d97e
        Info response=new Info();
        try {
            //获取方法
            Method method = this.getClass().getMethod(methodName, HttpServletRequest.class, HttpServletResponse.class);
            System.out.println(method+"----"+methodName);
            //4.执行方法
            //暴力反射
            //method.setAccessible(true);
            response.setData(method.invoke(this, req, resp));
            response.setFlag(true);
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            Throwable t = e.getTargetException();
            t.printStackTrace();
            response.setErrorMsg(t.getMessage());
        }catch (Exception e) {
            //出现异常  返回success=false，并设置异常信息，并设置
            e.printStackTrace();
            response.setErrorMsg(e.toString());
        }
        writeValue(response,resp);
    }

    /**
     * 直接将传入的对象序列化为json，并且写回客户端
     * @param obj
     * @param response
     * @throws IOException
     */
    public void writeValue1(Object obj,HttpServletResponse response) throws IOException {
        ObjectMapper mapper = new ObjectMapper();
        response.setContentType("application/json;charset=utf-8");
        mapper.writeValue(response.getOutputStream(),obj);
    }

    /**
     * 直接将传入的对象序列化为json字符串，并且写回客户端
     * @param obj
     * @throws IOException
     */
    public void writeValue(Object obj,HttpServletResponse resp) throws IOException {
        PrintWriter pw=resp.getWriter();
        pw.println(JSONUtil.serialize(obj));
        pw.flush();
    }
}

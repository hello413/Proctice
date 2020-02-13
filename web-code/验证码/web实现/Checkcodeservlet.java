package cn.itcast;

import javax.imageio.ImageIO;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Random;

@WebServlet("/checkcodeservlet")
public class Checkcodeservlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int width=100;
        int height=50;

        //1.创建一BufferedImage对象，规定图片格式
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_3BYTE_BGR);//红绿蓝

        //2.美化
        Graphics graphics = image.getGraphics();//画笔对象
        //2.1背景色
        graphics.setColor(Color.pink);
        graphics.fillRect(0,0,width,height);//方法作用：填充
        //2.2边框颜色
        graphics.setColor(Color.BLUE);
        graphics.drawRect(0,0,width-1,height-1);//方法作用：从坐标(0,0)到坐标(width,height)

        //2.3生成验证码
        String str="ABCDEFGHIGKLMNOPQRSTUVWXYZabcdefghigklmnopqrstuvwxyz0123456789";
        int size = 4;//生成验证码个数
        Random random = new Random();
        for (int i=1;i<=size;i++) {
            int index = random.nextInt(str.length());
            graphics.drawString(str.charAt(index) + "", width/(size+1)*i, height/2);
        }

        //2.4干扰线
        graphics.setColor(Color.GREEN);
        int nums = random.nextInt(5) + 6;
        for (int i=0;i<nums;i++){
            int x1 = random.nextInt(width);
            int x2 = random.nextInt(width);
            int y1 = random.nextInt(height);
            int y2 = random.nextInt(height);

            graphics.drawLine(x1,x2,y1,y2);
        }

        //3.展示
        ImageIO.write(image,"jpg",response.getOutputStream());
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request,response);
    }
}

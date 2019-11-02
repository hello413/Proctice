/*打印水仙花数
  统计水仙花数*/
public class shuixianhua {
	public static void main(String[] args) {
		int sum=0;
		for(int i=100;i<1000;i++)
			if(Math.pow(i%10, 3)+Math.pow(i%100/10, 3)+Math.pow(i/100, 3)==i){
				System.out.println(i);
				sum++;
			}
		System.out.println("数目为："+sum);
	}
}

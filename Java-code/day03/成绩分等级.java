import java.util.Scanner;
/*��д����ʵ���������ݣ�if���ʵ��
���Գɼ��ֵȼ���
	90~100	A�ȡ�
	80-89	B�ȡ�
	70-79	C�ȡ�
	60-69	D�ȡ�
	60����	E�ȡ�
����ݸ����ɼ��������Ӧ�ĵȼ���*/
public class score{
	public static void main(String[] args) {
		System.out.print("������ɼ���");
		int a=new Scanner(System.in).nextInt();
		if(a>90)System.out.println("A��");
		else if(a>80)System.out.println("B��");
		else if(a>70)System.out.println("C��");
		else if(a>60)System.out.println("D��");
		else System.out.println("E��");
	}
}
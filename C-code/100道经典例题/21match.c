#include<stdio.h>
/*����ƹ����ӽ��б������������ˡ��׶�Ϊa, b, c���ˣ��Ҷ�Ϊx, y, z���ˡ��ѳ�ǩ��������������
�������Ա����������������a˵������x�ȣ�c˵������x, z�ȣ��������ҳ�*/
int main()
{
	for (char a = 'x'; a <= 'z'; a++) {
		for (char b = 'x'; b <= 'z'; b++) {
			for (char c = 'x'; c <= 'z'; c++) {
				if (a != 'x' && c != 'x' && c != 'z' && a != b && a != c && b != c) { 
					printf("a vs %c       b vs %c     c vs %c\n", a, b, c);
				}
			}
		}
	}
	return 0;
}
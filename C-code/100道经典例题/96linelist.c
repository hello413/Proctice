#include <stdio.h>
#include <stdlib.h>

#define Size 5
typedef struct SeqList {
	int* head;//������һ����Ϊhead�ĳ��Ȳ�ȷ��������
	int length;//��¼��ǰ˳���ĳ���
	int size;//��¼˳������Ĵ洢����
}sqlt;
sqlt init_SeqList() {
	sqlt s;
	s.head = (int*)malloc(sizeof(int) * Size);
	if (!s.head)//�������ʧ�ܣ�������ʾ��ֱ���˳�����
	{
		printf("��ʼ��ʧ��\n");
		exit(0);
	}
	s.length = 0;//�ձ�ĳ��ȳ�ʼ��Ϊ0
	s.size = Size;//�ձ�ĳ�ʼ�洢�ռ�ΪSize
	return s;
}
//���뺯��������elemΪ�����Ԫ�أ�pΪ���뵽˳����λ��
sqlt insert_SeqList(sqlt s, int elem, int p)
{
	if (p > s.length + 1 || p < 1) {		//�������Ԫ��λ�ñ����ű�ĳ���+1���������ȣ���β��������
		printf("�����λ��������\n");
		return s;
	}
	//���������ʱ��������Ҫ��˳����Ƿ��ж���Ĵ洢�ռ��ṩ�������Ԫ�أ����û�У���Ҫ����
	if (s.length >= s.size) {
		s.head = (int*)realloc(s.head, (s.size + 1) * sizeof(int));
		if (!s.head) {
			printf("�洢����ʧ��\n");
		}
	}
	//�����������Ҫ���Ӳ���λ�ÿ�ʼ�ĺ���Ԫ�أ��������
	for (int i = s.length - 1; i >= p - 1; i--) {
		s.head[i + 1] = s.head[i];
	}
	//������ɺ�ֱ�ӽ��������Ԫ�أ���ӵ�˳������Ӧλ��
	s.head[p - 1] = elem;
	s.length++;
	return s;
}
sqlt del_SeqList(sqlt s, int p) {
	if (p > s.length || p < 1) {
		printf("��ɾ����Ԫ������\n");
		return s;
	}
	//ɾ������
	for (int i = p; i < s.length; i++) {
		s.head[i - 1] = s.head[i];
	}
	s.length--;//ɾ��һ��Ԫ�ر�ĳ���Ҫ��1
	return s;
}
//���Һ��������У�elem��ʾҪ���ҵ�����Ԫ�ص�ֵ
int select_SeqList(sqlt s, int elem) {
	for (int i = 0; i < s.length; i++) {
		if (s.head[i] == elem) {
			return i + 1;
		}
	}
	return -1;//�������ʧ�ܣ�����-1
}
//���ĺ��������У�elemΪҪ���ĵ�Ԫ�أ�newElemΪ�µ�����Ԫ��
sqlt amend_SeqList(sqlt s, int elem, int newElem) {
	int p = select_SeqList(s, elem);
	s.head[p - 1] = newElem;
	//���ڷ��ص���Ԫ����˳����е�λ�ã�����p-1���Ǹ�Ԫ���������е��±�
	return s;
}
//���˳�����Ԫ�صĺ���
void display_SeqList(sqlt s) 
{
	for (int i = 0; i < s.length; i++) {
		printf("%d", s.head[i]);
	}
	printf("\n");
}

int main() {
	sqlt s1 = init_SeqList();
	//��˳��������Ԫ��
	for (int i = 1; i <= Size; i++) {
		s1.head[i - 1] = i;
		s1.length++;
	}
	printf("ԭ˳���\n");
	display_SeqList(s1);

	printf("ɾ��Ԫ��2��\n");
	s1 = del_SeqList(s1, 2);
	display_SeqList(s1);

	printf("�ڵ�3��λ�ò���Ԫ��5��\n");
	s1 = insert_SeqList(s1, 5, 3);
	s1 = insert_SeqList(s1, 5, 3);
	s1 = insert_SeqList(s1, 5, 3);
	display_SeqList(s1);

	printf("����Ԫ��3��λ��:\n");
	int p = select_SeqList(s1, 3);
	printf("%d\n", p);

	printf("��Ԫ��3��Ϊ6:\n");
	s1 = amend_SeqList(s1, 3, 6);
	display_SeqList(s1);
	return 0;
}

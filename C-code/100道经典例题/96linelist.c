#include <stdio.h>
#include <stdlib.h>
 
#define Size 5
typedef struct SeqList {
	int* head;//声明了一个名为head的长度不确定的数组
	int length;//记录当前顺序表的长度
	int size;//记录顺序表分配的存储容量
}sqlt;
sqlt init_SeqList() {
	sqlt s;
	s.head = (int*)malloc(sizeof(int) * Size);
	if (!s.head)//如果申请失败，作出提示并直接退出程序
	{
		printf("初始化失败\n");
		exit(0);
	}
	s.length = 0;//空表的长度初始化为0
	s.size = Size;//空表的初始存储空间为Size
	return s;
}
//插入函数，其中elem为插入的元素，p为插入到顺序表的位置
sqlt insert_SeqList(sqlt s, int elem, int p)
{
	if (p > s.length + 1 || p < 1) {		//如果插入元素位置比整张表的长度+1还大（如果相等，是尾随的情况）
		printf("插入的位置有问题\n");
		return s;
	}
	//做插入操作时，首先需要看顺序表是否有多余的存储空间提供给插入的元素，如果没有，需要申请
	if (s.length >= s.size) {
		s.head = (int*)realloc(s.head, (s.size + 1) * sizeof(int));
		if (!s.head) {
			printf("存储分配失败\n");
		}
	}
	//插入操作，需要将从插入位置开始的后续元素，逐个后移
	for (int i = s.length - 1; i >= p - 1; i--) {
		s.head[i + 1] = s.head[i];
	}
	//后移完成后，直接将所需插入元素，添加到顺序表的相应位置
	s.head[p - 1] = elem;
	s.length++;
	return s;
}
sqlt del_SeqList(sqlt s, int p) {
	if (p > s.length || p < 1) {
		printf("被删除的元素有误\n");
		return s;
	}
	//删除操作
	for (int i = p; i < s.length; i++) {
		s.head[i - 1] = s.head[i];
	}
	s.length--;//删除一个元素表的长度要减1
	return s;
}
//查找函数，其中，elem表示要查找的数据元素的值
int select_SeqList(sqlt s, int elem) {
	for (int i = 0; i < s.length; i++) {
		if (s.head[i] == elem) {
			return i + 1;
		}
	}
	return -1;//如果查找失败，返回-1
}
//更改函数，其中，elem为要更改的元素，newElem为新的数据元素
sqlt amend_SeqList(sqlt s, int elem, int newElem) {
	int p = select_SeqList(s, elem);
	s.head[p - 1] = newElem;
	//由于返回的是元素在顺序表中的位置，所以p-1就是该元素在数组中的下标
	return s;
}
//输出顺序表中元素的函数
void display_SeqList(sqlt s) 
{
	for (int i = 0; i < s.length; i++) {
		printf("%d", s.head[i]);
	}
	printf("\n");
}

int main() {
	sqlt s1 = init_SeqList();
	//向顺序表中添加元素
	for (int i = 1; i <= Size; i++) {
		s1.head[i - 1] = i;
		s1.length++;
	}
	printf("原顺序表：\n");
	display_SeqList(s1);

	printf("删除元素2：\n");
	s1 = del_SeqList(s1, 2);
	display_SeqList(s1);

	printf("在第3的位置插入元素5：\n");
	s1 = insert_SeqList(s1, 5, 3);
	s1 = insert_SeqList(s1, 5, 3);
	s1 = insert_SeqList(s1, 5, 3);
	display_SeqList(s1);

	printf("查找元素3的位置:\n");
	int p = select_SeqList(s1, 3);
	printf("%d\n", p);

	printf("将元素3改为6:\n");
	s1 = amend_SeqList(s1, 3, 6);
	display_SeqList(s1);
	return 0;
}

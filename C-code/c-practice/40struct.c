#include<stdio.h>
/*ʹ�ýṹ�壨struct���洢ѧ����Ϣ��*/
#pragma warning(disable:4996);
struct students
{
	char name[10];
	int age;
	char sex;
	char id[10];
};
int main()
{
	struct students s = { "����", 20, "��", "20180101" };
	scanf("%s", s.name);
	s.age = 18;
	s.sex = 'm';
	printf("%s %d %c %s", s.name,s.age,s.sex,s.id);
	return 0;
}
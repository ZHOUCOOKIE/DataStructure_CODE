#include "contacts.h"
#include <stdio.h>
#include <stdlib.h>
void Menu()
{
	printf("--------------------����ͨѶ¼����ϵͳ----------------------------\n");
	printf("----------0����ʾ����ͨѶ¼--------1������ͨѶ¼------------------\n");
	printf("----------2�����ͨѶ¼��Ա--------3���޸�ͨѶ¼��Ա��Ϣ----------\n");
	printf("----------4��ɾ��ͨѶ¼��Ա��Ϣ----5�����沢�˳�------------------\n");
	printf("----------6���˳���������-----------------------------------------\n");
	printf("------------------------------------------------------------------\n");
}

void ContactInit(Contact *L)//һ�������������Ϣ������
{

}

void Print(Contact*s)
{
	printf("%d %s %s %s %s %s %s", s->age, s->Name, s->sex, s->PhNum, s->QQNuM, s->ComP, s->Email);
}
void Search()
{

}
void Add(Contact* L)
{
	Contact* s;
	L = (Contact*)malloc(sizeof(Contact));
	if (L == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�");
		return;
	}
	L->Next = NULL;
	printf("��������Ϣ��");
	s = (Contact*)malloc(sizeof(Contact));
	if (s == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�");
		return;
	}
	scanf("%d %s %s %s %s %s %s", &s->age, s->Name, s->sex, s->PhNum, s->QQNuM, s->ComP, s->Email);
	//12 abc �� 12345 54321 zhongkai 123
	L->Next = s;
	s->Next = NULL;
}
void Modify()
{

}
void Delete()
{

}
void SaveAndExit()
{

}
void ExitButSave()
{

}


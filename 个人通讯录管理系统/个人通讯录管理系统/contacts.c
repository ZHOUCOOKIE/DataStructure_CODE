#include "contacts.h"
#include <stdio.h>
#include <stdlib.h>
void Menu()
{
	printf("--------------------个人通讯录管理系统----------------------------\n");
	printf("----------0、显示所有通讯录--------1、查找通讯录------------------\n");
	printf("----------2、添加通讯录成员--------3、修改通讯录成员信息----------\n");
	printf("----------4、删除通讯录成员信息----5、保存并退出------------------\n");
	printf("----------6、退出但不保存-----------------------------------------\n");
	printf("------------------------------------------------------------------\n");
}

void ContactInit(Contact *L)//一次完成若干条信息的输入
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
		printf("申请内存失败！");
		return;
	}
	L->Next = NULL;
	printf("请输入信息：");
	s = (Contact*)malloc(sizeof(Contact));
	if (s == NULL)
	{
		printf("申请内存失败！");
		return;
	}
	scanf("%d %s %s %s %s %s %s", &s->age, s->Name, s->sex, s->PhNum, s->QQNuM, s->ComP, s->Email);
	//12 abc 男 12345 54321 zhongkai 123
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


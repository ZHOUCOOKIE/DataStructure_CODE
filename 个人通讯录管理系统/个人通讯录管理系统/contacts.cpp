#include "contacts.h"
#include <stdio.h>
#include <stdlib.h>
void Menu()//已实现
{
	printf("--------------------个人通讯录管理系统----------------------------\n");
	printf("----------0、显示所有通讯录--------1、查找通讯录------------------\n");
	printf("----------2、添加通讯录成员--------3、修改通讯录成员信息----------\n");
	printf("----------4、删除通讯录成员信息----5、保存------------------------\n");
	printf("----------6、不保存----------------7、退出程序--------------------\n");
	printf("------------------------------------------------------------------\n");
}

void PrintPlus(Contact*& L1, Contact*& L2)
{
	int judge = 0;
	printf("是否需要显示文件中的联系人信息？（1、显示2、不显示）:");
	scanf("%d", &judge);
	if (1 == judge)
	{
		Fread(L2);
		Print(L2);
	}
	if (L1 == NULL)
	{
		printf("您新增通讯录还没有输入任何信息\n");
		return;
	}
	else
	{
		Contact* p = L1->Next;
		while (p->Next != NULL)
		{
			printf("%d %s %s %s %lld %s %s\n", p->age, p->Name, p->sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
			p = p->Next;
		}
		printf("%d %s %s %s %lld %s %s\n", p->age, p->Name, p->sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
	}
}

void Print(Contact*& L)
{
	if (L == NULL)
	{
		return;
	}
	else
	{
		Contact* p = L->Next;
		printf("年龄  姓名  性别\t手机号码\tQQ号码\t工作单位\t邮箱\n");
		while (p->Next != NULL)
		{
			printf("%d %s %s %s %lld %s %s\n", p->age, p->Name, p->sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
			p = p->Next;
		}
		printf("%d %s %s %s %lld %s %s\n", p->age, p->Name, p->sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
	}
}

void Search()
{
	printf("请选择要查找的方式：");
}

void Add(Contact*& L)//判断是否重复
{
	Contact* s;
	int i = 0;
	L = (Contact*)calloc(1, sizeof(Contact));
	if (L == NULL)
	{
		printf("申请内存失败！");
		return;
	}
	L->Next = NULL;
	printf("请输入需要添加多少位联系人：");
	scanf("%d", &i);
	for (; i > 0; i--)
	{
		printf("请输入信息：(年龄 姓名 性别 手机号码 QQ号码 工作单位 邮箱)");
		s = (Contact*)calloc(1, sizeof(Contact));
		if (s == NULL)
		{
			printf("申请内存失败！");
			return;
		}
		scanf("%d %s %s %s %lld %s %s", &s->age, s->Name, s->sex, s->PhNum, &s->QQNuM, s->ComP, s->Email);
		//18 周俊安 男 13242825240 2117289243 仲恺农业工程学院 zhoucookie@outlook.com  2117289243仲恺农业工程学院 仲恺农业工程学院 
		//19 周俊 男 13242825240 2117289243 仲恺农业工程院 zhoucookie@outlook.com
		s->Next = L->Next;
		L->Next = s;
	}
}

void Modify()
{
	printf("请选择要修改的位置：");
}

void Delete(Contact *&L)
{
	int judge = 0;
	printf("请选择模式（1、删除原通讯录文件内容2、删除还未保存的联系人信息3、删除原通讯录所有文件内容）");
	scanf("%d", &judge);
	switch (judge)
	{
	case 1:
		break;
	case 2:
	{
		printf("请选择有要删除的还未保存的联系人信息：\n");
		Print(L);
		printf("请选择删除第几行的联系人:");
		int i = 0;
		scanf("%d", &i);
		Contact* p = L, * q;
		int j = 0;
		if (i < 1)
			break;
		while (p != NULL && j < i - 1)
		{
			j++;
			p = p->Next;
		}
		if (p == NULL)
			break;
		else
		{
			q = p->Next;
			if (q == NULL)
				break;
			p->Next = q->Next;
			free(q);
		}
		printf("删除完成！\n");
	}
		break;
	case 3:
		FILE * fp;
		fp = fopen("contact.txt", "w");
		fclose(fp);
		//remove("contact.txt");
		printf("您已经成功删除原通讯录文件内容\n");
		break;
	}
}

void Save(Contact*& L)//已实现
{
	int  judge;
	printf("确认将下列的信息存入文件中吗？(是1/否2/取消操作0)\n");
	Print(L);
	scanf("%d", &judge);
	if (1 == judge)
	{
		FILE* fp;
		Contact* p = L->Next;
		fp = fopen("contact.txt", "at");
		if (fp == NULL)
		{
			printf("无法打开文件或无法创建文件！");
			return;
		}
		while (p->Next != NULL)
		{
			fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
			p = p->Next;
		}
		fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
		fclose(fp);
		Destroy(L);
	}
	else if (2 == judge)
	{
		Destroy(L);
	}
	else if (0)
	{
		return;
	}
}

void NoSave(Contact*& L)//已实现
{
	Destroy(L);
	printf("退出成功！");
}

void Destroy(Contact*& L)//销毁链表L，释放链表L占用的内存空间。
{
	Contact* pre = L, * p = L->Next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->Next;
	}
	free(pre);
}

void Fread(Contact*& L2)
{
	FILE* fp;
	Contact* p , * s;
	fp = fopen("contact.txt", "rt");
	if (fp == NULL)
	{
		printf("无法打开文件！\n");
		return;
	}
	L2 = (Contact*)calloc(1, sizeof(Contact));
	if (L2 == NULL)
	{
		printf("申请内存失败！");
		return;
	}
	L2->Next = NULL;
	p = L2;
	while (!feof(fp))
	{
		s = (Contact*)calloc(1, sizeof(Contact));
		if (s == NULL)
		{
			printf("申请内存失败！");
			return;
		}
		fscanf(fp, "%d %s %s %s %lld %s %s\n", &s->age, s->Name, s->sex, s->PhNum, &s->QQNuM, s->ComP, s->Email);
		s->Next = p->Next;
		p->Next = s;
	}
	fclose(fp);
}

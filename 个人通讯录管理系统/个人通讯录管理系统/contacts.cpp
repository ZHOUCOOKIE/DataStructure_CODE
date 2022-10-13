#include "contacts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Menu()
{
	printf("--------------------------------------------个人通讯录管理系统------------------------------------------\n");
	printf("---------------------------------0、显示所有联系人---------1、查找联系人--------------------------------\n");
	printf("---------------------------------2、添加联系人信息---------3、按姓名排序联系人--------------------------\n");
	printf("---------------------------------4、修改联系人信息---------5、删除联系人信息----------------------------\n");
	printf("---------------------------------6、保存-------------------7、不保存------------------------------------\n");
	printf("----------------------------------------------8 、退出程序----------------------------------------------\n");
}

void display(Contact*& L1, Contact*& L2)
{
	system("cls");//清屏函数
	if (L2 == NULL)
		load(L2);
	Print(L2);
	if (L1 == NULL)
	{
		printf("无还未保存的新增联系人信息！\n");
		return;
	}
	else
	{
		printf("以下为未保存的通讯录信息：\n");
		Print(L1);
	}
}

void Print(Contact*& L)
{
	if (L == NULL)//防止非法访问内存
		return;
	Contact* p = L->Next;
	printf("  年龄  姓名     性别\t 手机号码      QQ号码\t      工作单位\t               邮箱\n");
	while (p != NULL && p->Next != NULL)
	{
		printf(" %4d  %-10s %-5s %10s  %-12lld %-20s %-30s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
		p = p->Next;
	}
	if(p != NULL)
		printf(" %4d  %-10s %-5s %10s  %-12lld %-20s %-30s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
}

void search(Contact*& L2)
{
	system("cls");
	int search = 0;
	char judge;
	if (L2 == NULL)
	{
		load(L2);
		if (L2 == NULL)
		{
			return;
		}
	}
	while (1)
	{
		Contact* p = L2->Next;
		printf("请选择要查找的方式(1、姓名 2、手机号 3、QQ号 4、单位 5、邮箱):");
		scanf("%d", &search);
		switch (search)
		{
		case 1:
			char name[MAX_NAME];
			printf("请输入要查找的名字：");
			scanf("%s", name);
			while (p->Next != NULL)
			{
				if (strcmp(p->Name, name) == 0)
				{
					break;
				}
				p = p->Next;
			}
			if (strcmp(p->Name, name) != 0)
			{
				printf("未找到联系人！\n");
				break;
			}
			printf("姓名为%s的通讯录信息：%d %s %s %s %lld %s %s\n", p->Name, p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
			break;
		case 2:
			char phnum[MAX_PHNUM];
			printf("请输入要查找的电话：");
			scanf("%s", phnum);
			while (p->Next != NULL)
			{
				if (strcmp(p->PhNum, phnum) == 0)
				{
					break;
				}
				p = p->Next;
			}
			if (strcmp(p->PhNum, phnum) != 0)
			{
				printf("未找到联系人！\n");
				break;
			}
			printf("电话为%s的通讯录信息：%d %s %s %s %lld %s %s\n", p->PhNum, p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
			break;
		case 3:
		{
			long long qqnum;
			printf("请输入要查找的QQ：");
			scanf("%lld", &qqnum);
			while (p->Next != NULL)
			{
				if (p->QQNuM == qqnum)
				{
					break;
				}
				p = p->Next;
			}
			if (p->QQNuM != qqnum)
			{
				printf("未找到联系人！\n");
				break;
			}
			printf("QQ为%lld的通讯录信息：%d %s %s %s %lld %s %s\n", p->QQNuM, p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
		}
		break;
		case 4:
		{
			char comp[MAX_COMP];
			int i = 0;
			printf("请输入要查找的单位：");
			scanf("%s", comp);
			while (p->Next != NULL)
			{
				if (strcmp(p->ComP, comp) == 0)
				{
					printf("单位为%s的通讯录信息：%d %s %s %s %lld %s %s\n", p->ComP, p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
					i++;
				}
				p = p->Next;
			}
			if (strcmp(p->ComP, comp) == 0)
			{
				printf("单位为%s的通讯录信息：%d %s %s %s %lld %s %s\n", p->ComP, p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
				i++;
			}
			if (i == 0)
			{
				system("cls");
				printf("未找到联系人！\n");
				break;
			}
			break;
		}
		case 5:
			char email[MAX_EMAIL];
			printf("请输入要查找的邮箱：");
			scanf("%s", email);
			while (p->Next != NULL)
			{
				if (strcmp(p->Email, email) == 0)
				{
					break;
				}
				p = p->Next;
			}
			if (strcmp(p->Email, email) != 0)
			{
				printf("未找到联系人！\n");
				break;
			}
			printf("邮箱为%s的通讯录信息：%d %s %s %s %lld %s %s\n", p->Email, p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
			break;
		}
		printf("是否取消查找？（Y/N）\n");
		getchar();//防止在之前有键盘输入
		scanf("%c", &judge);
		if (judge == 'Y')
		{
			break;
		}
	}
}

void enter(Contact*& L1, Contact*& L2)
{
	if (L2 == NULL)
	{
		load(L2);
	}
	Contact* s, * p = L2, * r;
	int i = 0;
	if (L1 == NULL)
	{
		L1 = (Contact*)calloc(1, sizeof(Contact));
	}
	r = L1;
	while (r->Next != NULL)
	{
		r = r->Next;
	}
	printf("请输入需要添加多少位联系人：");
	scanf("%d", &i);
	for (; i > 0; i--)//一个个存入单链表L1中
	{
		printf("请输入信息：(年龄 姓名 性别 手机号码 QQ号码 工作单位 邮箱)");
		s = (Contact*)calloc(1, sizeof(Contact));
		if (s == NULL)
		{
			printf("申请内存失败！\n");
			return;
		}
		scanf("%d %s %s %s %lld %s %s", &s->age, s->Name, s->Sex, s->PhNum, &s->QQNuM, s->ComP, s->Email);
		if (L2 != NULL)
		{
			p = L2->Next;
			char name[MAX_NAME];
			strcpy(name, s->Name);
			while (p->Next != NULL)
			{
				if (strcmp(p->Name, name) == 0)//防止重名
				{
					break;
				}
				p = p->Next;
			}
			while (strcmp(p->Name, name) == 0)
			{
				printf("您输入的联系人存在重名请修改后在输入！\n");
				printf("请重新输入信息：(年龄 姓名 性别 手机号码 QQ号码 工作单位 邮箱)");
				scanf("%d %s %s %s %lld %s %s", &s->age, s->Name, s->Sex, s->PhNum, &s->QQNuM, s->ComP, s->Email);
				strcpy(name, s->Name);
			}
		}

		r->Next = s;
		r = s;
	}
	r->Next = NULL;
	system("cls");
	printf("操作成功，可按6保存操作或者继续完成其他操作！\n");
}

void Modify(Contact*& L2)
{
	printf("请选择修改联系人的显示方式（1、显示全部通讯录查找错误 2、查找指定联系人）");
	int modify = 0;
	scanf("%d", &modify);
	if (L2 == NULL)
	{
		load(L2);
		if (L2 == NULL)
		{
			return;
		}
	}
	switch (modify)
	{
	case 1:
	{
		Print(L2);
		printf("请选择修改第几行的联系人:");
		int i = 0;
		int judge = 0;
		int interrupt = 0;
		Contact* p = L2->Next;
		scanf("%d", &i);
		for (; i > 1; i--)//使指针指向要修改的那行联系人
		{
			p = p->Next;
		}
		while (1)
		{
			printf("请选择要修改的信息（1、年龄 2、姓名 3、性别 4、手机号 5、QQ号 6、单位 7、邮箱）");
			scanf("%d", &judge);
			switch (judge)
			{
			case 1:
				int age;
				printf("请输入修正信息：");
				scanf("%d", &age);
				p->age = age;
				break;
			case 2:
				char name[MAX_NAME];
				printf("请输入修正信息：");
				scanf("%s", name);
				strcpy(p->Name, name);
				break;
			case 3:
				char sex[MAX_SEX];
				printf("请输入修正信息：");
				scanf("%s", sex);
				strcpy(p->Sex, sex);
				break;
			case 4:
				char phnum[MAX_PHNUM];
				printf("请输入修正信息：");
				scanf("%s", phnum);
				strcpy(p->PhNum, phnum);
				break;
			case 5:
				long long qqnum;
				printf("请输入修正信息：");
				scanf("%lld", &qqnum);
				p->QQNuM = qqnum;
				break;
			case 6:
				char comp[MAX_COMP];
				printf("请输入修正信息：");
				scanf("%s", comp);
				strcpy(p->ComP, comp);
				break;
			case 7:
				char email[MAX_EMAIL];
				printf("请输入修正信息：");
				scanf("%s", email);
				strcpy(p->Email, email);
				break;
			}
			printf("是否继续此行修改？（0、否 1、是）\n");
			scanf("%d", &interrupt);
			if (interrupt == 0)
			{
				break;
			}
		}
		system("cls");
		printf("修改完成！\n");
		break;
	}
	case 2:
		int search = 0, jud = 0;
		char judge;
		if (L2 == NULL)
		{
			load(L2);
			if (L2 == NULL)
			{
				return;
			}
		}
		Contact* p = L2->Next;
		while (1)
		{
			printf("请选择要查找的方式：(1、姓名 2、手机号 3、QQ号 4、邮箱):");
			scanf("%d", &search);
			switch (search)
			{
			case 1:
				char name[MAX_NAME];
				printf("请输入要查找的名字：");
				scanf("%s", name);
				while (p->Next != NULL)
				{
					if (strcmp(p->Name, name) == 0)
					{
						break;
					}
					p = p->Next;
				}
				if (strcmp(p->Name, name) != 0)
				{
					printf("未找到联系人！\n");
					break;
				}
				printf("请选择要修改的信息（1、年龄 2、姓名 3、性别 4、手机号 5、QQ号 6、单位 7、邮箱）:");
				scanf("%d", &jud);
				switch (jud)
				{
				case 1:
					int age;
					printf("请输入修正信息：");
					scanf("%d", &age);
					p->age = age;
					break;
				case 2:
					char name[MAX_NAME];
					printf("请输入修正信息：");
					scanf("%s", name);
					strcpy(p->Name, name);
					break;
				case 3:
					char sex[MAX_SEX];
					printf("请输入修正信息：");
					scanf("%s", sex);
					strcpy(p->Sex, sex);
					break;
				case 4:
					char phnum[MAX_PHNUM];
					printf("请输入修正信息：");
					scanf("%s", phnum);
					strcpy(p->PhNum, phnum);
					break;
				case 5:
					long long qqnum;
					printf("请输入修正信息：");
					scanf("%lld", &qqnum);
					p->QQNuM = qqnum;
					break;
				case 6:
					char comp[MAX_COMP];
					printf("请输入修正信息：");
					scanf("%s", comp);
					strcpy(p->ComP, comp);
					break;
				case 7:
					char email[MAX_EMAIL];
					printf("请输入修正信息：");
					scanf("%s", email);
					strcpy(p->Email, email);
					break;
				}
				break;
			case 2:
			{
				char phnum[MAX_PHNUM];
				printf("请输入要查找的电话：");
				scanf("%s", phnum);
				while (p->Next != NULL)
				{
					if (strcmp(p->PhNum, phnum) == 0)
					{
						break;
					}
					p = p->Next;
				}
				if (strcmp(p->PhNum, phnum) != 0)
				{
					printf("未找到联系人！\n");
					break;
				}
				printf("请选择要修改的信息（1、年龄 2、姓名 3、性别 4、手机号 5、QQ号 6、单位 7、邮箱）:");
				scanf("%d", &jud);
				switch (jud)
				{
				case 1:
					int age;
					printf("请输入修正信息：");
					scanf("%d", &age);
					p->age = age;
					break;
				case 2:
					char name[MAX_NAME];
					printf("请输入修正信息：");
					scanf("%s", name);
					strcpy(p->Name, name);
					break;
				case 3:
					char sex[MAX_SEX];
					printf("请输入修正信息：");
					scanf("%s", sex);
					strcpy(p->Sex, sex);
					break;
				case 4:
					char phnum[MAX_PHNUM];
					printf("请输入修正信息：");
					scanf("%s", phnum);
					strcpy(p->PhNum, phnum);
					break;
				case 5:
					long long qqnum;
					printf("请输入修正信息：");
					scanf("%lld", &qqnum);
					p->QQNuM = qqnum;
					break;
				case 6:
					char comp[MAX_COMP];
					printf("请输入修正信息：");
					scanf("%s", comp);
					strcpy(p->ComP, comp);
					break;
				case 7:
					char email[MAX_EMAIL];
					printf("请输入修正信息：");
					scanf("%s", email);
					strcpy(p->Email, email);
					break;
				}
				break;
			}
			case 3:
			{
				long long qqnum;
				printf("请输入要查找的QQ：");
				scanf("%lld", &qqnum);
				while (p->Next != NULL)
				{
					if (p->QQNuM == qqnum)
					{
						break;
					}
					p = p->Next;
				}
				if (p->QQNuM != qqnum)
				{
					printf("未找到联系人！\n");
					break;
				}
				printf("请选择要修改的信息（1、年龄 2、姓名 3、性别 4、手机号 5、QQ号 6、单位 7、邮箱）:");
				scanf("%d", &jud);
				switch (jud)
				{
				case 1:
					int age;
					printf("请输入修正信息：");
					scanf("%d", &age);
					p->age = age;
					break;
				case 2:
					char name[MAX_NAME];
					printf("请输入修正信息：");
					scanf("%s", name);
					strcpy(p->Name, name);
					break;
				case 3:
					char sex[MAX_SEX];
					printf("请输入修正信息：");
					scanf("%s", sex);
					strcpy(p->Sex, sex);
					break;
				case 4:
					char phnum[MAX_PHNUM];
					printf("请输入修正信息：");
					scanf("%s", phnum);
					strcpy(p->PhNum, phnum);
					break;
				case 5:
					long long qqnum;
					printf("请输入修正信息：");
					scanf("%lld", &qqnum);
					p->QQNuM = qqnum;
					break;
				case 6:
					char comp[MAX_COMP];
					printf("请输入修正信息：");
					scanf("%s", comp);
					strcpy(p->ComP, comp);
					break;
				case 7:
					char email[MAX_EMAIL];
					printf("请输入修正信息：");
					scanf("%s", email);
					strcpy(p->Email, email);
					break;
				}
				break;
			}
			break;
			case 4:
			{
				char email[MAX_EMAIL];
				printf("请输入要查找的邮箱：");
				scanf("%s", email);
				while (p->Next != NULL)
				{
					if (strcmp(p->Email, email) == 0)
					{
						break;
					}
					p = p->Next;
				}
				if (strcmp(p->Email, email) != 0)
				{
					printf("未找到联系人！\n");
					break;
				}
				printf("请选择要修改的信息（1、年龄 2、姓名 3、性别 4、手机号 5、QQ号 6、单位 7、邮箱）:");
				scanf("%d", &jud);
				switch (jud)
				{
				case 1:
					int age;
					printf("请输入修正信息：");
					scanf("%d", &age);
					p->age = age;
					break;
				case 2:
					char name[MAX_NAME];
					printf("请输入修正信息：");
					scanf("%s", name);
					strcpy(p->Name, name);
					break;
				case 3:
					char sex[MAX_SEX];
					printf("请输入修正信息：");
					scanf("%s", sex);
					strcpy(p->Sex, sex);
					break;
				case 4:
					char phnum[MAX_PHNUM];
					printf("请输入修正信息：");
					scanf("%s", phnum);
					strcpy(p->PhNum, phnum);
					break;
				case 5:
					long long qqnum;
					printf("请输入修正信息：");
					scanf("%lld", &qqnum);
					p->QQNuM = qqnum;
					break;
				case 6:
					char comp[MAX_COMP];
					printf("请输入修正信息：");
					scanf("%s", comp);
					strcpy(p->ComP, comp);
					break;
				case 7:
					char email[MAX_EMAIL];
					printf("请输入修正信息：");
					scanf("%s", email);
					strcpy(p->Email, email);
					break;
				}
				break;
			}
			break;
			}
			printf("是否取消查找？（Y/N）\n");
			getchar();
			scanf("%c", &judge);
			if (judge == 'Y')
			{
				break;
			}
		}
		printf("修改后请保存！\n");
		break;
	}
}

void Delete(Contact*& L1, Contact*& L2)
{
	int judge = 0;
	printf("请选择模式（1、删除已保存的联系人的信息2、删除还未保存的联系人信息3、删除原通讯录所有文件内容）");
	scanf("%d", &judge);
	switch (judge)
	{
	case 1:
	{
		if (L2 == NULL)
		{
			load(L2);
		}
		Print(L2);
		printf("请选择删除第几行的联系人:");
		int i = 0;
		scanf("%d", &i);
		Contact* p = L2, * q;
		int j = 0;
		if (i < 1)
			break;
		while (p != NULL && j < i - 1)//使指针指向要修改的那行联系人
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
		printf("操作成功，可按6保存操作或者继续完成其他操作！\n");
	}
	break;
	case 2:
	{
		if (L1 == NULL)
		{
			printf("无还未保存的联系人信息\n");
			return;
		}
		printf("请选择有要删除的还未保存的联系人信息：\n");
		Print(L1);
		printf("请选择删除第几行的联系人:");
		int i = 0;
		scanf("%d", &i);
		Contact* p = L1, * q;
		int j = 0;
		if (i < 1)
			break;
		while (p != NULL && j < i - 1)//使指针指向要修改的那行联系人
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
		if (L1->Next == NULL)
		{
			L1 = NULL;
		}
		printf("删除完成！\n");
	}
	break;
	case 3:
		remove("contact.txt");//remove函数可以直接将文件删除掉
		Destroy(L2);
		printf("您已经成功删除原通讯录文件内容\n");
		break;
	}
}

void save(Contact*& L1, Contact*& L2)
{
	int  judge;
	FILE* fp;
	printf("是否保存对原通讯录的修改？(是1/否2/取消操作0)\n");
	scanf("%d", &judge);
	if (1 == judge)
	{
		Contact* p = L2->Next;
		fp = fopen("contact.txt", "w");
		if (fp == NULL)
		{
			printf("\n无法打开文件或无法创建文件！");
			return;
		}
		while (p->Next != NULL)
		{
			fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
			p = p->Next;
		}
		fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
		fclose(fp);
	}
	else if (2 == judge)
	{
		Destroy(L2);
	}
	if (L1 == NULL)
	{
		printf("无新增的联系人信息！\n");
		return;
	}
	printf("\n是否将下列的信息添加入通讯录中？(是1/否2/取消操作0)\n");
	Print(L1);
	scanf("%d", &judge);
	if (1 == judge)
	{
		Contact* p = L1->Next;
		fp = fopen("contact.txt", "at");
		if (fp == NULL)
		{
			printf("\n无法打开文件或无法创建文件！");
			return;
		}
		while (p->Next != NULL)
		{
			fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
			p = p->Next;
		}
		fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
		fclose(fp);
		Destroy(L1);
	}
	else if (2 == judge)
	{
		Destroy(L1);
	}
	else if (0 == judge)
	{
		return;
	}
}

void NoSave(Contact*& L1, Contact*& L2)
{
	Destroy(L1);
	Destroy(L2);
	printf("操作成功！\n");
}

void Destroy(Contact*& L)//删除单链表
{
	if (L == NULL)
	{
		return;
	}
	Contact* pre = L, * p = L->Next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->Next;
	}
	free(pre);
	L = NULL;
}

void load(Contact*& L2)//读取文本文件中的内容并保存到单链表L2中
{
	FILE* fp;
	Contact* p, * s;
	fp = fopen("contact.txt", "rt");
	if (fp == NULL)
	{
		printf("无已保存通讯录！\n");
		return;
	}
	L2 = (Contact*)calloc(1, sizeof(Contact));
	if (L2 == NULL)
	{
		printf("申请内存失败！\n");
		return;
	}
	p = L2;
	while (!feof(fp))
	{
		s = (Contact*)calloc(1, sizeof(Contact));
		if (s == NULL)
		{
			printf("申请内存失败！\n");
			return;
		}
		fscanf(fp, "%d %s %s %s %lld %s %s\n", &s->age, s->Name, s->Sex, s->PhNum, &s->QQNuM, s->ComP, s->Email);//读文件保存到节点中
		p->Next = s;
		p = s;
	}
	p->Next = NULL;

	fclose(fp);
}

void Sort(Contact*& L2)
{
	if (L2 == NULL)
	{
		load(L2);
	}
	Contact* q = L2->Next, * p = q->Next;
	//创建中间变量
	int temp0;
	char temp1[MAX_NAME];
	char temp2[MAX_SEX];
	char temp3[MAX_PHNUM];
	long long temp4;
	char temp5[MAX_COMP];
	char temp6[MAX_EMAIL];
	while (q != NULL)
	{
		p = q->Next;
		while (p != NULL)
		{
			if (strcmp(q->Name, p->Name) > 0)//如果排序相反，把后面的联系人信息复制给前面，前面的联系人信息复制给后面
			{
				temp0 = q->age;
				q->age = p->age;
				p->age = temp0;
				strcpy(temp1, q->Name);
				strcpy(q->Name, p->Name);
				strcpy(p->Name, temp1);

				strcpy(temp2, q->Sex);
				strcpy(q->Sex, p->Sex);
				strcpy(p->Sex, temp2);

				strcpy(temp3, q->PhNum);
				strcpy(q->PhNum, p->PhNum);
				strcpy(p->PhNum, temp3);

				temp4 = q->QQNuM;
				q->QQNuM = p->QQNuM;
				p->QQNuM = temp4;

				strcpy(temp5, q->ComP);
				strcpy(q->ComP, p->ComP);
				strcpy(p->ComP, temp5);

				strcpy(temp6, q->Email);
				strcpy(q->Email, p->Email);
				strcpy(p->Email, temp6);
			}
			p = p->Next;
		}
		q = q->Next;
	}
	FILE* fp;
	fp = fopen("contact.txt", "w"); //“w”方式打开，为了覆盖原来的文件内容
	if (fp == NULL)
	{
		printf("无法打开文件或无法创建文件！");
		return;
	}
	p = L2->Next;
	while (p->Next != NULL)
	{
		fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
		p = p->Next;
	}
	fprintf(fp, "%d %s %s %s %lld %s %s\n", p->age, p->Name, p->Sex, p->PhNum, p->QQNuM, p->ComP, p->Email);
	fclose(fp);
	printf("排序成功！\n");
}
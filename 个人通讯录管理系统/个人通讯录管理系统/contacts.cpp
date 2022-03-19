#include "contacts.h"
#include <stdio.h>
#include <stdlib.h>
void Menu()//��ʵ��
{
	printf("--------------------����ͨѶ¼����ϵͳ----------------------------\n");
	printf("----------0����ʾ����ͨѶ¼--------1������ͨѶ¼------------------\n");
	printf("----------2�����ͨѶ¼��Ա--------3���޸�ͨѶ¼��Ա��Ϣ----------\n");
	printf("----------4��ɾ��ͨѶ¼��Ա��Ϣ----5������------------------------\n");
	printf("----------6��������----------------7���˳�����--------------------\n");
	printf("------------------------------------------------------------------\n");
}

void PrintPlus(Contact*& L1, Contact*& L2)
{
	int judge = 0;
	printf("�Ƿ���Ҫ��ʾ�ļ��е���ϵ����Ϣ����1����ʾ2������ʾ��:");
	scanf("%d", &judge);
	if (1 == judge)
	{
		Fread(L2);
		Print(L2);
	}
	if (L1 == NULL)
	{
		printf("������ͨѶ¼��û�������κ���Ϣ\n");
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
		printf("����  ����  �Ա�\t�ֻ�����\tQQ����\t������λ\t����\n");
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
	printf("��ѡ��Ҫ���ҵķ�ʽ��");
}

void Add(Contact*& L)//�ж��Ƿ��ظ�
{
	Contact* s;
	int i = 0;
	L = (Contact*)calloc(1, sizeof(Contact));
	if (L == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�");
		return;
	}
	L->Next = NULL;
	printf("��������Ҫ��Ӷ���λ��ϵ�ˣ�");
	scanf("%d", &i);
	for (; i > 0; i--)
	{
		printf("��������Ϣ��(���� ���� �Ա� �ֻ����� QQ���� ������λ ����)");
		s = (Contact*)calloc(1, sizeof(Contact));
		if (s == NULL)
		{
			printf("�����ڴ�ʧ�ܣ�");
			return;
		}
		scanf("%d %s %s %s %lld %s %s", &s->age, s->Name, s->sex, s->PhNum, &s->QQNuM, s->ComP, s->Email);
		//18 �ܿ��� �� 13242825240 2117289243 ����ũҵ����ѧԺ zhoucookie@outlook.com  2117289243����ũҵ����ѧԺ ����ũҵ����ѧԺ 
		//19 �ܿ� �� 13242825240 2117289243 ����ũҵ����Ժ zhoucookie@outlook.com
		s->Next = L->Next;
		L->Next = s;
	}
}

void Modify()
{
	printf("��ѡ��Ҫ�޸ĵ�λ�ã�");
}

void Delete(Contact *&L)
{
	int judge = 0;
	printf("��ѡ��ģʽ��1��ɾ��ԭͨѶ¼�ļ�����2��ɾ����δ�������ϵ����Ϣ3��ɾ��ԭͨѶ¼�����ļ����ݣ�");
	scanf("%d", &judge);
	switch (judge)
	{
	case 1:
		break;
	case 2:
	{
		printf("��ѡ����Ҫɾ���Ļ�δ�������ϵ����Ϣ��\n");
		Print(L);
		printf("��ѡ��ɾ���ڼ��е���ϵ��:");
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
		printf("ɾ����ɣ�\n");
	}
		break;
	case 3:
		FILE * fp;
		fp = fopen("contact.txt", "w");
		fclose(fp);
		//remove("contact.txt");
		printf("���Ѿ��ɹ�ɾ��ԭͨѶ¼�ļ�����\n");
		break;
	}
}

void Save(Contact*& L)//��ʵ��
{
	int  judge;
	printf("ȷ�Ͻ����е���Ϣ�����ļ�����(��1/��2/ȡ������0)\n");
	Print(L);
	scanf("%d", &judge);
	if (1 == judge)
	{
		FILE* fp;
		Contact* p = L->Next;
		fp = fopen("contact.txt", "at");
		if (fp == NULL)
		{
			printf("�޷����ļ����޷������ļ���");
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

void NoSave(Contact*& L)//��ʵ��
{
	Destroy(L);
	printf("�˳��ɹ���");
}

void Destroy(Contact*& L)//��������L���ͷ�����Lռ�õ��ڴ�ռ䡣
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
		printf("�޷����ļ���\n");
		return;
	}
	L2 = (Contact*)calloc(1, sizeof(Contact));
	if (L2 == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�");
		return;
	}
	L2->Next = NULL;
	p = L2;
	while (!feof(fp))
	{
		s = (Contact*)calloc(1, sizeof(Contact));
		if (s == NULL)
		{
			printf("�����ڴ�ʧ�ܣ�");
			return;
		}
		fscanf(fp, "%d %s %s %s %lld %s %s\n", &s->age, s->Name, s->sex, s->PhNum, &s->QQNuM, s->ComP, s->Email);
		s->Next = p->Next;
		p->Next = s;
	}
	fclose(fp);
}

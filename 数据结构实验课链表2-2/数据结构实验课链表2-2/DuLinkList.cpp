#include "DuLinkList.h"
#include <stdio.h>
#include <stdlib.h>

//��1����д��ͷ����˫��������DuLinkList.cpp�����ٰ���//��ʼ����//������//���롢�����Ȳ�����
//��2����ʵ��Ҫ���д�����㷨
//�㷨��ʾ��invertSort(DuLinkList* L).ʹ��ͷ�巨�ؽ�˫����

void CreateListF_DuL(DuLinkList*& L, ElemType a[], int n)
{
	DuLinkList* s, * r;
	int i;
	L = (DuLinkList*)malloc(sizeof(DuLinkList));
	L->prior = L->next = NULL;
	r = L;
	for (i = 0; i < n; i++)
	{
		s = (DuLinkList*)malloc(sizeof(DuLinkList));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}

void invertSort(DuLinkList* &L,ElemType a[],int n)
{
	DuLinkList* s;
	int i;
	L = (DuLinkList*)malloc(sizeof(DuLinkList));
	L->prior = L->next = NULL;
	for (i = 0; i < n; i++)
	{
		s = (DuLinkList*)malloc(sizeof(DuLinkList));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL)
		{
			L->next->prior = s;
		}
		L->next = s;
		s->prior = L;
	}
}

void PrintList_DuL(DuLinkList* L)
{
	DuLinkList* s = L->next;
	while (s != NULL)
	{
		printf("%c", s->data);
		s = s->next;
	}
	printf("\n");
}

bool ListDelete_DuL(DuLinkList*& L, int i, ElemType& e)
{
	int j = 0;
	DuLinkList* p = L, * s;
	while (j < i && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		e = p->data;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		free(p);
		return true;
	}
}

bool ListLnsert_DuL(DuLinkList*& L, int i, ElemType e)
{
	int j = 0;
	DuLinkList* p = L, * s;
	while (j < i && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		s = (DuLinkList*)malloc(sizeof(DuLinkList));
		s->data = e;
		s->prior = p->prior;
		s->next = p;
		p->prior->next = s;
		p->prior = s;
		return true;
	}
}

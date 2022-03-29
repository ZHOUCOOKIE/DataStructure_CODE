#include "DuLinkList.h"
#include <stdio.h>
#include <stdlib.h>

//（1）编写带头结点的双链表的设计DuLinkList.cpp，至少包含//初始化、//撤销、//插入、遍历等操作；
//（2）按实验要求编写逆置算法
//算法提示：invertSort(DuLinkList* L).使用头插法重建双链表。

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

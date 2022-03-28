#include "Linklist.h"
#include <stdio.h>
#include <stdlib.h>

bool Listlocate_Sq(Linklist*& L, int i, ElemType& e)//�������ĵ�i��Ԫ�ء�
{
	int j = 0;
	Linklist* p = L;
	while (p != NULL && j < i)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		e = p->data;
		return true;
	}
}

void CreatList_Sq(Linklist*& L, ElemType a[], int n)//β�巨��������
{
	Linklist* s, * r;
	int i;
	L = (Linklist*)malloc(sizeof(Linklist));
	if (L == NULL)
	{
		printf("�ڴ���䲻�ɹ���\n");
		return;
	}
	r = L;
	for (i = 0; i < n; i++)
	{
		s = (Linklist*)malloc(sizeof(Linklist));
		if (s == NULL) 
		{
			printf("�ڴ���䲻�ɹ���\n");
			return;
		}
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void InitList_Sq(Linklist*& L)//��ʼ�����Ա�����һ���յ�����L��
{
	L = (Linklist*)malloc(sizeof(Linklist));
	if (L == NULL)
	{
		printf("�ڴ���䲻�ɹ���\n");
		return;
	}
	L->next = NULL;
}

bool ListInsert_Sq(Linklist*& L, int i, ElemType e)//����Ԫ��
{
	Linklist* p = L, * s;
	int j = 0;
	if (i < 1)return false;
	while (p != NULL && j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		s = (Linklist*)malloc(sizeof(Linklist));
		if (s == NULL)
		{
			printf("�ڴ���䲻�ɹ���\n");
			return false;
		}
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

bool ListEmpty_Sq(Linklist* L)//�� L Ϊ�ձ��򷵻� TRUE�����򷵻� FALSE��
{
	return(L->next == NULL);
}

int ListLength_Sq(Linklist* L)//����L�е�����Ԫ�ظ�����
{
	Linklist* p = L;
	int n = 0;
	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

int LocateElem_Sq(Linklist* L, ElemType e)//���� L�е�һ����ֵ��e��ȵ�Ԫ�ص�λ�� ������������Ԫ�ز����ڣ��򷵻�ֵΪ0��
{
	int i = 1;
	Linklist* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
		return 0;
	else
		return i;
}

bool ListDelete_Sq(Linklist*& L, int i, ElemType& e)//ɾ������Ԫ�ء� ɾ��L�ĵ� i������Ԫ�أ����� e������ֵ��L�ĳ��ȼ� 1��
{
	Linklist* p = L, * q;
	int j = 0;
	if (i < 1)
		return false;
	while (p != NULL && j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		q = p->next;
		if (q == NULL)
			return false;
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
}

void DestroyList_Sq(Linklist*& L)//��������L���ͷ�����Lռ�õ��ڴ�ռ䡣
{
	Linklist* pre = L, * p = L->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

void deletes(Linklist*& L, char min, char max)
{
	Linklist* q = L;
	Linklist* p = q->next;
	while (p != NULL)
	{
		if (min <= p->data && p->data <= max)
		{
			q->next = p->next;
			free(p);
			p = q->next;
		}
		if (p->next == NULL)
		{
			return;
		}
	}
}

void CreateListF_DuL(DuLinkList*& DL, ElemType a[], int n)
{
	DuLinkList* s;
	int i;
	DL = (DuLinkList*)malloc(sizeof(DuLinkList));
	DL->prior = DL->next = NULL;
	for (i = 0; i < n; i++)
	{
		s = (DuLinkList*)malloc(sizeof(DuLinkList));
		s->data = a[i];
		s->next = DL->next;
		if (DL->next != NULL)
		{
			DL->next->prior = s;
		}
		DL->next = s;
		s->prior = DL;
	}
}

void invertSort(DuLinkList* DL)
{
	DuLinkList* p = DL->next,*q;
	while (p != DL)
	{
		q = p->next;
		p->next = p->prior;
		p->prior = q;
		p = q;
	}

	q = DL->next;
	DL->next = p->prior;
	DL->prior = q;
}

void PrintList_DuL(DuLinkList* DL)
{
	DuLinkList* s = DL->next;
	while (s != NULL)
	{
		printf("%c", s->data);
		s = s->next;
	}
	printf("\n");
}
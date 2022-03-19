//#include "Linklist.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//bool Listlocate_Sq(Linklist*& L, int i, ElemType& e)//输出链表的第i个元素。
//{
//	int j = 0;
//	Linklist* p = L;
//	while (p != NULL && j < i)
//	{
//		j++;
//		p = p->next;
//	}
//	if (p == NULL)
//		return false;
//	else
//	{
//		e = p->data;
//		return true;
//	}
//}
//
//void CreatList_Sq(Linklist*& L, ElemType a[], int n)//尾插法创建链表
//{
//	Linklist* s, * r;
//	int i;
//	L = (Linklist*)malloc(sizeof(Linklist));
//	if (L == NULL)
//	{
//		printf("内存分配不成功！\n");
//		return;
//	}
//	r = L;
//	for (i = 0; i < n; i++)
//	{
//		s = (Linklist*)malloc(sizeof(Linklist));
//		if (s == NULL) 
//		{
//			printf("内存分配不成功！\n");
//			return;
//		}
//		s->data = a[i];
//		r->next = s;
//		r = s;
//	}
//	r->next = NULL;
//}
//
//void InitList_Sq(Linklist*& L)//初始化线性表，构造一个空的链表L。
//{
//	L = (Linklist*)malloc(sizeof(Linklist));
//	if (L == NULL)
//	{
//		printf("内存分配不成功！\n");
//		return;
//	}
//	L->next = NULL;
//}
//
//bool ListInsert_Sq(Linklist*& L, int i, ElemType e)//插入元素
//{
//	Linklist* p = L, * s;
//	int j = 0;
//	if (i < 1)return false;
//	while (p != NULL && j < i - 1)
//	{
//		j++;
//		p = p->next;
//	}
//	if (p == NULL)
//		return false;
//	else
//	{
//		s = (Linklist*)malloc(sizeof(Linklist));
//		if (s == NULL)
//		{
//			printf("内存分配不成功！\n");
//			return false;
//		}
//		s->data = e;
//		s->next = p->next;
//		p->next = s;
//		return true;
//	}
//}
//
//bool ListEmpty_Sq(Linklist* L)//若 L 为空表，则返回 TRUE，否则返回 FALSE。
//{
//	return(L->next == NULL);
//}
//
//int ListLength_Sq(Linklist* L)//返回L中的数据元素个数。
//{
//	Linklist* p = L;
//	int n = 0;
//	while (p->next != NULL)
//	{
//		n++;
//		p = p->next;
//	}
//	return n;
//}
//
//int LocateElem_Sq(Linklist* L, ElemType e)//返回 L中第一个其值与e相等的元素的位序。 若这样的数据元素不存在，则返回值为0。
//{
//	int i = 1;
//	Linklist* p = L->next;
//	while (p != NULL && p->data != e)
//	{
//		p = p->next;
//		i++;
//	}
//	if (p == NULL)
//		return 0;
//	else
//		return i;
//}
//
//bool ListDelete_Sq(Linklist*& L, int i, ElemType& e)//删除数据元素。 删除L的第 i个数据元素，并用 e返回其值，L的长度减 1。
//{
//	Linklist* p = L, * q;
//	int j = 0;
//	if (i < 1)
//		return false;
//	while (p != NULL && j < i - 1)
//	{
//		j++;
//		p = p->next;
//	}
//	if (p == NULL)
//		return false;
//	else
//	{
//		q = p->next;
//		if (q == NULL)
//			return false;
//		e = q->data;
//		p->next = q->next;
//		free(q);
//		return true;
//	}
//}
//
//void DestroyList_Sq(Linklist*& L)//销毁链表L，释放链表L占用的内存空间。
//{
//	Linklist* pre = L, * p = L->next;
//	while (p != NULL)
//	{
//		free(pre);
//		pre = p;
//		p = pre->next;
//	}
//	free(pre);
//}

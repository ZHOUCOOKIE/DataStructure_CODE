#pragma once

typedef char ElemType;
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLinkList;

void CreateListF_DuL(DuLinkList*& L, ElemType a[], int n);//初始化双链表
void invertSort(DuLinkList*& L, ElemType a[], int n);//插入元素
void PrintList_DuL(DuLinkList* L);//遍历双链表
bool ListDelete_DuL(DuLinkList*& L, int i, ElemType& e);//删除元素
bool ListLnsert_DuL(DuLinkList*& L, int i, ElemType e);//逆置双链表
void DestroyList_DuL(DuLinkList*& L);//销毁链表L，释放链表L占用的内存空间。
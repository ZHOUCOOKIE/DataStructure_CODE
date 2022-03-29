#pragma once

typedef char ElemType;

typedef struct DuLNode
{
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLinkList;

void CreateListF_DuL(DuLinkList*& L, ElemType a[], int n);
void invertSort(DuLinkList*& L, ElemType a[], int n);
void PrintList_DuL(DuLinkList* L);
bool ListDelete_DuL(DuLinkList*& L, int i, ElemType& e);
bool ListLnsert_DuL(DuLinkList*& L, int i, ElemType e);
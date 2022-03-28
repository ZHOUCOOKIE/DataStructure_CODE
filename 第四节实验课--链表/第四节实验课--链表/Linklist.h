#pragma once


typedef char ElemType;

typedef struct Linklist {
	ElemType data;
	struct Linklist* next;
}SqList;

void InitList_Sq(Linklist*& L);
bool ListInsert_Sq(Linklist*& L, int i, ElemType e);
bool ListEmpty_Sq(Linklist* L);
int ListLength_Sq(Linklist* L);
int LocateElem_Sq(Linklist* L, ElemType e);
bool ListDelete_Sq(Linklist*& L, int i, ElemType& e);
void DestroyList_Sq(Linklist*& L);
bool Listlocate_Sq(Linklist*& L, int i, ElemType& e);
void CreatList_Sq(Linklist*& L, ElemType a[], int n);
void deletes(Linklist*& L, char min, char max);
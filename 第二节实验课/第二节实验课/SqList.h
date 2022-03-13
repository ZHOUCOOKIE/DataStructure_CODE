#include <stdio.h>
#include <stdlib.h>
#define MaxSize 6
typedef char ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

void InitList_Sq(SqList*& L);
bool ListInsert_Sq(SqList*& L, int i, ElemType e);
void ListTraverse_Sq(SqList*& L);
bool ListEmpty_Sq(SqList* L);
int ListLength_Sq(SqList* L);
int LocateElem_Sq(SqList* L, ElemType e);
bool ListDelete_Sq(SqList*& L, int i, ElemType& e);
void DestroyList_Sq(SqList*& L);
void Listlocate_Sq(SqList*& L, int i);
void Listbubble_sort(SqList*& L, int Maxsize);
void InterSection(SqList*& La, SqList*& Lb, SqList*& Lc);
void CreatList_Sq(SqList*& L, ElemType a[], int n);

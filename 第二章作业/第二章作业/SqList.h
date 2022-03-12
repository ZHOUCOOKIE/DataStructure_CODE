#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

void InitList_Sq(SqList*& L);
bool ListInsert_Sq(SqList*& L, int i, ElemType e);
void ListTraverse_Sq(SqList*& L);
void CreatList_Sq(SqList*& L, ElemType a[], int n);
bool ListEmpty_Sq(SqList* L);
void Union(SqList*& La, SqList*& Lb);
int ListLength_Sq(SqList* L);
int LocateElem_Sq(SqList* L, ElemType e);
bool ListDelete_Sq(SqList*& L, int i, ElemType& e);
void DestroyList_Sq(SqList*& L);
void Listlocate_Sq(SqList*& L, int i);
void Listbubble_sort(SqList*& L, int Maxsize);
void IntersectionList_Sq(SqList*& La, SqList*& Lb, SqList*& Lc);
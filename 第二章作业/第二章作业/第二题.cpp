//计算机215班 202110244532 周俊安
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;
void CreatList_Sq(SqList*& L, ElemType a[], int n)
{
	int i;
	L = (SqList*)malloc(sizeof(SqList));
	for (i = 0; i < n; i++)
		L->data[i] = a[i];
	L->length = n;
}

void ListTraverse_Sq(SqList*& L)
{
	int i = 0;
	for (i = 0; i < L->length; i++)
		printf("%d ", L->data[i]);
	printf("\n");
}

bool ListDelete_Sq(SqList*& L, int i, ElemType& e)
{
	int j;
	if ((i < 1) || (i > L->length))
		return false;
	i--;
	e = L->data[i];
	L->data[i] = 0;
	for (j = i; j < L->length - 1; j++)
		L->data[j] = L->data[j + 1];
	L->length--;
	return true;
}

int LocateElem_Sq(SqList* L, ElemType e)
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
		i++;
	if (i < L->length)
		return i + 1;
	else
		return 0;
}

bool ListInsert_Sq(SqList*& L, int i, ElemType e)
{
	int j;
	if (L->length == MaxSize)return false;
	i--;
	for (j = L->length; j > i; j--)
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;
	return true;
}

int ListLength_Sq(SqList* L)
{
	return(L->length);
}

void DestroyList_Sq(SqList*& L)
{
	free(L);
}

bool ListEmpty_Sq(SqList* L)
{
	return(L->length == 0);
}

int main()
{
	ElemType arr1[5] = { 1,2,3,6,7 };
	ElemType arr2[5] = { 1,2,3,4,5 };
	ElemType e;
	int La_Length;
	SqList* La, * Lb;
	CreatList_Sq(La, arr1, 5);
	CreatList_Sq(Lb, arr2, 5);
	printf("初始线性表La：");
	ListTraverse_Sq(La);
	printf("初始线性表Lb：");
	ListTraverse_Sq(Lb);
	printf("结果线性表L：");
	La_Length = ListLength_Sq(La);
	while (!ListEmpty_Sq(Lb))
	{
		ListDelete_Sq(Lb, 1, e);
		if (!LocateElem_Sq(La, e))
			ListInsert_Sq(La, ++La_Length, e);
	}
	ListTraverse_Sq(La);
	DestroyList_Sq(Lb);	DestroyList_Sq(La);
	return 0;
}
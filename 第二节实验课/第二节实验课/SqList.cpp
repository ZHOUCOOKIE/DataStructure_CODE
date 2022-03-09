#include "SqList.h"
void Listabc_Sq(SqList*& L, int i)
{
	printf("%c", L->data[i - 1]);
	printf("\n");
}

void InitList_Sq(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
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

void Listbubble_sort(SqList*& L, int length)
{
	int temp = 0;
	for (int i = 0; i < MaxSize - 1; i++)
		for (int j = 0; j < MaxSize - 1 - i; j++)
			if (L->data[j] > L->data[j + 1]) {
				temp = L->data[j];
				L->data[j] = L->data[j + 1];
				L->data[j + 1] = temp;
			}
}

void ListTraverse_Sq(SqList*& L)
{
	int i=0;
	for (i = 0; i < L->length; i++)
		printf("%c", L->data[i]);
	printf("\n");
}

bool ListEmpty_Sq(SqList* L)
{
	return(L->length);
}

int ListLength_Sq(SqList* L)
{
	return(L->length);
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

bool ListDelete_Sq(SqList*& L, int i, ElemType& e)
{
	int j;
	if ((i < 1) || (i > L->length))
		return false;
	i--;
	e = L->data[i];
	for (j = i; j < L->length - 1; j++)
		L->data[j] = L->data[j + 1];
	L->length--;
	return true;
}

void DestroyList_Sq(SqList*& L)
{
	free(L);
}

void IntersectionList_Sq(SqList*& La, SqList*& Lb, SqList*& Lc)
{
	int m = 0;
	char k;
	for (int i = 0; i < MaxSize; i++)//½»¼¯ 
	{
		for (int j = 0; j < MaxSize; j++)
		{
			if (La->data[i] == Lb->data[j])
			{
				Lc->data[m++] = La->data[i];
				break;
			}
		}
	}
}

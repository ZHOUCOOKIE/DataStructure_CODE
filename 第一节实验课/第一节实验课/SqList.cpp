//#include "SqList.h"
//void SqList::CreatList_Sq(SqList*& L, ElemType a[], int n)
//{
//	int i;
//	L = (SqList*)malloc(sizeof(SqList));
//	for (i = 0; i < n; i++)
//		L->data[i] = a[i];
//	L->length = n;
//}
//
//void SqList::InitList_Sq(SqList*& L)
//{
//	L = (SqList*)malloc(sizeof(SqList));
//	L->length = 0;
//}
//
//bool SqList::ListInsert_Sq(SqList*& L, int i, ElemType e)
//{
//	int j;
//	if (L->length == MaxSize)return false;
//	i--;
//	for (j = L->length; j > i; j--)
//		L->data[j] = L->data[j - 1];
//	L->data[i] = e;
//	L->length++;
//	return true;
//}
//
//void SqList::ListTraverse_Sq(SqList*& L)
//{
//	int i;
//	for (i = 0; i < L->length; i++)
//		printf("%d", L->data[i]);
//	printf("\n");
//}
//
//bool SqList::ListEmpty_Sq(SqList* L)
//{
//	return(L->length);
//}
//
//int SqList::ListLength_Sq(SqList* L)
//{
//	return(L->length);
//}
//
//int SqList::LocateElem_Sq(SqList* L, ElemType e)
//{
//	int i = 0;
//	while (i < L->length && L->data[i] != e)
//		i++;
//	if (i < L->length)
//		return i + 1;
//	else
//		return 0;
//}
//
//bool SqList::ListDelete_Sq(SqList*& L, int i, ElemType& e)
//{
//	int j;
//	if ((i < 1) || (i > L->length))
//		return false;
//	i--;
//	e = L->data[i];
//	for (j = i; j < L->length - 1; j++)
//		L->data[j] = L->data[j + 1];
//	L->length--;
//	return true;
//}
//
//void SqList::DestroyList_Sq(SqList*& L)
//{
//	free(L);
//}
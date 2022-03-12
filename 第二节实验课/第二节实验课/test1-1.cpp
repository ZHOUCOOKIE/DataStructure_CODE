#include <stdio.h>
#include "SqList.h"

int main()
{
	ElemType e;
	SqList* L;
	InitList_Sq(L);
	ListInsert_Sq(L, 1, 'e');
	ListInsert_Sq(L, 1, 'd');
	ListInsert_Sq(L, 1, 'c');
	ListInsert_Sq(L, 1, 'b');
	ListInsert_Sq(L, 1, 'a');
	ListTraverse_Sq(L);
	printf("%d\n",ListEmpty_Sq(L)); 
	printf("%d\n", ListLength_Sq(L));
	Listabc_Sq(L,3);
	printf("%d\n", LocateElem_Sq(L, 'a'));
	ListInsert_Sq(L, 4, 'f');
	ListTraverse_Sq(L);
	ListDelete_Sq(L, 3, e);
	ListTraverse_Sq(L);
	DestroyList_Sq(L);

}
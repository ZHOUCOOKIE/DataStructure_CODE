#include "SqList.h"
#include <stdio.h>

int main()
{
	ElemType e;
	SqList* L;
	printf("��ʼ��˳���L\n");
	InitList_Sq(L);
	ListInsert_Sq(L, 1, '6');
	ListInsert_Sq(L, 2, '7');
	ListInsert_Sq(L, 3, '9');
	ListInsert_Sq(L, 4, '1');
	ListInsert_Sq(L, 5, '2');
	printf("���˳���L:");
	ListTraverse_Sq(L);
	printf("sort˳���L\n");
	Listbubble_sort(L, MaxSize);
	printf("���˳���L:");
	ListTraverse_Sq(L);
	DestroyList_Sq(L);
}
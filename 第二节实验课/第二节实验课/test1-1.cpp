#include <stdio.h>
#include "SqList.h"

int main()
{
	ElemType e;
	SqList* L;
	printf("��ʼ��˳���L\n");
	InitList_Sq(L);
	printf("���β���a��b��c��d��e\n");
	ListInsert_Sq(L, 1, 'a');
	ListInsert_Sq(L, 2, 'b');
	ListInsert_Sq(L, 3, 'c');
	ListInsert_Sq(L, 4, 'd');
	ListInsert_Sq(L, 5, 'e');
	printf("���˳���L:");
	ListTraverse_Sq(L);
	printf("���˳���L�ĳ���:%d\n", ListLength_Sq(L));
	printf("�ж�˳���L�Ƿ�Ϊ��(1��ʾΪ��/0��ʾ�ǿ�):%d\n",ListEmpty_Sq(L));
	printf("���˳���ĵ�3��Ԫ��:");
	Listlocate_Sq(L, 3);
	printf("���Ԫ��a���߼�λ��:%d\n", LocateElem_Sq(L, 'a'));
	printf("�ڵ�4��Ԫ��λ���ϲ���Ԫ��f\n");
	ListInsert_Sq(L, 4, 'f');
	printf("���˳���L:");
	ListTraverse_Sq(L);
	printf("ɾ��L�ĵ�3��Ԫ��\n");
	ListDelete_Sq(L, 3, e);
	printf("���˳���L:");
	ListTraverse_Sq(L);
	printf("�ͷ�˳���L");
	DestroyList_Sq(L);
	return 0;
}
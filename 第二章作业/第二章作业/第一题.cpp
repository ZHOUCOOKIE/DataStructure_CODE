#include "SqList.h"
int main()
{
	ElemType e;
	SqList* L;
	printf("��ʼ��˳���L\n");
	InitList_Sq(L);
	printf("���β���1��2��3��4\n");
	ListInsert_Sq(L, 1, 1);
	ListInsert_Sq(L, 2, 2);
	ListInsert_Sq(L, 3, 3);
	ListInsert_Sq(L, 4, 4);
	printf("���˳���L:");
	ListTraverse_Sq(L);
	printf("���˳���L�ĳ���:%d\n", ListLength_Sq(L));
	printf("���Ԫ��2���߼�λ��:");
	Listlocate_Sq(L, 2);
	printf("�ڵ�5��Ԫ��λ���ϲ���Ԫ��5\n");
	ListInsert_Sq(L, 5, 5);
	printf("���˳���L:");
	ListTraverse_Sq(L);
	printf("ɾ��L�ĵ�3��Ԫ��\n");
	ListDelete_Sq(L, 3,e);
	printf("���˳���L:");
	ListTraverse_Sq(L);
	printf("�ͷ�˳���L");
	DestroyList_Sq(L);
	return 0;
}


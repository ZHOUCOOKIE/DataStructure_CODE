#include "DuLinkList.h"
#include <stdio.h>
void main()
{
	DuLinkList* L;
	ElemType e;
	ElemType a[] = "abcde";
	printf("˫�����ʼ����");
	CreateListF_DuL(L, a, 5);
	PrintList_DuL(L);
	printf("ɾ��˫����ڶ���Ԫ�أ�");
	ListDelete_DuL(L, 2, e);
	PrintList_DuL(L);
	printf("�ڵڶ���λ�ò���ո�ɾ����Ԫ�أ�");
	ListLnsert_DuL(L, 2, e);
	PrintList_DuL(L);
	printf("����˫����");
	invertSort(L,  a, 5);
	PrintList_DuL(L);
}

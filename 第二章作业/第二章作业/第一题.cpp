#include "SqList.h"
int main()
{
	ElemType e;
	SqList* L;
	printf("初始化顺序表L\n");
	InitList_Sq(L);
	printf("依次插入1，2，3，4\n");
	ListInsert_Sq(L, 1, 1);
	ListInsert_Sq(L, 2, 2);
	ListInsert_Sq(L, 3, 3);
	ListInsert_Sq(L, 4, 4);
	printf("输出顺序表L:");
	ListTraverse_Sq(L);
	printf("输出顺序表L的长度:%d\n", ListLength_Sq(L));
	printf("输出元素2的逻辑位置:");
	Listlocate_Sq(L, 2);
	printf("在第5个元素位置上插入元素5\n");
	ListInsert_Sq(L, 5, 5);
	printf("输出顺序表L:");
	ListTraverse_Sq(L);
	printf("删除L的第3个元素\n");
	ListDelete_Sq(L, 3,e);
	printf("输出顺序表L:");
	ListTraverse_Sq(L);
	printf("释放顺序表L");
	DestroyList_Sq(L);
	return 0;
}


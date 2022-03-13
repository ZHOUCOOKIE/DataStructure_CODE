#include <stdio.h>
#include "SqList.h"

int main()
{
	ElemType e;
	SqList* L;
	printf("初始化顺序表L\n");
	InitList_Sq(L);
	printf("依次插入a、b、c、d、e\n");
	ListInsert_Sq(L, 1, 'a');
	ListInsert_Sq(L, 2, 'b');
	ListInsert_Sq(L, 3, 'c');
	ListInsert_Sq(L, 4, 'd');
	ListInsert_Sq(L, 5, 'e');
	printf("输出顺序表L:");
	ListTraverse_Sq(L);
	printf("输出顺序表L的长度:%d\n", ListLength_Sq(L));
	printf("判断顺序表L是否为空(1表示为空/0表示非空):%d\n",ListEmpty_Sq(L));
	printf("输出顺序表的第3个元素:");
	Listlocate_Sq(L, 3);
	printf("输出元素a的逻辑位置:%d\n", LocateElem_Sq(L, 'a'));
	printf("在第4个元素位置上插入元素f\n");
	ListInsert_Sq(L, 4, 'f');
	printf("输出顺序表L:");
	ListTraverse_Sq(L);
	printf("删除L的第3个元素\n");
	ListDelete_Sq(L, 3, e);
	printf("输出顺序表L:");
	ListTraverse_Sq(L);
	printf("释放顺序表L");
	DestroyList_Sq(L);
	return 0;
}
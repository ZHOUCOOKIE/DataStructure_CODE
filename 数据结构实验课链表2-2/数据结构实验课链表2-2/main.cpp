#include "DuLinkList.h"
#include <stdio.h>
void main()
{
	DuLinkList* L;
	ElemType e;
	ElemType a[] = "abcde";
	printf("双链表初始化：");
	CreateListF_DuL(L, a, 5);
	PrintList_DuL(L);
	printf("删除双链表第二个元素：");
	ListDelete_DuL(L, 2, e);
	PrintList_DuL(L);
	printf("在第二个位置插入刚刚删除的元素：");
	ListLnsert_DuL(L, 2, e);
	PrintList_DuL(L);
	printf("逆置双链表");
	invertSort(L,  a, 5);
	PrintList_DuL(L);
}

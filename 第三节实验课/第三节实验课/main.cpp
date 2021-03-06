////（1）初始化单链表h
////（2）采用尾插法依次插入a、b、c、d、e
////（3）输出单链表h
////（4）输出单链表h的长度
////（5）判断单链表h是否为空
////（6）输出单链表h的第3个元素
////（7）输出元素a的逻辑位置
////（8）在第4个元素位置上插入元素f
////（9）输出单链表h
////（10）删除单链表h的第3个元素
////（11）输出单链表h
////（12）释放单链表h
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Linklist.h"

void ListTraverse_Sq(Linklist*& L)//当线性表L不为空时，依次输出L中的每个数据元素。
{

	Linklist* p = L->next;
	while (p->next != NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("%c\n", p->data);
}

int main()
{
	ElemType e;
	Linklist* L;
	char a[] = "abcde";
	printf("依次插入a、b、c、d、e\n");
	CreatList_Sq(L, a, 5);
	printf("输出顺序表L:");
	ListTraverse_Sq(L);
	printf("输出顺序表L的长度:%d\n", ListLength_Sq(L));
	printf("判断顺序表L是否为空(1表示为空/0表示非空):%d\n", ListEmpty_Sq(L));
	printf("输出顺序表的第3个元素:");
	Listlocate_Sq(L, 3, e);
	printf("%c\n", e);
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
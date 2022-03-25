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

void ListTraverse_Sq(Linklist*& L)//当链表L不为空时，依次输出L中的每个数据元素。
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
	DuLinkList* DL;
	ElemType a[] = "abcde";

	printf("依次插入a、b、c、d、e\n");
	CreatList_Sq(L, a, 5);
	printf("输出链表L:");
	ListTraverse_Sq(L);
	printf("删除a - c");
	deletes(L, 'a', 'd');
	printf("输出链表L:");
	ListTraverse_Sq(L);
	printf("释放链表L\n");
	DestroyList_Sq(L);
	CreateListF_DuL(DL, a, 5);
	PrintList_DuL(DL);
	invertSort(DL);
	PrintList_DuL(DL);
	return 0;
}

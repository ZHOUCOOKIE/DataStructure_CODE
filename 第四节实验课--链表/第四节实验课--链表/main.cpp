////��1����ʼ��������h
////��2������β�巨���β���a��b��c��d��e
////��3�����������h
////��4�����������h�ĳ���
////��5���жϵ�����h�Ƿ�Ϊ��
////��6�����������h�ĵ�3��Ԫ��
////��7�����Ԫ��a���߼�λ��
////��8���ڵ�4��Ԫ��λ���ϲ���Ԫ��f
////��9�����������h
////��10��ɾ��������h�ĵ�3��Ԫ��
////��11�����������h
////��12���ͷŵ�����h
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Linklist.h"

void ListTraverse_Sq(Linklist*& L)//������L��Ϊ��ʱ���������L�е�ÿ������Ԫ�ء�
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

	printf("���β���a��b��c��d��e\n");
	CreatList_Sq(L, a, 5);
	printf("�������L:");
	ListTraverse_Sq(L);
	printf("ɾ��a - c");
	deletes(L, 'a', 'd');
	printf("�������L:");
	ListTraverse_Sq(L);
	printf("�ͷ�����L\n");
	DestroyList_Sq(L);
	CreateListF_DuL(DL, a, 5);
	PrintList_DuL(DL);
	invertSort(DL);
	PrintList_DuL(DL);
	return 0;
}

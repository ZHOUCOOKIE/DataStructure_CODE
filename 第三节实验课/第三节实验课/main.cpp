//��1����ʼ��������h
//��2������β�巨���β���a��b��c��d��e
//��3�����������h
//��4�����������h�ĳ���
//��5���жϵ�����h�Ƿ�Ϊ��
//��6�����������h�ĵ�3��Ԫ��
//��7�����Ԫ��a���߼�λ��
//��8���ڵ�4��Ԫ��λ���ϲ���Ԫ��f
//��9�����������h
//��10��ɾ��������h�ĵ�3��Ԫ��
//��11�����������h
//��12���ͷŵ�����h
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Linklist.h"

void ListTraverse_Sq(Linklist*& L)//�����Ա�L��Ϊ��ʱ���������L�е�ÿ������Ԫ�ء�
{

	Linklist* p = L->next;
	int n = 0;
	while (p->next != NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("%c", p->data);
	printf("\n");
}

int main()
{
	ElemType e;
	Linklist* L;
	char a[] = "abcde";
	printf("���β���a��b��c��d��e\n");
	CreatList_Sq(L, a, 5);
	printf("���˳���L:");
	ListTraverse_Sq(L);
	printf("���˳���L�ĳ���:%d\n", ListLength_Sq(L));
	printf("�ж�˳���L�Ƿ�Ϊ��(1��ʾΪ��/0��ʾ�ǿ�):%d\n", ListEmpty_Sq(L));
	printf("���˳���ĵ�3��Ԫ��:");
	Listlocate_Sq(L, 3, e);
	printf("%c\n", e);
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
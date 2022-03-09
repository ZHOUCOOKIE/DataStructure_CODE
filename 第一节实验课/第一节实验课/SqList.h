#include <iostream>

typedef char ElemType;
#define MaxSize 60
using namespace std;

#pragma once

class SqList
{
private:
	ElemType data[MaxSize];
	int length;
public:
	void CreatList_Sq(SqList*& L, ElemType a[], int n);
	void InitList_Sq(SqList *&L);
	bool ListInsert_Sq(SqList *&L, int i, ElemType e);
	void ListTraverse_Sq(SqList*& L);
	bool ListEmpty_Sq(SqList* L);
	int ListLength_Sq(SqList* L);

	int LocateElem_Sq(SqList* L, ElemType e);

	bool ListDelete_Sq(SqList*& L, int i, ElemType& e);
	void DestroyList_Sq(SqList*& L);

};

//1.��дһ������ʵ��˳���ĸ��ֻ������㣬��ʵ���˳���Ԫ�ص�����Ϊchar�����������е���˳���Ļ�������������²���:
//��1����ʼ��˳���L
//��2��������˳���L��β������a��b��c��d��e��5���ַ�
//��3�����˳���L
//��4���ж�˳���L�Ƿ�Ϊ��
//��5�����˳���L�ĳ���
//��6�����˳���L�ĵ�3��Ԫ��
//��7�����Ԫ��a���߼�λ��
//��8���ڵ�4��Ԫ��λ���ϲ����ַ�f
//��9�����˳���L
//��10��ɾ��L�ĵ�3��Ԫ��
//��11�����˳���L
//��12���ͷ�˳���L
//����ʵ�鲽��
//1.��1���ο��̲����˳������ƣ��ļ���ΪSqList.cpp��
//��2����SqList.cpp�б�дmain���������ȵ���˳���ĸ�������Ȼ�������ƺõ�˳������������ʵ�����ݺ�Ҫ���е�12��������
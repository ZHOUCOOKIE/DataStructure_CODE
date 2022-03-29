#pragma once

typedef char ElemType;
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLinkList;

void CreateListF_DuL(DuLinkList*& L, ElemType a[], int n);//��ʼ��˫����
void invertSort(DuLinkList*& L, ElemType a[], int n);//����Ԫ��
void PrintList_DuL(DuLinkList* L);//����˫����
bool ListDelete_DuL(DuLinkList*& L, int i, ElemType& e);//ɾ��Ԫ��
bool ListLnsert_DuL(DuLinkList*& L, int i, ElemType e);//����˫����
void DestroyList_DuL(DuLinkList*& L);//��������L���ͷ�����Lռ�õ��ڴ�ռ䡣
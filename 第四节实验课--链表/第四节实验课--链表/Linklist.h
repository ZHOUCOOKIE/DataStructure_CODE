#pragma once
typedef char ElemType;
typedef struct Linklist {
	ElemType data;
	struct Linklist* next;
}SqList;

void InitList_Sq(Linklist*& L);//��ʼ������
bool ListInsert_Sq(Linklist*& L, int i, ElemType e);//����Ԫ��
bool ListEmpty_Sq(Linklist* L);//�ж������Ƿ�Ϊ��
int ListLength_Sq(Linklist* L);//����������
int LocateElem_Sq(Linklist* L, ElemType e);//���� L�е�һ����ֵ��e��ȵ�Ԫ�ص�λ��
bool ListDelete_Sq(Linklist*& L, int i, ElemType& e);//ɾ��Ԫ��
void DestroyList_Sq(Linklist*& L);//��������L���ͷ�����Lռ�õ��ڴ�ռ�
bool Listlocate_Sq(Linklist*& L, int i, ElemType& e);//�������ĵ�i��Ԫ��
void CreatList_Sq(Linklist*& L, ElemType a[], int n);//β�巨��������
void deletes(Linklist*& L, char min, char max);//ɾ��min��max֮���Ԫ��

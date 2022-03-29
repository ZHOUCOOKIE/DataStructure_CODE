#pragma once
typedef char ElemType;
typedef struct Linklist {
	ElemType data;
	struct Linklist* next;
}SqList;

void InitList_Sq(Linklist*& L);//初始化链表
bool ListInsert_Sq(Linklist*& L, int i, ElemType e);//插入元素
bool ListEmpty_Sq(Linklist* L);//判断链表是否为空
int ListLength_Sq(Linklist* L);//计算链表长度
int LocateElem_Sq(Linklist* L, ElemType e);//返回 L中第一个其值与e相等的元素的位序
bool ListDelete_Sq(Linklist*& L, int i, ElemType& e);//删除元素
void DestroyList_Sq(Linklist*& L);//销毁链表L，释放链表L占用的内存空间
bool Listlocate_Sq(Linklist*& L, int i, ElemType& e);//输出链表的第i个元素
void CreatList_Sq(Linklist*& L, ElemType a[], int n);//尾插法创建链表
void deletes(Linklist*& L, char min, char max);//删除min和max之间的元素

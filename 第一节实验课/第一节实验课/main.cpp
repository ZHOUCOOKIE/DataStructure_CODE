
//1.编写一个程序，实现顺序表的各种基本运算，本实验的顺序表元素的类型为char，在主函数中调用顺序表的基本操作完成如下操作:
//（1）初始化顺序表L
//（2）依次在顺序表L的尾部插入a、b、c、d、e等5个字符
//（3）输出顺序表L
//（4）判断顺序表L是否为空
//（5）输出顺序表L的长度
//（6）输出顺序表L的第3个元素
//（7）输出元素a的逻辑位置
//（8）在第4个元素位置上插入字符f
//（9）输出顺序表L
//（10）删除L的第3个元素
//（11）输出顺序表L
//（12）释放顺序表L
//三、实验步骤
//1.（1）参考教材完成顺序表的设计，文件名为SqList.cpp；
//（2）在SqList.cpp中编写main函数，首先调试顺序表的各操作，然后调用设计好的顺序表函数，需完成实验内容和要求中的12个操作。
//#include <stdio.h>
//#include <stdlib.h>
//#define MaxSize 60
//typedef char ElemType;
//
//typedef struct {
//	ElemType data[MaxSize];
//	int length;
//}SqList;
//
//void CreatList_Sq(SqList*& L, ElemType a[], int n);
//void InitList_Sq(SqList*& L);
//bool ListInsert_Sq(SqList*& L, int i, ElemType e);
//void ListTraverse_Sq(SqList*& L);
//bool ListEmpty_Sq(SqList* L);
//int ListLength_Sq(SqList* L);
//int LocateElem_Sq(SqList* L, ElemType e);
//bool ListDelete_Sq(SqList*& L, int i, ElemType& e);
//void DestroyList_Sq(SqList*& L);
//void Listabc_Sq(SqList*& L, int i);
//
//
//int main()
//{
//	ElemType e;
//	SqList* L;
//	InitList_Sq(L);
//	ListInsert_Sq(L, 1, 'e');
//	ListInsert_Sq(L, 1, 'd');
//	ListInsert_Sq(L, 1, 'c');
//	ListInsert_Sq(L, 1, 'b');
//	ListInsert_Sq(L, 1, 'a');
//	ListTraverse_Sq(L);
//	printf("%d\n",ListEmpty_Sq(L)); 
//	printf("%d\n", ListLength_Sq(L));
//	Listabc_Sq(L,3);
//	printf("%d\n", LocateElem_Sq(L, 'a'));
//	ListInsert_Sq(L, 4, 'f');
//	ListTraverse_Sq(L);
//	ListDelete_Sq(L, 3, e);
//	ListTraverse_Sq(L);
//	DestroyList_Sq(L);
//
//}
//
////（1）初始化顺序表L
////（2）依次在顺序表L的尾部插入a、b、c、d、e等5个字符
////（3）输出顺序表L
////（4）判断顺序表L是否为空
////（5）输出顺序表L的长度
////（6）输出顺序表L的第3个元素
////（7）输出元素a的逻辑位置
////（8）在第4个元素位置上插入字符f
////（9）输出顺序表L
////（10）删除L的第3个元素
////（11）输出顺序表L
////（12）释放顺序表L
//
//void Listabc_Sq(SqList*& L,int i)
//{
//	printf("%c", L->data[i-1]);
//	printf("\n");
//}
//
//void InitList_Sq(SqList*& L)
//{
//	L = (SqList*)malloc(sizeof(SqList));
//	L->length = 0;
//}
//
//bool ListInsert_Sq(SqList*& L, int i, ElemType e)
//{
//	int j;
//	if (L->length == MaxSize)return false;
//	i--;
//	for (j = L->length; j > i; j--)
//		L->data[j] = L->data[j - 1];
//	L->data[i] = e;
//	L->length++;
//	return true;
//}
//
//void ListTraverse_Sq(SqList*& L)
//{
//	int i;
//	for (i = 0; i < L->length; i++)
//		printf("%c", L->data[i]);
//	printf("\n");
//}
//
//bool ListEmpty_Sq(SqList* L)
//{
//	return(L->length);
//}
//
//int ListLength_Sq(SqList* L)
//{
//	return(L->length);
//}
//
//int LocateElem_Sq(SqList* L, ElemType e)
//{
//	int i = 0;
//	while (i < L->length && L->data[i] != e)
//		i++;
//	if (i < L->length)
//		return i + 1;
//	else
//		return 0;
//}
//
//bool ListDelete_Sq(SqList*& L, int i, ElemType& e)
//{
//	int j;
//	if ((i < 1) || (i > L->length))
//		return false;
//	i--;
//	e = L->data[i];
//	for (j = i; j < L->length - 1; j++)
//		L->data[j] = L->data[j + 1];
//	L->length--;
//	return true;
//}
//
//void DestroyList_Sq(SqList*& L)
//{
//	free(L);
//}
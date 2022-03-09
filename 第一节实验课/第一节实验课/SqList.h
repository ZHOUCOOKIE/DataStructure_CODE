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
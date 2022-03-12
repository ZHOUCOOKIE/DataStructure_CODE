////3.假设有两个集合 A 和 B，分别用两个顺序表 La 和 Lb表示，
////即顺序表中的数据元素即为集合中的元素，利用顺序表的基本运算
////编写一个算法实现集合的交运算，即求一个新的集合C = A∩B。
//#include "SqList.h"
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	ElemType e;
//	SqList* La;
//	SqList* Lb;
//	SqList* Lc;
//	InitList_Sq(La);
//	InitList_Sq(Lb);
//	InitList_Sq(Lc);
//	ListInsert_Sq(La, 1, '2');
//	ListInsert_Sq(La, 2, '3');
//	ListInsert_Sq(La, 3, '5');
//	ListInsert_Sq(La, 4, '6');
//	ListInsert_Sq(La, 5, '8');
//
//	ListInsert_Sq(Lb, 1, '2');
//	ListInsert_Sq(Lb, 2, '4');
//	ListInsert_Sq(Lb, 3, '5');
//	ListInsert_Sq(Lb, 4, '7');
//	ListInsert_Sq(Lb, 5, '9');
//
//	ListInsert_Sq(Lc, 1, '\0');//在比较到两线性表都有元素插入的时候不会搞，所以先分配好线性表长度
//	ListInsert_Sq(Lc, 2, '\0');
//	ListInsert_Sq(Lc, 3, '\0');
//	ListInsert_Sq(Lc, 4, '\0');
//	ListInsert_Sq(Lc, 5, '\0');//最多有五个元素相同
//
//	ListTraverse_Sq(La);
//	ListTraverse_Sq(Lb);
//	ListTraverse_Sq(Lc);
//
//	IntersectionList_Sq(La, Lb, Lc);
//
//	ListTraverse_Sq(La);
//	ListTraverse_Sq(Lb);
//	ListTraverse_Sq(Lc);
//
//	DestroyList_Sq(La);
//	DestroyList_Sq(Lb);
//	DestroyList_Sq(Lc);
//
//}

#include "SqList.h"
#include <stdio.h>
#include <string.h>
int main()
{
	ElemType e,a[5]={'2','3','5','6','8'}, b[5] = { '2','4','5','7','9' };
	SqList* La;
	SqList* Lb;
	SqList* Lc;
	CreatList_Sq(La, a, 5);
	CreatList_Sq(Lb, b, 5);
	InitList_Sq(Lc);
	printf("顺序表La:");
	ListTraverse_Sq(La);
	printf("顺序表Lb:");
	ListTraverse_Sq(Lb);
	InterSection(La, Lb, Lc);
	printf("顺序表La Lb交集Lc:");
	ListTraverse_Sq(Lc);
	DestroyList_Sq(La);
	DestroyList_Sq(Lb);
	DestroyList_Sq(Lc);
	return 0;
}

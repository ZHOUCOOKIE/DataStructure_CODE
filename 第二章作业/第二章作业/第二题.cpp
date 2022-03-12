#include "SqList.h"
int main()
{
	ElemType arr1[5] = { 1,2,3,6,7 };
	ElemType arr2[5] = {1,2,3,4,5};
	SqList *La, *Lb;
	CreatList_Sq(La, arr1, 5);
	CreatList_Sq(Lb, arr2, 5);
	ListTraverse_Sq(La);
	ListTraverse_Sq(Lb);
	Union(La, Lb);
	DestroyList_Sq(La);
	return 0;
}
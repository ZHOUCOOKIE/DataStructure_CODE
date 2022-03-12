////4.编写一个算法，一个线性表L采用顺序存储结构，若其中所有元素为整数，
////删除数据值在[x, y]之间的所有元素，要求算法的时间复杂度为O(n)，
////空间复杂度为O(1).（提示：该算法无需调用顺序表的基本操作，而是直接操作顺序表L）
//#include "SqList.h"
//#define x 1
//#define y 3
//int main()
//{
//	ElemType e, arr[5]={0,1,2,3,4};
//	SqList* L;
//	CreatList_Sq(L, arr, 5);
//	ListTraverse_Sq(L);
//	for (int i = 0; i < L->length; i++)
//	{
//		if (L->data[i] >= x && L->data[i] <= y)
//		{
//			ListDelete_Sq(L, i+1, e);
//			i--;
//		}
//	}
//	ListTraverse_Sq(L);
//	DestroyList_Sq(L);
//	return 0;
//}
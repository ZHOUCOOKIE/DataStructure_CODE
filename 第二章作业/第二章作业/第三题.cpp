//3. 算法设计：假设一个顺序表中所有元素为整数，编写算法将所有小于0的元素
// 移动到所有大于0的元素前面，要求算法的时间复杂度为O(n)，空间复杂度为O(1).
// （提示：该算法无需调用顺序表的基本操作，而是直接操作顺序表L）
#include "SqList.h"
int main()
{
	ElemType e, j = 0, temp;
	SqList* L;
	int arr[5] = { 1,2,3,-1,-2 };
	CreatList_Sq(L, arr, 5);
	printf("初始线性表L：");
	ListTraverse_Sq(L);
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] < 0)
		{
			temp = L->data[i];
			L->data[i] = L->data[j];
			L->data[j++] = temp;
		}
	}
	printf("结果线性表L：");
	ListTraverse_Sq(L);
	DestroyList_Sq(L);
	return 0;
}
//�����215�� 202110244532 �ܿ���
#include "SqList.h"
#define x 1
#define y 3
int main()
{
	ElemType e, arr[5]={0,1,2,3,4};
	SqList* L;
	CreatList_Sq(L, arr, 5);
	printf("��ʼ���Ա�L��");
	ListTraverse_Sq(L);
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] >= x && L->data[i] <= y)
		{
			ListDelete_Sq(L, i+1, e);
			i--;
		}
	}
	printf("������Ա�L��");
	ListTraverse_Sq(L);
	DestroyList_Sq(L);
	return 0;
}
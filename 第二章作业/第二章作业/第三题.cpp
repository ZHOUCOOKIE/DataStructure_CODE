//�����215�� 202110244532 �ܿ���
#include "SqList.h"
int main()
{
	ElemType e, j = 0, temp;
	SqList* L;
	int arr[5] = { 1,2,3,-1,-2 };
	CreatList_Sq(L, arr, 5);
	printf("��ʼ���Ա�L��");
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
	printf("������Ա�L��");
	ListTraverse_Sq(L);
	DestroyList_Sq(L);
	return 0;
}
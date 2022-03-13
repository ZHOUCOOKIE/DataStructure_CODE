//计算机215班 202110244532 周俊安
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

void CreatList_Sq(SqList*& L, ElemType a[], int n)
{
	int i;
	L = (SqList*)malloc(sizeof(SqList));
	for (i = 0; i < n; i++)
		L->data[i] = a[i];
	L->length = n;
}

void ListTraverse_Sq(SqList*& L)
{
	int i = 0;
	for (i = 0; i < L->length; i++)
		printf("%d ", L->data[i]);
	printf("\n");
}

void DestroyList_Sq(SqList*& L)
{
	free(L);
}

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
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

bool ListDelete_Sq(SqList*& L, int i, ElemType& e)
{
	int j;
	if ((i < 1) || (i > L->length))
		return false;
	i--;
	e = L->data[i];
	L->data[i] = 0;
	for (j = i; j < L->length - 1; j++)
		L->data[j] = L->data[j + 1];
	L->length--;
	return true;
}

void DestroyList_Sq(SqList*& L)
{
	free(L);
}

#define x 1
#define y 3
int main()
{
	ElemType e, arr[5]={0,1,2,3,4};
	SqList* L;
	CreatList_Sq(L, arr, 5);
	printf("初始线性表L：");
	ListTraverse_Sq(L);
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] >= x && L->data[i] <= y)
		{
			ListDelete_Sq(L, i+1, e);
			i--;
		}
	}
	printf("删除1-3结果线性表L：");
	ListTraverse_Sq(L);
	DestroyList_Sq(L);
	return 0;
}
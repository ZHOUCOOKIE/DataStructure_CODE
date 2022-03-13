//计算机215班 202110244532 周俊安
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

void InitList_Sq(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}

bool ListInsert_Sq(SqList*& L, int i, ElemType e)
{
	int j;
	if (L->length == MaxSize)return false;
	i--;
	for (j = L->length; j > i; j--)
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;
	return true;
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

int ListLength_Sq(SqList* L)
{
	return(L->length);
}


int LocateElem_Sq(SqList* L, ElemType e)
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
		i++;
	if (i < L->length)
		return i + 1;
	else
		return 0;
}

int main()
{
	ElemType e;
	SqList* L;
	printf("初始化顺序表L\n");
	InitList_Sq(L);
	printf("依次插入1，2，3，4\n");
	ListInsert_Sq(L, 1, 1);
	ListInsert_Sq(L, 2, 2);
	ListInsert_Sq(L, 3, 3);
	ListInsert_Sq(L, 4, 4);
	printf("输出顺序表L:");
	ListTraverse_Sq(L);
	printf("输出顺序表L的长度:%d\n", ListLength_Sq(L));
	printf("输出元素2的逻辑位置:%d\n", LocateElem_Sq(L, 2));
	printf("在第5个元素位置上插入元素5\n");
	ListInsert_Sq(L, 5, 5);
	printf("输出顺序表L:");
	ListTraverse_Sq(L);
	printf("删除L的第3个元素\n");
	ListDelete_Sq(L, 3,e);
	printf("输出顺序表L:");
	ListTraverse_Sq(L);
	printf("释放顺序表L");
	DestroyList_Sq(L);
	return 0;
}
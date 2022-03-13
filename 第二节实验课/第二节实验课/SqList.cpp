#include "SqList.h"
void Listlocate_Sq(SqList*& L, int i)//输出顺序表的第i个元素。
{
	printf("%c", L->data[i - 1]);
	printf("\n");
}

void InitList_Sq(SqList*& L)//初始化线性表，构造一个空的线性表L。
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}

bool ListInsert_Sq(SqList*& L, int i, ElemType e)//插入数据元素，在L中第1个位置之前插入新的数据元素 e, L的长度加一。
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

void Listbubble_sort(SqList*& L, int length)
{
	int temp = 0;
	for (int i = 0; i < L->length - 1; i++)
		for (int j = 0; j < L->length - 1 - i; j++)
			if (L->data[j] > L->data[j + 1]) {
				temp = L->data[j];
				L->data[j] = L->data[j + 1];
				L->data[j + 1] = temp;
			}
}

void ListTraverse_Sq(SqList*& L)//当线性表L不为空时，依次输出L中的每个数据元素。
{
	int i=0;
	for (i = 0; i < L->length; i++)
		printf("%c ", L->data[i]);
	printf("\n");
}

bool ListEmpty_Sq(SqList* L)//若 L 为空表，则返回 TRUE，否则返回 FALSE。
{
	return(L->length == 0);
}

int ListLength_Sq(SqList* L)//返回L中的数据元素个数。
{
	return(L->length);
}

int LocateElem_Sq(SqList* L, ElemType e)//返回 L中第一个其值与e相等的元素的位序。 若这样的数据元素不存在，则返回值为0。
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
		i++;
	if (i < L->length)
		return i + 1;
	else
		return 0;
}

bool ListDelete_Sq(SqList*& L, int i, ElemType& e)//删除数据元素。 删除L的第 i个数据元素，并用 e返回其值，L的长度减 1。
{
	int j;
	if ((i < 1) || (i > L->length))
		return false;
	i--;
	e = L->data[i];
	for (j = i; j < L->length - 1; j++)
		L->data[j] = L->data[j + 1];
	L->length--;
	return true;
}

void DestroyList_Sq(SqList*& L)//销毁线性表L，释放线性表L占用的内存空间。
{
	free(L);
}

void InterSection(SqList*& La, SqList*& Lb, SqList*& Lc)
{
	int i, j, m = 0, k = 1;
	for (i = 0; i < 5; i++)//交集 
	{
		for (j = 0; j < 5; j++)
		{
			if (La->data[i] == Lb->data[j])
			{
				ListInsert_Sq(Lc, k, La->data[i]);
				k++;
				break;
			}
		}
	}
}

void CreatList_Sq(SqList*& L, ElemType a[], int n)
{
	int i;
	L = (SqList*)malloc(sizeof(SqList));
	for (i = 0; i < n; i++)
		L->data[i] = a[i];
	L->length = n;
}
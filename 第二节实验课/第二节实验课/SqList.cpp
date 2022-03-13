#include "SqList.h"
void Listlocate_Sq(SqList*& L, int i)//���˳���ĵ�i��Ԫ�ء�
{
	printf("%c", L->data[i - 1]);
	printf("\n");
}

void InitList_Sq(SqList*& L)//��ʼ�����Ա�����һ���յ����Ա�L��
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}

bool ListInsert_Sq(SqList*& L, int i, ElemType e)//��������Ԫ�أ���L�е�1��λ��֮ǰ�����µ�����Ԫ�� e, L�ĳ��ȼ�һ��
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

void ListTraverse_Sq(SqList*& L)//�����Ա�L��Ϊ��ʱ���������L�е�ÿ������Ԫ�ء�
{
	int i=0;
	for (i = 0; i < L->length; i++)
		printf("%c ", L->data[i]);
	printf("\n");
}

bool ListEmpty_Sq(SqList* L)//�� L Ϊ�ձ��򷵻� TRUE�����򷵻� FALSE��
{
	return(L->length == 0);
}

int ListLength_Sq(SqList* L)//����L�е�����Ԫ�ظ�����
{
	return(L->length);
}

int LocateElem_Sq(SqList* L, ElemType e)//���� L�е�һ����ֵ��e��ȵ�Ԫ�ص�λ�� ������������Ԫ�ز����ڣ��򷵻�ֵΪ0��
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
		i++;
	if (i < L->length)
		return i + 1;
	else
		return 0;
}

bool ListDelete_Sq(SqList*& L, int i, ElemType& e)//ɾ������Ԫ�ء� ɾ��L�ĵ� i������Ԫ�أ����� e������ֵ��L�ĳ��ȼ� 1��
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

void DestroyList_Sq(SqList*& L)//�������Ա�L���ͷ����Ա�Lռ�õ��ڴ�ռ䡣
{
	free(L);
}

void InterSection(SqList*& La, SqList*& Lb, SqList*& Lc)
{
	int i, j, m = 0, k = 1;
	for (i = 0; i < 5; i++)//���� 
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
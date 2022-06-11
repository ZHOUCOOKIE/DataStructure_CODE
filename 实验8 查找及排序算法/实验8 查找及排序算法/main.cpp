//计算机215班202110244532周俊安
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//设计一个算法，输出在顺序表｛3，6，2，10，1，8，5，7，4，9｝中采用顺序方法查找关键字5的过程。
//设计一个非递归的算法，输出在顺序表｛1，2，3，4，5，6，7，8，9，10｝中采用二分查找法查找关键字9的过程。
#define MAXL 10
typedef int KeyType;
typedef int InfoType;

typedef struct {
	KeyType key;
	InfoType data;
}NodeType;

typedef NodeType SeqList[MAXL];

void CreateSeqList(SeqList R, int arr[]);
int SeqSearch(SeqList R1, int n, KeyType k);
int BinSearch(SeqList R, int n, KeyType k);
void CreateRecord(RecordType r[], int arr[]);

typedef int keyType;
typedef struct RecordType {
	keyType key;
	InfoType otherdata;
}RecordType;


int main()
{
	SeqList R1, R2;
	int arr1[] = { 3,6,2,10,1,8,5,7,4,9 };
	int arr2[] = { 1,2,3,4,5,6,7,8,9,10 };
	CreateSeqList(R1, arr1);
	CreateSeqList(R2, arr2);
	printf("5在线性表1中的位置为%d\n", SeqSearch(R1, 10, 5));
	printf("9在线性表2中的位置为%d\n", BinSearch(R2, 10, 9));

	RecordType r1[5];
	CreateRecord(r1,arr1);
	return 0;
}


void CreateSeqList(SeqList R, int arr[])
{
	for (int i = 0; i <= 10; i++)
	{
		R[i].key = arr[i];
	}
}

void CreateRecord(RecordType r[], int arr[])
{
	for (int i = 0; i <= 10; i++)
	{
		r[i].key = arr[i];
	}
}

int SeqSearch(SeqList R1, int n, KeyType k)
{
	int i = 0;
	while (i < n && R1[i].key != k)
	{
		printf("%d与%d比较\n", R1[i].key, k);
		i++;
	}
	printf("%d与%d比较\n", R1[i].key, k);
	if (i >= n)
		return -1;
	else
		return i;
}

int BinSearch(SeqList R, int n, KeyType k)
{
	int low = 0, high = n - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		printf("在[%d,%d]中比较元素R[%d]:%d\n", low, high, mid, R[mid]);
		if (R[mid].key == k)
			return mid;
		if (R[mid].key > k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

void DirectInsertSort(RecordType r[], int n)
{
	int i, j;
	for (i = 2; i < n; i++)
	{
		r[0] = r[i];
		j = i - 1;
		while (r[0].key < r[j].key)
		{
			r[j + 1] = r[j];
			j--;
		}
		r[j + 1] = r[0];
	}
}